#!/bin/sh

rm -rf tscf*
echo > tscf1
echo > tscf2
mkdir tscf3
echo > tscf4

for file in tscf*
do
	if [ -d "$file" ]; then
		echo "skipping directory $file"
		continue
	fi
	echo file is $file
done

rm -rf tscf*

exit 0

