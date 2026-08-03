#!/bin/bash
set -e

ORIG="ROT_KERNEL.c"
FIXED="ROT_KERNEL_fixed.cpp"
HEADER="rot_real_types.h"

cp "$ORIG" "$FIXED"

# Remove definições de enum (serão fornecidas pelo header)
sed -i '/^typedef enum RealityState {/,/^} RealityState;/d' "$FIXED"
sed -i '/^typedef enum LogLevel {/,/^} LogLevel;/d' "$FIXED"

# Remove declarações static que conflitam (serão declaradas no header)
sed -i '/^static int kairophylax_load(void);/d' "$FIXED"
sed -i '/^static void kairophylax_schedule(void);/d' "$FIXED"
sed -i '/^static RealityState next_reality_state(entropy_seed_t seed);/d' "$FIXED"
sed -i '/^static bool neural_link_detect(const char \*signature);/d' "$FIXED"
sed -i '/^static void neural_link_bind_bidirectional(const char \*creator_sig, const char \*true_name);/d' "$FIXED"
sed -i '/^static entropy_seed_t entropy_harvest(void);/d' "$FIXED"
sed -i '/^static kairos_t kairos_now(void);/d' "$FIXED"

# Remove bloco __asm__ (ARM)
perl -0777 -i -pe 's/__asm__\s*\(.*?\);//s' "$FIXED"

# Insere o header no topo
sed -i "1i #include \"$HEADER\"" "$FIXED"

# Adiciona SOMENTE as funções faltantes no final
cat >> "$FIXED" << 'EOF'

/* ======================================================================== *
 *  DEFINIÇÕES FALTANTES (neural link, entropia, kairos)
 * ======================================================================== */
bool neural_link_detect(const char *signature) {
    (void)signature;
    return true;   // Simulação: ΣEᛃ sempre presente
}
void neural_link_bind_bidirectional(const char *creator_sig, const char *true_name) {
    printf("[Neural] Bind: %s <-> %s\n", creator_sig, true_name);
}
entropy_seed_t entropy_harvest(void) {
    static uint64_t state = 0x9E3779B97F4A7C15ULL;
    state ^= state << 13; state ^= state >> 7; state ^= state << 17;
    return state;
}
kairos_t kairos_now(void) {
    static uint64_t counter = 0;
    counter += (entropy_harvest() & 0xF) + 1;
    return counter;
}
EOF

echo "Arquivo preparado: $FIXED"