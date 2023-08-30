#pragma once
#define SIZE 30
#include <stdint.h>

struct PNG
{
	char fileName[SIZE];
	uint32_t pixelHeight;
	uint32_t pixelWidth;
};

struct IHDR
{
	uint32_t chunkLength;
	uint8_t chunkID[4];
	uint32_t Width;
	uint32_t Height;
	uint8_t bitDepth;
	uint8_t colorType;
	uint8_t compressionMethod;
	uint8_t filterMethod;
	uint8_t interlaceMathod;
	uint32_t CRC;
};

struct sRGB
{
	uint8_t chunkLength;
	uint8_t chunkID[4];
	uint8_t renderingIntent;
	uint32_t CRC;
};

struct gAMA
{
	uint32_t chunkLength;
	uint8_t chunkID[4];
	uint32_t imageGAMA; // GAMA * 100000
	uint32_t CRC;
};

struct pHYs
{
	uint32_t chunkLength;
	uint8_t chunkID[4];
	uint32_t PPUX;
	uint32_t PPUY;
	uint8_t UnitSpecifier; 
	uint32_t CRC;
};

struct IDAT
{
	uint32_t chunkLength;
	uint8_t chunkID[4];
	uint8_t imageDATA[550];
};