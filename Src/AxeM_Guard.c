#include <stdio.h>
#include <stdlib.h>
#include "../Include/AxeM_Guard.h"

typedef struct {
    void* address;     
    size_t size;       
    const char* file;  
    int line;          
} MemoryEntry;

MemoryEntry book[100];
int entry_count = 0;

// Спокойно вызываем стандартный malloc внутри нашей функции
void* axem_malloc(size_t size, const char* file, int line) {
    void* ptr = malloc(size); 
    if (ptr != NULL && entry_count < 100) {
        book[entry_count].address = ptr;
        book[entry_count].size = size;
        book[entry_count].file = file;
        book[entry_count].line = line;
        entry_count++; 
    }
    return ptr;
}

// Спокойно вызываем стандартный free
void axem_free(void* ptr) {
    if (ptr == NULL) return;

    for (int i = 0; i < entry_count; i++) {
        if (book[i].address == ptr) {
            book[i].address = NULL; 
            break;
        }
    }
    free(ptr); 
}

void check_leaks() {
    printf("\n--- [AxeMGuard] Checking memory leaks... ---\n");
    int leaks_found = 0;

    for (int i = 0; i < entry_count; i++) {
        if (book[i].address != NULL) {
            printf("[LEAK DETECTED] %zu bytes at %p (File: %s, Line: %d)\n",
                   book[i].size, book[i].address, book[i].file, book[i].line);
            leaks_found++;
        }
    }

    if (leaks_found == 0) {
        printf("[SUCCESS] Perfect! No leaks. Your code is clean.\n");
    } else {
        printf("[WARNING] Total leaks found: %d\n", leaks_found);
    }
}