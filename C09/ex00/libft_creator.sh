#!/bin/sh
C="-Wall -Wextra -Werror"
for file in *.c
do
	cc $C -c $file
done

ar rcs libft.a *.o
for file in *.o
do
	rm $file
done
