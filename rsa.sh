#!/usr/bin/env bash
# Factorize numbers into a product of two smaller numbers

while IFS= read -r LINE
do
	NUM=$LINE
	for ((DIV = 2; DIV * DIV <= NUM; DIV++))
	do
		while ((NUM % DIV == 0))
		do
			printf "%d=%d*%d\n" "$LINE" "$DIV" "$((NUM / DIV))"
			((NUM /= DIV))
		done
	done
	if ((NUM > 1)); then
		printf "%d=%d*%d\n" "$LINE" "$NUM" 1
	fi
done < "$1"
