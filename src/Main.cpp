#include "Global.h"
#include "GameWindow/GameWindow.h"




bool lastWin = NULL;

HBRUSH redBrush;
HBRUSH blueBrush;

HBRUSH whiteBrush = (HBRUSH)(0);
HBRUSH grayBrush = (HBRUSH)(1);
HBRUSH blackBrush = (HBRUSH)(2);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {

	redBrush = CreateSolidBrush(COLOR_RED);
	blueBrush = CreateSolidBrush(COLOR_BLUE);


	InitializeGameWindow();

	return 0;

}