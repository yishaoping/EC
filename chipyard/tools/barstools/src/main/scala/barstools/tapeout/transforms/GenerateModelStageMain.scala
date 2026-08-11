package barstools.tapeout.transforms

import barstools.tapeout.transforms.stage._
import firrtl._
import firrtl.annotations._
import firrtl.ir._
import firrtl.options.{Dependency, InputAnnotationFileAnnotation, StageMain}
import firrtl.passes.wiring.{SinkAnnotation, SourceAnnotation}
import firrtl.stage.{FirrtlCircuitAnnotation, FirrtlStage, RunFirrtlTransformAnnotation}
import firrtl.transforms.DontTouchAnnotation
import logger.LazyLogging

private class GenerateModelStageMain(annotations: AnnotationSeq) extends LazyLogging {
  val outAnno: Option[String] = annotations.collectFirst { case OutAnnoAnnotation(s) => s }

  val annoFiles: List[String] = annotations.flatMap {
    case InputAnnotationFileAnnotation(f) => Some(f)
    case _                                => None
  }.toList

  // Dump firrtl and annotation files
  // Use global param outAnno
  protected def dumpAnnos(
    annotations: AnnotationSeq,
    circuit:    Circuit
  ): Unit = {
    val moduleNamespaces = circuit.modules.map { module =>
      module.name -> Namespace(module)
    }.toMap
    outAnno.foreach { annoPath =>
      val outputFile = new java.io.PrintWriter(annoPath)
      outputFile.write(JsonProtocol.serialize(annotations.filter {
        case _: DeletedAnnotation       => false
        case _: EmittedComponent        => false
        case _: EmittedAnnotation[_]    => false
        case _: FirrtlCircuitAnnotation => false
        case _: OutAnnoAnnotation       => false
        // WiringTransform has already materialized these connections. Passing
        // its implementation annotations to CIRCT wires them a second time.
        case _: SourceAnnotation | _: SinkAnnotation => false
        // LowForm flattens aggregates and removes aliases, but FIRRTL 1.5.5 can
        // leave DontTouch targets referring to the old declarations.
        case DontTouchAnnotation(target) =>
          moduleNamespaces.get(target.leafModule).exists(_.contains(target.ref))
        case _ => true
      }))
      outputFile.close()
    }
  }

  def executeStageMain(): Unit = {
    val annos = new FirrtlStage().execute(Array.empty, annotations)

    annos.collectFirst { case FirrtlCircuitAnnotation(circuit) => circuit } match {
      case Some(circuit) =>
        dumpAnnos(annos, circuit)
      case _ =>
        throw new Exception(s"executeStageMain failed while executing FIRRTL!\n")
    }
  }
}

// main run class
object GenerateModelStageMain extends StageMain(new TapeoutStage())
