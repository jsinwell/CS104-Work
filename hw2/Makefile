BIN_DIR = bin
LIB_DIR = lib
SRC_DIR = src
CXX = g++
CPPFLAGS = -Wall -g -I$(LIB_DIR)

all: $(BIN_DIR)/.dirstamp interpreter

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

interpreter: $(SRC_DIR)/interpreter.cpp $(BIN_DIR)/ProgramState.o $(BIN_DIR)/Statement.o $(BIN_DIR)/DivStatement.o $(BIN_DIR)/AddStatement.o $(BIN_DIR)/EndStatement.o $(BIN_DIR)/GoSubStatement.o $(BIN_DIR)/IfStatement.o $(BIN_DIR)/LetStatement.o $(BIN_DIR)/MultiplyStatement.o $(BIN_DIR)/PrintAllStatement.o $(BIN_DIR)/ReturnStatement.o $(BIN_DIR)/SubStatement.o $(BIN_DIR)/PrintStatement.o $(BIN_DIR)/GoToStatement.o
	$(CXX) $(CPPFLAGS) $^ -o $@

$(BIN_DIR)/ProgramState.o: $(SRC_DIR)/ProgramState.cpp $(LIB_DIR)/ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/Statement.o: $(SRC_DIR)/Statement.cpp $(LIB_DIR)/Statement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/DivStatement.o: $(SRC_DIR)/DivStatement.cpp $(LIB_DIR)/DivStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/AddStatement.o: $(SRC_DIR)/AddStatement.cpp $(LIB_DIR)/AddStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/EndStatement.o: $(SRC_DIR)/EndStatement.cpp $(LIB_DIR)/EndStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/GoSubStatement.o: $(SRC_DIR)/GoSubStatement.cpp $(LIB_DIR)/GoSubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/IfStatement.o: $(SRC_DIR)/IfStatement.cpp $(LIB_DIR)/IfStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/LetStatement.o: $(SRC_DIR)/LetStatement.cpp $(LIB_DIR)/LetStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/GoToStatement.o: $(SRC_DIR)/GoToStatement.cpp $(LIB_DIR)/GoToStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/MultiplyStatement.o: $(SRC_DIR)/MultiplyStatement.cpp $(LIB_DIR)/MultiplyStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/PrintAllStatement.o: $(SRC_DIR)/PrintAllStatement.cpp $(LIB_DIR)/PrintAllStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/PrintStatement.o: $(SRC_DIR)/PrintStatement.cpp $(LIB_DIR)/PrintStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
	
$(BIN_DIR)/ReturnStatement.o: $(SRC_DIR)/ReturnStatement.cpp $(LIB_DIR)/ReturnStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/SubStatement.o: $(SRC_DIR)/SubStatement.cpp $(LIB_DIR)/SubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean	
clean:
	rm -rf $(BIN_DIR)