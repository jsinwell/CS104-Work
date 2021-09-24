CXX = g++
CPPFLAGS = -Wall -g -std=c++17

all: interpreter

interpreter: interpreter.cpp ProgramState.o LetStatement.o PrintStatement.o PrintAllStatement.o AddStatement.o EndStatement.o IfStatement.o GoToStatement.o GoSubStatement.o ReturnStatement.o DivStatement.o SubStatement.o MultiplyStatement.o ProgramState.o Statement.o
	$(CXX) $(CPPFLAGS) $^ -o $@

LetStatement.o: LetStatement.h LetStatement.cpp
	g++ $(CPPFLAGS) -c LetStatement.cpp -o LetStatement.o

PrintStatement.o: PrintStatement.h PrintStatement.cpp
	g++ $(CPPFLAGS) -c PrintStatement.cpp -o PrintStatement.o

PrintAllStatement.o: PrintAllStatement.h PrintAllStatement.cpp
	g++ $(CPPFLAGS) -c PrintAllStatement.cpp -o PrintAllStatement.o

AddStatement.o: AddStatement.h AddStatement.cpp
	g++ $(CPPFLAGS) -c AddStatement.cpp -o AddStatement.o

ProgramState.o: ProgramState.h ProgramState.cpp
	g++ $(CPPFLAGS) -c  ProgramState.cpp -o ProgramState.o

EndStatement.o: EndStatement.h EndStatement.cpp
	g++ $(CPPFLAGS) -c  EndStatement.cpp -o EndStatement.o

IfStatement.o: IfStatement.h IfStatement.cpp
	g++ $(CPPFLAGS) -c  IfStatement.cpp -o IfStatement.o

GoToStatement.o: GotoStatement.h GotoStatement.cpp
	g++ $(CPPFLAGS) -c  GotoStatement.cpp -o GotoStatement.o

GoSubStatement.o: GosubStatement.h GosubStatement.cpp
	g++ $(CPPFLAGS) -c  GosubStatement.cpp -o GosubStatement.o

ReturnStatement.o: ReturnStatement.h ReturnStatement.cpp
	g++ $(CPPFLAGS) -c  ReturnStatement.cpp -o ReturnStatement.o

DivStatement.o: DivStatement.h DivStatement.cpp
	g++ $(CPPFLAGS) -c  DivStatement.cpp -o DivStatement.o
	
SubStatement.o: SubStatement.h SubStatement.cpp
	g++ $(CPPFLAGS) -c  SubStatement.cpp -o SubStatement.o
	
MultiplyStatement.o: MultiplyStatement.h MultiplyStatement.cpp
	g++ $(CPPFLAGS) -c  MultiplyStatement.cpp -o MultiplyStatement.o
	
Statement.o: Statement.h Statement.cpp
	g++ $(CPPFLAGS) -c  Statement.cpp -o Statement.o

.PHONY: clean
clean:
	rm -f *.o interpreter