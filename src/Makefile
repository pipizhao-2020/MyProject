INC_DIR = ../include
SRC_DIR = ./
OBJ_DIR = ../obj
BIN_DIR = ../bin
OBJS = $(OBJ_DIR)/main.o ${OBJ_DIR}/logic.o
TARGET = $(BIN_DIR)/main
INC_OPT = -I$(INC_DIR)
LNK_OPT = -lpthread -std=c++11

$(TARGET) : chkobjdir chkbindir $(OBJS)
	$(CXX) -o $@ $(OBJS) ${LNK_OPT}

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(INC_OPT) -c -o $@ $< ${LNK_OPT}

chkobjdir :
	@if test ! -d $(OBJ_DIR) ; \
	then \
		mkdir $(OBJ_DIR) ; \
	fi

chkbindir :
	@if test ! -d $(BIN_DIR) ; \
	then \
		mkdir $(BIN_DIR) ; \
	fi

.PHONY : clean
clean :
	-rm -f $(TARGET)
	-rm -rf $(OBJ_DIR)