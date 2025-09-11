#FOR VIM
#:set number will number your lines of code
#/search
#%s/this/that
#FOR VIM

#!/bin/bash 
#shebang/ hashbang => tell the shell what interpreter to use.

#DataTypes: -Bash views all data as strings/text 
#           -if a string contains special characters like space, tab, or newline
#           -the string needs to be enclosed in quotes(single/double)
#           -else bash will split the string into multiple strings
#
#commandline-cat 'my file.txt' or cat "my file.txt"

#Variables: -Variables are also stored as strings
#           -Variable is created as soon as you assign a value to it
#           -To call a variable: -$var    -${var}=>delimit the variable value
#var="Hello World"   #correct
#echo $var
#echo ${var}

#echo $var2    #prints nothing because it looks for a variable called var2
#echo ${var}2  #prints Hello World2 because it substitutes Hello World and then adds 2 as a separate character

#var = "Hello World" #incorrect

#Single/double quotes: -Double quotes allow for variable resolution
#                      -single quotes do not allow for variable resoltuion
#                      -single quotes has no special meaning in bash(literal string)


#var="Hello World"

#echo "the variable stores $var"   #substitutes the value of var

#echo 'the variable stores $var'   #will print out the literal value '$var'

#Scope of the Variables: -all variables in bash are in global scope by default, even if the variables are inside the function
#                        -these variables can be accessed anywhere in the script regardless of its scope
#                        -in-accessible outside the script
#                        -in-accessible in any other script calling the variable
#                        -to share variable across script make the variable an env(use command export)

#Environment Variables: -these are the variables that are created by our system
#                       -the variables contian system specific information
#                       -to access evironment variables use command: env
#export x=10

#                       -few environment variables:
#                                -$? (exit status)
#                                -LOGNAME, $USER
#                                -$RANDOM
#                                -$SECONDS
#                                -$PS1 (prompt string)
#                                -\u -> username, \w ->working directory, \d -> date, etc

#Expansions: Few ways that you can operate on strings
#variable expansion -> operations on variables like getting length, slicing substring, etc
#    -${var}
#    -${#var}=>length of variable
#    -${var:position}=> extract substring from position
#    -${var:position:length}=> extracts substring from position of length
#command expansion -> stores the output of a command into a variable
#                  -Use `command` (back quotes) or $(command) 
#arithmetic expansion -> allows to perform arithmetic operations on text
#                     -Use $((expression))
#filename expansion -> bash scans each word for certain characters(like *, ?, [])
#                     -if these characters appear in a text, bash regards them as a pattern
#                     -it replaces all the file names matching the patterm
#                                 -*matches for any character, including null characters
#                                 -?matches any single character
#                                 -[]matches for any single character enclosed wihtin the []
#tilde expansion -> Replaces unquoted tilde - with the path of the home directory
#brace expression -> Expands over a sequence of characters or a list of commas separate
#                 - Use {}
#                 - Brace expansion will be the one performed before any other expansion
#                 - Variable expansion is in-eligible with brace expansion