set shell := ['bash', '-ceuo', 'pipefail']

cmake_install_prefix := env_var_or_default("CONDA_PREFIX", "")
cmake_build_type := "Release"
cmake_build_dir := "build"

@default: build

@help:
    echo 'Usage: just [cmake_install_prefix=<PREFIX>] [cmake_build_dir=<DIR>] [cmake_build_type=<TYPE>]'
    echo 'Passes variables to CMake for the C++ build.'
    echo 'Defaults:'
    echo "  cmake_install_prefix=\$CONDA_PREFIX (currently: \"${CONDA_PREFIX:-<unset>}\")"
    echo "  cmake_build_type={{cmake_build_type}}"
    echo "  cmake_build_dir={{cmake_build_dir}} (relative to current directory)"
    echo 'Run "just --list" or "just --summary" to see available recipes (default: "build").'

@configure:
    cmake -GNinja -S . -B {{cmake_build_dir}} \
        -DCMAKE_BUILD_TYPE:STRING={{cmake_build_type}} \
        -DCMAKE_INSTALL_PREFIX:PATH={{cmake_install_prefix}} \
        -DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE \
        -DCMAKE_INSTALL_RPATH:PATH="{{cmake_install_prefix}}/lib"

@build: configure
    cmake --build {{cmake_build_dir}} --config {{cmake_build_type}}

@install: build
    cmake --install {{cmake_build_dir}} --config {{cmake_build_type}}