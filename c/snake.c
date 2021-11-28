#include <ncurses.h>
#include <stdlib.h>
enum { exit_key = 27, max_tail = 7 };

static void print(int y, int x, char chr)
{
  mvprintw(0, 0, "%d,%d  ", x, y);
  move(y, x);
  addch(chr);
  refresh();
}

static void move_snake(int *snake, int dy, int dx)
{
  int y = 0, x = 1;
  do {
    print(snake+y, snake+x, '*');
    y += 2;
    x += 2;
  } while(*snake++);
}

//|0| 0 1 |1| 2 3 |2| 4 5 |3| 6

int main()
{
  int *snake = calloc(max_tail, sizeof(int));
  int row, col, key, length = 1;
  initscr(); /* Initialization ncurses! */
  cbreak();/* Ctr-C and etc. turn On; Raw is Ctr-C and etc. turn Off */
  noecho();
  curs_set(0);
  keypad(stdscr, 1); /* specific sequence, arrow and etc. 0 turn Off */
  getmaxyx(stdscr, row, col);
  snake[0] = col/2;
  snake[1] = row/2-1;
  print(snake[0], snake[1], '*');
  while((key = getch()) != exit_key) {
     switch(key) {
       case KEY_UP:
         move_snake(snake, -1, 0);
         break;
       case KEY_DOWN:
         //move_snake(crt_y, crt_x, 1, 0);
         break;
       case KEY_LEFT:
         //move_snake(crt_y, crt_x, 0, -1);
         break;
       case KEY_RIGHT:
         //move_snake(crt_y, crt_x, 0, 1);
         break;
     }
  }
  endwin();
  return 0;
}
