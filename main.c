// My Robot Game - Learning Git and GitHub
#include <stdio.h>

void printTopBorder()
{
    printf("+---+---+---+---+---+\n");
}

void printMiddleBorder()
{
    printf("+---+---+---+---+---+\n");
}

void printBottomBorder()
{
    printf("+---+---+---+---+---+\n");
}

void printBoard(int A[6][5], int robotRow, int robotCol)
{
    printTopBorder();

    for(int i = 0; i < 6; i++)
    {
        printf("|");

        for(int j = 0; j < 5; j++)
        {
            if(i == robotRow && j == robotCol)
            {
                printf(" R |");
            }
            else if(A[i][j] == 10000)
            {
                printf(" F |");
            }
            else
            {
                printf(" . |");
            }
        }

        printf("\n");

        if(i == 5)
            printBottomBorder();
        else
            printMiddleBorder();
    }
}

int main()
{
    int A[6][5];

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            A[i][j] = 0;
        }
    }

    A[5][4] = 10000;
    A[0][2] = -50;
    A[2][0] = -50;
    A[2][2] = -50;
    A[1][4] = -50;
    A[4][1] = -50;
    A[5][2] = -50;

    int robotRow = 0;
    int robotCol = 0;

    printBoard(A, robotRow, robotCol);

    while(1)
    {
        int moved = 0;
        char n;

        printf("Enter U/D/L/R : ");
        scanf(" %c", &n);

        switch(n)
        {
            case 'U':
            case 'u':
                if(robotRow == 0)
                {
                    printf("Invalid Instructions\n");
                }
                else
                {
                    robotRow--;
                    moved = 1;
                }
                break;

            case 'D':
            case 'd':
                if(robotRow == 5)
                {
                    printf("Invalid Instructions\n");
                }
                else
                {
                    robotRow++;
                    moved = 1;
                }
                break;

            case 'L':
            case 'l':
                if(robotCol == 0)
                {
                    printf("Invalid Instructions\n");
                }
                else
                {
                    robotCol--;
                    moved = 1;
                }
                break;

            case 'R':
            case 'r':
                if(robotCol == 4)
                {
                    printf("Invalid Instructions\n");
                }
                else
                {
                    robotCol++;
                    moved = 1;
                }
                break;

            default:
                printf("Invalid Instruction\n");
        }

        if(moved)
        {
            printBoard(A, robotRow, robotCol);

            if(A[robotRow][robotCol] == -50)
            {
                printf("Game Over!\n");
                printf("You hit a bomb.\n");
                break;
            }
            else if(A[robotRow][robotCol] == 10000)
            {
                printf("Congratulations! You Win!\n");
                break;
            }
        }
    }

    return 0;
}