#/bin/bash

mkdir build
cd build
conan remote add piponazo https://api.bintray.com/conan/piponazo/piponazo
conan install --build=missing  -s compiler.libcxx=libstdc++ ..
cmake ..
cmake --build . -- -j$(nproc --all)
