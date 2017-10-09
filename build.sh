#/bin/bash

mkdir build
cd build
conan install --build=missing  -s compiler.libcxx=libstdc++ ..
cmake ..
cmake --build . -- -j$(nproc --all)
