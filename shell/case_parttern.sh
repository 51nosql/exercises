#!/bin/sh

echo "Is it morning? Please anwser yes or no"
read timeofday

case "$timeofday" in
	yes | y | Yes | YES )
			echo "Good morning"
			echo "Up bright and early this morning"
			;;
	[nN]* )
			echo "Good Afternoon"
			;;
	* )
			echo "Sorry, answer not recognized"
			echo "Please answer yes or no"
			exit 1
			;;
esac

exit 0

