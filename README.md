# cyrinx

Tool for finding typos in C/C++ source code

Based on [Clang](https://clang.llvm.org/) LibTooling API.

### Build

- Follow the instructions in the LLVM [GettingStarted](https://llvm.org/docs/GettingStarted.html) guide to clone the monorepo and build clang.
- Make a new directory `cyrinx` in the clang/tools directory for the tool.
- Modify the CMakeLists.txt to include the directory
    - `add_clang_subdirectory(cyrinx)`
- Change to the directory 
- Copy the contents of `lib` into that directory.
- Move to clang build directory and run `ninja cyrinx`
