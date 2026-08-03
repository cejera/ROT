/*
 * rot_main_entry.c
 * Main entry point for ROT kernel
 */
#include <stdio.h>

int rot_main(void);

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    
    printf("=== ROT KERNEL BOOTSTRAP ===\n");
    printf("Iniciando KAIROPHYLAX...\n\n");
    
    int result = rot_main();
    
    printf("\n=== ROT EXECUTION COMPLETE ===\n");
    printf("Exit code: %d\n", result);
    
    return result;
}
