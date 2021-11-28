#include <ncurses.h>

enum { key_exit = 27, delay = 100 };

struct star {
  int cur_x, cur_y, dx, dy;
};

static void show_hide(const struct star *s, char chr)
{
  move(s->cur_y, s->cur_x);
  addch(chr);
  refresh();

}

static void check(int *crd, int max)
{
  if(*crd > max)
    *crd -= max;
  else
    if(*crd < 0)
      *crd += max;
}

static void move_star(struct star *s, int max_x, int max_y)
{
  mvprintw(0, 0, "%d,%d    ", s->cur_x, s->cur_y);
  mvprintw(1, 0, "%d ,%d ", s->dx, s->dy);
  show_hide(s, ' ');
  s->cur_x += s->dx;
  check(&s->cur_x, max_x);
  s->cur_y += s->dy;
  check(&s->cur_y, max_y);
  show_hide(s, '*');
}

static void set_direction(struct star *s, int dx, int dy)
{
  s->dx = dx;
  s->dy = dy;
}

static void handle_resize(struct star *s, int *col, int *row)
{
  getmaxyx(stdscr, *row, *col);
  if(s->cur_x > *col)
    s->cur_x = *col;
  if(s->cur_y > *row)
    s->cur_y = *row;
      
}

int main()
{
  int row, col, key;
  struct star s;
  initscr();
  cbreak();
  noecho();
  timeout(delay);
  keypad(stdscr, 1);
  curs_set(0);
  getmaxyx(stdscr, row, col);
  s.cur_x = col/2;
  s.cur_y = row/2;
  set_direction(&s, 0, 0);
  while((key = getch()) != key_exit) {
    switch(key) {
      case ' ':
        set_direction(&s, 0, 0);
        break;
      case KEY_UP:
        set_direction(&s, 0, -1);
        break;
      case KEY_DOWN:
        set_direction(&s, 0, 1);
        break;
      case KEY_LEFT:
        set_direction(&s, -1, 0);
        break;
      case KEY_RIGHT:
        set_direction(&s, 1, 0);
        break;
      case ERR:
        move_star(&s, col-1, row-1);
        break;
      case KEY_RESIZE:
        handle_resize(&s, &col, &row);
        break;
    }
  }
  endwin();
  return 0;
}
