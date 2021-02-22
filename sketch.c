#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "sketch.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define m 200
float points[m][2];
float cx, cy, r;

// This code in setup will be run only once
void setup() {
	cx = WIDTH/2.0;
	cy = HEIGHT/2.0;
	r = WIDTH/3.0;

	double theta = (2.0 * M_PI)/m;

	for (int i = 0; i < m; ++i) {
		points[i][0] = cx + r * cos(i*theta);
		points[i][1] = cy + r * sin(i*theta);
	}

	
}

int t = 513;

// This code in draw will run every frame
void draw() {
	al_clear_to_color(al_map_rgb(51, 51, 51));
	al_draw_circle(cx, cy, r, al_map_rgb(128,0,128), 2.0);
	for (int i = 0; i < m; ++i) {

		int j = (i*t) % m;

		float x1 = points[i][0];
		float y1 = points[i][1];
		float x2 = points[j][0];
		float y2 = points[j][1];

		al_draw_line(x1, y1, x2, y2, al_map_rgb(200, 200, 200), 1.0);
	}

	++t;
}



void mousePressed(bool lmb) {
	// Handle mouse click events here
}
	


void keyPressed(int keyCode) {
	// Handle key press events
}