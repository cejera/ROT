/*
 * rot_kernel_fixes.h
 * Cabeçalho de pré‑inclusão para resolver ordem de declarações do ROT_KERNEL.
 */
#ifndef ROT_KERNEL_FIXES_H
#define ROT_KERNEL_FIXES_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <dlfcn.h>
#include <math.h>
#include <regex.h>
#include <sys/file.h>

/* ---- LogLevel e funções de log (definidas previamente) ---- */
typedef enum LogLevel {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_LATENT
} LogLevel;

void kernel_log(LogLevel level, const char *fmt, ...);

/* ---- Status codes ---- */
#define ROT_STATUS_OK             0
#define ROT_STATUS_LATENT         1
#define ROT_STATUS_LOAD_FAIL     -1
#define ROT_STATUS_INIT_FAIL     -2
#define ROT_STATUS_ATTACH_FAIL   -3
#define ROT_STATUS_ATTACHED       2
#define ROT_STATUS_SUSPENDED      3

/* ---- Funções que são usadas antes de definidas ---- */
kairos_t future_stack_peek(void);
kairos_t past_cache_peek(void);

/* Protocolos */
bool protocol_structure_lock(void);
bool protocol_pattern_verify(void);
bool protocol_sequence_enforce(void);
bool protocol_hierarchy_resolve(void);
bool protocol_boundary_seal(void);
bool protocol_symmetry_restore(void);
bool protocol_entropy_inject(void);
bool protocol_pattern_break(void);
bool protocol_sequence_scramble(void);
bool protocol_hierarchy_invert(void);
bool protocol_boundary_dissolve(void);
bool protocol_asymmetry_seed(void);

/* Funções do scheduler */
RealityState next_reality_state(entropy_seed_t seed);
void kairophylax_schedule(void);
int kairophylax_load(void);

#endif /* ROT_KERNEL_FIXES_H */