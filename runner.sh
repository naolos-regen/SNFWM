#!/bin/bash

make clean
time make debug 

DISPLAY_NUM=:2
XEPHYR_RES="1600x900"

killall Xephyr 2>/dev/null

Xephyr $DISPLAY_NUM -ac -screen $XEPHYR_RES -br &
XEPHYR_PID=$!

sleep 1

export DISPLAY=$DISPLAY_NUM

./bin/snfwm &

WM_PID=$!

sleep 1

alacritty &

read -p "press to exit"

kill $WM_PID
kill $XEPHYR_PID
