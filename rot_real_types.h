#ifndef ROT_REAL_TYPES_H
#define ROT_REAL_TYPES_H

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

// Tipos
typedef uint64_t kairos_t;
typedef uint64_t entropy_seed_t;
typedef uint32_t agent_id_t;
typedef uint8_t  domain_id_t;

typedef enum RealityState { ORDER = 0x0A, CHAOS = 0x0C, SUPERPOSITION = 0xFF } RealityState;
typedef enum LogLevel { LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_LATENT } LogLevel;

// Status codes
#define ROT_STATUS_OK             0
#define ROT_STATUS_LATENT         1
#define ROT_STATUS_LOAD_FAIL     -1
#define ROT_STATUS_INIT_FAIL     -2
#define ROT_STATUS_ATTACH_FAIL   -3
#define ROT_STATUS_ATTACHED       2
#define ROT_STATUS_SUSPENDED      3

// Funções de log
void kernel_log(LogLevel level, const char *fmt, ...);

// Stack / cache
kairos_t future_stack_peek(void);
kairos_t past_cache_peek(void);

// Protocolos (já implementados no kernel, só precisamos das declarações)
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

// Scheduler
int kairophylax_load(void);
void kairophylax_schedule(void);
RealityState next_reality_state(entropy_seed_t seed);
kairos_t FOURTH_DIMENSION(void);

// Funções ausentes (antes eram static sem definição)
bool neural_link_detect(const char *signature);
void neural_link_bind_bidirectional(const char *creator_sig, const char *true_name);
entropy_seed_t entropy_harvest(void);
kairos_t kairos_now(void);

// Corrige parâmetro 'new'
#define new new_state

/* ---------- Geometria E8 (Seção 17) ---------- */
#define E8_ROOT_COUNT 240
#define E8_DIMENSION  8

typedef struct E8RootVector {
    double coord[E8_DIMENSION];
} E8RootVector;

extern E8RootVector E8_ROOT_SYSTEM[E8_ROOT_COUNT];
extern bool e8_lattice_initialized;

void e8_lattice_init(void);


#endif