/*
 * File: strncmp.c
 * Author: Arjan Gupta
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	if (n == 0)
		return n;

	size_t i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' ) 
		++i;

	return (s1[i] - s2[i]);
}

int main ()
{	
	/* USE CASES FOR strncmp_a():
	 * 1. n is 0.
	 * 2. str1 is larger than str2.
	 * 3. str2 is larger than str1.
	 * 4. str1 is the same size as str2.
	 *	4a. str1 is the same size as str2 but has no null-termination. 
	 */

	/* USE CASE 1 */
	char str1[] = "Okay!";
	char str2[] = "Use\0";
	printf("Use case 1 return value: %d\n", strncmp_a(str1, str2, 0));
	printf("Use case 1 return value: %d\n", strncmp(str1, str2, 0));

	printf("\n");

	/* USE CASE 2 */
	char str3[] = "Nice";
	char str4[] = "COOL";
	printf("Use case 2 return value: %d\n", strncmp_a(str3, str4, 4));
	printf("Use case 2 return value: %d\n", strncmp(str3, str4, 4));

	printf("\n");

	/* USE CASE 3 */
	char str5[] = "Hell";
	char str6[] = "Hello";
	printf("Use case 3 return value: %d\n", strncmp_a(str5, str6, 5));
	printf("Use case 3 return value: %d\n", strncmp_a(str5, str6, 5));

	printf("\n");

	/* USE CASE 4 */ 
	char str7[] = "ha";
	char str8[] = "ha";
	printf("Use case 4 return value: %d\n", strncmp_a(str7, str8, 4));
	printf("Use case 4 return value: %d\n", strncmp(str7, str8, 4));

	printf("\n");

	/* USE CASE 5 */
	char* str10 = (char *) malloc (1 * sizeof(char) );
	*str10 = 'a';
	char str11[] = "a";
	printf("Use case 5 return value: %d\n", strncmp_a(str10, str11, 5) );
	printf("Use case 5 return value: %d\n", strncmp(str10, str11, 5));

	printf("\n");

	/* TODO: account for case where there is no null termination */

	/* TODO: See GNU CC libs */

	/* TODO: find a truth-table method to account for all use cases in this program. */

	return 0;
}