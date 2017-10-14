#!/bin/bash

set -e
set -x

if [[ "$(uname -s)" == 'Darwin' ]]; then
    if which pyenv > /dev/null; then
        eval "$(pyenv init -)"
    fi
    pyenv activate conan
fi

export CXX=$CXX_COMPILER
export CC=$C_COMPILER

mkdir _build && cd _build
conan install --build=missing ..
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DCMAKE_C_COMPILER=$C_COMPILER -DCMAKE_CXX_COMPILER=$CXX_COMPILER ..
cmake --build . -- -j$(nproc --all)
