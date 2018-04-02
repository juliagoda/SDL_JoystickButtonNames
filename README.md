# SDL_JoystickButtonNames

1. [Description](#description)  
2. [Shoutout](#shoutout)  
3. [How it works](#how-it-works)  
4. [Running the examples](#running-the-examples)  
5. [Getting started](#getting-started)  
6. [Database](#database)   


# Description

[![Build Status](https://travis-ci.org/cxong/SDL_JoystickButtonNames.svg?branch=master)](https://travis-ci.org/cxong/SDL_JoystickButtonNames)

A small library to get joystick button names and colors, to be used with SDL2

SDL2's game controller API works by assuming an "ideal gamepad" - the Xbox 360 controller - and all button names will be translated to the same layout as that gamepad. That is, the bottom face button will always be called "A", and the right face button "B", even if you're not using the Xbox 360 controller.

What if you want to display button names that match the real controller's? What about the button colors too?

This library intends to provide this missing functionality, by providing a database of controller button names and colors, given an `SDL_Joystick` and an `SDL_GameControllerButton`.

The library looks up the controller's buttons using a combination of its GUID and its joystick name.

# Shoutout

Author "cxong":
[https://github.com/cxong/SDL_JoystickButtonNames](https://github.com/cxong/SDL_JoystickButtonNames)

# How it works

Given the following code:

    SDL_Joystick *joy;
    char name[256];
    Uint8 r, g, b;
    SDLJBN_GetButtonNameAndColor(joy, SDL_CONTROLLER_BUTTON_A, name, &r, &g, &b);
    printf("Button A is %s with color rgb(%d,%d,%d)\n", name, r, g, b);

If you have an Xbox 360 controller connected, this will print:

> Button A is A with color rgb(96,160,0)

But if you have a Logitech Dual Action

Then the code will print:

> Button A is 2 with color rgb(244,244,244)

# Running the examples

- Clone this repo
- Use CMake to configure and compile the examples:

      cd SDL_JoystickButtonNames/examples
      cmake .
      make
- Make sure you have joysticks plugged in, and run the example

      ./find_all_joy_buttons
- You should now have a file called `out.html`, which when you open up you'll see diagrams.
You should see some output too. For example for my gamepad:

```
Platform: Linux
Read 1 new mappings
Button: 2 [R: 244, G: 244, B 244], Button: 3 [R: 244, G: 244, B 244], Button: 1 [R: 244, G: 244, B 244], Button: 4 [R: 244, G: 244, B 244], Button: 9 [R: 64, G: 64, B 64], Button: Guide [R: 128, G: 176, B 0], Button: 10 [R: 64, G: 64, B 64], Button: Left Stick [R: 64, G: 64, B 64], Button: Right Stick [R: 64, G: 64, B 64], Button: 5 [R: 64, G: 64, B 64], Button: 6 [R: 64, G: 64, B 64], Button: D-pad Up [R: 64, G: 64, B 64], Button: D-pad Down [R: 64, G: 64, B 64], Button: D-pad Left [R: 64, G: 64, B 64], Button: D-pad Right [R: 64, G: 64, B 64], Axis: Left Stick X [R: 64, G: 64, B 64], Axis: Left Stick Y [R: 64, G: 64, B 64], Axis: Right Stick X [R: 64, G: 64, B 64], Axis: Right Stick Y [R: 64, G: 64, B 64], Axis: 7 [R: 64, G: 64, B 64], Axis: 8 [R: 64, G: 64, B 64],
```

In second example, when you run:
`./minimal`

You should see something like this:
```
Logitech Logitech Dual Action

BUTTONS

On joystick 1, button X is "X" with color rgb(0,96,208)
On joystick 1, button A is "A" with color rgb(96,160,0)
On joystick 1, button B is "B" with color rgb(240,0,0)
On joystick 1, button Y is "Y" with color rgb(255,160,0)
On joystick 1, button Back is "Back" with color rgb(224,224,224)
On joystick 1, button Start is "Start" with color rgb(224,224,224)
On joystick 1, left shoulder is "LB" with color rgb(224,224,224)
On joystick 1, left shoulder is "RB" with color rgb(224,224,224)
On joystick 1, left stick is "Left Stick" with color rgb(96,128,128)
On joystick 1, right stick is "Right Stick" with color rgb(96,128,128)
On joystick 1, button Up is "D-pad Up" with color rgb(96,128,128)
On joystick 1, button Down is "D-pad Down" with color rgb(96,128,128)
On joystick 1, button Left is "D-pad Left" with color rgb(96,128,128)
On joystick 1, button Right is "D-pad Right" with color rgb(96,128,128)


AXES

On joystick 1, left trigger is "LT" with color rgb(224,224,224)
On joystick 1, right trigger is "RT" with color rgb(224,224,224)
On joystick 1, axis X of left trigger is "Left Stick X" with color rgb(96,128,128)
On joystick 1, axis Y of left trigger is "Left Stick Y" with color rgb(96,128,128)
On joystick 1, axis X of right trigger is "Right Stick X" with color rgb(96,128,128)
On joystick 1, axis Y of right trigger is "Right Stick Y" with color rgb(96,128,128)

```

# Getting started

- Include the library in your SDL2 + CMake project, or if you are using a different build system, include `SDL_joystickbuttonnames.c` and `SDL_joystickbuttonnames.h` in your project
  - This includes `db.h`, which is generated from `db.h.cmake`
- In your code:
  - Call `SDLJBN_Init()` during startup
  - (Recommended) take a copy of `gamecontrollerbuttondb.txt` and include it in your game's data directory, and load it during runtime using `SDLJBN_AddMappingsFromFile()`. Remember to find line about your gamepad in `gamecontrollerdb.txt` and overwrite line under a name of your system in `gamecontrollerbuttondb.txt`. (This method will be changed to automatic method)
  - Once you have detected and opened `SDL_Joystick` devices, get button names and colors using `SDLJBN_GetButtonNameAndColor()`
  - You can also get axis names and colors using `SDLJBN_GetAxisNameAndColor()`
- Check out `examples/minimal.c` for a minimal code example


# Database

If you have a joystick that is not included in this project's database (`gamecontrollerbuttondb.txt`), please let me know. Include your OS, the joystick's SDL2 GUID, and a picture of the joystick, so it can be added to the database.
