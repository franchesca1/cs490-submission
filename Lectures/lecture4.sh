#functions in Bash
#very powerful, treated as mini scripts

#function myfunc(){
#   echo $1 -first function parameter
#   echo $2 -second function parameter
#   var=999 -global scope
#   local var2=123
#   var123
#   return 100 -exit status
#}

#myfunc -calling function


#function myfunc(){
#    echo "Hello!"
#}

#var=`myfunc`
#echo $var



#echo $var

#echo $1 -shell parameter


#Traversing through a directory:
#Search algorithms:
#DFS (Depth First Search)
#BFS (Breadth First Search)


#DEPTH FIRST SEARCH
#function traversal(){
#   dir="$1"
#   echo $dir
#
#   if [ ! -d "$dir" ]; then
#       return
#   fi
#
#   if [ `ls "$dir" \ wc -l` -eq 0 ]; then #checks if directory is 0 in case just print the function
#       return
#   fi

#   entries=("${dir}"/*)

#   for i in "${entries[@]}"
#   do
#       traversal "$i"
#   done
#}   

#traversal "$1"



#BREADTH FIRST SEARCH

#queue=()
#queue[0]="$1"
#while [ -d "${#queue[@]}" -ne 0]
#do
#    echo "${queue[0]}"
#    if [ -d "${queue[@]}"] && [ `ls "${queue[0]}" | wc -l` -ne 0 ]; then
#        entries=("${queue[0]}"/*)
#        #merge both entries and queue
#        queue=("${queue[@]}" "${entries[@]}")
#
#    fi

    #remove the element at position 0
#    queue=("${queue[@]:1}")
#done
