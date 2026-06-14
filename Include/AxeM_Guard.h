#ifndef AXEM_GUARD_H
#define AXEM_GUARD_H

#include <stddef.h>

// Чистые, уникальные имена функций. Никакой путаницы для компилятора!
void* axem_malloc(size_t size, const char* file, int line);
void axem_free(void* ptr);
void check_leaks();

#endif // AXEM_GUARD_H