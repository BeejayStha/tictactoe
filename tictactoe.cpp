#include <iostream>
#include <iomanip>
#include <time.h>
#include <unistd.h>
#define clear()
#define Sleep(X) usleep(1000*X)

using namespace std;

class TicTacToe_Game
{
  public:
    TicTacToe_Game();
  void play();
  private:
    uint32_t option, getWinner, player1Score, player2Score;
  char matrix[3][3];
  void instructions();
  void GameReset();
  void matrixDisplay();
  void player1Move();
  void player2Move();
  bool filled(int square, char symbol);
  int result();
};

int main(int argc, char ** argv)
{
  system("clear");
    time_t l_time = time(NULL);
    printf("%s", ctime(&l_time));
  TicTacToe_Game match;
  cout << "\n";
  cout << "TicTacToe Game \n";
  cout << "  Designed by  \n";
  cout << "Bijaya Shrestha\n";
    cout << "__________________________________________________\n";

  match.play();
  return (0);
}

void TicTacToe_Game::instructions()
{
  do
  {
    cout << "Please choose one of the options listed below:\n";
    cout << "1. Human Vs Computer\n";
    cout << "2. Human Vs Human\n";
    cout << "0. Quit\n";
    cout << "Options: ";
    cin >> option;
  }
  while (option > 2);
    if (option == 1 or option == 2 )
    {
        cout << "Continue Game\n";
    }
    else
    {
    cout << "Program Terminated\n" "GoodBye\n";
    }
    
}

void TicTacToe_Game::play()
{
  instructions();
  while (option)
  {
    GameReset();
    system("clear");
    matrixDisplay();
    while (!getWinner)
    {
      player1Move();
      system("clear");
      matrixDisplay();
      if ((getWinner = result()))
          continue;
      player2Move();
      system("clear");
      matrixDisplay();
      getWinner = result();
    }
    switch (getWinner)
    {
    case 1:
      player1Score++;
      system("clear");
      matrixDisplay();
      cout << "\n" << "Player 1 won!" << "\n" << "\n";
      break;
    case 2:
      player2Score++;
      system("clear");
      matrixDisplay();
      cout << "\n" << "Player 2 won!" << "\n" << "\n";
      break;
    case 3:
      cout << "\n" << "Game Tie!" << "\n" << "\n";
      break;
    }
    instructions();
  }
}

void TicTacToe_Game::GameReset()
{
  int i, j;
  getWinner = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      matrix <:i:> <:j:> = ' ';
    }
  }
}

void TicTacToe_Game::matrixDisplay()
{
  int i, j;
  cout << setfill('0');
  cout << "1st Player Score: " << setw(2) << player1Score << "\n";
  cout << "2nd Player Score: " << setw(2) << player2Score << "\n" << "\n";
  for (i = 0; i < 3; i++) {
    cout << setfill(' ');
    cout << 9 - 3 * i - 2 << setw(3) << "|";
    cout << 9 - 3 * i - 1 << setw(3) << "|";
    cout << 9 - 3 * i - 0 << "\n";
      
    for (j = 0; j < 3; j++)
    {
      cout << setw(2) << matrix <:i:> <:j:> ;
      if (j < 2)
        cout << setw(2) << "|";
    }
    cout << "\n";
    if (i < 2)
      cout << setfill('_');
    cout << setw(4) << "|" << setw(4) << "|" << setw(3) << "\n";
  }
}

void TicTacToe_Game::player1Move()
{
  int square;
  do {
    cout << "First player (X): Select an empty square: ";
    cin >> square;
  }
  while (!filled(square, 'X'));
}

void TicTacToe_Game::player2Move()
{
  int square;

  do {
    if (option == 2)
    {
      cout << "Second player (O): Select an empty square: ";
      cin >> square;
    }
    else
    {
        int k;
        for(k=1; k<10; k++)
        {
                int i = 3 - (k + 2) / 3;
                int j = (k - 1) % 3;
                if(matrix <:i:> <:j:> != ' ')
                        continue;
                matrix <:i:> <:j:> = 'X';
                int win = result();
                matrix <:i:> <:j:> = ' ';
                if(win==1)
                {
                        square = k;
                        break;
                }
        }
        if(k == 10)
      square = rand() % 9 + 1;
}
}
    while (!filled(square, 'O'));
    
    if (option == 1) Sleep(800);

}

TicTacToe_Game::TicTacToe_Game()
{
  srand((uint32_t) time(nullptr));
  player1Score = 0;
  player2Score = 0;
}

bool TicTacToe_Game::filled(int square, char symbol)
{
  bool True = (1);
  int i, j;
  if (1 <= square and square <= 9)
  {
    i = 3 - (square + 2) / 3;
    j = (square - 1) % 3;
    if (matrix <:i:> <:j:> == ' ')
    {
      matrix <:i:> <:j:> = symbol;
    }
    else
    {
      if (option != 1 or symbol == 'X')
        cout << square << " Already filled! Please choose another empty square." << "\n";
      True = (0);
    }
  }
  else
  {
    if (option != 1 or symbol == 'X')
      cout << square << " Invalid move!! Try again" << "\n";
    True = (0);
  }
  return (True);
}

int TicTacToe_Game::result()
{
    int i,j, getWinner = 3;
    for
        (i = 0; i< 3 and getWinner == 3; i++)
    {
        for
            (j = 0; j < 3 and getWinner == 3; j++)
        {
            if
                (matrix<:i:><:j:> == ' ')
                getWinner = 0;
        }
    }
    //checks rows
    for(i = 0; i < 3 and (getWinner != 1 and getWinner != 2); i++)
    {
        if
            ((matrix <:i:> <:0:> == 'X')
             and(matrix <:i:> <:0:> == matrix <:i:> <:1:>)
             and(matrix <:i:> <:1:> == matrix <:i:> <:2:>))
            getWinner = 1;
        else if
            ((matrix <:i:> <:0:> == 'O')
             and (matrix <:i:> <:0:> == matrix <:i:> <:1:>)
             and (matrix <:i:> <:1:> == matrix <:i:> <:2:>))
            getWinner = 2;
    }
    //checks columns
    for
        (j = 0; j < 3
        and (getWinner != 1 and getWinner != 2); j++)
    {
        if
            ((matrix <:0:> <:j:> == 'X')
             and (matrix <:0:> <:j:> == matrix <:1:> <:j:>)
             and (matrix <:1:> <:j:> == matrix <:2:> <:j:>))
            getWinner = 1;
        else if
            ((matrix <:0:> <:j:> == 'O')
             and (matrix <:0:> <:j:> == matrix <:1:> <:j:>)
             and (matrix <:1:> <:j:> == matrix <:2:> <:j:>))
            getWinner = 2;
    }
    //checks diagonals
    if
        (getWinner != 1 and getWinner != 2)
    {
        if
            ((matrix <:0:> <:0:> == 'X')
             and (matrix <:0:> <:0:> == matrix <:1:> <:1:>)
             and (matrix <:1:> <:1:> == matrix <:2:> <:2:>))
            getWinner = 1;
        else if
            ((matrix <:0:> <:0:> == 'O')
             and (matrix <:0:> <:0:> == matrix <:1:> <:1:>)
             and (matrix <:1:> <:1:> == matrix <:2:> <:2:>))
            getWinner = 2;
        else if
            ((matrix <:0:> <:2:> == 'X')
             and (matrix <:0:> <:2:> == matrix <:1:> <:1:>)
             and (matrix <:1:> <:1:> == matrix <:2:> <:0:>))
            getWinner = 1;
        else if
            ((matrix <:0:> <:2:> == 'O')
             and (matrix <:0:> <:2:> == matrix <:1:> <:1:>)
             and (matrix <:1:> <:1:> == matrix <:2:> <:0:>))
            getWinner = 2;
    }
    return(getWinner);
}
