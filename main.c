#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define BALL_SIZE 1
#define GAME_SPEED 10

int playerX;
int ballX, ballY;
int gameOver;

void initializeGame();
void updateGame();
void handleInput();
void render();

int main()
{
  initializeGame();

  while (!gameOver)
  {
    handleInput();
    updateGame();
    render();
    Sleep(GAME_SPEED); // Delay for game speed
  }

  return 0;
}

void initializeGame()
{
  srand(time(NULL));

  playerX = SCREEN_WIDTH / 2;
  ballX = rand() % (SCREEN_WIDTH - BALL_SIZE);
  ballY = 0;
  gameOver = 0;
}

void updateGame()
{
  ballY++;

  if (ballY == SCREEN_HEIGHT - 1)
  {
    gameOver = 1;
  }
  else if (ballY == SCREEN_HEIGHT - 2 && ballX >= playerX - BALL_SIZE && ballX <= playerX + BALL_SIZE)
  {
    gameOver = 1;
  }
}

void handleInput()
{
  if (_kbhit())
  {
    int key = _getch();
    if (key == 224)
    {
      key = _getch();
      if (key == 75 && playerX > BALL_SIZE)
      {
        playerX--;
      }
      else if (key == 77 && playerX < SCREEN_WIDTH - BALL_SIZE - 1)
      {
        playerX++;
      }
    }
    else if (key == 'q' || key == 'Q')
    {
      gameOver = 1;
    }
  }
}

void render()
{
  system("cls");

  for (int i = 0; i < SCREEN_HEIGHT; i++)
  {
    for (int j = 0; j < SCREEN_WIDTH; j++)
    {
      if (i == ballY && j == ballX)
      {
        printf("O");
      }
      else if (i == SCREEN_HEIGHT - 2 && (j == playerX - BALL_SIZE || j == playerX + BALL_SIZE))
      {
        printf("|");
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }
}
