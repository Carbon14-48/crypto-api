#! /usr/bin/bash
echo "fetching crypto market data ... "
./scripts/crypto-fetcher.sh
if [ $? -eq 0 ]; then 
    echo "crypto data fetched successfully!"
else
    echo "failed to fetch data"
    exit 1
fi

echo "compiling the c program..."
gcc ./c/main.c -o ./bin/crypto-program -ljansson
if [ $? -ne 0 ]; then
    echo "failed to compile the c program"
    exit 1
fi

echo "Running C program"
./bin/crypto-program

