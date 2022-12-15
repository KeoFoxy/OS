#!/bin/bash

#if [[ $1 == "Keypad" ]] ##TODO Check for arguments
#./test -q testPipe #> testPipe & #rfid_data <-- Named Pipe

#./lastHope.sh

#./test -q testPipe


if [[ $1 == "Keypad" ]]
    then 
        ./KeyPad/keypad_AS_SD -q testPipe
fi

if [[ $1 == "RFID" ]]
    then
        ./RF-ID-Reader/RFID_AS_SD testPipe
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