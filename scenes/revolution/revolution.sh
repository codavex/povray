#!/bin/bash

options="r rd rld rldu"
images=`ls -1 *.png`

for opt in $options
do
	for input in $images
	do
		symmetry.py -i $input -o $opt/$input -$opt
	done
	cd $opt
	make_animation_24fps
	cd ..
done




