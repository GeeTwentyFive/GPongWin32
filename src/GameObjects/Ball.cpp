#include "Ball.h"




float ballX = 0;
float ballY = 0;

bool ballRestart = true;

float ballMoveOffsetX = 0;
float ballMoveOffsetY = 0;

RECT ballRect = { 0 };


int redScore = 0;
int blueScore = 0;


void DrawBall(HDC hdc) {

	if (ballRestart) {


		ballX = (GAME_WINDOW_WIDTH / 2);
		ballY = (GAME_WINDOW_HEIGHT / 2);


		if (lastWin == RED_WIN) {

			ballMoveOffsetX = ((float)BALL_SPEED);
			ballMoveOffsetY = ((float)BALL_SPEED) * -1;

		}

		else if (lastWin == BLUE_WIN) {

			ballMoveOffsetX = ((float)BALL_SPEED) * -1;
			ballMoveOffsetY = ((float)BALL_SPEED);

		}


		ballRestart = false;

	}




	ballX += ballMoveOffsetX;
	ballY += ballMoveOffsetY;




	ballRect.left = ((int)ballX) - BALL_THICKNESS;
	ballRect.right = ((int)ballX) + BALL_THICKNESS;
	ballRect.top = ((int)ballY) - BALL_THICKNESS;
	ballRect.bottom = ((int)ballY) + BALL_THICKNESS;

	FillRect(hdc, &ballRect, whiteBrush);




	if ( (ballRect.left <= (PLAYFIELD_BORDER_THICKNESS + 1)) || (ballRect.right >= (GAME_WINDOW_WIDTH - PLAYFIELD_BORDER_THICKNESS - 1))) {


		if (ballRect.left <= (PLAYFIELD_BORDER_THICKNESS + 1)) {	// Blue scored!

			blueScore++;
			lastWin = BLUE_WIN;

		}


		else {														// Red scored!

			redScore++;
			lastWin = RED_WIN;

		}




		ballRestart = true;

	}




	if (ballRect.left <= (lPaddleRect.right + 1) && ballRect.top <= (lPaddleRect.bottom + 1) && ballRect.bottom >= (lPaddleRect.top - 1)) {

		ballMoveOffsetX = ballMoveOffsetX * -1;

	}

	else if (ballRect.right >= (rPaddleRect.right - 1) && ballRect.top <= (rPaddleRect.bottom + 1) && ballRect.bottom >= (rPaddleRect.top - 1)) {

		ballMoveOffsetX = ballMoveOffsetX * -1;

	}


	if ((ballRect.top <= (PLAYFIELD_BORDER_THICKNESS + 1)) || (ballRect.bottom >= (GAME_WINDOW_HEIGHT - PLAYFIELD_BORDER_THICKNESS - 1))) {

		ballMoveOffsetY = ballMoveOffsetY * -1;

	}

}