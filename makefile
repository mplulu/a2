#############################################################################
# COSC2541 - Programming Techniques
# Semester 2 2011 Assignment #2
# Full Name        : EDIT HERE
# Student Number   : EDIT HERE
# Start up code provided by Christopher Hoobin, Xiaodong Li and Quang Tran
#############################################################################

# Delete this comment and insert your code here.
# Delete this comment and insert your code here.
gjc: gjc.o gjc_options.o gjc_utility.o
	gcc -ansi -Wall -pedantic -o gjc gjc.o gjc_options.o gjc_utility.o
gjc.o: gjc.h gjc.c
	gcc -ansi -Wall -pedantic -c gjc.h gjc.c
gjc_utility.o: gjc.h gjc_utility.c
	gcc -ansi -Wall -pedantic -c gjc.h gjc_utility.c
gjc_options.o: gjc.h gjc_options.c
	gcc -ansi -Wall -pedantic -c gjc.h gjc_options.c

archive:
	zip s3269900-a2.zip gjc.c gjc.h gjc_options.c gjc_utility.c makefile README.txt

clean:
	rm -f *.o gjc

