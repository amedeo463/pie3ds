#include <stdio.h>
#include <stdlib.h>
#include <3ds.h>

int main(int argc, char* argv[])
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	printf("Pie3DS ver. 1.0\n");
	printf("Hold A to calculate\n");
	printf("\nPress START to quit.\n");
	long double current = 3.000000000000000L;
	long double toggle = 1.000000000000000L;
	long double count = 2.000000000000000L;

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		gfxSwapBuffers();
		hidScanInput();

		u32 kDown = hidKeysDown();
		u32 kHeld = hidKeysHeld();
		if (kDown & KEY_START) {
			break; // break in order to return to hbmenu
		} else if (kHeld & KEY_A) {
			current += toggle*(4.0000000L/(count*(count+1.0000000L)*(count+2.L)));
			printf("%Lf\n", current);

			toggle *= -1;
			count += 2;

		}
	}

	gfxExit();
	return 0;
}
