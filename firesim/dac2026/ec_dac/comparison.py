"""Explicit, immutable comparability evidence for reuse of a public baseline.

Completion identity stays strict. Only analysis may join different campaigns,
and only when both embed admissions to the same reviewed comparison context.
"""
from __future__ import annotations
from . import DEFINITION
from .common import digest, filehash, read_json, require

SCHEMA = "ec-dac-comparison/1"
ARTIFACTS = {"bitstream", "driver", "kernel", "rootfs", "rtl_manifest", "observer_manifest"}


def configuration_signature(config):
    # Readiness is an admission state, not part of the hardware being compared.
    return {k:v for k,v in config.items() if k not in {"ready", "structural_ready", "deferred"}}


def _hash(value):
    return isinstance(value, str) and len(value) == 64 and all(c in "0123456789abcdef" for c in value)


def _descriptor(spec, check_files=False):
    require(isinstance(spec, dict) and bool(spec.get("path")) and _hash(spec.get("sha256")),
            "comparison evidence needs an exact path and SHA256")
    if check_files:
        require(filehash(spec["path"]) == spec["sha256"], "comparison evidence changed: " + spec["path"])


def validate_context(context, check_files=False):
    require(context.get("schema") == SCHEMA and context.get("definition") == DEFINITION,
            "unknown comparison context schema/measurement definition")
    require(context.get("reviewed") is True, "comparison context is not reviewed")
    require(bool(context.get("common")), "comparison context has no common parameters")
    require(not any(isinstance(v, str) and "BLOCKED" in v for v in context["common"].values()),
            "comparison context contains unresolved common parameters")
    baseline = context["baseline"]
    require(baseline["configuration"].get("id") == "B" and
            baseline["configuration"].get("rockets") == 0 and
            baseline["configuration"].get("mode") == "unprotected", "comparison baseline must be true B")
    require(ARTIFACTS <= set(baseline["artifacts"]), "baseline comparison artifacts are incomplete")
    for spec in baseline["artifacts"].values():
        _descriptor(spec, check_files)
    for key in ("software_manifest", "observer_manifest", "comparability_evidence"):
        _descriptor(context[key], check_files)
    # Documents must be retained with the campaign. Their hashes become part of
    # the immutable context; a changed baseline/image/observer yields a new id.
    return digest(context)


def validate_sample_comparison(sample):
    proof = sample.get("comparison")
    require(isinstance(proof, dict), "sample has no admitted comparison context")
    context, admission = proof["context"], proof["admission"]
    context_id = validate_context(context)
    require(proof["context_id"] == context_id, "comparison context digest mismatch")
    require(proof["admission_id"] == digest(admission), "comparison admission digest mismatch")
    require(admission.get("schema") == SCHEMA and admission.get("reviewed") is True,
            "comparison admission has not been reviewed")
    require(admission.get("context_id") == context_id, "admission is for a different comparison context")
    require(admission.get("configuration") == configuration_signature(sample["configuration"]),
            "comparison admission configuration mismatch")
    require(admission.get("source_id") == sample["source_id"], "comparison admission source mismatch")
    require(admission.get("artifacts_id") == digest(sample["artifacts"]), "comparison admission artifacts mismatch")
    require(ARTIFACTS <= set(sample["artifacts"]), "admitted configuration artifacts are incomplete")
    for spec in sample["artifacts"].values():
        _descriptor(spec)
    require(sample["definition"] == context["definition"] and sample["case"]["common"] == context["common"],
            "comparison context common parameters/definition mismatch")
    require(sample["comparison_key"] == digest(sample["case"]), "comparison workload digest mismatch")
    evidence = admission.get("evidence")
    require(isinstance(evidence, list) and bool(evidence), "comparison admission has no evidence")
    for spec in evidence:
        _descriptor(spec)
    if sample["configuration"]["id"] == "B":
        require(configuration_signature(sample["configuration"]) == context["baseline"]["configuration"] and
                sample["artifacts"] == context["baseline"]["artifacts"], "public baseline version changed")
    return context_id


def admit_sample(site, sample):
    """Load and freeze exact evidence while planning; never manufacture approval."""
    spec = site.get("comparison_context")
    if spec is None:
        return None
    _descriptor(spec, True)
    context = read_json(spec["path"])
    context_id = validate_context(context, check_files=True)
    require(context["common"] == sample["case"]["common"], "planned common parameters differ from context")
    spec = site.get("comparison_admissions", {}).get(sample["configuration"]["id"])
    _descriptor(spec, True)
    admission = read_json(spec["path"])
    for item in admission.get("evidence", []):
        _descriptor(item, True)
    for item in sample["artifacts"].values():
        _descriptor(item, True)
    proof = {"context":context, "context_id":context_id, "admission":admission, "admission_id":digest(admission)}
    validate_sample_comparison({**sample, "comparison":proof})
    return proof


def grouping(sample):
    if sample.get("comparison") is not None:
        return "admitted-context", sample["comparison_key"], validate_sample_comparison(sample)
    # Older or first-link records may only be compared within their exact full
    # identity. They never gain cross-campaign reuse by omission of evidence.
    return "exact-identity", sample["comparison_key"], sample["source_id"], sample["site_id"], sample.get("kit_id")
