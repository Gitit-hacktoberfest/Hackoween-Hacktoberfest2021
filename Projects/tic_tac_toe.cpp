#include <iostream>
#include <conio.h>
using namespace std;

char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
bool draw = false;

void display_board()
{

    system("cls");

    cout << "\t      |     |     " << endl;
    cout << "\t   " << arr[0][0] << "  |  " << arr[0][1] << "  |   " << arr[0][2] << "  " << endl;
    cout << "\t______|_____|_____" << endl;
    cout << "\t      |     |     " << endl;
    cout << "\t   " << arr[1][0] << "  |  " << arr[1][1] << "  |   " << arr[1][2] << "  " << endl;
    cout << "\t______|_____|_____" << endl;
    cout << "\t      |     |     " << endl;
    cout << "\t  " << arr[2][0] << "   |  " << arr[2][1] << "  |  " << arr[2][2] << "   " << endl;
    cout << "\t      |     |     " << endl;
}

void player_turn()
{

    int choice;
    int row;
    int column;

    if (turn == 'X')
    {
        cout << "\n\t player1 [X] turn: ";
    }
    if (turn == 'O')
    {
        cout << "\n\t player2 [O] turn: ";
    }
    cin >> choice;

    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;

    case 2:
        row = 0;
        column = 1;
        break;

    case 3:
        row = 0;
        column = 2;
        break;

    case 4:
        row = 1;
        column = 0;
        break;

    case 5:
        row = 1;
        column = 1;
        break;

    case 6:
        row = 1;
        column = 2;
        break;

    case 7:
        row = 2;
        column = 0;
        break;

    case 8:
        row = 2;
        column = 1;
        break;

    case 9:
        row = 2;
        column = 2;
        break;

    default:
        cout << "Invalid choice" << endl;
        break;
    }

    if (turn == 'X' && arr[row][column] != 'X' && arr[row][column] != 'O')
    {
        arr[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && arr[row][column] != 'X' && arr[row][column] != 'O')
    {
        arr[row][column] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "\n enter another number" << endl;
        player_turn();
    }

    display_board();
}

bool game_over()
{

    // check win

    // horizontal win
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] == 'X')
        {
            cout << "\n\tPLAYER 1 WON !!" << endl;
            return false;
        }
        else if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] == 'O')
        {
            cout << "\n\tPLAYER 2 WON !!" << endl;
            return false;
        }
    }

    // vertical win
    for (int i = 0; i < 3; i++)
    {
        if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] == 'X')
        {
            cout << "\n\tPLAYER 1 WON !!" << endl;
            return false;
        }
        else if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] == 'O')
        {
            cout << "\n\tPLAYER 2 WON !!" << endl;
            return false;
        }
    }

    //diagnol win
    for (int i = 0; i < 3; i++)
    {
        if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] == 'X')
        {
            cout << "\n\tPLAYER 1 WON !!" << endl;
            return false;
        }
        else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] == 'X')
        {
            cout << "\n\tPLAYER 1 WON !!" << endl;
            return false;
        }

        else if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] == 'O')
        {
            cout << "\n\tPLAYER 2 WON !!" << endl;
            return false;
        }
        else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] == 'O')
        {
            cout << "\n\tPLAYER 2 WON !!" << endl;
            return false;
        }
    }

    //playing
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 'X' && arr[i][j] != 'O')
            {
                return true;
            }
        }
    }

    //draw
    draw = true;
    cout << "\n\t GAME DRAW :( " << endl;
    return false;
}

int main()
{

    display_board();
    while (game_over())
    {

        player_turn();
    }

    cout << "\n\n *** Hope you enjoyed playing it :) *** \n\n";

    getch();

    return 0;
}
