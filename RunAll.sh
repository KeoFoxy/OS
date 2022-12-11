#!/bin/bash

./Receiver.sh &
./Runner.sh 

sleep 4

#kill -9 $(pgrep 'Receiver.sh')
#kill $(ps aux | grep 'Receiver.sh' | awk '{print $2}')