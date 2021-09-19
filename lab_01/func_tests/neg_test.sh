#!/bin/bash

fine=0
error_code=1

file=$1

../app.exe < "$file" >out.txt

rc=$?

num=${file:6:2}

file1=neg_${num}_out.txt

if [ ${rc} -ne 0 ]
then 
  echo -e "${file1} \e[32mPASSED\e[0m"
  exit ${fine}
fi

if [ ${rc} -eq 0 ]
then
  echo -e "${file1} \e[31mFAILED\e[0m"
  echo
  exit ${error_code}
fi