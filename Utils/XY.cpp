#include <windows.h>
#include <iostream>

using namespace std;

int main () {
	while(1)
	{
		POINT cursor;
		GetCursorPos(&cursor);
		int X = cursor.x;
		int Y = cursor.y;
		cout<<X<<" "<<Y<<endl;
	}
}
