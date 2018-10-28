#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_gamecontroller.h>

int SDLJBN_Init(void);
const char * SDLJBN_GetError(void);
void SDLJBN_Quit(void);

// Detect all the currently connected joysticks and write a HTML page showing
// their names, buttons and button colors.
int main(int argc, char *argv[])
{
	FILE *f = NULL;

	// Init SDL
	if (SDL_Init(SDL_INIT_GAMECONTROLLER) != 0)
	{
		printf("SDL_Init error: %s\n", SDL_GetError());
		goto bail;
	}
	if (SDLJBN_Init() != 0)
	{
		printf("SDLJBN_Init error: %s\n", SDLJBN_GetError());
		goto bail;
	}

	printf("Platform: %s\n", SDL_GetPlatform());

	// Open output file
	f = fopen("guid.txt", "w");
	if (f == NULL)
	{
		perror("Failed to open output file");
		goto bail;
	}

	// Detect all current controllers
	const int numJoysticks = SDL_NumJoysticks();
	fprintf(f, "%d joystick(s) detected", numJoysticks);
	for (int i = 0; i < numJoysticks; i++)
	{
        fprintf(f, "Joystick %d: ", (i+1));
		if (!SDL_IsGameController(i))
		{
			fprintf(f, "Not a game controller");
			continue;
		}

		SDL_GameController *gc = SDL_GameControllerOpen(i);
		if (gc == NULL)
		{
			fprintf(f, "Error");
			printf("Cannot open game controller: %s\n", SDL_GetError());
			continue;
		}

		SDL_Joystick *j = SDL_GameControllerGetJoystick(gc);
		if (j == NULL)
		{
			fprintf(f, "Error");
			printf("Cannot get joystick: %s\n", SDL_GetError());
			SDL_GameControllerClose(gc);
			continue;
		}

		char buf[256];
		SDL_JoystickGetGUIDString(SDL_JoystickGetGUID(j), buf, 256);
		fprintf(f, "(Name: %s | GUID: %s):", SDL_JoystickName(j), buf);
        printf("(Name: %s | GUID: %s)\n", SDL_JoystickName(j), buf);

		SDL_GameControllerClose(gc);
	}
	
bail:
	fclose(f);
	SDLJBN_Quit();
	SDL_Quit();
	return 0;
}
