#!/bin/sh

rm -rf tscf*
echo > tscf1
echo > tscf2
mkdir tscf3
echo > tscf4

for file in tscf*
do
	if [ -d "$file" ]; then
		break;
	fi
done

echo first directory starting fred was $file

rm -rf tscf*

exit 0

