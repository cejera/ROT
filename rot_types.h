/*
 * rot_types.h
 * Tipos fundamentais extraídos do ROT_KERNEL para uso antecipado.
 */
#ifndef ROT_TYPES_H
#define ROT_TYPES_H

#include <stdint.h>

typedef uint64_t kairos_t;
typedef uint64_t entropy_seed_t;
typedef uint32_t agent_id_t;
typedef uint8_t  domain_id_t;

typedef enum RealityState {
    ORDER        = 0x0A,
    CHAOS        = 0x0C,
    SUPERPOSITION = 0xFF
} RealityState;

#endif