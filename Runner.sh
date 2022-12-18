#!/bin/bash

#if [[ $1 == "Keypad" ]] ##TODO Check for arguments
#./test -q testPipe #> testPipe & #rfid_data <-- Named Pipe

#./lastHope.sh

#./test -q testPipe


if [[ $1 == "Keypad" ]]
    then 
        sudo ./keypad_AS_SD -q testPipe
fi

if [[ $1 == "RFID" ]]
    then
        echo "Starting RFID" 
        ./RFID_AS_SD -q testPipe
        #./test -q testPipe
fi
#./printer.sh < testPipe

####################################

#executeResult=`./test -q testPipe`

#echo $executeResult
#echo $variable
#tsc prints/print.ts
#node prints/print.js $variable


##############################################

#runn=$(./buff testPipe)
#echo $runn
#variable=`./buff`
#./printer.sh