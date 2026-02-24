- Functions are C generated using the configuration in SPART/CSPART.proj from Matlab coder

- validate_C_functions.m compares all functions in matlab (matlab, casadi, and C versions)

- example_robot_import_matlabCheck.m is an example call to all functions, that can be used when setting up the matlab coder to define variable types. Note that the coder is set up so that it works with any space robot model, without needing to recompile any C code.