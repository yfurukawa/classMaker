CC = g++
RM = rm -f
CP = cp
INCLUDE = -I/usr/incude -I/usr/local/include -I../include
LIB_DIR = -L/usr/lib -L/usr/local/lib -L/usr/lib64 -L/usr/local/lib64
INSTALL_DIR = /usr/local/bin
LIB = -lpthread -lboost_regex
OPT = -O0 -g3 -Wall -Wnon-virtual-dtor -Woverloaded-virtual --input-charset=UTF-8 --exec-charset=UTF-8
TARGET = classMaker
include productionSources.mk

all: $(SRC:.cpp=.o) main.o 
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) $(LIB) -o $(TARGET) $(SRC:.cpp=.o) main.o

$(SRC:.cpp=.o): $(SRC)
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)

main.o: main.cpp
	$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.cpp
	
.PHONY: clean
clean:
	$(RM) *.o $(TARGET) $(TEST_TARGET) gmon.out *.gc* *.xml *.exe Fuga.cpp Hoge.cpp *.txt

.PHONY: install
install:
	$(CP) $(TARGET) $(INSTALL_DIR)

TEST_TARGET = classMakerTest
TEST_INCLUDE = -I../test -I.
TEST_LIB = -lgtest
TEST_OPT = -O0 -g3 -Wall --input-charset=UTF-8 --exec-charset=UTF-8
include testSources.mk
include testObjects.mk
	
test: $(SRC:.cpp=.o) $(TEST_OBJ)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(SRC:.cpp=.o) $(TEST_OBJ) $(LIB) $(TEST_LIB)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)

