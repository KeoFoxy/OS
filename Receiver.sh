#!/bin/bash

variable=`./buff testPipe`

#echo $variable
tsc prints/app.ts
node prints/app.js $variable

#sleep 10
