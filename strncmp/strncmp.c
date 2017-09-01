/*
 * File: strncmp.c
 * Author: Arjan Gupta
 */

#include <stdio.h>

/* This function should work similarly to the library 
 * function `strncmp()`. We will call it strncmp_a in order
 * to avoid a library function redeclaration warning 
 * from the compiler.
 */
int strncmp_a (const char *s1, const char *s2, size_t n)
{
	/* Rules of return value:
	 * 1. If ret < 0, then s1 is smaller than s2.
	 * 2. If ret > 0, then s2 is smaller than s1.
	 * 3. If ret == 0, then s1 and s2 are the same size.
	 */
	int ret = 0;
	for (size_t i = 0; i < n; ++i)
	{
		if (s1[i] > s2[i])
		{
			++ret;
		} else if (s1[i] < s2[i]) {
			--ret;
		} else {
			//do not alter the value of ret.
		}
	}
	return ret;
}

int main ()
{	
	/* USE CASES FOR strncmp_a():
	 * 1. n is 0.
	 * 2. str1 is larger than str2.
	 * 3. str2 is larger than str1.
	 * 4. str1 is the same size as str2. 
	 */

	/* USE CASE 1 */
	char str1[5] = "Okay!";
	char str2[3] = "Use";
	printf("Use case 1 return value: %d\n", strncmp_a(str1, str2, 0));

	/* USE CASE 2 */
	char str3[4] = "Nice";
	char str4[4] = "COOL";
	printf("Use case 2 return value: %d\n", strncmp_a(str3, str4, 4));

	/* USE CASE 3 */
	char str5[4] = "Hell";
	char str6[5] = "Hello";
	printf("Use case 3 return value: %d\n", strncmp_a(str5, str6, 5)); /* wait, why does this happen? */

	/* USE CASE 4 */
	char str7[2] = "ha";
	char str8[2] = "ah";
	printf("Use case 4 return value: %d\n", strncmp_a(str7, str8, 2));

	return 0;
}