#include "iGraphics.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <cstdio>
#include <cctype>
#pragma comment(lib, "Winmm.lib")

void drawHomePage();
void drawFirstPage();
void drawAboutPage();
void drawInstructionPage();
void drawInstruction2Page();
void drawLeaderBoardPage();
void drawEasyPage();
void drawMediocrePage();
void drawUltraProPage();
void drawCustomTypeTestPage();
void drawEasyPageTextBox();
void drawMediocrePageTextBox();
void drawUltraProPageTextBox();
void drawCustomTypeTestPageTextBox();
void drawCustomInputTextBox();
void drawGameOverPage();
void drawTimerDisplay();
void drawTimer();
void showNameChar();
void drawScoreInGameOverPage();

void FirstButtonClickHandler();
void AboutButtonClickHandler();
void InstructionButtonClickHandler();
void Instruction2ButtonClickHandler();
void LeaderBoardButtonClickHandler();
void EasyButtonClickHandler();
void BackButtonClickHandler();
void MediocreButtonClickHandler();
void UltraProButtonClickHandler();
void CustomTypeTestButtonClickHandler();
void ExitButtonClickHandler();
void SubmitButtonClickHandler();

int FirstButtonClick = 0;
int AboutButtonClick = 0;
int InstructionButtonClick = 0;
int Instruction2ButtonClick = 0;
int LeaderBoardButtonClick = 0;
int EasyButtonClick = 0;
int MediocreButtonClick = 0;
int UltraProButtonClick = 0;
int CustomTypeTestButtonclick = 0;
int ExitButtonClick = 0;
int SubmitButtonClick = 0;

int HomePage = 1;
int FirstPage = 0;
int AboutPage = 0;
int InstructionPage = 0;
int Instruction2Page = 0;
int LeaderBoardPage = 0;
int EasyPage = 0;
int MediocrePage = 0;
int UltraProPage = 0;
int CustomTypeTestPage = 0;
int GameOverPage = 0;

// For the Main Part...
char str[10000], str2[1000], str3[1000];
int len = 0;
int EasyMode;
int MediocreMode;
int UltraProMode;
int CustomTypeTestMode;
int CustomInputMode;

// For CustomTypeTest part...
char customstr1[1000], customstr2[1000], str4[1000];
int customLen = 0;

// For generating Gameover Page...
int TotalWords = 0;
int incorrectWords = 0;
int correctWords;
int score = 0;

// For taking name..
char name[100], name2[100];
int length = 0;
int mode2;

// For Time...
int second = 0;
char sec[100000];
int minute = 0;
int hour = 0;
char hr[10000];
int TotalSecond = 0;
char point[100000];

bool musicOn = true;

// GameOverPage Results...
char correctWordsStr[1000];
char incorrectWordsStr[1000];
char scoreStr[1000];
char WPMStr[1000];

// For WPM
float TimeTaken = 0;
float WPM = 0;

void updateTimer()
{
    TotalSecond = 0;
    TotalSecond = (second++) + (60 * minute) + (60 * 60 * hour);
}

// Function to update the display
void drawTimerDisplay()
{
    TimeTaken = 0;
    iSetColor(148, 148, 184);
    iFilledRectangle(790, 550, 200, 40);

    iSetColor(255, 0, 0);
    sprintf(sec, "%d", second / 100);

    TimeTaken = second / 100.0;
    iText(940, 560, sec, GLUT_BITMAP_TIMES_ROMAN_24);

    iText(800, 560, "Timer :", GLUT_BITMAP_TIMES_ROMAN_24);
}

void changeTimer()
{
    TotalSecond = 0;
    TotalSecond = (second++);

    drawTimerDisplay();
}

void compareEasyStrings(char *str, char *EasyTar)
{
    correctWords = 0;
    incorrectWords = 0;
    WPM = 0;
    // TimeTaken = 0;

    char prothom[800][1000], ditiyo[800][1000];
    int x = 0, y = 0;
    char *a, *b;

    // Create a duplicate of str using strdup
    char *strCopy = strdup(str);

    a = strtok(strCopy, " ");
    while (a != NULL)
    {
        strcpy(prothom[x++], a);
        a = strtok(NULL, " ");
    }

    // Free the memory allocated by strdup
    free(strCopy);

    b = strtok(EasyTar, " ");
    while (b != NULL)
    {
        strcpy(ditiyo[y++], b);
        b = strtok(NULL, " ");
    }

    int mi = (x < y) ? x : y;
    for (int i = 0; i < mi; i++)
    {
        if (!strcmp(prothom[i], ditiyo[i]))
            correctWords++;
        else
            incorrectWords++;
    }

    score = correctWords * 5 - incorrectWords * 2;
    WPM = (correctWords * 60.0) / TimeTaken;
}

void compareMediocreStrings(char *str, char *EasyTar)
{
    correctWords = 0;
    incorrectWords = 0;
    WPM = 0;
    // TimeTaken = 0;

    char prothom[80][100], ditiyo[80][100];
    int x = 0, y = 0;
    char *a, *b;

    // Create a duplicate of str using strdup
    char *strCopy = strdup(str);

    a = strtok(strCopy, " ");
    while (a != NULL)
    {
        strcpy(prothom[x++], a);
        a = strtok(NULL, " ");
    }

    // Free the memory allocated by strdup
    free(strCopy);

    b = strtok(EasyTar, " ");
    while (b != NULL)
    {
        strcpy(ditiyo[y++], b);
        b = strtok(NULL, " ");
    }

    int mi = (x < y) ? x : y;
    for (int i = 0; i < mi; i++)
    {
        if (!strcmp(prothom[i], ditiyo[i]))
            correctWords++;
        else
            incorrectWords++;
    }

    score = correctWords * 5 - incorrectWords * 2;
    WPM = (correctWords * 60.0) / TimeTaken;
}

void compareUltraProStrings(char *str, char *EasyTar)
{
    correctWords = 0;
    incorrectWords = 0;
    WPM = 0;
    // TimeTaken = 0;

    char prothom[80][100], ditiyo[80][100];
    int x = 0, y = 0;
    char *a, *b;

    // Create a duplicate of str using strdup
    char *strCopy = strdup(str);

    a = strtok(strCopy, " ");
    while (a != NULL)
    {
        strcpy(prothom[x++], a);
        a = strtok(NULL, " ");
    }

    // Free the memory allocated by strdup
    free(strCopy);

    b = strtok(EasyTar, " ");
    while (b != NULL)
    {
        strcpy(ditiyo[y++], b);
        b = strtok(NULL, " ");
    }

    int mi = (x < y) ? x : y;
    for (int i = 0; i < mi; i++)
    {
        if (!strcmp(prothom[i], ditiyo[i]))
            correctWords++;
        else
            incorrectWords++;
    }

    score = correctWords * 5 - incorrectWords * 2;
    WPM = (correctWords * 60.0) / TimeTaken;
}

void compareCustomTypeTestStrings(char *str, char *EasyTar)
{
    correctWords = 0;
    incorrectWords = 0;
    WPM = 0;
    // TimeTaken = 0;

    char prothom[800][1000], ditiyo[800][1000];
    int x = 0, y = 0;
    char *a, *b;

    // Create a duplicate of str using strdup
    char *strCopy = strdup(str);

    a = strtok(strCopy, " ");
    while (a != NULL)
    {
        strcpy(prothom[x++], a);
        a = strtok(NULL, " ");
    }

    // Free the memory allocated by strdup
    free(strCopy);

    b = strtok(EasyTar, " ");
    while (b != NULL)
    {
        strcpy(ditiyo[y++], b);
        b = strtok(NULL, " ");
    }

    int mi = (x < y) ? x : y;
    for (int i = 0; i < mi; i++)
    {
        if (!strcmp(prothom[i], ditiyo[i]))
            correctWords++;
        else
            incorrectWords++;
    }

    score = correctWords * 5 - incorrectWords * 2;
    WPM = (correctWords * 60.0) / TimeTaken;
}

void drawScoreInGameOverPage()
{
    iSetColor(135, 29, 228);

    sprintf(correctWordsStr, "%d", correctWords);
    sprintf(incorrectWordsStr, "%d", incorrectWords);
    sprintf(scoreStr, "%d", score);
    sprintf(WPMStr, "%.0f", WPM);

    iText(415, 465, "Correct  : ", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 465, correctWordsStr, GLUT_BITMAP_TIMES_ROMAN_24);

    iText(415, 435, "Incorrect: ", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 435, incorrectWordsStr, GLUT_BITMAP_TIMES_ROMAN_24);

    iText(415, 400, "Score     : ", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 400, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);

    iText(415, 330, "WPM    : ", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(550, 330, WPMStr, GLUT_BITMAP_TIMES_ROMAN_24);
}

void newHighScore();
void readScore();

bool newScore = true;

struct Hscore
{
    char Name[30];
    int Score = 0;
} High_score[5];

void newHighScore()
{
    FILE *fp;
    fp = fopen("ScoreHolder\\Score.txt", "r");

    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%d \n", &High_score[i].Score);
    }

    int t; // temporary score for s
    char n[30];
    if (newScore)
    {
        for (int i = 5; i >= 0; i--)
        {
            if (score > High_score[i].Score)
            {
                t = High_score[i].Score;
                High_score[i].Score = score;
                High_score[i + 1].Score = t;

                // Writting the sorted scores to the file
                FILE *fp;
                fp = fopen("ScoreHolder\\Score.txt", "w");

                for (int i = 0; i < 5; i++)
                {
                    fprintf(fp, "%d \n", High_score[i].Score);
                }
                fclose(fp);

                newScore = false; // reset new score
                break;            // exit the loop since sorting is done...
            }
        }
    }
}

void readScore()
{
    char showName[5][30], showScore[5][5];

    for (int i = 0; i < 5; i++)
    {
        sprintf(showName[i], "%s", High_score[i].Name);
        sprintf(showScore[i], "%d", High_score[i].Score);
        iSetColor(135, 29, 228);
        iText(415, 385 - 55 * i, showName[i], GLUT_BITMAP_TIMES_ROMAN_24);
        iText(600, 385 - 55 * i, showScore[i], GLUT_BITMAP_TIMES_ROMAN_24);
    }
}

void showNameChar()
{
    iSetColor(135, 29, 228);
    iText(410, 250, "Enter your name...", GLUT_BITMAP_HELVETICA_18);
    iRectangle(410, 195, 275, 40);
    iText(415, 205, name, GLUT_BITMAP_HELVETICA_18);

    iSetColor(135, 29, 228);
    iText(550, 180, "Click to activate the box..", GLUT_BITMAP_HELVETICA_12);
}

void iDraw()
{
    iClear();
    if (HomePage == 1)
    {
        drawHomePage();
    }
    else if (FirstPage == 1)
    {
        drawFirstPage();
    }
    else if (AboutPage == 1)
    {
        drawAboutPage();
    }
    else if (InstructionPage == 1)
    {
        drawInstructionPage();
    }
    else if (Instruction2Page == 1)
    {
        drawInstruction2Page();
    }
    else if (LeaderBoardPage == 1)
    {
        drawLeaderBoardPage();
    }
    else if (EasyPage == 1)
    {
        drawEasyPage();
        drawEasyPageTextBox();
    }
    else if (MediocrePage == 1)
    {
        drawMediocrePage();
        drawMediocrePageTextBox();
    }
    else if (UltraProPage == 1)
    {
        drawUltraProPage();
        drawUltraProPageTextBox();
    }
    else if (CustomTypeTestPage == 1)
    {
        drawCustomTypeTestPage();
        drawCustomTypeTestPageTextBox();
        drawCustomInputTextBox();
    }
    else if (GameOverPage == 1)
    {
        drawGameOverPage();
    }
    else if (mode2 == 1)
    {
        showNameChar();
    }
}

void iMouseMove(int mx, int my)
{
    printf("x = %d, y= %d\n", mx, my);
    printf("Correct Words: %d\n", correctWords);
    printf("Incorrect Words: %d\n", incorrectWords);
}

void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        printf("x = %d, y= %d\n", mx, my);
        if (HomePage == 1 && (mx >= 70 && mx <= 290) && (my >= 410 && my <= 460))
        {
            FirstButtonClickHandler();
        }
        else if (HomePage == 1 && (mx >= 70 && mx <= 290) && (my >= 200 && my <= 250))
        {
            AboutButtonClickHandler();
        }
        else if (HomePage == 1 && (mx >= 70 && mx <= 290) && (my >= 270 && my <= 320))
        {
            InstructionButtonClickHandler();
        }
        else if (InstructionPage == 1 && (mx >= 785 && mx <= 988) && (my >= 5 && my <= 55))
        {
            Instruction2ButtonClickHandler();
        }
        else if (HomePage == 1 && (mx >= 70 && mx <= 290) && (my >= 340 && my <= 390))
        {
            LeaderBoardButtonClickHandler();
        }
        else if (FirstPage == 1 && (mx >= 70 && mx <= 290) && (my >= 410 && my <= 460))
        {
            EasyButtonClickHandler();
        }
        else if (FirstPage == 1 && (mx >= 70 && mx <= 290) && (my >= 340 && my <= 390))
        {
            MediocreButtonClickHandler();
        }
        else if (FirstPage == 1 && (mx >= 70 && mx <= 290) && (my >= 270 && my <= 320))
        {
            UltraProButtonClickHandler();
        }
        else if (FirstPage == 1 && (mx >= 70 && mx <= 290) && (my >= 200 && my <= 320))
        {
            CustomTypeTestButtonClickHandler();
        }
        else if (FirstPage == 1 | LeaderBoardPage == 1 | EasyPage == 1 | MediocrePage == 1 | UltraProPage == 1 | CustomTypeTestPage == 1 | GameOverPage == 1 && (mx >= 20 && mx <= 70) && (my >= 530 && my <= 580))
        {
            BackButtonClickHandler();
        }
        else if (InstructionPage == 1 && (mx >= 20 && mx <= 125) && (my >= 540 && my <= 585))
        {
            BackButtonClickHandler();
        }
        else if (Instruction2Page == 1 && (mx >= 16 and mx <= 109) && (my >= 541 && my <= 585))
        {
            BackButtonClickHandler();
        }
        else if (AboutPage == 1 && (mx >= 27 && mx <= 109) && (my >= 540 && my <= 573))
        {
            BackButtonClickHandler();
        }
        else if (HomePage == 1 && (mx >= 70 && mx <= 290) && (my >= 130 && my <= 180))
        {
            ExitButtonClickHandler();
        }
        else if (EasyPage == 1 && (mx >= 102 && mx <= 900) && (my >= 142 && my <= 202) && EasyMode == 0)
        {
            EasyMode = 1;
        }
        else if (MediocrePage == 1 && (mx >= 102 && mx <= 900) && (my >= 142 && my <= 202) && MediocreMode == 0)
        {
            MediocreMode = 1;
        }
        else if (UltraProPage == 1 && (mx >= 102 && mx <= 900) && (my >= 142 && my <= 202) && UltraProMode == 0)
        {
            UltraProMode = 1;
        }
        else if (CustomTypeTestPage == 1 && (mx >= 102 && mx <= 900) && (my >= 142 && my <= 202) && CustomTypeTestMode == 0)
        {
            CustomTypeTestMode = 1;
        }
        else if (CustomTypeTestPage == 1 && (mx >= 50 && mx <= 950) && (my >= 262 && my <= 520) && CustomInputMode == 0)
        {
            CustomInputMode = 1;
        }
        else if (EasyPage == 1 | MediocrePage == 1 | UltraProPage == 1 | CustomTypeTestPage == 1 && (mx >= 820 && mx <= 980) && (my >= 25 && my <= 80))
        {
            SubmitButtonClickHandler();
            EasyPage = 0;
            MediocrePage = 0;
            UltraProPage = 0;
            CustomTypeTestPage = 0;
            second = 0;
        }
        else if (GameOverPage == 1 && (mx >= 410 && mx <= 685 && my >= 195 && my <= 235) && mode2 == 0)
        {
            mode2 = 1;
        }
    }

    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
    }
}

/*
    function iKeyboard() is called whenever the user hits a key on the keyboard.
    key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    // For main work....
    // For EasyPage...
    int i;
    if (EasyMode == 1)
    {
        if (key == '\r')
        {
            EasyMode = 0;
            GameOverPage = 1;
            SubmitButtonClickHandler();
            strcpy(str2, str);
            printf("%s\n", str2);

            // loop to reset input string...
            for (i = 0; i < len; i++)
            {
                str[i] = 0;
            }

            // resetting the length...
            len = 0;
        }

        else if (key == '\b')
        {
            if (len <= 0)
            {
                len = 0;
            }
            else
            {
                len--;
            }
            str[len] = '\0';
        }

        else
        {
            str[len] = key;
            len++;
        }
    }

    // For MediocrePage...
    int a;
    if (MediocreMode == 1)
    {
        if (key == '\r')
        {
            MediocreMode = 0;
            SubmitButtonClickHandler();

            strcpy(str2, str);
            printf("%s\n", str2);

            // loop to reset input string...
            for (a = 0; a < len; a++)
            {
                str[a] = 0;
            }

            // resetting the length...
            len = 0;
        }

        else if (key == '\b')
        {
            if (len <= 0)
            {
                len = 0;
            }
            else
            {
                len--;
            }
            str[len] = '\0';
        }

        else
        {
            str[len] = key;
            len++;
        }
    }

    // For UltraProPage...
    int b;
    if (UltraProMode == 1)
    {
        if (key == '\r')
        {
            UltraProMode = 0;
            SubmitButtonClickHandler();

            strcpy(str2, str);
            printf("%s\n", str2);

            // loop to reset input string...
            for (b = 0; b < len; b++)
            {
                str[b] = 0;
            }

            // resetting the length...
            len = 0;
        }

        else if (key == '\b')
        {
            if (len <= 0)
            {
                len = 0;
            }
            else
            {
                len--;
            }
            str[len] = '\0';
        }

        else
        {
            str[len] = key;
            len++;
        }
    }

    // For CustomInput...
    int d;
    if (CustomInputMode == 1)
    {
        if (key == '\r')
        {
            CustomTypeTestMode = 0;

            strcpy(customstr2, customstr1);
            printf("%s\n", customstr2);

            // loop to reset input string...
            for (d = 0; d < len; d++)
            {
                str[d] = 0;
            }

            // resetting the length...
            len = 0;
        }

        else if (key == '\b')
        {
            if (len <= 0)
            {
                len = 0;
            }
            else
            {
                len--;
            }
            customstr1[len] = '\0';
        }

        else
        {
            customstr1[len] = key;
            len++;
        }
    }

    // For CustomPage...
    int c;
    if (CustomTypeTestMode == 1)
    {
        if (key == '\r')
        {
            CustomTypeTestMode = 0;
            SubmitButtonClickHandler();

            strcpy(str2, str);
            printf("%s\n", str2);

            // loop to reset input string...
            for (c = 0; c < len; c++)
            {
                str[c] = 0;
            }

            // resetting the length...
            len = 0;
        }

        else if (key == '\b')
        {
            if (len <= 0)
            {
                len = 0;
            }
            else
            {
                len--;
            }
            str[len] = '\0';
        }

        else
        {
            str[len] = key;
            len++;
        }
    }

    // For taking name input...
    int j;
    if (mode2 == 1)
    {
        if (key == '\r')
        {
            mode2 = 0;
            strcpy(name2, name);
            printf("%s\n", name2);
            for (j = 0; j < length; j++)
                name[j] = 0;
            length = 0;

            HomePage = 1;
            newHighScore();
        }
        else if (key == '\b')
        {
            if (length <= 0)
            {
                length = 0;
            }
            else
            {
                length--;
            }
            name[length] = '\0';
        }
        else
        {
            name[length] = key;
            length++;
        }
    }
}

/*
    function iSpecialKeyboard() is called whenever user hits special keys like-
    function keys, home, end, pg up, pg down, arrows, etc. you have to use
    appropriate constants to detect them. A list is:
    GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
    */

void iSpecialKeyboard(unsigned char key)
{
    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    if (key == GLUT_KEY_F2)
    {
        if (musicOn)
        {
            musicOn = false;
            PlaySound(0, 0, 0);
        }
        else if (!musicOn)
        {
            musicOn = true;
            PlaySound("music\\BackgroundMusic.wav", NULL, SND_LOOP | SND_ASYNC);
        }
    }
}

void drawHomePage()
{
    iSetColor(128, 128, 128);
    iFilledRectangle(0, 0, 1000, 600);
    iShowBMP2(0, 0, "Images\\Background.bmp", 0);

    iShowBMP2(70, 410, "Images\\button.bmp", 0);
    iShowBMP2(70, 340, "Images\\button.bmp", 0);
    iShowBMP2(70, 270, "Images\\button.bmp", 0);
    iShowBMP2(70, 200, "Images\\button.bmp", 0);
    iShowBMP2(70, 130, "Images\\button.bmp", 0);

    iSetColor(255, 255, 255);
    iText(100, 430, "Start Typing...", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100, 360, "LeaderBoard", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100, 290, "How to play?", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100, 220, "About Game...", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100, 150, "Exit!!", GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawFirstPage()
{
    iFilledRectangle(0, 0, 1000, 600);
    iShowBMP2(0, 0, "Images\\Background.bmp", 0);

    iShowBMP2(70, 410, "Images\\button.bmp", 0);
    iShowBMP2(70, 340, "Images\\button.bmp", 0);
    iShowBMP2(70, 270, "Images\\button.bmp", 0);
    iShowBMP2(70, 200, "Images\\button.bmp", 0);
    iShowBMP2(20, 530, "Images\\BackButton.bmp", 0);

    iSetColor(255, 255, 255);
    iText(100, 430, "Beginner...", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100, 360, "Mediocre...", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100, 290, "UltraPro...", GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100, 220, "Custom Type...", GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawAboutPage()
{
    iFilledRectangle(0, 0, 1000, 600);
    iClear();
    iShowBMP2(0, 0, "Images\\AboutPage.bmp", 0);
}

void drawInstructionPage()
{
    iFilledRectangle(0, 0, 1000, 600);
    iClear();
    iShowBMP2(0, 0, "Images\\Instruction1.bmp", 0);
}

void drawInstruction2Page()
{
    iFilledRectangle(0, 0, 1000, 600);
    iClear();
    iShowBMP2(0, 0, "Images\\Instruction2.bmp", 0);
}

void drawLeaderBoardPage()
{
    iFilledRectangle(0, 0, 1000, 600);
    iShowBMP2(0, 0, "Images\\LeaderBoard.bmp", 0);
    iShowBMP2(20, 530, "Images\\BackButton.bmp", 0);

    readScore();
    iText(80, 75, "Don't be obsessed with others score. Be happy with your own progress...", GLUT_BITMAP_TIMES_ROMAN_24);
}

void circularCopy(char *source, char *destination, int max_length)
{
    int source_length = strlen(source);
    int destination_length = strlen(destination);

    if (source_length <= max_length)
    {
        strcpy(destination, source);
    }
    else
    {
        int offset = (source_length - max_length) % source_length;
        strncpy(destination, source + offset, max_length);
        destination[max_length] = '\0'; // Null-terminate the destination string
    }
}

void drawEasyPage()
{
    iFilledRectangle(0, 0, 1000, 600);
    iClear();
    iShowBMP2(0, 0, "Images\\EasyPageDisplay.bmp", 0);
    iShowBMP2(20, 530, "Images\\BackButton.bmp", 0);

    // Move the changeTimer call here
    changeTimer();

    drawEasyPageTextBox();
    circularCopy(str, str3, 75);

    if (EasyMode == 1)
    {
        iSetColor(0, 0, 0);
        iText(120, 165, str3, GLUT_BITMAP_TIMES_ROMAN_24);
    }

    iText(10, 10, "Click to activate the box, Submit to finish.", GLUT_BITMAP_TIMES_ROMAN_24);

    char EasyTarget[] = "The quick brown fox jumps over a lazy dog while playing a xylophone and juggling colorful quokkas";
    compareEasyStrings(str, EasyTarget);
}

void drawMediocrePage()
{
    iFilledRectangle(0, 0, 1000, 600);
    iClear();
    iShowBMP2(0, 0, "Images\\MediocrePage.bmp", 0);
    iShowBMP2(20, 530, "Images\\BackButton.bmp", 0);

    // Move the changeTimer call here
    changeTimer();

    drawMediocrePageTextBox();
    circularCopy(str, str3, 75);

    if (MediocreMode == 1)
    {
        iSetColor(0, 0, 0);
        iText(120, 165, str3, GLUT_BITMAP_TIMES_ROMAN_24);
    }

    iText(10, 10, "Click to activate the box, enter to finish.", GLUT_BITMAP_TIMES_ROMAN_24);

    char MediocreTarget[] = "In the bustling metropolis, where luminous skyscrapers pierce the night sky, a cacophony of car horns and distant chatter creates an urban symphony, echoing through the vibrant streets adorned with neon signs and eclectic storefronts, each telling its own story in the tapestry of city life.";
    compareMediocreStrings(str, MediocreTarget);
}

void drawUltraProPage()
{
    iFilledRectangle(0, 0, 1000, 600);
    iClear();
    iShowBMP2(0, 0, "Images\\UltraProPage.bmp", 0);
    iShowBMP2(20, 530, "Images\\BackButton.bmp", 0);

    // Move the changeTimer call here
    changeTimer();

    drawUltraProPageTextBox();
    circularCopy(str, str3, 75);

    if (UltraProMode == 1)
    {
        iSetColor(0, 0, 0);
        iText(120, 165, str3, GLUT_BITMAP_TIMES_ROMAN_24);
    }

    iText(10, 10, "Click to activate the box, Submit to finish.", GLUT_BITMAP_TIMES_ROMAN_24);

    char UltraProTarget[] = "Ed Nott was shot and Sam Shott was not. So it is better to be Shott than Nott. Some say Nott was not shot. But Shott says he shot Nott. Either the shot Shott shot at Nott was not shot, or Nott was shot.";
    compareUltraProStrings(str, UltraProTarget);
}

void drawCustomTypeTestPage()
{
    iFilledRectangle(0, 0, 1000, 600);
    iClear();
    iShowBMP2(0, 0, "Images\\CustomPage.bmp", 0);
    iShowBMP2(20, 530, "Images\\BackButton.bmp", 0);

    drawCustomTypeTestPageTextBox();
    drawCustomInputTextBox();

    circularCopy(customstr1, str4, 75);

    if (CustomInputMode == 1)
    {
        iSetColor(0, 0, 0);
        iText(120, 465, str4, GLUT_BITMAP_TIMES_ROMAN_24);
    }

    if (CustomTypeTestMode == 1)
    {
        iSetColor(0, 0, 0);
        iText(120, 165, str3, GLUT_BITMAP_TIMES_ROMAN_24);
    }

    iText(10, 10, "Click to activate the box, Submit to finish.", GLUT_BITMAP_TIMES_ROMAN_24);

    compareCustomTypeTestStrings(str, customstr1);
}

void drawEasyPageTextBox()
{
    iSetColor(135, 29, 228);
    iRectangle(102, 142, 798, 60);
}

void drawMediocrePageTextBox()
{
    iSetColor(135, 29, 228);
    iRectangle(102, 142, 798, 60);
}

void drawUltraProPageTextBox()
{
    iSetColor(135, 29, 228);
    iRectangle(102, 142, 798, 60);
}

void drawCustomTypeTestPageTextBox()
{
    iSetColor(135, 29, 228);
    iRectangle(50, 262, 900, 257);
}

void drawCustomInputTextBox()
{
    iSetColor(135, 29, 228);
    iRectangle(102, 142, 798, 60);
}

void drawGameOverPage()
{
    iFilledRectangle(0, 0, 1000, 600);
    iClear();
    iShowBMP2(0, 0, "Images\\GameOver.bmp", 0);
    iShowBMP2(20, 530, "Images\\BackButton.bmp", 0);

    showNameChar();
    drawScoreInGameOverPage();
}

void FirstButtonClickHandler()
{
    HomePage = 0;
    FirstPage = 1;
}

void AboutButtonClickHandler()
{
    HomePage = 0;
    FirstPage = 0;
    AboutPage = 1;
}

void InstructionButtonClickHandler()
{
    HomePage = 0;
    FirstPage = 0;
    AboutPage = 0;
    InstructionPage = 1;
}

void Instruction2ButtonClickHandler()
{
    HomePage = 0;
    FirstPage = 0;
    AboutPage = 0;
    InstructionPage = 0;
    Instruction2Page = 1;
}
void LeaderBoardButtonClickHandler()
{
    HomePage = 0;
    FirstPage = 0;
    AboutPage = 0;
    InstructionPage = 0;
    Instruction2Page = 0;
    LeaderBoardPage = 1;
}

void EasyButtonClickHandler()
{
    HomePage = 0;
    FirstPage = 0;
    AboutPage = 0;
    InstructionPage = 0;
    Instruction2Page = 0;
    LeaderBoardPage = 0;
    EasyPage = 1;
}

void MediocreButtonClickHandler()
{
    HomePage = 0;
    FirstPage = 0;
    AboutPage = 0;
    InstructionPage = 0;
    Instruction2Page = 0;
    LeaderBoardPage = 0;
    EasyPage = 0;
    MediocrePage = 1;
    CustomTypeTestPage = 0;
}

void UltraProButtonClickHandler()
{
    HomePage = 0;
    FirstPage = 0;
    AboutPage = 0;
    InstructionPage = 0;
    Instruction2Page = 0;
    LeaderBoardPage = 0;
    EasyPage = 0;
    MediocrePage = 0;
    UltraProPage = 1;
    CustomTypeTestPage = 0;
}

void CustomTypeTestButtonClickHandler()
{
    HomePage = 0;
    FirstPage = 0;
    AboutPage = 0;
    InstructionPage = 0;
    Instruction2Page = 0;
    LeaderBoardPage = 0;
    EasyPage = 0;
    MediocrePage = 0;
    UltraProPage = 0;
    CustomTypeTestPage = 1;
}

void BackButtonClickHandler()
{
    HomePage = 1;
    FirstPage = 0;
    AboutPage = 0;
    InstructionPage = 0;
    Instruction2Page = 0;
    LeaderBoardPage = 0;
    EasyPage = 0;
    MediocrePage = 0;
    UltraProPage = 0;
    CustomTypeTestPage = 0;
}

void ExitButtonClickHandler()
{
    exit(0);
}

void timerHandler()
{
    updateTimer();
    drawTimerDisplay();
}

void SubmitButtonClickHandler()
{
    HomePage = 0;
    FirstPage = 0;
    AboutPage = 0;
    InstructionPage = 0;
    Instruction2Page = 0;
    LeaderBoardPage = 0;
    EasyPage = 0;
    MediocrePage = 0;
    UltraProPage = 0;
    CustomTypeTestPage = 0;
    GameOverPage = 1;
}
 
int main()
{
    FILE *fp;
    fp = fopen("ScoreHolder\\Score.txt", "r");

    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %d \n", High_score[i].Name, &High_score[i].Score);
    }
    fclose(fp);

    if (musicOn)
    {
        PlaySound("music\\BackgroundMusic.wav", NULL, SND_LOOP | SND_ASYNC);
    }

    len = 0;
    EasyMode = 0;
    MediocreMode = 0;
    UltraProMode = 0;
    str[0] = '\0';
    str3[0] = '\0';
    str4[0] = '\0';

    length = 0;
    mode2 = 0;
    name[0] = 0;

    iSetTimer(1000, timerHandler);

    iInitialize(1000, 600, "Typing Master...");
    return 0;
}
