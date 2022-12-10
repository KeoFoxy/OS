#!/bin/bash

#Run RF ID Reader // -q mode is broken
#./RFID_AS_SD #rfid_data <-- Named Pipe

while true
do
    if read line 
        then
            if [[ $line != " " ]] 
                then
                    if [[ ${line:0:14} == "Access Granted" ]] 
                        then
                            tsc prints/print.ts
                            node prints/print.js -w
                            break
                        else
                            tsc prints/print.ts
                            node prints/print.js -e
                            break
                    fi
            fi
    fi
done






#tsc prints/print.ts
#node prints/print.js -w
