#include "shared.h"
#include "fire.h"

const char *gamename[] = {
"  _______ _                        _     __          __                   _____             __            _ _   ",
" |__   __| |                      | |    \\\\ \\        / /                  / ____|           / _|          | | |  ",
"    | |  | |__  _ __ ___  __ _  __| |_____\\\\ \\  /\\  / /_ _ _ __ ___ _____| (___   ___  __ _| |_ __ _ _   _| | |_ ",
"    | |  | '_ \\| '__/ _ \\/ _` |/ _` |______\\\\ \\/  \\/ / _` | '__/ __|______\\___ \\ / _ \\/ _` |  _/ _` | | | | | __|",
"    | |  | | | | | |  __/ (_| | (_| |       \\  /\\  / (_| | |  \\__ \\      ____) |  __/ (_| | || (_| | |_| | | |_ ",
"    |_|  |_| |_|_|  \\___|\\__,_|\\__,_|        \\/  \\/ \\__,_|_|  |___/     |_____/ \\___|\\__, |_| \\__,_|\\__,_|_|\\__|",
"                                                                                      __/ |                     ",
"                                                                                     |___/                      "
};

static int *b = NULL;
static int width;
static int height;
static int size;

static void sizechanged()
{
	getmaxyx(stdscr, height, width);
	size = width * height;
	b = (int *)realloc(b, (size + width + 1) * sizeof(int));
	memset(b, 0, (size + width + 1) * sizeof(int));
	clear();
}

void* menu_over_fire(void * args){
  (void) args;
	initscr();
  noecho(); // no ghost characters
  cbreak(); // faster response
  keypad(stdscr, TRUE);

	const char *charz[] = {" ", ".", ":", "^", "*", "x", "s", "S", "#", "$"};

	curs_set(0); // blinking cursor turn off 
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);

  init_pair(5, COLOR_WHITE, COLOR_BLACK); // for text

	sizechanged();

  int selected_option = 0; // 0 - START, 1 - EXIT
  int menu_active = 1;
  int choice = -1;


	while (1)
	{
		for (int i = 0; i < width / 9; i++)
			b[(rand() % width) + width * (height - 1)] = 65;
		for (int i = 0; i < size; i++)
		{
			b[i] = (b[i] + b[i + 1] + b[i + width] + b[i + width + 1]) / 4;
			int color = ((b[i] > 15) ? 4 : ((b[i] > 9) ? 3 : ((b[i] > 4) ? 2 : 1)));
			if (i < size - 1)
			{
				attrset(COLOR_PAIR(color) | A_BOLD);
				move(i / width, i % width);
				addstr(charz[((b[i] > 9) ? 9 : b[i])]);
			}
		}

    int art_lines = 8;
    int art_width = 106;
    int start_y = (height / 2) - (art_lines / 2) - 5; // Moving just a bit higher
    int start_x = (width / 2) - (art_width / 2);

    attrset(COLOR_PAIR(2) | A_BOLD);
    for (int i = 0; i < art_lines; i++){
      if(start_x >= 0 && start_y + i >= 0 && start_y + i < height) {
        mvaddstr(start_y + i, start_x, gamename[i]);
      }
    }

    attrset(COLOR_PAIR(5) | A_BOLD);

    mvprintw(height / 2 + 2, width /2 - 8, "%s START GAME",  (selected_option == 0) ? ">>" : "  ");
    mvprintw(height / 2 + 4, width / 2 - 8, "%s EXIT", (selected_option == 1) ? ">>" : "  ");

		refresh();
		timeout(30);
		int ch = getch();

    if (ch == KEY_RESIZE) {
        sizechanged();
    } else if (ch == KEY_UP || ch == 'w') {
        selected_option = 0;
    } else if (ch == KEY_DOWN || ch == 's') {
        selected_option = 1;
    } else if (ch == '\n') {
        choice = selected_option;
        break; 
    }
  }

	endwin(); // closing ncurses
	return (void*)(long)choice;
}