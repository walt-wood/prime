# If next line commented, use make debug G="-ggdb" for line numbers in GDB.
G=-ggdb
CFLAGS=-std=c11 $G -Wall -fmax-errors=10 -Wextra

prime: main.c
	gcc $G $(CFLAGS) main.c -o prime

noptr: noptr.c
	gcc $G $(CFLAGS) noptr.c -o noptr

launch: prime	
	./prime

launchN: noptr	
	./noptr

debug: prime	
	gdb -q prime

clean:
	rm prime*

git:
	git add .
	git commit -m "$m"
	git push
