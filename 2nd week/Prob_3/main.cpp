#include<stdio.h>

int main()
{
	int kor = 3, eng = 5, mat = 4;                             // Initialize credits for Korean, English, and math
	double credits;                                            // Variables to store full credits
	int res;                                                   // Variable to store computation results
	double kscore = 3.8, escore = 4.4, mscore = 3.9;           // Initialize each subject's score
	double grade;                                              // Variables to store score averages

	credits = kor + eng + mat;                                 // Full credits calculation
	grade = (kscore * kor + escore * eng + mscore * mat) / credits;  // Calculating the score averages
	res = (credits >= 10) && (grade > 4.0);                    // Full credits >= 10 and score averages > 4/ true=1 or false=0
	printf("%d", res);
	return 0;
}