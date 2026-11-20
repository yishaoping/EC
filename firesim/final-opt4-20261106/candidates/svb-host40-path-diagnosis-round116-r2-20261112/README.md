Run `python3 analyze.py` once to preserve independent copies of the completed
host40 probe and r2 A physical timing reports, parse fixed-column clock tables
and representative timing paths, and export the negative shell path/fanout CSV.
The runner checks the frozen policy, original probe report hash, stable reads,
completed A snapshot marker, all 66 unchanged clock periods, and global minima.
It refuses to overwrite evidence. It invokes no CAD or FPGA operation and does
not hash or modify any live DCP. Group endpoint counts are not additive, and a
physical-stage report is not a final routed timing pass or certificate.

Version r2 preserves failed r1; it parses the eight-column Other Path Groups table with its separate group/from/to labels.
