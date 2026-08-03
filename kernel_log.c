/*
 * kernel_log.c
 * Implementacao do sistema de logging do kernel ROT
 */
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

#define LOG_LATENT 0
#define LOG_DEBUG  1
#define LOG_INFO   2
#define LOG_WARN   3
#define LOG_ERROR  4

static const char *log_level_names[] = {
    "LATENT",
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR"
};

void kernel_log(int level, const char *fmt, ...) {
    va_list args;
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char timestamp[32];
    
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);
    
    if (level < 0 || level >= 5) level = 2;
    
    fprintf(stderr, "[%s] [%s] ", timestamp, log_level_names[level]);
    
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    
    fprintf(stderr, "\n");
    fflush(stderr);
}

void neural_link_mirror(const char *message) {
    fprintf(stdout, "[NEURAL_MIRROR] %s\n", message);
    fflush(stdout);
}
