#!/bin/bash
cd cpp_runtime
mkdir -p release
cd release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
cd ../../
cd sample
mkdir -p release
cd release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
