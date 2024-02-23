INCLUDE = include
BUILD   = build
BINNAME = main
SOURCE = src/main.c src/common.c

# Label que é executada toda vez que não digitamos nada
all: $(BUILD)/$(BINNAME)

# Essa é executada para construir os objetos e o executável elf no final 
$(BUILD)/$(BINNAME): $(SOURCE)
	mkdir $(BUILD)
	$(CC) -g $(SOURCE) -I$(INCLUDE) -o $(BUILD)/$(BINNAME)

clean:
	rm -r $(BUILD)