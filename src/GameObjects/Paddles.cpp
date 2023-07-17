#include "Paddles.h"




RECT lPaddleRect = { PLAYFIELD_BORDER_THICKNESS + PADDLE_BORDER_OFFSET - PADDLE_THICKNESS, 0, PLAYFIELD_BORDER_THICKNESS + PADDLE_BORDER_OFFSET + (PADDLE_THICKNESS * 2), 0 };
RECT rPaddleRect = { GAME_WINDOW_WIDTH - PLAYFIELD_BORDER_THICKNESS - PADDLE_BORDER_OFFSET - (PADDLE_THICKNESS * 2), 0, GAME_WINDOW_WIDTH - PLAYFIELD_BORDER_THICKNESS - PADDLE_BORDER_OFFSET + PADDLE_THICKNESS, 0 };

int vMid = (GAME_WINDOW_HEIGHT / 2);

int lPaddleY = vMid;
int rPaddleY = vMid;




void DrawLeftPaddle(HDC hdc);
void DrawRightPaddle(HDC hdc);


void DrawPaddles(HDC hdc) {

	DrawLeftPaddle(hdc);
	DrawRightPaddle(hdc);

}




void DrawLeftPaddle(HDC hdc) {

	if (ballRestart) {

		lPaddleY = vMid;

	}


	if ((GetKeyState(0x53) & 0x8000) && (lPaddleY < GAME_WINDOW_HEIGHT - (PADDLE_HEIGHT * 2) - PLAYFIELD_BORDER_THICKNESS)) {			// S

		if (GetKeyState(0xA0) & 0x8000) {	// Left Shift
			lPaddleY += (PADDLE_SPEED / 2);
		}

		else {
			lPaddleY += PADDLE_SPEED;
		}

	}

	else if ((GetKeyState(0x57) & 0x8000) && (lPaddleY > (PADDLE_HEIGHT * 2) + PLAYFIELD_BORDER_THICKNESS)) {		// W

		if (GetKeyState(0xA0) & 0x8000) {	// Left Shift
			lPaddleY -= (PADDLE_SPEED / 2);
		}

		else {
			lPaddleY -= PADDLE_SPEED;
		}

	}


	lPaddleRect.top = lPaddleY - PADDLE_HEIGHT;
	lPaddleRect.bottom = lPaddleY + PADDLE_HEIGHT;

	FillRect(hdc, &lPaddleRect, whiteBrush);

}




void DrawRightPaddle(HDC hdc) {

	if (ballRestart) {

		rPaddleY = vMid;

	}


	if ((GetKeyState(VK_UP) & 0x8000) && (rPaddleY > (PADDLE_HEIGHT * 2) + PLAYFIELD_BORDER_THICKNESS)) {

		if (GetKeyState(0xA1) & 0x8000) {	// Right Shift
			rPaddleY -= (PADDLE_SPEED / 2);
		}

		else {
			rPaddleY -= PADDLE_SPEED;
		}

	}

	else if ((GetKeyState(VK_DOWN) & 0x8000) && (rPaddleY < GAME_WINDOW_HEIGHT - (PADDLE_HEIGHT * 2) - PLAYFIELD_BORDER_THICKNESS)) {

		if (GetKeyState(0xA1) & 0x8000) {	// Right Shift
			rPaddleY += (PADDLE_SPEED / 2);
		}

		else {
			rPaddleY += PADDLE_SPEED;
		}

	}


	rPaddleRect.top = rPaddleY - PADDLE_HEIGHT;
	rPaddleRect.bottom = rPaddleY + PADDLE_HEIGHT;

	FillRect(hdc, &rPaddleRect, whiteBrush);

}