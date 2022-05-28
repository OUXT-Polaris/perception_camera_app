sudo apt update && sudo apt install libzmqpp-dev libprotobuf-dev protobuf-compiler
mkdir build
cd build
cmake ../
make -j4
