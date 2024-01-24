#include <iostream>
#include <string>
// #include <conio.h>

using namespace std;
// global variable
bool game_over;
const int width = 20;
const int height = 20;
int x, y, fruit_x, fruit_y, score;
enum eDirection
{
  STOP = 0,
  LEFT,
  RIGHT,
  UP,
  DOWN
};
eDirection dir;
// setup function
void setup()
{
  game_over = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruit_x = rand() % width;
  fruit_y = rand() % height;
  score = 0;
}
//
void draw()
{

  for (int i = 0; i < width; i++)
  {
    cout << "#";
  }

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (j == 0 || j == width - 1)
      {
        cout << "#";
      }
      else if (j == x && i == y)
      {
        cout << "O";
      }
      else if (j == fruit_x && i == fruit_y)
      {
        cout << "F";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }

  for (int i = 0; i < width; i++)
  {
    cout << "#";
  }
}
//
void input()
{
  // conio.h librari doesn't work here so
  if (_kbhit())
  {
    switch (_getch())
    {
    case 'a':
      dir = LEFT;
      break;
    case 'd':
      dir = RIGHT;
      break;
    case 'w':
      dir = UP;
      break;
    case 's':
      dir = DOWN;
      break;
    default:
      break;
    }
  }
}
//
void logic()
{
 //movment
  switch (dir)
  {
  case UP:
    y--;
    break;
  case DOWN:
    y++;
    break;
  case LEFT:
    x--;
    break;
  case RIGHT:
    x++;
    break;
  default:
    break;
  }
  //scoring
  if(x == fruit_x && y == fruit_y) {
    score++;
  }
  //termination
  if (x < 0 || x > width || y < 0 || y > height) {
    game_over = true;
  }
}

int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  setup();

  while (!game_over)
  {
    draw();
    input();
    logic();
    // game_over = true;
  }

  cout << "you lost the game looser!" << endl;
}
