#include <stdio.h>
#include "FileHandle.h"
#include "Structs.h"
#include"Converter.h"
#include "convEndian.h"

int main()
{
	printf("Welcome to the PNG to ASCII converter!\n");

	struct IDAT* picture;

	picture = read_struct_png("SamplePicture.png");

	printf("IMAGE DATA: ");
	for (int i = 0; i < 550; i++)
	{
		printf("%d ", picture->imageDATA[i]);
	}
	printf("\n");

	/* DISPLAY IHDR DATA
	picture = read_struct_png("SamplePicture.png");

	printf("IHDR ID: ");
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", picture->chunkID[i]);
	}
	printf("\n");

	printf("Chunk Length: %d\n", change_Endian_32(picture->chunkLength));
	printf("Width: %d\n", change_Endian_32(picture->Width));
	printf("Height: %d\n", change_Endian_32(picture->Height));
	printf("Bit Depth: %d\n", picture->bitDepth);
	printf("Colour type: %d\n", picture->colorType);
	printf("Compression method: %d\n", picture->compressionMethod);
	printf("Filter method: %d\n", picture->filterMethod);
	printf("Interlace method: %d\n", picture->interlaceMathod);
	*/
	return 0;
}

