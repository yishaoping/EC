// See LICENSE for license details.

package midas.passes.fame


import firrtl._
import firrtl.analyses.InstanceGraph

import midas.targetutils.FirrtlFAMEModelAnnotation
import firrtl.annotations.transforms.{EliminateTargetPaths, ResolvePaths}

import scala.annotation.tailrec

class ExtractModel extends Transform {
  def inputForm = HighForm
  def outputForm = HighForm

  @tailrec
  private def promoteModels(state: CircuitState): CircuitState = {
    val fmAnns = state.annotations.collect({
      case ann: FirrtlFAMEModelAnnotation => ann.target.module -> ann
    }).toMap
    // Pick by order of parent in linearization -- don't pick children of main
    val modOrder = (new InstanceGraph(state.circuit)).moduleOrder.filterNot(_.name == state.circuit.main)
    val topModelAnn = modOrder.collectFirst(Function.unlift(dm => fmAnns.get(dm.name)))
    topModelAnn match {
      case None => state
      case Some(FirrtlFAMEModelAnnotation(it)) =>
        val anns = PromoteSubmoduleAnnotation(it) +: state.annotations
        val nextPromoted = (new PromoteSubmodule).runTransform(state.copy(annotations = anns))
        promoteModels(nextPromoted)
    }
  }

  override def execute(state: CircuitState): CircuitState = {
    // A Chisel instance annotation may name a bank under one specific caller.
    // Resolve the PARENT path using FIRRTL's stock specialization pass first.
    // Resolving the child itself would duplicate the model type unnecessarily.
    // Merely dropping the path would instead select every caller of that type.
    val parents = state.annotations.collect {
      case FirrtlFAMEModelAnnotation(it) if !it.isLocal => it.targetParent
    }.distinct
    val localized = if (parents.isEmpty) state else {
      val resolved = (new EliminateTargetPaths).runTransform(
        state.copy(annotations = state.annotations :+ ResolvePaths(parents)))
      require(resolved.annotations.collect {
        case FirrtlFAMEModelAnnotation(it) => it.isLocal
      }.forall(identity), "FAME model parent paths must resolve without widening selection")
      resolved
    }
    val transformed = promoteModels(localized)
    // At this point, the FIRRTLFAMEModelAnnotations are no longer used, so remove them for cleanup.
    // FAMEDefaults uses structure of "AQB form" to infer that all top-level, non-channel modules are FAME models.
    transformed.copy(annotations = transformed.annotations.filterNot(_.isInstanceOf[FirrtlFAMEModelAnnotation]))
  }
}
