#!/bin/bash
count=$1
rm -f input
rm -f your_output
rm -f standard_output

echo "================== input ======================"
for (( i=0; i<${count}; i++ ));
do
  echo $RANDOM
done | tee -a input

echo "============= execution result ================"
cat input | ./problem2 | tee your_output

sort -n input > standard_output

echo "====== differences from correct result ======="
diff your_output standard_output
