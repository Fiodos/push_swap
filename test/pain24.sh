#!/bin/bash
NBR_COUNT=500
##
NBR="1 2"
RES=OK
i=0
result=0
size=100
until [ $i -gt $size ]
do
	NBR=$(seq 1 $NBR_COUNT | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev)
	cmd=$(../push_swap $NBR | wc -l)
	((result=result+cmd))
	#./push_swap $NBR | ./checker_Mac $NBR
	((i=i+1))
done

echo "average op count: $((result/$size))"
CMD=$( ../push_swap $NBR)
#echo "NBR [$NBR]"
#echo "Operations: $CMD"
