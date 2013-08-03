#!/bin/sh

echo "Is it morning? Please answer yes or no"
read timeofday

case "$timeofday" in
	yes	) echo "Good morning" ;;
	no	) echo "Good afternon" ;;
	y	) echo "Good morning" ;;
	n	) echo "Good afternon" ;;
	*	) echo "Sorry, answer not recognized" ;;
esac

exit 0
