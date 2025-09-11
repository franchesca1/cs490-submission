#!/bin/bash

#problem1
function myfunc(){
    num="$1"

    local result=1
    if [ "${num}" -lt 0 ]; then
        return
    fi

    i=1
    while [ $i -le $num]
    do
        result=$((result * i))
        i=$((i++))
    done

    echo $result
    return 0

}

factorial $1

#problem2
function bruh(){
    dir="$1"
    echo $dir

    if [ ! -d "$dir" ]; then
       return
    fi

    if [ `ls "$dir" \ wc -l` -eq 0 ]; then #checks if directory is 0 in case just print the function
       return
    fi

    entries=("${dir}"/*)

    for i in "${entries[@]}"
    do
        if [ -d "$i"]; then
            traversal "$i"
        fi
        if [ -f "$i" ] && [ ! -s "$i"]
            rm "$i"
        fi
    done
}

traversal "$1"





