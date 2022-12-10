#!/bin/bash

if [[ $1 == "Keypad" ]] ##TODO Check for arguments
./test -q testPipe > testPipe & #rfid_data <-- Named Pipe

./printer.sh < testPipe