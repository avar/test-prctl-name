all:
	gcc -ggdb3 -O0 -Wall prctl.c -o prctl

clean:
	rm prctl
