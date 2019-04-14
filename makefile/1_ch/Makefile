CFLAGS=-g -Wall
TARGETS=output

$(TARGETS): source.c
	gcc $< $(CFLAGS) -o $@

%.gz: %
	gzip $<

helloWorld:
	echo hello world

clean:
	rm $(TARGETS) *.gz
