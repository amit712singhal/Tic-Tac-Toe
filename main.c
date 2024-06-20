#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*--------------------------------------- Tic-Tac-Toe Game -----------------------------------*/

const int N = 3;

int playerMove(int matrix[N][N], int player);
int draw(int a[N][N]);
int check_diagonals(int array[N][N], int player);
int check_columns(int array[N][N], int player);
int check_rows(int array[N][N], int player);
int win(int a[N][N], int player);
int set(int a[N][N], int m, int n, int player);
void display(int a[N][N]);

/*----------------------------------------- Driver_Code --------------------------------------*/

int main()
{
    int game, matrix[3][3] = {0};
    char choice;
    printf("\n\n---------------- Welcome to Compiler Gamings -------------------\n\n");

tictactoe:
    while (1)
    {  
        if (playerMove(matrix, 1) || playerMove(matrix, 2))
        {
            goto end;
        }
    }

end:
    printf("\nWant to Play Again? (y/n) :: ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = 0;
            }
        }
        goto tictactoe;
    }
    printf("\n");
    goto exit;

exit:
    return 0;
}

/*------------------------------------ Tic-Tac-Toe Game functions ----------------------------*/

// function to create a 2-D matrix to store tic-tac-toe

int draw(int a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

// function to display tic-tac-toe in each turn

void display(int a[N][N])
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("    ");
    for (int j = 0; j < N; j++)
    {
        printf(" %d ", j);
    }
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        printf("  +");
        for (int j = 0; j < N; j++)
        {
            printf("---+");
        }
        printf("\n");

        printf("%d |", i);
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] == 0)
            {
                printf("   |");
            }
            else if (a[i][j] == 1)
            {
                printf(" X |");
            }
            else
            {
                printf(" O |");
            }
        }
        printf("\n");
    }

    printf("  +");
    for (int j = 0; j < N; j++)
    {
        printf("---+");
    }
    printf("\n");
}

// function to check win in each row

int check_rows(int array[N][N], int player)
{
    for (int i = 0; i < N; i++)
    {
        if (array[i][0] == array[i][1] && array[i][1] == array[i][2] && array[i][1] == player)
        {
            printf("\nRow %d Win! ", i);
            return 1;
        }
    }
    return 0;
}

// function to check win in each column

int check_columns(int array[N][N], int player)
{
    for (int i = 0; i < N; i++)
    {
        if (array[0][i] == array[1][i] && array[1][i] == array[2][i] && array[1][i] == player)
        {
            printf("\nColumn %d Win! ", i);
            return 1;
        }
    }
    return 0;
}

// function to check win in each diagonal

int check_diagonals(int array[N][N], int player)
{
    if (array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[1][1] == player)
    {
        printf("\nDiagonal 1 win! ");
        return 1;
    }
    else if (array[2][0] == array[1][1] && array[1][1] == array[0][2] && array[1][1] == player)
    {
        printf("\nDiagonal 2 Win! ");
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to check win in either row, column or diagonal

int win(int a[N][N], int player)
{
    if (check_rows(a, player) || check_columns(a, player) || check_diagonals(a, player))
    {
        printf("\n\nCongratulations! Player %d wins!", player);
        return 1;
    }
    return 0;
}

// function to set move according to player number

int set(int a[N][N], int m, int n, int player)
{
    a[m][n] = player;
    return 0;
}

// function to take moves from player turn-wise

int playerMove(int matrix[N][N], int player)
{
    int m, n;
    char choice = 'c';

    display(matrix);
    if (draw(matrix)){
        printf("\n\nNo one Wins!\n\nThank you for playing. \n");
        return 1;
    }
    printf("\nPlayer %d Move (col,row) :: ", player);

    while (1)
    {
        scanf("%d %d", &m, &n);
        if (matrix[n][m] != 0 || m > 2 || n > 2)
        {
            printf("\nIncorrect Move!!\n\nRe-Enter the Move (col,row) :: ");
            continue;
        }
        set(matrix, n, m, player);
        break;
    }

    display(matrix);

    if (win(matrix, player))
    {
        printf("\n\nMatch Over!\n\nThank you for Playing. \n");
        return player;
    }
    return 0;
}

/*--------------------------------------------------------------------------------------------*/