/*
 * rot_missing_defs.cpp
 * Implementações para funções declaradas mas não definidas no ROT_KERNEL.
 */
#include "rot_types.h"

// Essas funções eram static no kernel; agora serão globais.
int kairophylax_load(void) {
    return 0;   // carregamento simbólico bem-sucedido
}

void kairophylax_schedule(void) {
    // O scheduler real está em ΚΑΙΡΟΦΥΛΑΞ::schedule()
}

RealityState next_reality_state(entropy_seed_t seed); // já definida no namespace
// Não precisamos redefinir next_reality_state, pois a definição no namespace serve.