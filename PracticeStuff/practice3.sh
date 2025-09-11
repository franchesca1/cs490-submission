#!/bin/bash
#problem 1
#function count_occurences(){
#    word="$1" #takes in first argument
#    file="$2" #takes in second argument
#    count=`grep "$word" "$file" | wc -l`
#    echo "the word ${word} occurs ${count} times in file ${file}"
#}

#count_occurences "$1" "$2"


#problem 2

#grep '[\+-][0-9]+(\.[0-9]*)?' *.c

#problem 3

#sed '/echo/s/echo/replaced echo/' sample.txt #sed '/echo/s/echo/replaced echo/2-' sample.txt ?
#sed '/echo/d/' sample.txt #'/^$/d' this will delete all the blank lines
#sed  '5s/echo/print/' sample.txt 