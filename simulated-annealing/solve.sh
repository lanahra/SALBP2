#!/bin/bash -e

mkdir -p solutions

steps=200000

for seed in $(seq 0 9); do
    ./salbp2-sa instances/HAHN.IN2 3 $seed $steps > solutions/hahn3-$seed.sol
    ./salbp2-sa instances/HAHN.IN2 8 $seed $steps > solutions/hahn8-$seed.sol
    ./salbp2-sa instances/HAHN.IN2 10 $seed $steps > solutions/hahn10-$seed.sol
    ./salbp2-sa instances/LUTZ3.IN2 3 $seed $steps > solutions/lutz3-$seed.sol
    ./salbp2-sa instances/LUTZ3.IN2 20 $seed $steps > solutions/lutz20-$seed.sol
    ./salbp2-sa instances/LUTZ3.IN2 5 $seed $steps > solutions/lutz5-$seed.sol
    ./salbp2-sa instances/WEE-MAG.IN2 3 $seed $steps > solutions/weemag3-$seed.sol
    ./salbp2-sa instances/WEE-MAG.IN2 10 $seed $steps > solutions/weemag10-$seed.sol
    ./salbp2-sa instances/WEE-MAG.IN2 20 $seed $steps > solutions/weemag20-$seed.sol
    ./salbp2-sa instances/WEE-MAG.IN2 30 $seed $steps > solutions/weemag30-$seed.sol
done
