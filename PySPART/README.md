- Functions are C generated using the configuration in SPART/CSPART.proj from Matlab coder

- CODEGEN_VALIDATION_MATLAB.m compares all functions in matlab (matlab, casadi, and C versions)

- DEFINE_CODEGEN_VARIABLE_TYPES.m is an example call to all functions, that can be used when setting up the matlab coder to define variable types. Note that the coder is set up so that it works with any space robot model, without needing to recompile any C code. (this needs to be done manually in the matlab coder, by setting the manipulator joint dimensions (7 and 8) to inf)

- All generated C code is in SPART/codegen/dll/SPART_C