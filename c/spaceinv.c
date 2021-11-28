#include <ncurses.h>
#include <time.h>
enum { key_exit = 27 };

static void show_spaceship(int y, int x)
{
  mvprintw(1, 0, "%d,%d    ", y, x);
  mvprintw(y, x, "^");
  mvprintw(y+1, x-1, "<@>");
  mvprintw(y+2, x, "%%");
  refresh();
}

static void hide_spaceship(int y, int x)
{
  mvprintw(y, x, " ");
  mvprintw(y+1, x-1, "   ");
  mvprintw(y+2, x, " ");
}

static void check_y(int *crd, int max)
{
  if(*crd < 0)
    *crd = 0;
  else
    if(*crd > max-3)
      *crd = max-3;
}

static void check_x(int *crd, int max)
{
  if(*crd < 2)
    *crd = 1;
  else
    if(*crd > max-2)
      *crd = max-2;
}

static void move_spaceship(int *y, int *x, int dy, int dx, int max_y, int max_x)
{
  hide_spaceship(*y, *x);
  *y += dy;
  check_y(y, max_y);
  *x += dx;
  check_x(x, max_x);
  show_spaceship(*y, *x);
  refresh();
}

static void printch(int y, int x, char chr)
{
  mvprintw(y, x, "%c", chr);
  refresh();
}

static void piw_piw(int crt_y, int crt_x)
{
  for(int j = 1, i = crt_y; i > 0; i--,j++) {
    printch(crt_y-j, crt_x, '^');
    sleep(1);
    printch(crt_y-j, crt_x, ' ');
    //printch(crt_y-j-1, crt_x, '^');
  }
}

int main()
{
  int row, col, crt_y, crt_x, key;
  initscr();
  cbreak();
  keypad(stdscr, 1);
  curs_set(0);
  getmaxyx(stdscr, row, col);
  crt_y = row-6;
  crt_x = col/2-4;
  mvprintw(0, 0, "%d,%d", row, col);
  show_spaceship(crt_y, crt_x);
  while((key = getch()) != key_exit) {
    switch(key) {
      case KEY_UP:
        move_spaceship(&crt_y, &crt_x, -1, 0, row, col);
        break;
      case KEY_DOWN:
        move_spaceship(&crt_y, &crt_x, 1, 0, row, col);
        break;
      case KEY_LEFT:
        move_spaceship(&crt_y, &crt_x, 0, -3, row, col);
        break;
      case KEY_RIGHT:
        move_spaceship(&crt_y, &crt_x, 0, 3, row, col);
        break;
      case ' ':
        piw_piw(crt_y, crt_x);
        break;
    }
  }
  endwin();
  return 0;
}
