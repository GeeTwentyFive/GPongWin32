#include "GameWindow.h"




HWND InitializeGameWindow() {

    HINSTANCE hInstance = GetModuleHandle(NULL);




    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = GAME_WINDOW_CLASS_NAME;

    RegisterClass(&wc);

    


    // Obtain amount of pixels occupied by window styling and based on that offset the desired size to set the client area of the window to that specific desired size
    RECT wr = {0, 0, GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT};
    AdjustWindowRect(&wr, GAME_WINDOW_STYLE, FALSE);
    int wWidth = (wr.right - wr.left);
    int wHeight = (wr.bottom - wr.top);


    // Obtain coordinates for window to be centered on screen
    int screenX = GetSystemMetrics(SM_CXSCREEN);
    int screenY = GetSystemMetrics(SM_CYSCREEN);
    int wX = ((screenX / 2) - (wWidth / 2));
    int wY = ((screenY / 2) - (wHeight / 2));


    // Create the window
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        GAME_WINDOW_CLASS_NAME,         // Window class
        GAME_WINDOW_TITLE,              // Window text
        GAME_WINDOW_STYLE,              // Window style

        // Size and position
        wX, wY, wWidth, wHeight,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );


    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, SW_NORMAL);




    MSG msg = { 0 };


    while (true) {


        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {


            TranslateMessage(&msg);
            DispatchMessage(&msg);


            if (msg.message == WM_QUIT) {

                DeleteObject(redBrush);
                DeleteObject(blueBrush);

                break;

            }


        }


        else {

            Sleep(1000 / GAME_FRAMERATE);

            InvalidateRect(hwnd, NULL, TRUE);

        }

    }




    return 0;

}