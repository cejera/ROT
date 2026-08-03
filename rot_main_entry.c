/*
 * rot_main_entry.c
 * Ponto de entrada (main) para o kernel ROT
 */
#include <stdio.h>

/* Forward declaration */
int rot_main(void);

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    
    printf("=== ROT KERNEL BOOTSTRAP ===\n");
    printf("Iniciando ΚAIΡΟΦΥΛΑΞ...\n\n");
    
    int result = rot_main();
    
    printf("\n=== ROT EXECUTION COMPLETE ===\n");
    printf("Exit code: %d\n", result);
    
    return result;
}
