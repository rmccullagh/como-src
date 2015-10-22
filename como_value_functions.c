/*
 * functions for creating como_value's
 */

#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include "como_value.h"
#include "como_memory_manager.h"

static como_value* 
como_value_init(como_value_type type)
{
	como_value* return_value;
	
	return_value = malloc_or_die(sizeof(como_value));

	return_value->type = type;	
	return_value->flags = 0;

	return return_value;
}

static void
como_value_init_string(como_value* value, const char* source, size_t length)
{
	value->value.string_value.length = length;
	
	value->value.string_value.value = malloc_or_die(length + 1);

	memcpy(value->value.string_value.value, source, length);
		
	value->value.string_value.value[length] = '\0';
}

como_value* 
como_value_create_string(const char* source)
{
	como_value* return_value;
	
	return_value = como_value_init(IS_STRING);	

	como_value_init_string(return_value, source, strlen(source));
	
	return return_value;
}

como_value*
como_value_create_long(const uint64_t source)
{
	como_value* return_value;

	return_value = como_value_init(IS_LONG);
	
	return_value->value.long_value = source;
	
	return return_value;
}

como_value*
como_value_create_double(const double source)
{
	como_value* return_value;

	return_value = como_value_init(IS_DOUBLE);
	
	return_value->value.double_value = source;
	
	return return_value;
}

como_value* 
como_value_create_null(void)
{
	como_value* return_value;

	return_value = como_value_init(IS_NULL);
	
	return_value->value.null_value = NULL;
	
	return return_value;
}

como_value*
como_value_create_bool(const int source)
{
	como_value* return_value;

	return_value = como_value_init(IS_BOOL);
	
	return_value->value.bool_value = source ? 1 : 0;
	
	return return_value;
}

como_value*
como_value_create_pointer(void* source)
{
	como_value* return_value;

	return_value = como_value_init(IS_POINTER);
	
	return_value->value.pointer_value = source;
	
	return return_value;
}

static void 
como_value_destroy_string(como_value* value)
{
	free(COMO_VALUE_STRING(value));
	free(value);
}

void como_value_destroy(como_value* value)
{
	switch(COMO_VALUE_TYPE(value)) {
		case IS_STRING:
			como_value_destroy_string(value);
		return;
		case IS_LONG:
		case IS_DOUBLE:
		case IS_NULL:
		case IS_BOOL:
		case IS_POINTER:
			free(value);
		return;	
	}	
}
