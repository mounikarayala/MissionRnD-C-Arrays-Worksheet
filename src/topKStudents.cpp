/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void sort(struct student *students, int len){
	struct student temp;
	int i = 0,j;
	for (i = 0; i < len - 1; i++){
		for (j = i + 1; j < len; j++){
			if (students[i].score < students[j].score){
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}
struct student ** topKStudents(struct student *students, int len, int K) {
	struct student **result;
	int i = 1, j;
	if (len <= 0 || K <= 0)
		return NULL;
	if (K == 1){
		int max = students[0].score, j;
		for (i = 1; i < len; i++){
			if (students[i].score > max){
				max = students[i].score;
				j = i;
			}
		}
		result = (struct student **)malloc(K*sizeof(struct student));
		result[0] = &students[j];
	}
	else{
		sort(students,len);
		result = (struct student **)malloc(len*sizeof(struct student));
		for (i = 0; i < K; i++){
			result[i] = &students[i];
		}
	}
	return result;
}