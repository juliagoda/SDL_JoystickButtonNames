#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <SDL2/SDL_gamecontroller.h>

int SDLJBN_Init(void);
int SDLJBN_AddMappingsFromFile(const char* file);
int SDLJBN_GetButtonName(SDL_Joystick* joystick, SDL_GameControllerButton button, char *s);
int SDLJBN_GetAxisName(SDL_Joystick* joystick, SDL_GameControllerAxis axis, char *s);
void SDLJBN_Quit(void);

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_GAMECONTROLLER);
	SDLJBN_Init();

    SDL_GameControllerAddMappingsFromFile("../gamecontrollerdb.txt");
    
	for (int i = 0; i < SDL_NumJoysticks(); i++)
	{
		SDL_GameController *gc = SDL_GameControllerOpen(i);
		SDL_Joystick *j = SDL_GameControllerGetJoystick(gc);

		char buf[256];

        printf(SDL_JoystickName(j));

        printf("\n\nBUTTONS\n\n");
        
        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_X, buf);
        printf("On joystick %d, button X is \"%s\"", i+1, buf);

		SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_A, buf);
        printf("On joystick %d, button A is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_B, buf);
        printf("On joystick %d, button B is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_Y, buf);
        printf("On joystick %d, button Y is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_BACK, buf);
        printf("On joystick %d, button Back is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_START, buf);
        printf("On joystick %d, button Start is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_LEFTSHOULDER, buf);
        printf("On joystick %d, left shoulder is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, buf);
        printf("On joystick %d, left shoulder is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_LEFTSTICK, buf);
        printf("On joystick %d, left stick is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_RIGHTSTICK, buf);
        printf("On joystick %d, right stick is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_DPAD_UP, buf);
        printf("On joystick %d, button Up is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_DPAD_DOWN, buf);
        printf("On joystick %d, button Down is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_DPAD_LEFT, buf);
        printf("On joystick %d, button Left is \"%s\" \n", i+1, buf);

        SDLJBN_GetButtonName(j, SDL_CONTROLLER_BUTTON_DPAD_RIGHT, buf);
        printf("On joystick %d, button Right is \"%s\" \n", i+1, buf);

        printf("\n\nAXES\n\n");

        SDLJBN_GetAxisName(j, SDL_CONTROLLER_AXIS_TRIGGERLEFT, buf);
        printf("On joystick %d, left trigger is \"%s\" \n", i+1, buf);

        SDLJBN_GetAxisName(j, SDL_CONTROLLER_AXIS_TRIGGERRIGHT, buf);
        printf("On joystick %d, right trigger is \"%s\" \n", i+1, buf);

        SDLJBN_GetAxisName(j, SDL_CONTROLLER_AXIS_LEFTX, buf);
        printf("On joystick %d, axis X of left trigger is \"%s\" \n", i+1, buf);

        SDLJBN_GetAxisName(j, SDL_CONTROLLER_AXIS_LEFTY, buf);
        printf("On joystick %d, axis Y of left trigger is \"%s\" \n", i+1, buf);

        SDLJBN_GetAxisName(j, SDL_CONTROLLER_AXIS_RIGHTX, buf);
        printf("On joystick %d, axis X of right trigger is \"%s\" \n", i+1, buf);

        SDLJBN_GetAxisName(j, SDL_CONTROLLER_AXIS_RIGHTY, buf);
        printf("On joystick %d, axis Y of right trigger is \"%s\" \n", i+1, buf);

		SDL_GameControllerClose(gc);
	}

	SDLJBN_Quit();
	SDL_Quit();
	return 0;
}
