#ifndef _WINMAIN_H
#define _WINMAIN_H

//C runtime Header Files
#ifndef _WINDOW_
	#include <Windows.h>
#endif

int t_main(int argc, char* argv[]);
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

#endif // _WINMAIN_H
