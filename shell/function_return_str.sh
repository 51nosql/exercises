#!/bin/sh

foo() {
	echo "Return Val"
}

result="$(foo)"
echo $result

exit 0

