#include<windows.h>
#include<stdio.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<string.h>
#include<math.h>
   
typedef WINAPI COLORREF (*GETPIXEL)(HDC, int, int);
using namespace std;

int main(int argc, char** argv)
{
int _Lred;
int _Lgreen;
int _Lblue;
int __Lred;
int __Lgreen;
int __Lblue;
int _Rred;
int _Rgreen;
int _Rblue;
int __Rred;
int __Rgreen;
int __Rblue;
int keyDownn=1;
POINT centerL;
POINT centerR;
centerL.x=639;
centerL.y=362;
centerR.x=641;
centerR.y=362;
COLORREF _Lcolor;
COLORREF _Rcolor;
	using namespace std;
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
   
    HINSTANCE _hGDI = LoadLibrary("gdi32.dll");
    if(_hGDI)
    {
	
        while(true) {
		
	if (GetKeyState('C') < 0) {
	keyDownn=keyDownn+1;
	//printf("%02x\n",keyDownn%2);
	printf("Gun primed, ready to shoot.\n");
	Sleep(200);
 GETPIXEL pGetPixel = (GETPIXEL)GetProcAddress(_hGDI, "GetPixel");
            HDC _hdc = GetDC(NULL);
            if(_hdc)
            {
                //POINT _cursor;
                //GetCursorPos(&_cursor);
		//POINT center;
		//centerL.x=956;
		//centerL.y=544;
                _Lcolor = (*pGetPixel) (_hdc, centerL.x,centerL.y);
                 _Lred = GetRValue(_Lcolor);
                 _Lgreen = GetGValue(_Lcolor);
                 _Lblue = GetBValue(_Lcolor);
		_Rcolor = (*pGetPixel) (_hdc, centerR.x,centerR.y);
                 _Rred = GetRValue(_Rcolor);
                 _Rgreen = GetGValue(_Rcolor);
                 _Rblue = GetBValue(_Rcolor);
}}
    // The C key is down.
	
	if(keyDownn%2==0){
		
            GETPIXEL pGetPixel = (GETPIXEL)GetProcAddress(_hGDI, "GetPixel");
            HDC _hdc = GetDC(NULL);
            if(_hdc)
            {
                //POINT _cursor;
		//POINT center;
		//centerL.x=0;
		//centerL.y=0;
                //GetCursorPos(&_cursor);
                _Lcolor = (*pGetPixel) (_hdc, centerL.x,centerL.y);
                __Lred = GetRValue(_Lcolor);
                __Lgreen = GetGValue(_Lcolor);
                __Lblue = GetBValue(_Lcolor);
		_Rcolor = (*pGetPixel) (_hdc, centerR.x,centerR.y);
                __Rred = GetRValue(_Rcolor);
                __Rgreen = GetGValue(_Rcolor);
                __Rblue = GetBValue(_Rcolor);
		//if(abs(_green - __green) > 10 && abs(_red-__red>10) && abs(_blue - __blue)>10){
		if(_Lgreen != __Lgreen && _Lred!=__Lred && _Lblue != __Lblue || _Rgreen != __Rgreen && _Rred!=__Rred && _Rblue != __Rblue){
		using namespace std;
    mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(1000);
	keyDownn=keyDownn+1;
	printf("Gun fired, we stopped.\n");
}}
            }
            FreeLibrary(_hGDI);
		
        }
    }
    return 0;
}
