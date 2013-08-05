#!/bin/sh

x=10
x=`expr $x + 1`
y=$(expr $x + 1)

echo $x
echo $y

exit 0

