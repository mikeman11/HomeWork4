CC=gcc
FLAGS=-Wall -g
AR=ar
#--------------------------------------------------------------

main.o: main.c homework4.h
	$(CC) $(FLAGS) -c main.c

homework4.o:
	$(CC) $(FLAGS) -c  homework4.c

frequency: main.o libhomework4.a 
	$(CC) $(FLAGS) main.o libhomework4.a -o frequency

libhomework4.a: homework4.o
	$(AR) -rcs libhomework4.a homework4.o 

#--------------------------------------------------------------

.PHONY: homework4 main all clean

# Creating static library
homework4s: homework4.o  libhomework4.a

all: frequency 

res : clean all frequency  

clean:
	rm  homework4.o libhomework4.a  main.o frequency 
