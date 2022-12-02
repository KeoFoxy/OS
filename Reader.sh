#!/bin/bash

declare +i password_input=""
declare pass="123"
while true
do
    if read line 
        then  
            if [[ $line != " " ]]
                then
                    sizeLine=`expr length "$line"`
                    if [[ $sizeLine == 1 ]]
                        then
                            if [[ $line != "*" ]]
                                then
                                password_input=$password_input$line;
                                echo $password_input;
                                date +"%D %T"
                            else
                                if [[ $password_input == $pass ]]
                                then
                                    echo "Access granted via Password"
                                    echo "Access granted via Password" $password_input $(date +"%D %T") > file
                                    date +"%D %T"
                                    break
                                else
                                    echo "Access denied via Password"
                                    echo "Access denied via Password" $password_input $(date +"%D %T") > file
                                    date +"%D %T"
                                    break
                                fi
                            fi
                        else
                            if [[ $line  == "91 2d 0c 26" ]]
                                then
                                    echo "Access granted via ID" $line $(date +"%D %T")
                                    echo "Access granted via ID" $line $(date +"%D %T") > file
                                    date +"%D %T"
                                    break
                            else
                                echo "Access denied via ID" $line $(date +"%D %T")
                                echo "Access denied via ID" $line $(date +"%D %T") > file
                                date +"%D %T"
                                break
                            fi
                    fi
            fi
    fi
done
