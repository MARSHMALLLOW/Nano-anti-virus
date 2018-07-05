#include <windows.h>


int GetTextSize(LPCSTR a0)
{
	for (int iLoopCounter = 0; ; iLoopCounter++)
	{
		if (a0[iLoopCounter] == '\0')
			return iLoopCounter;
	}
}
