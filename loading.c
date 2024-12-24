#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <conio.h>  // For _kbhit() and _getch()

int main(int argc, char const *argv[])
{
    while (1)
    {
        printf("--");
        Sleep(300);
        if (_kbhit()) break;  // Check if a key has been pressed

        system("cls");
        
        printf("\\");
        Sleep(300);
        if (_kbhit()) break;

        system("cls");
        
        printf("|");
        Sleep(300);
        if (_kbhit()) break;

        system("cls");
        
        printf("/");
        Sleep(300);
        if (_kbhit()) break;

        system("cls");
    }

    return 0;
}