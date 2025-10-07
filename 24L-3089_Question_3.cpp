// Console Based Tic-Tac-Toe Game
#include <iostream>
using namespace std;

const int SIZE = 3;
const char EMPTY = ' ';

char board[SIZE][SIZE]; // Board

void initializeBoard() 
{
   for (int i = 0; i < SIZE; ++i)
   {
       for (int j = 0; j < SIZE; ++j)
       {
           board[i][j] = EMPTY;
       }
   }
}

void displayBoard() 
{
   cout << endl;
   for (int i = 0; i < SIZE; ++i)
   {
       cout << " ";
       for (int j = 0; j < SIZE; ++j)
       {
           cout << board[i][j];
           if (j < SIZE - 1) cout << " | ";
       }
       cout << endl;
       if (i < SIZE - 1) cout << "---+---+---\n";
   }
   cout << endl;
}

bool isValidMove(int row, int col)
{
   return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY);
}

void makeMove(int row, int col, char symbol)
{
   board[row][col] = symbol;
}

bool checkWin(char symbol) 
{
   // Rows and columns
   for (int i = 0; i < SIZE; ++i) {
       if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
           (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol))
       {
           return true;
       }
   }

   // Diagonals
   if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
       (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol))
   {
       return true;
   }

   return false;
}

bool isDraw() 
{
   for (int i = 0; i < SIZE; ++i)
   {
       for (int j = 0; j < SIZE; ++j)
       {
           if (board[i][j] == EMPTY)
           {
               return false;
           }
       }
   }
   return true;
}

char switchPlayer(char current) 
{
   return (current == 'X') ? 'O' : 'X';
}

void playGame() 
{
   initializeBoard();
   char currentPlayer = 'X';
   int row, col;

   cout << "Welcome to Tic-Tac-Toe!" << endl;
   cout << "Player 1: X\nPlayer 2: O" << endl;

   while (true) 
   {
       displayBoard();
       cout << "Player " << currentPlayer << ", enter your move (row and column: 0 1 2): ";
       cin >> row >> col;

       if (!cin || !isValidMove(row, col)) 
       {
           cin.clear(); // clear error flags
           cin.ignore(1000, '\n'); // discard invalid input
           cout << "Invalid move. Try again." << endl;
           continue;
       }

       makeMove(row, col, currentPlayer);

       if (checkWin(currentPlayer)) 
       {
           displayBoard();
           cout << "Player " << currentPlayer << " wins!"<<endl;
           break;
       }

       if (isDraw()) 
       {
           displayBoard();
           cout << "Game drawn!" << endl;
           break;
       }

       currentPlayer = switchPlayer(currentPlayer);
   }
}

int main()
{
   playGame();
   return 0;
}



