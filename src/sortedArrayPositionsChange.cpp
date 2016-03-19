/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i = 0, j,a1[2],k=0,a;
	if (Arr == NULL || len < 0)
		return NULL;
	else{
		j = i + 1;
		while (j < len){
			if (*(Arr + i) > *(Arr + j)){
				a1[k] = i;
				k++;
				break;
			}
			j++;
			i++;
		}
		i = len - 1;
		j = i - 1;
		while (j > a1[0]){
			if (*(Arr + i) < *(Arr + j)){
				a1[k] = i;
				break;
			}
			j--;
			i--;
		}
		if (k != 0){
			a = *(Arr + a1[0]);
			*(Arr + a1[0]) = *(Arr + a1[1]);
			*(Arr + a1[1]) = a;
		}
	}

}