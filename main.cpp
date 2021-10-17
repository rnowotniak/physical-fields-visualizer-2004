#include <cstdio>
#include <cstdlib>
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include "pola.h"

using namespace std;

int main()
{

	PL_Font = FL_FREE_FONT;
	const char *font = "-*-andale mono-*-r-*-*-*-*-*-*-*-*-iso8859-2";

	Fl::set_fonts(font);
	Fl::set_font(PL_Font, font);
	fl_message_font(PL_Font, 14);


	UserInterface();

	return Fl::run();
}

