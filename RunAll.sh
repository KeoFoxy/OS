#!/bin/bash

./Receiver.sh &

if [[ $1 == "Keypad" ]]
    then
        echo "Running $1"
        ./Runner.sh $1
fi

if [[ $1 == "RFID" ]]
    then
        echo "Running $1"
        ./Runner.sh $1
fi

sleep 4

#kill -9 $(pgrep 'Receiver.sh')
#kill $(ps aux | grep 'Receiver.sh' | awk '{print $2}')