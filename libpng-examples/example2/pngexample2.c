#include "../libpng-1.6.32/png.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum rc
{
	FILE_OPEN_FAILED = -100,
	WRITE_STRUCT_ALLOC_FAILED, //-99
	INFO_STRUCT_ALLOC_FAILED, //-98
	PNG_CREATION_ERROR //-97
} return_code;

void static inline set_RGB(png_bytep row_ptr, float buff_val)
{
	const int threshold = 768;
	int32_t val = (int32_t) (buff_val * threshold);
	if (val < 0) val = 0;
	if (val > threshold) val = threshold;
	int32_t offset = val % 256;

	if (val < 256)
	{
		row_ptr[0] = 255; //red 
		row_ptr[1] = 0; //green
		row_ptr[2] = offset; //blue
	}
	else if (val < 512)
	{
		row_ptr[0] = 0; 
		row_ptr[1] = 255 - offset; 
		row_ptr[2] = offset;
	}
	else
	{
		row_ptr[0] = offset - 100;
		row_ptr[1] = 255 - offset;
		row_ptr[2] = 0;
	}
}

return_code static inline write_png(uint32_t rows, uint32_t cols, float *buff)
{
	//Declarations
	FILE *fp = NULL;
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_bytep row = NULL;
	return_code ret = 0;

	//Open write file
	fp = fopen("output.png", "wb");
	if (fp == NULL)
	{
		ret = FILE_OPEN_FAILED; //CHANGE ALL RETURNS TO SETTING RET
		goto conclude;
	}

	//Init write struct
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL)
	{
		ret = WRITE_STRUCT_ALLOC_FAILED;
		goto conclude;
	}

	//Init info struct
	info_ptr = png_create_info_struct(png_ptr);
	if(info_ptr == NULL)
	{
		ret = INFO_STRUCT_ALLOC_FAILED;
		goto conclude;
	}

	//Exception handling
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		ret = PNG_CREATION_ERROR;
		goto conclude;
	}

	png_init_io(png_ptr, fp);

	//PNG header
	png_set_IHDR(png_ptr, info_ptr, cols, rows, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
		PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	png_write_info(png_ptr, info_ptr);

	row = (png_bytep) malloc (3 * cols * sizeof(png_byte) );

	//Image data writing
	size_t w, h;
	for(h = 0; h < rows; ++h)
	{
		for(w = 0; w < cols; ++w)
		{
			set_RGB( &(row[w * 3]), (buff[(h * cols) + w]) );
		}
		png_write_row(png_ptr, row);
	}

	//Conclude writing the data
	png_write_end(png_ptr, NULL);

	conclude:
	if (fp != NULL) fclose(fp);
	if (info_ptr != NULL) png_free_data (png_ptr, info_ptr, PNG_FREE_ALL, -1);
	if (png_ptr != NULL)  png_destroy_write_struct (&png_ptr, (png_infopp)NULL);
	if (row != NULL) free(row);

	return ret;
}

int main()
{
	return_code ret = -1000;
	//Decide the dimensions of the image
	uint32_t height = 768; //rows
	uint32_t width = 1024; //columns
	float *buff = (float*) malloc (height * width * sizeof(float) );

	if (buff == NULL)
	{
		printf("buff is NULL. Exiting.\n");
		return 1;
	}

	//Set values in the buffer
	for(size_t i = 0; i < (height * width); ++i)
	{
		buff[i] = i;
		while (buff[i] > 1)
			buff[i] /= 10;
	}

	if( (ret =  write_png(height, width, buff)) == 0 )
	{
		printf("Example succeeded!\n");
	} else {
		printf("Example failed. ret = %d\n", ret);
	}

	free(buff);

	return 0;
}
