#! /usr/bin/bash

echo "Hello ! welcome to your Crypto-market viewer"
sleep 3
echo "Crypto is the Future !"
curl -s "https://api.coingecko.com/api/v3/coins/markets?vs_currency=usd&ids=bitcoin,ethereum,ripple,cardano,solana&order=market_cap_desc&per_page=5&page=1&sparkline=false" > ./data/crypto.json
echo "crypto data is saved successfully "
