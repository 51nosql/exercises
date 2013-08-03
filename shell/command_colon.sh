#!/bin/sh

#冒号命令是一个空命令

rm -f tscf
if [ -f tscf ]; then
	:
else
	echo file tscf did not exist
fi

value="My Value"
var=$value
echo $var

value1="My Value1"
: ${var1:=value1}
echo $var1

exit 0
