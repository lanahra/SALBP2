#!/bin/bash -ex

mkdir -p solutions

for dat in data/*.dat; do
    glpsol -m salbp2.mod -d $dat --tmlim 3600 > solutions/$(basename $dat .dat).sol
done
