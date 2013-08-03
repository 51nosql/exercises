#!/bin/sh

[ -f /bin/bash ] && {
	echo "script 1"
	echo
	echo "end script 1"
	echo "call 2"
}

exit 0

