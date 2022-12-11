#!/bin/bash

#Run RF ID Reader // -q mode is broken

#./test -q testPipe #rfid_data <-- Named Pipe
#pipe=./testPipe

line=$1
line=$line$2

#while true
#do
    #if read line  
        #then
            if [[ $line != "" ]] 
                then
                    if [[ ${line:0:14} == "AccessGranted" ]] 
                        then
                            echo ${line:0:14}
                            tsc prints/print.ts
                            node prints/print.js -w
                            #break
                        else
                            echo $line
                            tsc prints/print.ts
                            node prints/print.js -e
                            #break
                    fi
            fi
    #fi
#done


