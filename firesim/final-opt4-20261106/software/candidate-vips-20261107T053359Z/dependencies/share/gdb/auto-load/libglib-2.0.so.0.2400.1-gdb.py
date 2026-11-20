import sys
import gdb

# Update module path.
dir = '/data1/gzh/EC/firesim/final-opt4-20261106/software/candidate-vips-20261107T053359Z/dependencies/share/glib-2.0/gdb'
if not dir in sys.path:
    sys.path.insert(0, dir)

from glib import register
register (gdb.current_objfile ())
