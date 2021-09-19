#!/bin/bash

fine=0
error_code=1
error_in_solve=2

file=$1

../app.exe <"$file" >out.txt

rc=$?

if [ ${rc} -ne 0 ]
then 
  echo -en "(rc == ${rc})"
  exit ${error_code}
fi

num=${file:4:2}

file1=pos_${num}_out.txt
file2=out.txt

python ./comparator.py "$file1" "$file2"
check=$?

if [ $check -eq 0 ]
then
  echo -e "${file1} \e[32mPASSED\e[0m"
  rm out.txt
  exit ${fine}
else
  echo -e "${file1} \e[31mFAILED\e[0m"
  echo
  exit ${error_in_solve}
fi