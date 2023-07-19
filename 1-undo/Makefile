all:
	gcc -std=c11 -g -Wall -I../include ../include/transcript.c src/*.c -o ./mysolution -lm
clean:
	rm ./mysolution
	@echo Cleanup complete!
run: all
	./mysolution ../data/test.txt
test:
	python ../scripts/sanitycheck.py 
	