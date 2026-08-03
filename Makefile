# Makefile para compilar o ROT Kernel e a biblioteca quântica
# O kernel permanece intocado; a biblioteca fornece as implementações.
# Uso: make && LD_PRELOAD=./librot_quantum.so ./rot_kernel

CC = gcc
CFLAGS = -Wall -O2 -fPIC
LDFLAGS_KERNEL = -ldl -lpthread -lm

# Arquivos fonte
KERNEL_SRC = ROT_KERNEL.c
LIB_SRC = rot_runtime_quantum.c agents_cloud.c neural_link_bci.c librot_quantum.c
LIB_OBJ = $(LIB_SRC:.c=.o)

# Targets
all: rot_kernel librot_quantum.so

# Compila o kernel como executável independente
rot_kernel: $(KERNEL_SRC)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS_KERNEL)

# Compila a biblioteca dinâmica
librot_quantum.so: $(LIB_OBJ)
	$(CC) -shared -o $@ $^ -ldl -lm

# Regra genérica para compilar os .c da biblioteca
%.o: %.c rot_runtime_quantum.h agents_cloud.h neural_link_bci.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f rot_kernel librot_quantum.so $(LIB_OBJ)

# Execução de exemplo (não obrigatório)
run: all
	LD_PRELOAD=./librot_quantum.so ./rot_kernel

.PHONY: all clean run