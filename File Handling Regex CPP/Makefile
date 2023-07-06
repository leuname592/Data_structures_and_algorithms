TARGET  = $(BIN_DIR)/employee.exe
OBJS    = $(OBJ_DIR)/class_implementation.o $(OBJ_DIR)/function_implementation.o $(OBJ_DIR)/main.o
BIN_DIR = bin
INCDIR  = inc
SRC_DIR = src
OBJ_DIR = obj
HTML_DIR = html
CFLAGS  = -Wall -I$(INCDIR)

$(TARGET) : $(OBJS)
	@mkdir -p $(BIN_DIR) 
	@g++ $(CFLAGS) $(OBJS) -o $(TARGET)
	@./bin/employee.exe
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@g++ -c -MD $(CFLAGS) $< -o $@

-include $(OBJ_DIR)/*.d

#Crear Doxy doc
ifeq ($(OS),Windows_NT)
	DOXYGEN = doxygen.exe
else
	DOXYGEN = doxygen
endif

.PHONY: doc
doc:
	$(DOXYGEN) Doxyfile
	xdg-open $(HTML_DIR)/index.html

.PHONY: clean
clean: 
	@rm -rf $(BIN_DIR) $(OBJ_DIR) $(HTML_DIR) latex *.bak
