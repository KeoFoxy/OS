#!/bin/bash

variable=`./buff testPipe`

#echo $variable
tsc prints/print.ts
node prints/print.js $variable

#sleep 10
