PROJ=makePNG

$(PROJ): pngexample2.c
	gcc -Wall -std=c99 -o $@ pngexample2.c -L. -lpng
clean:
	rm $(PROJ) output.png
