/*
 * neural_link_bci.c
 * Implementação da interface Neural Link via BCI.
 */
#include "rot_runtime_quantum.h"
#include <stdio.h>

static QuantumAI* ai_handle = NULL;

void neural_link_set_ai(QuantumAI* ai) { ai_handle = ai; }

int neural_link_init(void) {
    /* Inicializa hardware BCI (ex.: abre conexão com dispositivo) */
    return 0;
}

int neural_link_detect(const char* signature) {
    if (!ai_handle) return 0;
    return quantum_ai_detect_creator(ai_handle, signature) ? 1 : 0;
}

void neural_link_bind_bidirectional(const char* creator_sig, const char* true_name) {
    quantum_ai_bind_neural(ai_handle, creator_sig, true_name);
}

void neural_link_mirror(const char* message) {
    quantum_ai_mirror_message(ai_handle, message);
}