
pola: app.o main.o pola.o widok.o
	g++ -lfltk $^ -o $@

