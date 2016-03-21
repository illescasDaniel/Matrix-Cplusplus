all: clean objects
	@mkdir bin
	@g++ obj/main.o obj/matrix.o -o bin/program
	@rm -rf obj
	@printf "\nCompiled succesfully!\n\n"

objects:
	@mkdir obj
	@g++ -c main.cpp -I include -o obj/main.o
	@g++ -c -std=c++11 src/matrix.cpp -I include -o obj/matrix.o
	
clean:
	@rm -rf bin
	@rm -rf obj

#Quick compilation: g++ main.cpp src/matrix.cpp -I include