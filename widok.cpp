#include <cstdio>
#include <cstdlib>
#include "pola.h"
#include <FL/fl_draw.H>
#include "app.h"
#include <vector>
#include <cmath>

using namespace std;

Widok_t::Widok_t(int x, int y, int w, int h, const char *label ) : Fl_Box(x, y, w, h, label)
{
	return;
}

const double dlugosc_strzalki = 0.5;

Fl_Color color_Linie_Pola = fl_rgb_color(0xBB, 0xBB, 0xBB);
Fl_Color color_Zrodlo_Dodatnie = fl_rgb_color(0xFF, 0x88, 0x88);
Fl_Color color_Zrodlo_Ujemne = fl_rgb_color(0x88, 0x88, 0xFF);

void
Widok_t::draw()
{
	fl_color(FL_BLACK);
	fl_rectf(1, 1, w(), h());

	fl_push_matrix();
	fl_mult_matrix(1, 0, 0, -1, w() / 2, h() / 2);
	fl_scale(w() / 2 / App1.skala, h() / 2 / App1.skala);

	fl_color(FL_YELLOW);

	for (unsigned n = 0; n < App1.Zrodla.size(); n++) {
		if (App1.Zrodla[n].wlaczone()) {
			if (App1.Zrodla[n].q > 0) {
				fl_color(color_Zrodlo_Dodatnie);
				fl_begin_complex_polygon();
				fl_circle(App1.Zrodla[n].x, App1.Zrodla[n].y, 0.25);
				fl_end_complex_polygon();

				fl_color(FL_WHITE);
				fl_begin_line();
					fl_vertex(App1.Zrodla[n].x - .2, App1.Zrodla[n].y);
					fl_vertex(App1.Zrodla[n].x + .2, App1.Zrodla[n].y);
				fl_end_line();
				fl_begin_line();
					fl_vertex(App1.Zrodla[n].x, App1.Zrodla[n].y - .2);
					fl_vertex(App1.Zrodla[n].x, App1.Zrodla[n].y + .2);
				fl_end_line();
			}
			else {
				fl_color(color_Zrodlo_Ujemne);
				fl_begin_complex_polygon();
				fl_circle(App1.Zrodla[n].x, App1.Zrodla[n].y, 0.25);
				fl_end_complex_polygon();

				fl_color(FL_WHITE);
				fl_begin_line();
					fl_vertex(App1.Zrodla[n].x - .2, App1.Zrodla[n].y);
					fl_vertex(App1.Zrodla[n].x + .2, App1.Zrodla[n].y);
				fl_end_line();
			}
		}
	}

	vector <const Zrodlo_t *> Aktywne;
	Aktywne.reserve(MAX_ZRODEL);
	for (unsigned n = 0; n < App1.Zrodla.size(); n++)
		if (App1.Zrodla[n].wlaczone())
			Aktywne.push_back(&App1.Zrodla[n]);

	double dlugosc = .5 / .7 * App1.gestosc;

	if (Aktywne.size() > 0) {
		wektor W1;
		double l, lx, ly;
		fl_color(color_Linie_Pola);
		for (float y = App1.skala; y >= -App1.skala; y -= App1.gestosc)
			for (float x = -App1.skala; x <= App1.skala; x += App1.gestosc) {
				W1.x = 0;
				W1.y = 0;
				for (unsigned n = 0; n < Aktywne.size(); n++)
					W1 += Aktywne[n]->Natezenie(x, y);

				if (W1.x || W1.y) {
					l = dlugosc / hypot(W1.x, W1.y);
					lx = W1.x * l;
					ly = W1.y * l;
				} else {
					lx = 0;
					ly = 0;
				}

				fl_begin_line();
				fl_vertex(x, y);
				fl_vertex(x + lx, y + ly);
				fl_end_line();
			}

	}

	fl_pop_matrix();

}


