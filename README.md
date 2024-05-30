# cyrinx

Tool for finding typos in C/C++ source code

Based on [Clang](https://clang.llvm.org/) LibTooling API.

Searching for typos occurs using a dictionary. 
You can specify it explicitly using the `-d` option, or you can paste the `dict.txt` file next to the executable.

### Build

- Follow the instructions in the LLVM [GettingStarted](https://llvm.org/docs/GettingStarted.html) guide to clone the monorepo and build clang.
- Make a new directory `cyrinx` in the clang/tools directory for the tool.
- Modify the CMakeLists.txt to include the directory
    - `add_clang_subdirectory(cyrinx)`
- Change to the directory 
- Copy `include` and `lib` into that directory.
- Move to clang build directory and run `ninja cyrinx`

### Usage

Move to `bin` directory with executable `cyrinx` and run `./cyrinx hello.cpp -d dict.txt`