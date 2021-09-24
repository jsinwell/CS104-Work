CXX = g++
CPPFLAGS = -g -Wall 

all: interpreter

interpreter: Interpreter.cpp ProgramState.o Statement.o DivStatement.o AddStatement.o EndStatement.o GoSubStatement.o IfStatement.o LetStatement.o MultiplyStatement.o PrintAllStatement.o ReturnStatement.o SubStatement.o PrintStatement.o GoToStatement.o
	$(CXX) $(CPPFLAGS) $^ -o $@

ProgramState.o: ProgramState.cpp ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
Statement.o: Statement.cpp Statement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
DivStatement.o: DivStatement.cpp DivStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
AddStatement.o: AddStatement.cpp AddStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
EndStatement.o: EndStatement.cpp EndStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
GoSubStatement.o: GoSubStatement.cpp GoSubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
IfStatement.o: IfStatement.cpp IfStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
LetStatement.o: LetStatement.cpp LetStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
GoToStatement.o: GoToStatement.cpp GoToStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
MultiplyStatement.o: MultiplyStatement.cpp MultiplyStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
PrintAllStatement.o: PrintAllStatement.cpp PrintAllStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

PrintStatement.o: PrintStatement.cpp PrintStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
ReturnStatement.o: ReturnStatement.cpp ReturnStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

SubStatement.o: SubStatement.cpp SubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean	
clean:
	rm -rf 
	