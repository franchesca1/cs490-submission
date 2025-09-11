# egrep 'a.+e' /f
# grep 'a.+e' /etc/passwd /etc/passwd-
# grep at searching/filtering a pattern from a file/ standard input
# grep expression on each line of a file
# echo "Hello World" | grep 'wor.d'
# options for grep:
#   -> -h: hides the file names Ex: grep -h 'a.*e' /etc/passwd /etc/passwd- >> file.txt
#   -> -n: precede each line with number Ex: grep -n 'a.*e' /etc/passwd
#   -> -l: lists only the file names that have matching patterns Ex: grep -l 'a.*e' /etc/passwd /etc/passwd-
#   -> -v: (negate) ignores the matching lines Ex: grep -v 'a.*e' /etc/passwd
#   -> -i: ignore case(case insensitive) Ex: grep -i 'A.*E' /etc/passwd 
#   -> -o: output only the matching substring from each line Ex: grep -o 'a.*e' /etc/passwd
#Note:regular expressions may have spaces in them and bash will divide into multiple strings
#     to avoid this happening, use quotes
#     regular expressions may also have special characters, and these special characters have different menaings in bash shell and in regex
#     like () in bash is array while in regex it's sub-expressions
#     to overcome, we use single quotes because single quotes have no special meaning in bash(literal string)
# sed -> stream editor
# sed excels at transforming or operating on a pattern
# searches for pattern from a file or standard input
# operated on each line for a file
# sed -> non-iterative editor
# all the editing commands come in the form of scripts
# syntax: sed script file/s
# scipt -> address and action
# address -> regex pattern or line number
# action -> the operation
# regex pattern -> needs to be enclosed with / example /
# sed -E -n '/a.*e, /mongo.{2}/p' /etc/passwd
# sed '/a.*e/d' /etc/passwd
# sed '1,10d' /etc/passwd
# sed '/e.*r/, /a.*e/d' /etc/passwd
# sed -n'/a.*e/=' /etc/passwd
# sed -n '$=' /etc/passwd
# sed '/u..x/s/unix/linux/' practice.txt
# sed '/unix/s/unix/linux/2' practice.txt
# sed '/u..x/s/unix/linux/g' practice.txt
# sed '/u..x/s/rocks/awesome/' practice.txt
# sed '0x[0-9a-f]/y/abcdef/ABCDEF/'
# sed '/u..x/!s/rocks/awesome/' practice.txt
# sed -n '/black/, $w/p' practice.txt
# practice.txt
# the black horse 
# the brown horse
# golden goose
# 