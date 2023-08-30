#include "FileHandle.h"
#include "convEndian.h"
struct IHDR* read_struct_png(char * filename)
{
	FILE* file;

	errno_t err = fopen_s(&file, filename, "rb");
	if (err) return NULL;

	struct IHDR* IHDRdata = malloc(sizeof(struct IHDR));
	if (IHDRdata == NULL) return NULL;

	struct sRGB* sRGBdata = malloc(sizeof(struct sRGB));
	if (sRGBdata == NULL) return NULL;

	struct gAMA* gAMAdata = malloc(sizeof(struct gAMA));
	if (gAMAdata == NULL) return NULL;

	struct pHYs* pHYsdata = malloc(sizeof(struct pHYs));
	if (pHYsdata == NULL) return NULL;

	struct IDAT* IDATdata = malloc(sizeof(struct IDAT));
	if (IDATdata == NULL) return NULL;

	uint8_t PNGSIG[8];
	fread(PNGSIG, sizeof(uint8_t), 8, file);
	printf("PNG Signature: ");
	for (int i = 0; i < 8; i++)
	{
		printf("%x ", PNGSIG[i]);
	}
	printf("\n");

	fread(IHDRdata, sizeof(struct IHDR), 1, file);
	fread(sRGBdata, sizeof(struct sRGB), 1, file);
	fread(gAMAdata, sizeof(struct gAMA), 1, file);
	fread(pHYsdata, sizeof(struct pHYs), 1, file);
	fread(IDATdata, sizeof(struct IDAT), 1, file);

	//uint32_t chunkSize;
	//fread(&chunkSize, sizeof(chunkSize), 1, file);
	//printf("Chunk Size: %d\n", change_Endian_32(chunkSize));

	/*
	* USED TO DISPLAY THE WHOLE BINARY CONTENT
	* 
	uint8_t test;
	while (!feof(file))
	{
		fread(&test, sizeof(test), 1, file);
		printf("%d ", test);
	}

	*/

	/*
	uint8_t NEXTBLOCK[3];
	uint8_t test;
	while (!feof(file))
	{
		fread(&test, sizeof(test), 1, file);

		if (test == 73)
		{
			fread(NEXTBLOCK, sizeof(NEXTBLOCK), 1, file);
			break;
		}
	}
	
	printf("WEWE Signature: \n 73 ");
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", NEXTBLOCK[i]);
	}
	printf("\n");
	*/

	fclose(file);
	return IDATdata;
}
