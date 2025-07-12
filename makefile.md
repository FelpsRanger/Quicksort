# Makefile para compilação dos códigos do Quicksort
# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
DEBUG_FLAGS = -g -DDEBUG

# Nomes dos executáveis
EXEC_TESTS = quicksort_tests
EXEC_COMP = quicksort_comparacao

# Arquivos fonte
SRC_TESTS = quicksort_tests.c
SRC_COMP = quicksort_comparacao.c

# Regra padrão
all: $(EXEC_TESTS) $(EXEC_COMP)

# Compilar programa de testes
$(EXEC_TESTS): $(SRC_TESTS)
	$(CC) $(CFLAGS) -o $(EXEC_TESTS) $(SRC_TESTS) -lm

# Compilar programa de comparação
$(EXEC_COMP): $(SRC_COMP)
	$(CC) $(CFLAGS) -o $(EXEC_COMP) $(SRC_COMP) -lm

# Versões debug
debug: $(EXEC_TESTS)_debug $(EXEC_COMP)_debug

$(EXEC
