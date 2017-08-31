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
	return 0;
}