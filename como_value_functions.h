#ifndef __COMO_VALUE_FUNCTION_INCLUDED_H__
#define __COMO_VALUE_FUNCTION_INCLUDED_H__

#include "como_value.h"

como_value* 
como_value_create_string(const char* source);

como_value*
como_value_create_long(const uint64_t source);

como_value*
como_value_create_double(const double source);

como_value* 
como_value_create_null(void);

como_value*
como_value_create_bool(const int source);

como_value*
como_value_create_pointer(void* source);

void
como_value_destroy(como_value* value);

#endif
