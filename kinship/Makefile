INC = -I ./headers/
FLAG = -g -Wall -Wextra -std=c++17 

executable: parentesco.o person.o date.o familytree.o
	g++ $(FLAG) -o parentesco.out parentesco.o person.o date.o familytree.o

parentesco.o: parentesco.cpp headers/person.h headers/date.h headers/familytree.h
	g++ $(FLAG) $(INC) -c parentesco.cpp

familytree.o: familytree.cpp headers/familytree.h person.o
	g++ $(FLAG) $(INC) -c familytree.cpp

person.o: person.cpp headers/person.h headers/date.h
	g++ $(FLAG) $(INC) -c person.cpp 

date.o: headers/date.h
	g++ $(FLAG) $(INC) -c date.cpp

clear:
	$(RM) *.o
