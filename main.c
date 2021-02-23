#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = 255;
  c.blue = 0;

  clear_screen(s);
  //octants 1 and 5
  draw_line(0, 0, XRES-1, YRES-1, s, c);
  draw_line(0, 0, XRES-1, YRES / 2, s, c);
  draw_line(XRES-1, YRES-1, 0, YRES / 2, s, c);

  //octants 8 and 4
  c.blue = 255;
  draw_line(0, YRES-1, XRES-1, 0, s, c);
  draw_line(0, YRES-1, XRES-1, YRES/2, s, c);
  draw_line(XRES-1, 0, 0, YRES/2, s, c);

  //octants 2 and 6
  c.red = 255;
  c.green = 0;
  c.blue = 0;
  draw_line(0, 0, XRES/2, YRES-1, s, c);
  draw_line(XRES-1, YRES-1, XRES/2, 0, s, c);

  //octants 7 and 3
  c.blue = 255;
  draw_line(0, YRES-1, XRES/2, 0, s, c);
  draw_line(XRES-1, 0, XRES/2, YRES-1, s, c);

  //horizontal and vertical
  c.blue = 0;
  c.green = 255;
  draw_line(0, YRES/2, XRES-1, YRES/2, s, c);
  draw_line(XRES/2, 0, XRES/2, YRES-1, s, c);

  display(s);
  save_extension(s, "lines.png");



  // Picture for Gallery Submission
  screen s2;
  color c2;

  clear_screen(s2);

  srand(time(NULL));

  int x = 250;
  int y = 250;

  for (int i = 0; i < 50000; i++) {
    c2.red = rand() % 256;
    c2.green = rand() % 256;
    c2.blue = rand() % 256;

    int r = rand() % 4;

    if (r == 0) {
      draw_line(x, y-5, x, y, s2, c2);
      y -= 5;
    }

    else if (r == 1) {
      draw_line(x, y, x + 5, y, s2, c2);
      x += 5;
    }

    else if (r == 2) {
      draw_line(x, y, x, y + 5, s2, c2);
      y += 5;
    }

    else {
      draw_line(x - 5, y, x, y, s2, c2);
      x -= 5;
    }
  }

  save_extension(s2, "The_cooler_lines.png");
}
