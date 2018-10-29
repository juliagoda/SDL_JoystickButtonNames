#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_gamecontroller.h>

int SDLJBN_Init(void);
int SDLJBN_AddMappingsFromFile(const char* file);
int SDLJBN_GetButtonNameAndColor(SDL_Joystick* joystick, SDL_GameControllerButton button, char *s, Uint8* red, Uint8* green, Uint8* blue);
int SDLJBN_GetAxisNameAndColor(SDL_Joystick* joystick, SDL_GameControllerButton button, char *s, Uint8* red, Uint8* green, Uint8* blue);
void SDLJBN_Quit(void);

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_GAMECONTROLLER);
	SDLJBN_Init();

    SDL_GameControllerAddMappingsFromFile("../gamecontrollerdb.txt");
    SDLJBN_AddMappingsFromFile("../gamecontrollerbuttondb.txt");

	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		SDL_GameController *gc = SDL_GameControllerOpen(i);
		SDL_Joystick *j = SDL_GameControllerGetJoystick(gc);

		char buf[256];
		Uint8 r, g, b;

        printf(SDL_JoystickName(j));

        printf("\n\nBUTTONS\n\n");

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_X, buf, &r, &g, &b);
        printf("On joystick %d, button X is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

		SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_A, buf, &r, &g, &b);
        printf("On joystick %d, button A is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_B, buf, &r, &g, &b);
        printf("On joystick %d, button B is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_Y, buf, &r, &g, &b);
        printf("On joystick %d, button Y is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_BACK, buf, &r, &g, &b);
        printf("On joystick %d, button Back is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_START, buf, &r, &g, &b);
        printf("On joystick %d, button Start is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_LEFTSHOULDER, buf, &r, &g, &b);
        printf("On joystick %d, left shoulder is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, buf, &r, &g, &b);
        printf("On joystick %d, left shoulder is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_LEFTSTICK, buf, &r, &g, &b);
        printf("On joystick %d, left stick is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_RIGHTSTICK, buf, &r, &g, &b);
        printf("On joystick %d, right stick is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_DPAD_UP, buf, &r, &g, &b);
        printf("On joystick %d, button Up is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_DPAD_DOWN, buf, &r, &g, &b);
        printf("On joystick %d, button Down is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_DPAD_LEFT, buf, &r, &g, &b);
        printf("On joystick %d, button Left is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetButtonNameAndColor(j, SDL_CONTROLLER_BUTTON_DPAD_RIGHT, buf, &r, &g, &b);
        printf("On joystick %d, button Right is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        printf("\n\nAXES\n\n");

        SDLJBN_GetAxisNameAndColor(j, SDL_CONTROLLER_AXIS_TRIGGERLEFT, buf, &r, &g, &b);
        printf("On joystick %d, left trigger is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetAxisNameAndColor(j, SDL_CONTROLLER_AXIS_TRIGGERRIGHT, buf, &r, &g, &b);
        printf("On joystick %d, right trigger is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetAxisNameAndColor(j, SDL_CONTROLLER_AXIS_LEFTX, buf, &r, &g, &b);
        printf("On joystick %d, axis X of left trigger is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetAxisNameAndColor(j, SDL_CONTROLLER_AXIS_LEFTY, buf, &r, &g, &b);
        printf("On joystick %d, axis Y of left trigger is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetAxisNameAndColor(j, SDL_CONTROLLER_AXIS_RIGHTX, buf, &r, &g, &b);
        printf("On joystick %d, axis X of right trigger is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

        SDLJBN_GetAxisNameAndColor(j, SDL_CONTROLLER_AXIS_RIGHTY, buf, &r, &g, &b);
        printf("On joystick %d, axis Y of right trigger is \"%s\" with color rgb(%d,%d,%d)\n", i+1, buf, r, g, b);

		SDL_GameControllerClose(gc);
	}

	SDLJBN_Quit();
	SDL_Quit();
	return 0;
}
