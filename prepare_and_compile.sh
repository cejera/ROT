#!/bin/bash

# Script para preparar o ROT_KERNEL.c sem modificá-lo permanentemente
# e compilar o sistema.

set -e

KERNEL_ORIG="ROT_KERNEL.c"
KERNEL_TMP="ROT_KERNEL_prepared.cpp"

# 1. Copiar o original para um temporário
cp "$KERNEL_ORIG" "$KERNEL_TMP"

# 2. Corrigir o parâmetro 'new' (apenas se ainda não foi corrigido)
sed -i 's/RealityState new)/RealityState new_state)/g' "$KERNEL_TMP"
sed -i 's/old,new)/old,new_state)/g' "$KERNEL_TMP"

# 3. Remover as declarações static conflitantes (linhas exatas podem variar,
#    vamos remover as linhas que contêm essas declarações)
sed -i '/^static int kairophylax_load(void);/d' "$KERNEL_TMP"
sed -i '/^static void kairophylax_schedule(void);/d' "$KERNEL_TMP"
sed -i '/^static RealityState next_reality_state(entropy_seed_t seed);/d' "$KERNEL_TMP"

# 4. Compilar tudo
g++ -std=c++11 -pthread -o rot_kernel \
    -include rot_types.h \
    "$KERNEL_TMP" \
    rot_missing_defs.cpp \
    -ldl

# 5. Opcional: remover o temporário
# rm "$KERNEL_TMP"

echo "Compilação concluída. Execute ./rot_kernel"