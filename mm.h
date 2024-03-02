#ifndef MM_H_
#define MM_H_

#include "defs.h"
#include "platform.h"
#include "types.h"

#define MEMORY_CAPACITY 1024
static u8 MEMORY_ARRAY[MEMORY_CAPACITY] = {0};
static u64 mem_ptr = 0;

static void* mm_malloc(u64 size)
{
	if (size < MEMORY_CAPACITY && (mem_ptr + size) < MEMORY_CAPACITY) {
		void* block_ptr = &MEMORY_ARRAY[mem_ptr];
		mem_ptr += size;
		return block_ptr;
	}

	return NULL;
}

static void mm_log()
{
	Platform_log_mem((float) mem_ptr / (float)MEMORY_CAPACITY);
}

#endif // MM_H_
