#!/bin/bash

variable=`./buff testPipe`

tsc prints/app.ts
node prints/app.js $variable

#sleep 10
