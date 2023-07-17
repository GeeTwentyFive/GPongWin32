#include "Playfield.h"




void DrawPlayfield(HDC hdc, PAINTSTRUCT* ps) {

	FillRect(hdc, &ps->rcPaint, grayBrush);


	RECT playfieldRect = ps->rcPaint;
	playfieldRect.left += PLAYFIELD_BORDER_THICKNESS;
	playfieldRect.top += PLAYFIELD_BORDER_THICKNESS;
	playfieldRect.right -= PLAYFIELD_BORDER_THICKNESS;
	playfieldRect.bottom -= PLAYFIELD_BORDER_THICKNESS;

	FillRect(hdc, &playfieldRect, blackBrush);


	RECT redGoalRect = ps->rcPaint;
	redGoalRect.right = PLAYFIELD_BORDER_THICKNESS;
	redGoalRect.top += PLAYFIELD_BORDER_THICKNESS;
	redGoalRect.bottom -= PLAYFIELD_BORDER_THICKNESS;

	FillRect(hdc, &redGoalRect, redBrush);


	RECT blueGoalRect = ps->rcPaint;
	blueGoalRect.left = (blueGoalRect.right - PLAYFIELD_BORDER_THICKNESS);
	blueGoalRect.top += PLAYFIELD_BORDER_THICKNESS;
	blueGoalRect.bottom -= PLAYFIELD_BORDER_THICKNESS;

	FillRect(hdc, &blueGoalRect, blueBrush);


}