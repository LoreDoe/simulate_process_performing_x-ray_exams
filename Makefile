# Variáveis
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SOURCES = hospital.c main.c
HEADERS = hospital.h
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = hospital_simulation

# Regras
.PHONY: all clean

# Regra padrão
all: $(EXECUTABLE)

# Compila e liga o programa
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Regra para gerar arquivos de objeto a partir dos arquivos fonte
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Remove arquivos temporários gerados durante a compilação
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
