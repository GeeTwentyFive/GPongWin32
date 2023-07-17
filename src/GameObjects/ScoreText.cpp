#include "ScoreText.h"




#define SCORE_TEXT_SIZE 20

RECT blueScoreRect = { GAME_WINDOW_WIDTH - PLAYFIELD_BORDER_THICKNESS - (SCORE_TEXT_SIZE * 2), PLAYFIELD_BORDER_THICKNESS + SCORE_TEXT_SIZE, GAME_WINDOW_WIDTH - PLAYFIELD_BORDER_THICKNESS - SCORE_TEXT_SIZE, PLAYFIELD_BORDER_THICKNESS + (SCORE_TEXT_SIZE * 2) };
RECT redScoreRect = { PLAYFIELD_BORDER_THICKNESS + SCORE_TEXT_SIZE, PLAYFIELD_BORDER_THICKNESS + SCORE_TEXT_SIZE, PLAYFIELD_BORDER_THICKNESS + (SCORE_TEXT_SIZE * 2), PLAYFIELD_BORDER_THICKNESS + (SCORE_TEXT_SIZE * 2) };


void DrawScoreText(HDC hdc) {

	char blueScoreText[8] = "";
	_itoa_s(blueScore, blueScoreText, 10);
	
	char redScoreText[8] = "";
	_itoa_s(redScore, redScoreText, 10);




	DrawTextA(hdc, blueScoreText, -1, &blueScoreRect, (DT_CENTER | DT_VCENTER));

	DrawTextA(hdc, redScoreText, -1, &redScoreRect, (DT_CENTER | DT_VCENTER));

}