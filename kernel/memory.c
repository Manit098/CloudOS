#include <stdint.h>

#define TOTAL_MEMORY 0x40000000  // Assume 1GB RAM
#define PAGE_SIZE 4096           // 4KB Pages

uint8_t memory_map[TOTAL_MEMORY / PAGE_SIZE];  // Bitmap for tracking pages

void init_memory() {
    for (int i = 0; i < TOTAL_MEMORY / PAGE_SIZE; i++)
        memory_map[i] = 0;  // Mark all pages as free
}

void* alloc_page() {
    for (int i = 0; i < TOTAL_MEMORY / PAGE_SIZE; i++) {
        if (memory_map[i] == 0) {
            memory_map[i] = 1;  // Mark as used
            return (void*)(i * PAGE_SIZE);
        }
    }
    return 0;  // No memory available
}

void free_page(void* addr) {
    int index = (uint32_t)addr / PAGE_SIZE;
    memory_map[index] = 0;  // Mark as free
}
