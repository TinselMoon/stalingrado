#!/bin/bash

BIN="./build/stalingrado"

if [ ! -d "build" ] || [ ! -f "$BIN" ]; then
    rm -rf "build"
    mkdir build
    cd build || exit 1
    cmake .. && make -j$(nproc)
    cd ..
fi

cd build

if [ -x "stalingrado" ]; then
    ./stalingrado
else
    echo "Erro ao executar o jogo, tente novamente."
fi
