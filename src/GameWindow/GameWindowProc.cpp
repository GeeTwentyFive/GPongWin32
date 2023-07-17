#include "GameWindowProc.h"




bool gameStarted = false;

#define START_GAME_TEXT_SIZE 20
const char* START_GAME_TEXT = "Press Enter to start the game!\0";
RECT startGameTextRect = { 0, (GAME_WINDOW_HEIGHT / 2) - START_GAME_TEXT_SIZE, GAME_WINDOW_WIDTH, (GAME_WINDOW_HEIGHT / 2) + START_GAME_TEXT_SIZE };


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    switch (uMsg)
    {


    case WM_DESTROY:    // WM_DESTROY message must be handled
    {
    
        PostQuitMessage(0);
        return 0;
    
    }




    case WM_PAINT:
    {

        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);


        DrawPlayfield(hdc, &ps);




        if (!gameStarted) {

            DrawTextA(hdc, START_GAME_TEXT, -1, &startGameTextRect, (DT_CENTER | DT_VCENTER));

            if (GetKeyState(VK_RETURN) & 0x8000) {
                gameStarted = true;
            }

        }


        else {

            DrawPaddles(hdc);


            DrawBall(hdc);


            DrawScoreText(hdc);

        }




        EndPaint(hwnd, &ps);


        return 0;

    }


    }


    return DefWindowProc(hwnd, uMsg, wParam, lParam);

}