#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "como_memory_manager.h"

#define SAFE_BAIL_OUT() do { \
	fprintf(stderr, "%s:%d:%s: Fatal error: %s (%d)\n", \
		__FILE__, __func__, __LINE__, strerror(errno), errno); \
	exit(1); \
} while(0)

void*
malloc_or_die(size_t size)
{
	void* return_value;
	return_value = malloc(size);
	
	if(!return_value) {
		SAFE_BAIL_OUT();
	}

	return return_value;
}
