clear
if [ ! -d "$DIRECTORY" ]; then
    mkdir build
fi

cd ./build/
cmake ..
make

echo "Running"
#./SRC/PACMAN
valgrind -s --leak-check=full ./SRC/PACMAN
echo "Finnished"
