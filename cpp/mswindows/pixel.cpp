#include<windows.h>
#include<stdio.h>

typedef WINAPI COLORREF (*GETPIXEL)(HDC, int, int);

int main(int argc, char** argv)
{

    HINSTANCE _hGDI = LoadLibrary("gdi32.dll");
    if(_hGDI)
    {
        while(true) {
            GETPIXEL pGetPixel = (GETPIXEL)GetProcAddress(_hGDI, "GetPixel");
            HDC _hdc = GetDC(NULL);
            if(_hdc)
            {
                POINT _cursor;
                GetCursorPos(&_cursor);
                COLORREF _color = (*pGetPixel) (_hdc, _cursor.x, _cursor.y);
                int _red = GetRValue(_color);
                int _green = GetGValue(_color);
                int _blue = GetBValue(_color);

                printf("Red: 0x%02x\n", _red);
                printf("Green: 0x%02x\n", _green);
                printf("Blue: 0x%02x\n", _blue);
            }
            FreeLibrary(_hGDI);
        }
    }
    return 0;
}
