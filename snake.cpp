#include <iostream>
#include <string>
using namespace std; 
//global variable
bool game_over;
const int width = 40;
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
void setup() {
  game_over = false;
  dir = STOP;
  x = width / 2;
  y = height / 2; 
  fruit_x = rand() % width;
  fruit_y = rand() % height;
  score = 0;
}
//
void draw() {
  system("cls");
  for (int i = 0; i < width; i++) {
    cout << "#"; 
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0 || j == width -1)
      {
        cout << "#";
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
void input() {

}
//
void logic() {

}

int main () {

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
    game_over = true;
  }
}

