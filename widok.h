#ifndef __HAVE_WIDOK_H
#define __HAVE_WIDOK_H 1
#include <cstdio>
#include <cstdlib>

#include <FL/Fl_Box.H>

using namespace std;

class Widok_t : public Fl_Box {

	public:
		Widok_t(int x, int y, int w, int h, const char *label = 0);

	protected:
		void draw();

};

#endif

