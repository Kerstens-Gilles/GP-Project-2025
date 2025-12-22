clear
if [ ! -d "$DIRECTORY" ]; then
    mkdir build
fi

cd ./build/
cmake ..
make

echo "Running"
./SRC/PACMAN
echo "Finnished"
