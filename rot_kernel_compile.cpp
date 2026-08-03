/*
 * rot_kernel_compile.cpp
 * Wrapper para compilar ROT_KERNEL.c sem modificar sua estrutura.
 * Inclui as correções de ordem e definições ausentes.
 */
#include "rot_kernel_fixes.h"

/* Incluir o código do kernel como texto. 
   (Renomeie ROT_KERNEL.c para ROT_KERNEL.inc se preferir,
   mas podemos simplesmente forçar a inclusão de um .c)
*/
#include "ROT_KERNEL.c"