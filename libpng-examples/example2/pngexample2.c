#include "../libpng-1.6.32/png.h"
#include <stdint.h>
#include <stdio.h>

enum return_code
{
	FILE_OPEN_FAILED = -100,
	WRITE_STRUCT_ALLOC_FAILED, //-99
	INFO_STRUCT_ALLOC_FAILED, //-98
	PNG_CREATION_ERROR //-97
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

	//Initialize the write structure
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL)
	{
		return WRITE_STRUCT_ALLOC_FAILED;
	}

	//Initialize the info structure
	info_ptr = png_create_info_struct(png_ptr);
	if(info_ptr == NULL)
	{
		return INFO_STRUCT_ALLOC_FAILED;
	}

	//Set up exception handling
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		return PNG_CREATION_ERROR;
	}

	png_init_io(png_ptr, fp);

	//Write PNG header
	

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
