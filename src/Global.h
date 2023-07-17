#pragma once


#include <Windows.h>

#ifndef UNICODE
#define UNICODE
#endif




#define GAME_FRAMERATE 60




#define COLOR_RED RGB(255, 0, 0)
#define COLOR_BLUE RGB(0, 0, 255)

extern HBRUSH redBrush;
extern HBRUSH blueBrush;
extern HBRUSH whiteBrush;
extern HBRUSH grayBrush;
extern HBRUSH blackBrush;




// Could have just used .rcPaint from PAINTSTRUCT but this works too since Window is scaled so that client/drawing area size matches these numbers
#define GAME_WINDOW_WIDTH 960
#define GAME_WINDOW_HEIGHT 720




#define PLAYFIELD_BORDER_THICKNESS 10




#define BALL_THICKNESS 10
#define BALL_SPEED 20

extern bool ballRestart;




#define RED_WIN true
#define BLUE_WIN false




extern bool lastWin;




#define PADDLE_HEIGHT 20
#define PADDLE_THICKNESS 5
#define PADDLE_BORDER_OFFSET 25
#define PADDLE_SPEED BALL_SPEED

extern RECT lPaddleRect;
extern RECT rPaddleRect;




extern int redScore;
extern int blueScore;