# Makefile para compilar o ROT Kernel (fixed version)
# Branch: ROT-Q
# Uso: make clean && make

CXX = g++
CC = gcc
CXXFLAGS = -std=c++11 -Wall -O2 -fPIC -pthread
CFLAGS = -Wall -O2 -fPIC -pthread
LDFLAGS = -ldl -lpthread -lm

# Arquivos fonte
KERNEL_SRC = ROT_KERNEL_fixed.cpp
SUPPORT_SRCS = kernel_log.c rot_missing_functions.c rot_main_entry.c
SUPPORT_OBJS = $(SUPPORT_SRCS:.c=.o)

# Target final
TARGET = rot_kernel

# Default target
all: $(TARGET)

# Compila o kernel (C++)
$(TARGET): $(KERNEL_SRC) $(SUPPORT_OBJS)
	@echo "[CXX] Compilando kernel..."
	$(CXX) $(CXXFLAGS) $(KERNEL_SRC) $(SUPPORT_OBJS) -o $(TARGET) $(LDFLAGS)
	@echo "[OK] Kernel compilado: $(TARGET)"

# Regra para compilar .c para .o
%.o: %.c
	@echo "[CC] Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(TARGET) $(SUPPORT_OBJS)
	@echo "[OK] Limpeza completa"

# Execucao
run: all
	./$(TARGET)

# Phony targets
.PHONY: all clean run
