#include <windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;

WINAPI void KillAndCorruptVirus (LPCSTR virus, FILE *virusFile) {
	fwrite(NULL, 5, 2, virusFile);
	remove(virus);
}
