# PARSEC reference checkpoint

This branch preserves the exact PARSEC development checkpoint as a verified
incremental Git bundle. The public upstream commit is an explicit prerequisite.
The bundle contains the 206 existing source/configuration/input changes and the
subsequent editor-cache housekeeping commit. No runtime data was deleted.

Restore in a fresh directory:

```sh
git clone https://github.com/bigwwwttt/Parsec.git /path/to/parsec-restored
git -C /path/to/parsec-restored bundle verify /path/to/this/parsec-development-incremental.bundle
git -C /path/to/parsec-restored fetch /path/to/this/parsec-development-incremental.bundle HEAD:refs/heads/checkpoint/parsec-reference-20261104
git -C /path/to/parsec-restored switch checkpoint/parsec-reference-20261104
```

The exact checkpoint and prerequisite object IDs are in CHECKPOINT.json.
