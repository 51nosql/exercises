#!/bin/sh

unset foo
echo ${foo:-bar}
echo $foo
echo ${foo:=bar}
echo $foo
foo=fud
echo ${foo:-bar}

foo=/usr/local/php/bin/php
echo ${foo#*/}
echo ${foo##*/}
echo ${foo#*local}
echo ${foo##*h}

echo ${foo%php*}
echo ${foo%%php*}

exit 0

