/* win32_stubs.c — adaptações para compilar ROT_KERNEL no Windows */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

/* getentropy: emulação simples usando rand() */
int getentropy(void *buf, size_t buflen) {
    unsigned char *p = (unsigned char *)buf;
    for (size_t i = 0; i < buflen; i++)
        p[i] = (unsigned char)(rand() & 0xFF);
    return 0;
}

/* flock: emulação usando LockFileEx */
#define LOCK_EX 2
#define LOCK_NB 4
int flock(int fd, int operation) {
    HANDLE h = (HANDLE)_get_osfhandle(fd);
    if (h == INVALID_HANDLE_VALUE) return -1;
    DWORD flags = (operation & LOCK_EX) ? LOCKFILE_EXCLUSIVE_LOCK : 0;
    if (operation & LOCK_NB) flags |= LOCKFILE_FAIL_IMMEDIATELY;
    OVERLAPPED ov = {0};
    return LockFileEx(h, flags, 0, 1, 0, &ov) ? 0 : -1;
}

/* unlink: redireciona para _unlink */
int unlink(const char *path) {
    return _unlink(path);
}

/* regcomp / regexec / regfree: stubs que sempre retornam sucesso */
#include <regex.h>
int regcomp(regex_t *preg, const char *regex, int cflags) {
    (void)preg; (void)regex; (void)cflags;
    return 0;
}
int regexec(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags) {
    (void)preg; (void)string; (void)nmatch; (void)pmatch; (void)eflags;
    return 0; /* sempre match */
}
void regfree(regex_t *preg) {
    (void)preg;
}