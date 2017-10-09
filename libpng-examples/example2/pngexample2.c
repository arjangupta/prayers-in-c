//#include "../libpng-1.6.32/png.h"

#include <png.h>

#include <stdint.h>
#include <stdio.h>

enum return_code
{
	FILE_OPEN_FAILED = -100

};

int write_png(uint32_t rows, uint32_t cols, float *buffer)
{
	//declarations
	FILE *fp = NULL;
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_bytep row = NULL;

	//Open a file to be written to
	fp = fopen("output.png", "wb");
	if (fp == NULL)
	{
		return FILE_OPEN_FAILED;
	}

	//Initialize the png structure


	return 100; //still implementing
}

int main()
{
	int rc = -1000;
	float *buffer = NULL;
	if( (rc =  write_png(1, 1, buffer)) == 0 )
	{
		printf("Example succeeded!\n");
	} else {
		printf("Example failed. rc = %d\n", rc);
	}
	return 0;
}
