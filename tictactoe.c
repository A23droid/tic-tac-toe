#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void viewBoard(char arr[][3], int n) 
{
    printf(" ---+---+---+\n");
    for (int i = 0; i  < n; i++)
    {
        printf("| ");
        for (int j = 0; j < n; j++)
        {
            printf("%c | ", arr[i][j]);
        }
        printf("\n ---+---+---+\n");
    }
}

char stop(char arr[][3], int n, int mc)
{
    int x = 0, o = 0;
    for (int i = 0;  i < n; i++)
    {
        // Vertically
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[2][i] == arr[0][i] && arr[0][i] != '.')
        {
            return arr[0][i];
        } 

        // Horizontally
        else if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] == arr[i][0] && arr[i][0] != '.')
        {
            return arr[i][0];
        } 
            
    }

    // Diagonals
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == arr[0][0] && arr[0][0] != '.')
    {
        return arr[0][0];
    }
    else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] == arr[0][2] && arr[0][2] != '.')
    {
        return arr[0][2];
    }

    if (mc == 9) return 'D'; // Draw
    return 'N'; // No stopping
}

void playwithHuman(char arr[][3], int n, int *ptr)
{
    char currentPlayer = 'X';
    while (1)
    {
        viewBoard(arr, n);
        int p, q;
        printf("Choose your spot, %c: ", currentPlayer);
        scanf("%d %d", &p, &q);

        // Input Validation
        if (p < 1 || p > 3 || q < 1 || q > 3 || arr[p - 1][q - 1] != '.')
        {
            printf("\nBruhh. Illegal move! Nice try diddy %c <smirk_emoji>\n", currentPlayer);
            continue;
        }

        arr[p - 1][q - 1] = currentPlayer;
        (*ptr)++;

        
        char result = stop(arr, n, *ptr);
        if (result != 'N')
        {
            viewBoard(arr, n);
            if (result == 'D') printf("\n--- --- --- ---\nDRAW!!\n--- --- --- ---");
            else if (result == 'X') printf("\n--- --- --- ---\nPlayer X wins!!\n--- --- --- ---");
            else printf("\n--- --- --- ---\nPlayer O wins!!\n--- --- --- ---");
            break;
        }

        if (currentPlayer == 'X')
        {
            currentPlayer = 'O';
        }
        else
        {
            currentPlayer = 'X';
        }
    }
}

void playwithEz(char arr[][3], int n, int *ptr)
{
    char currentPlayer = 'X';
    printf("\nMeet Ez, the most random bot you'll ever find.\nIf this guy defeats you, ig it's the time you reconsider your life :)\n");
    while (1)
    {
        // PLAYER
        viewBoard(arr, n);
        int p, q;
        printf("Choose your spot, %c: ", currentPlayer);
        scanf("%d %d", &p, &q);

        // Input Validation
        if (p < 1 || p > 3 || q < 1 || q > 3 || arr[p - 1][q - 1] != '.')
        {
            printf("\nBruhh. Illegal move! Nice try diddy <smirk_emoji>\n");
            continue;
        }

        arr[p - 1][q - 1] = currentPlayer;
        (*ptr)++;

        char result = stop(arr, n, *ptr);
        if (result != 'N')
        {
            viewBoard(arr, n);
            if (result == 'D') printf("\n--- --- --- ---\nDRAW!!\n--- --- --- ---");
            else if (result == 'X') printf("\n--- --- --- ---\nYou won!!\n--- --- --- ---");
            else printf("\n--- --- --- ---\nBot Ez won!\nReconsider your life now ;)\n--- --- --- ---");
            break;
        }

       // BOT
       // Get random values
       int a, b;
       do
       {
            a = rand() % 3;
            b = rand() % 3;
       } 
       while (arr[a][b] == 'X' || arr[a][b] == 'O');
       
       // Make the move
       arr[a][b] = 'O';
       (*ptr)++; 

       // Check if game ended
       result = stop(arr, n, *ptr);
       viewBoard(arr, n);
        if (result != 'N')
        {
            if (result == 'D') printf("\n--- --- --- ---\nDRAW!!\n--- --- --- ---");
            else if (result == 'X') printf("\n--- --- --- ---\nPlayer X wins!!\n--- --- --- ---");
            else printf("\n--- --- --- ---\nPlayer O wins!!\n--- --- --- ---");
            break;
        }
    }
}

void playwithMid(char arr[][3], int n, int *ptr)
{
    char currentPlayer = 'X';
    printf("\nMeet Mid, the most mid bot you'll ever find.\nI bet defeating it would be a challenge.\n");
    while (1)
    {
        // PLAYER
        viewBoard(arr, n);
        int p, q;
        printf("Choose your spot, %c: ", currentPlayer);
        scanf("%d %d", &p, &q);

        // Input Validation
        if (p < 1 || p > 3 || q < 1 || q > 3 || arr[p - 1][q - 1] != '.')
        {
            printf("\nBruhh. Illegal move! Nice try diddy <smirk_emoji>\n");
            continue;
        }

        arr[p - 1][q - 1] = currentPlayer;
        (*ptr)++;
        viewBoard(arr, n);
        printf("Mid bot strikes!\n");

        char result = stop(arr, n, *ptr);
        if (result != 'N')
        {
            viewBoard(arr, n);
            if (result == 'D') printf("\n--- --- --- ---\nDRAW!!\n--- --- --- ---");
            else if (result == 'X') printf("\n--- --- --- ---\nYou won!!\n--- --- --- ---");
            else printf("\n--- --- --- ---\nMid bot won!\nNice game, btw ;)\n--- --- --- ---");
            break;
        }

       // BOT
       // BLOCK : Player has 2/3 then block 
       // Let blocking co-ord be A, B;
       int A, B, didIMove = 0;
       // int x = 0, o = 0, dot = 0;

       // ROWS
       for (int i = 0; i < n; i++)
       {
        int x = 0, o = 0, dot = 0;
        for (int j = 0; j < n; j++)
        {
            
            if (arr[i][j] == 'X') x++;
            else if (arr[i][j] == 'O') o++;
            else 
            {
                dot++;
                A = i, B = j;
            }
        }

        if (x == 2 && dot == 1) 
        {
            arr[A][B] = 'O';
            didIMove = 1;
            (*ptr)++;
            // viewBoard(arr, n);
        }
       }

       // COLUMNS
       if (didIMove == 0)
       {
        for (int i = 0; i < n; i++)
        {
            int x = 0, o = 0, dot = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j][i] == 'X') x++;
                else if (arr[j][i] == 'O') o++;
                else 
                {
                    dot++;
                    A = j, B = i;
                }
            }

            if (x == 2 && dot == 1 && didIMove == 0) 
            {
                arr[A][B] = 'O';
                didIMove++;
                (*ptr)++;
                // viewBoard(arr, n);
            }
        }
       }

       // DIAGONALS
       if (didIMove == 0)
       {
            int x = 0, o = 0, dot = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i][i] == 'X') x++;
                else if (arr[i][i] == 'O') o++;
                else 
                {
                    dot++;
                    A = i, B = i;
                }
            }

            if (x == 2 && dot == 1 && didIMove == 0) 
            {
                arr[A][B] = 'O';
                didIMove++;
                (*ptr)++;
                // viewBoard(arr, n);
            }

            for (int i = 0; i < n; i++)
            {
                x = 0, o = 0, dot = 0;
                for (int j = 0; j < n; j++)
                {
                    if (i + j == n - 1)
                    {
                        if (arr[i][j] == 'X') x++;
                        else if (arr[i][j] == 'O') o++;
                        else 
                        {
                            dot++;
                            A = i, B = j;
                        }
                    }
                }

                if (x == 2 && dot == 1 && didIMove == 0) 
                {
                    arr[A][B] = 'O';
                    didIMove = 1;
                    (*ptr)++;
                    // viewBoard(arr, n);
                }
            }
       }

       // WIN : Bot has 2/3 then win
       if (didIMove == 0)
       {
            // ROWS
            for (int i = 0; i < n; i++)
            {
                int x = 0, o = 0, dot = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 'X') x++;
                else if (arr[i][j] == 'O') o++;
                else 
                {
                    dot++;
                    A = i, B = j;
                }
            }

            if (o == 2 && dot == 1) 
            {
                arr[A][B] = 'O';
                didIMove = 1;
                (*ptr)++;
            }
            }

            // COLUMNS
            
            for (int i = 0; i < n; i++)
            {
                int x = 0, o = 0, dot = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j][i] == 'X') x++;
                else if (arr[j][i] == 'O') o++;
                else 
                {
                    dot++;
                    A = j, B = i;
                }
            }

            if (o == 2 && dot == 1 && didIMove == 0) 
            {
                arr[A][B] = 'O';
                didIMove++;
                (*ptr)++;
            }
            }

            // DIAGONALS
            for (int i = 0; i < n; i++)
            {
                int x = 0, o = 0, dot = 0;
                if (arr[i][i] == 'X') x++;
                else if (arr[i][i] == 'O') o++;
                else 
                {
                    dot++;
                    A = i, B = i;
                }

            if (o == 2 && dot == 1 && didIMove == 0) 
            {
                arr[A][B] = 'O';
                didIMove++;
                (*ptr)++;
            }
            }

            for (int i = 0; i < n; i++)
            {
                int x = 0, o = 0, dot = 0;
            for (int j = 0; j < n; j++)
            {
                if (i + j == n - 1)
                {
                    if (arr[i][j] == 'X') x++;
                    else if (arr[i][j] == 'O') o++;
                    else 
                    {
                        dot++;
                        A = i, B = j;
                    }
                }
            }

            if (o == 2 && dot == 1 && didIMove == 0) 
            {
                arr[A][B] = 'O';
                didIMove = 1;
                (*ptr)++;
            }
            }
       }
       
       // Ez mode : If none, then revert back to Ez model
       if (didIMove == 0)
       {
        int a, b;
        do
        {
             a = rand() % 3;
             b = rand() % 3;
        } 
        while (arr[a][b] == 'X' || arr[a][b] == 'O');
        
        // Make the move
        arr[a][b] = 'O';
        (*ptr)++; 
       }
       
       // Check if game ended
       result = stop(arr, n, *ptr);
        if (result != 'N')
        {
            printf("\nBOOM!\n");
            viewBoard(arr, n);
            if (result == 'D') printf("\n--- --- --- ---\nDRAW!!\n--- --- --- ---");
            else if (result == 'X') printf("\n--- --- --- ---\nPlayer X wins!!\n--- --- --- ---");
            else printf("\n--- --- --- ---\nPlayer O wins!!\n--- --- --- ---");
            break;
        }
    }
}

int main(void)
{
    int n = 3;
    char arr[3][3];

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = '.';
        }
    }
    int moveCounter = 0, *ptr = &moveCounter;

    printf("\nHey, welcome to TIC-TAC-TOE!\nWould you like to play this game:\n1. With a friend\n2. With a bot.\n3. Exit\nChoose: ");
    int ch;
    scanf("%d", &ch);

    if (ch == 1) playwithHuman(arr, n, ptr);

    else if (ch == 2) 
    {
        srand(time(NULL));
        printf("\nHa! Choose your oppenent:\n1. Ez bot\n2. Mid bot\nEnter your choice: ");

        int choice; scanf("%d", &choice);
        if (choice == 1) playwithEz(arr, n, ptr);
        else if (choice == 2) playwithMid(arr, n, ptr);
        else printf("Bruh.\n");
    }
    
    else if (ch == 3)
    {
        printf("Bye Broo <waving_hand_emoji>\n");
        return 1;
    }

    char again;
    printf("\nAyy Wanna replay? (y/n)");
    scanf(" %c", &again);

    if (again == 'y') main();
    else printf("\nValid, see ya!\n");
}