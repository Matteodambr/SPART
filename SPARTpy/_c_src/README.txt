# This directory is populated at build/install time by setup.py.
# It holds the MATLAB Coder-generated C sources (*.c, *.h) and the compiled
# shared library (SPART_C.so) for the SPARTpy C back-end.
#
# Contents are NOT committed to git (see .gitignore).  To regenerate:
#   python setup.py build_py          # during development
#   pip install .                     # during normal install
