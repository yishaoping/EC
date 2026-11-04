#!/usr/bin/env python3
import sys
from ec_dac.cli import main
if __name__ == "__main__":
    try:
        sys.exit(main())
    except (ValueError, OSError, KeyError, TimeoutError) as e:
        import json
        print(json.dumps({"status":"BLOCKED_OR_FAILED","reason":str(e)},ensure_ascii=False),file=sys.stderr)
        sys.exit(2)
