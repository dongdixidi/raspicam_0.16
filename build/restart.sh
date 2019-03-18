#!/bin/bash 
temp=$(ps -ef | grep raspicam_still_test | grep -v grep | cut -c 9-15)
sudo kill -9 $temp
make -j4
./utils/raspicam_still_test
