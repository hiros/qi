#include "qi_common.h"
#include "curses.h"

int qiInitCurses(WINDOW **win)
{
	setenv("TERM", "xterm-256color", 1);

	*win = initscr();
	start_color();

	if (!can_change_color()) {
		refresh();
		return QI_ERR_INIT_CURSES;
	};

	return QI_OK;
}

void qiTermCurses(void)
{
	endwin();
}

int qiDisableEcho(void)
{
	noecho();
	return QI_OK;
}

void qiDraw256colors(void)
{
	int16_t i, j;
	static const char *fmt = " %03d ";

	for (i = 0, j = 0; i < 256; i++, j++) {
		if (i % 16 == 0) {
			printw("\n");
		}
		init_pair(j, 0, i);
		attron(COLOR_PAIR(j));
		printw(fmt, i);
	}
	refresh();
}

