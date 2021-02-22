#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
	int x = x0;
	int y = y0;
	int dx = x1 - x0;
	int dy = y1 - y0; 
	
	if (x1 < x0) {
		x = x1;
		y = y1;
		dx *= -1;
		dy *= -1;
	}

	int xr = x + dx;
	int yr = y + dy;
	int d;
	int a;
	int b;

    // horizontal line
	if (dy == 0) {
		for (x = x0; x < x1; x++)
			plot(s, c, x, y);
	}

    // vertical line
	else if (dx == 0) {
		for (y = y0; y < y1; y++)
			plot(s, c, x, y);
	}

    // octant 1
	else if (dy <= dx && dy > 0) {
		a = dy;
		b = -1 * dx; 
		d = 2 * a + b;
		xr = x + dx;

		while (x <= xr) {
			plot(s, c, x, y);

			if (d > 0) {
				y++;
				d += 2 * b;
			}

			x++;
			d += 2 * a;
		}
	}

    // octant 2
	else if (dy > dx) {
		a = dx;
		b = -1 * dy;
		d = 2 * a + b;
		yr = y + dy;

		while (y <= yr) {   
			plot(s, c, x, y);

			if (d > 0) {
				x++;
				d += 2 * b;
			}

			y++; 
			d += 2 * a;
		}
	}

    // octant 3
	else if (-1 * dy > dx) {
		a = dx;
		b = -1 * dy;
		d = 2 * a - b;

		while (y >= yr) {   
			plot(s, c, x, y);

			if (d > 0) {
				x++;
				d -= 2 * b;
			}

			y--; 
			d += 2 * a;
		}
	}

    // octant 4
	else {
		a = dy;
		b = -1 * dx; 
		d = 2 * a - b;

		while (x <= xr) {
			plot(s, c, x, y);

			if (d < 0) {
				y--;
				d -= 2 * b;
			}

			x++;
			d += 2 * a;
		}
	}
}