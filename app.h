#ifndef __HAVE_APP_H
#define __HAVE_APP_H 1
#include <vector>
#include <cmath>
#include <FL/fl_ask.H>

const int MAX_ZRODEL = 7;

extern Fl_Font PL_Font;

using namespace std;

class wektor {
	public:
		double x;
		double y;
		wektor() : x(0), y(0) { }
		wektor operator+= (const wektor & W2) {
			wektor ret;
			x += W2.x;
			y += W2.y;
		}
};

class Zrodlo_t {

	bool _wlaczone;

	public:

		double x;
		double y;
		double q;

		Zrodlo_t(double _x = 0, double _y = 0, double _q = 0, bool on = false)
			: x(_x), y(_y), q(_q), _wlaczone(on) {}

		bool wlaczone() {
			return _wlaczone;
		}
		void wlacz() {
			_wlaczone = true;
		}
		void wylacz() {
			_wlaczone = false;
		}

		/*
		 * funkcja zwraca wektor linii pola (d³ugo¶æ jest nieprawid³owa).
		 * Chodzi tylko o kieruneki zwrot.
		 */
		wektor Natezenie(double x1, double y1) const {
			wektor ret;
			double r = hypot(x1 - x, y1 - y);

			if (r) {
				ret.x = q * (x1 - x) / r / r;
				ret.y = q * (y1 - y) / r / r;
			} else {
				ret.x = 0;
				ret.y = 0;
			}

			return ret;
		}

};

class App {

	public:
		vector <Zrodlo_t> Zrodla;
		double skala;
		double gestosc;
	
	App() {
		Zrodla.resize(MAX_ZRODEL);
		skala = 11;
		gestosc = 0.7;
	}

};

extern App App1;

#endif

