#include "visualiser.h"
#include "stdlib.h"
#include "stdio.h"
#include <GLFW/glfw3.h>

#define SCREENWIDTH 640
#define SCREENHEIGHT 640

//Helper function to draw a box at a specific co-ordinate
void draw_box(float x, float y, float side_length, int colour) {
	if (colour == 1) {
		glColor3f(0xc5 / 255.0f, 0x95 / 255.0f, 0x62 / 255.0f);
	} else {
		glColor3f(0xfb / 255.0f, 0xfb / 255.0f, 0xf1 / 255.0f);
	}
	glBegin(GL_QUADS); 
		glVertex2f(x, y);
		glVertex2f(x + side_length, y);
		glVertex2f(x + side_length, y + side_length);
		glVertex2f(x, y + side_length);
	glEnd();
}

//Helper function to draw the background
void draw_grid() {
	int ROWS = 8;
	int COLUMNS = 8;
	int SIZE = 80;

	int colour;
	for(float i = 0; i < ROWS; i++) {
		for(float j = 0; j < COLUMNS; j++) {
			if ((int)(i + j) % 2 == 1) {
				colour = 1;
			} else {
				colour = 0;
			}
			draw_box(i*SIZE, j*SIZE, SIZE, colour);
		}
	}
}

void draw_board() {
	printf("Drawing Board\n");
	if (!glfwInit())
	{
		//We are good programmers here, handle these things
		printf("Initialisation Failed\n");
		exit(1);
	}
	GLFWwindow* window = glfwCreateWindow(SCREENWIDTH, SCREENHEIGHT, "Chess Window", NULL, NULL);	
	glfwMakeContextCurrent(window);

    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	glOrtho(0, SCREENWIDTH, 0, SCREENHEIGHT, -1, 1); 
	glMatrixMode(GL_MODELVIEW);

	draw_grid();
	glfwSwapBuffers(window);
        glfwPollEvents();
}
