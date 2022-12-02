/* File:         square-spiral/src/main.c
 *
 * Author:       Raffy Doquenia
 *
 * Date & time:  11/30/2022-01:11:40-PM
 */

#include <stdbool.h>
#include <stdio.h>
#include <SFML/Graphics.h>


typedef struct Square {
	int number;
	float row;
	float column;
}Square;


typedef struct {
	int x, y;
}Initial_position;


Initial_position init_pos;


Square sq[7][7] = {
	{{7, 0,   0}, {8,  100,   0}, {9,  200,   0}, {10, 300,   0}, {11, 400,   0}, {12, 500,   0}, {13, 600,   0}},
	{{6, 0, 100}, {29, 100, 100}, {30, 200, 100}, {31, 300, 100}, {32, 400, 100}, {33, 500, 100}, {14, 600, 100}},
	{{5, 0, 200}, {28, 100, 200}, {43, 200, 200}, {44, 300, 200}, {45, 400, 200}, {34, 500, 200}, {15, 600, 200}},
	{{4, 0, 300}, {27, 100, 300}, {42, 200, 300}, {49, 300, 300}, {46, 400, 300}, {35, 500, 300}, {16, 600, 300}},
	{{3, 0, 400}, {26, 100, 400}, {41, 200, 400}, {48, 300, 400}, {47, 400, 400}, {36, 500, 400}, {17, 600, 400}},
	{{2, 0, 500}, {25, 100, 500}, {40, 200, 500}, {39, 300, 500}, {38, 400, 500}, {37, 500, 500}, {18, 600, 500}},
	{{1, 0, 600}, {24, 100, 600}, {23, 200, 600}, {22, 300, 600}, {21, 400, 600}, {20, 500, 600}, {19, 600, 600}}
};


sfColor my_color[7] = { // Cyan RGBA{0, 183, 235, 255}
	{0, 183, 235, 255},
	{0, 183, 235, 205},
	{0, 183, 235, 155},
	{0, 183, 235, 105},
	{0, 183, 235, 055},
	{0, 183, 235, 005},
	{0, 183, 235, 001}
};


int main() {
	// Create a window
	sfVideoMode vid_mode = {700, 700, 32};
	sfRenderWindow *window = sfRenderWindow_create(vid_mode, "Square Spiral", sfClose, NULL);

	// Circle shape
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f size = {100, 100};
	sfRectangleShape_setSize(rect, size);

    // Start the loop
	while (sfRenderWindow_isOpen(window) == true) {
		
		// Close the window
		sfEvent event;
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (event.type == sfEvtClosed) {
				sfRenderWindow_close(window);
			}
        }
		
		// Clear the window with black color
		sfRenderWindow_clear(window, sfBlack);
		
		// Draw anything here...
		int x = 6, y = 0, i = 0, color_counter = 0;
		// This array is responsible for how each shade of cyan is applied.
		int i_array[] = {12, 23, 32, 39, 44, 48, 0};
		
		while (i < 50) {
			init_pos.x = x;
			init_pos.y = y;
			
			for (int n = 0; n < 4; n++) {
				switch (n) {
					case 0: if (y > 0) { y--; } break;
					case 1: if (x > 0) { x--; } break;
					case 2: if (y < 6) { y++; } break;
					case 3: if (x < 6) { x++; } break;
				}
				
				if ((sq[x][y].number - sq[init_pos.x][init_pos.y].number) == 1 || i == 49) {
					sfVector2f pos = {sq[init_pos.x][init_pos.y].row, sq[init_pos.x][init_pos.y].column};
					sfRectangleShape_setPosition(rect, pos);
					
					if (i == i_array[color_counter]) {
						color_counter++;
					}
					if (i == 49) {
						color_counter = 0;
					}
					
					sfRectangleShape_setFillColor(rect, my_color[color_counter]);
					sfRenderWindow_drawRectangleShape(window, rect, NULL);

					break;
				}
				
				x = init_pos.x;
				y = init_pos.y;
			}

			i++;
		}
		
		// end the current frame
		sfRenderWindow_display(window);
	}
	
    return 0;
}


