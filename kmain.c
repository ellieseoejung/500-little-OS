#include "io.h"

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LGREY 7
#define DGREY 8
#define LBLUE 9
#define LGREEN 10
#define LCYAN 11
#define LRED 12
#define LMAGENTA 13
#define LBROWN 14
#define WHITE 15


    /** fb_write_cell:
     *  Writes a character with the given foreground and background to position i
     *  in the framebuffer.
     *
     *  @param i  The location in the framebuffer
     *  @param c  The character
     *  @param fg The foreground color
     *  @param bg The background color
     */
    void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
    {
		char *fb = (char *) 0x000B8000;
        fb[i] = c;
        fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
    }

    void fb_move_cursor(unsigned short position)
	{
        output(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
        output(FB_DATA_PORT,    ((position >> 8) & 0x00FF));
        output(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
        output(FB_DATA_PORT,    position & 0x00FF);
	}

/*
char *li = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque tellus diam, pellentesque vel tincidunt non, mattis sed ex. Nunc at magna tincidunt neque imperdiet vehicula vitae mollis leo. Aenean neque lectus, tincidunt sit amet massa ac, tempus cursus lorem. Etiam eu posuere nulla, at aliquam quam. Pellentesque sagittis, ante eget fermentum varius, augue nunc dapibus dui, vitae consequat est turpis cursus arcu. Phasellus sagittis nec leo ut elementum. Etiam et fringilla sapien, et egestas urna. Vestibulum bibendum dolor elit, et fermentum sapien maximus vitae. In non mollis lectus. Pellentesque laoreet dui nulla, et sollicitudin sem placerat eget. Fusce bibendum nunc dapibus massa maximus efficitur. Phasellus consectetur, nunc at ornare elementum, nisl ipsum commodo justo, ac vulputate nisi ante non libero. Morbi volutpat turpis eu libero dapibus vehicula. Phasellus at sodales mi, pharetra consectetur odio. Praesent lobortis, nisi sit amet maximus fermentum, justo risus mollis nisl, sit amet bibendum lacus dolor eu mauris.  Maecenas finibus non est accumsan convallis. Phasellus tincidunt sapien metus, quis posuere libero dictum sed. Cras viverra nisl purus, non vestibulum sem porttitor faucibus. Aenean pharetra ut neque sed pharetra. Morbi eget eros ac nunc vestibulum sodales. Duis sit amet lobortis urna. Phasellus interdum orci eu feugiat iaculis. Sed ut ante rhoncus, accumsan metus commodo, aliquet ligula. Sed eget commodo ligula.  Integer fermentum risus sit amet eros efficitur, eu molestie lectus consectetur. Vestibulum faucibus imperdiet elit ac facilisis. Nullam sit amet tortor risus. Nulla id maximus lectus. Integer nisl nunc, tristique ac mauris eget, iaculis fermentum eros. Aliquam in purus quis dui porttitor commodo. Ut molestie ac ex vitae posuere. Mauris ultricies magna nibh, nec aliquet elit suscipit sit amet. Nunc convallis, felis sit amet lobortis hendrerit, libero leo auctor nulla, ac dignissim elit risus eu purus. Nam posuere venenatis eros, ";
*/

//char *li = "Lorem";

void kmain()
{
	while (1)
	{
		for (int pos = 0;pos < 80*25;pos++)
		{
			fb_write_cell(pos*2,'*',WHITE,BLACK);
			fb_move_cursor(pos);
		}
	}
}
