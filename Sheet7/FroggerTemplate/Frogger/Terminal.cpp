#include "Terminal.h"

#if defined(_WIN32)
#include <curses.h>
#else
#include <ncurses.h>
#endif


Terminal::Terminal(int width, int height)
{
	initscr();
	resize_term(height, width);

	cbreak();
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	timeout(0);
	start_color();
	init_pair(1, 10, 2);
}

int Terminal::width() const
{
	return COLS;
}

int Terminal::height() const
{
	return LINES;
}

void Terminal::set_cell(int x, int y, char symbol, int color)
{
	init_pair(color, color, 0);
	attron(COLOR_PAIR(color));
	mvaddch(y, x, symbol);
	attroff(COLOR_PAIR(color));
}

void Terminal::draw_text(int x, int y, const std::string& text)
{
	mvaddstr(y, x, text.c_str());
}

void Terminal::clear()
{
	::clear();
}

void Terminal::close()
{
	endwin();
	curs_set(1);
}

void Terminal::sleep(int ms)
{
	napms(ms);
}

char Terminal::get_key() const
{
	return wgetch(stdscr);
}
