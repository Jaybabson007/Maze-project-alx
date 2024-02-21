#include "../inc/header.h"

extern texture_t wallTextures[NUM_TEXTURES];

static const char *textureFileNames[NUM_TEXTURES] = {
	"./images/redbrick.png",
	"./images/purplestone.png",
	"./images/mossystone.png",
	"./images/graystone.png",
	"./images/colorstone.png",
	"./images/bluestone.png",
	"./images/wood.png",
	"./images/eagle.png",
};

/**
 * WallTexturesready - load textures in the respective position
 *
*/
void WallTexturesready(void)
{
	int i;

	for (i = 0; i < NUM_TEXTURES; i++)
	{
		upng_t *upng;

		/*Creates a new UPNG structure and load the texture from file*/
		upng = upng_new_from_file(textureFileNames[i]);
		
		/*Decode the texture*/
		if (upng != NULL)
		{
			upng_decode(upng);

			/*Check for decoding errors*/
			if (upng_get_error(upng) == UPNG_EOK)
			{	/*Store information about the texture in the wallTextures array*/
				wallTextures[i].upngTexture = upng;
				wallTextures[i].width = upng_get_width(upng);
				wallTextures[i].height = upng_get_height(upng);
				wallTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
			}
		}
	}

}

/**
 * freeWallTextures - free wall textures
 *
*/

void freeWallTextures(void)
{
	int i;
	/*Iterate through wallTextures array and free each texture*/
	for (i = 0; i < NUM_TEXTURES; i++)
		upng_free(wallTextures[i].upngTexture);
}

