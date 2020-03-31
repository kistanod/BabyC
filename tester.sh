#!/bin/bash

make all > /dev/null

for i in 1 2 3 4 5 6 7 8
do  
   ./bcc tests/test"$i".bc > output
   diff output tests/test"$i"_result.txt > test_result
   if [ -s test_result ]
   then
    echo "mismatch found in $i"
    cat test_result 
   else
    echo "no mismarch found in $i"
    fi
done

rm output
rm test_result
make clean > /dev/null