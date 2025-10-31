clear
if [ ! -d "$DIRECTORY" ]; then
    mkdir build
fi

cd ./build/
cmake ..
make

valgrind ./SRC/PACMAN