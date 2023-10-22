//Dino Jump Game developed using C
//Author - Anush Raghavender
//RollNumber - CED16I042
//Course - Operating Systems

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int true = 1;
int t, speed = 40;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//Initialize Game
void setupGame()
{
    system("cls");
    gotoxy(10, 2);
    printf("Press X to Exit, Press Space to Start and Jump");
    gotoxy(62, 2);
    printf("SCORE : ");
    gotoxy(1, 25);
    for (int x = 0; x < 79; x++)
        printf("o");
}

//Logic for dinosaur
void dinosaur(int* jump)
{
    static int a = 1;

    if (*jump == 0)
        t = 0;
    else if (*jump == 2)
        t--;
    else
        t++;

    gotoxy(2, 15 - t);
    printf("                 ");
    gotoxy(2, 16 - t);
    printf("         AAAAAAAA");
    gotoxy(2, 17 - t);
    printf("         AAAAAAAA");
    gotoxy(2, 18 - t);
    printf("         AAAAAAAA");
    gotoxy(2, 19 - t);
    printf(" A      AAAAAAAA ");
    gotoxy(2, 20 - t);
    printf(" AAA  AAAAAAAAAA ");
    gotoxy(2, 21 - t);
    printf(" AAAAAAAAAAA  A ");
    gotoxy(2, 22 - t);
    printf("   AAAAAAAA     ");
    gotoxy(2, 23 - t);

    if (*jump == 1 || *jump == 2)
    {
        printf("    AAA AA       ");
        gotoxy(2, 24 - t);
        printf("    AA   AA      ");
    }
    else if (a == 1)
    {
        printf("    AAAAA AAA    ");
        gotoxy(2, 24 - t);
        printf("      AA         ");
        a = 2;
    }
    else if (a == 2)
    {
        printf("     AAA AA      ");
        gotoxy(2, 24 - t);
        printf("          AA     ");
        a = 1;
    }
    gotoxy(2, 25 - t);
    if (*jump != 0)
    {
        printf("                ");
    }
    else
    {
        printf("ooooooooooooooooo");
    }
    delay(speed);
}

//Logic for obstacles
void obstacles(int *scr)
{
    static int x = 0;
    if (x == 56 && t < 4)
    {
        *scr = 0;
        speed = 40;
        gotoxy(36, 8);
        printf("Game Over");
        getch();
        gotoxy(36, 8);
        printf("         ");
    }

    gotoxy(74 - x, 20);
    printf("X    X ");
    gotoxy(74 - x, 21);
    printf("X    X ");
    gotoxy(74 - x, 22);
    printf("XXXXX ");
    gotoxy(74 - x, 23);
    printf("  X    ");
    gotoxy(74 - x, 24);
    printf("  X  ");
    x++;

    if (x == 73)
    {
        x = 0;
        (*scr)++;
        gotoxy(70, 2);
        printf("     ");
        gotoxy(70, 2);
        printf("%d", *scr);
        if (speed > 20)
            speed--;
    }
}

int main()
{
    system("mode con: lines=29 cols=82");
    char ch;
    int i, jump = 0;
    int p = 1;
    int q = 2;
    int scr = 0;

    HANDLE l;
    DWORD lthreadid;
    l = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)setupGame, NULL, 0, &lthreadid);
    WaitForSingleObject(l, INFINITE);

    while (true)
    {
        while (!_kbhit())
        {
            dinosaur(&jump);
            obstacles(&scr);
        }
        ch = _getch();
        if (ch == ' ')
        {
            for (i = 0; i < 10; i++)
            {
                dinosaur(&p);
                obstacles(&scr);
            }
            for (i = 0; i < 10; i++)
            {
                dinosaur(&q);
                obstacles(&scr);
            }
        }
        else if (ch == 'x')
            return (0);
    }
    return 0;
}
