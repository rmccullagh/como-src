#ifndef __COMO_ARRAY_INCLUDED_H__
#define __COMO_ARRAY_INCLUDED_H__

#include <stddef.h>
#include "como_value.h"

typedef struct como_array {
	size_t        size;
	size_t 	      capacity;
	como_value**  table;	
} como_array;

#endif
