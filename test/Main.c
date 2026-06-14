#include <stdio.h>
#include "../Include/AxeM_Guard.h"

// Включаем слежку ТОЛЬКО для файла пользователя
#define malloc(size) axem_malloc(size, __FILE__, __LINE__)
#define free(ptr) axem_free(ptr)

int main() {
    printf("--- Test Program Started ---\n");

    // Этот malloc превратится в axem_malloc автоматически!
    int* my_array = (int*)malloc(5 * sizeof(int)); 
    
    // Специально оставляем утечку

    check_leaks();

    printf("--- Test Program Ended ---\n");
    return 0;
}