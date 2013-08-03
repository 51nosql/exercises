#!/bin/sh

echo "Is it morning? Please answer yes or no"
read timeofday

case "$timeofday" in
	y | yes | Y | YES )	echo "Good morning" ;;
	n* | N* )			echo "Good afternon" ;;
	* )					echo "Sorry, answer not recognized" ;;
esac

exit 0
