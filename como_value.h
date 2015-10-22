#ifndef __COMO_VALUE_INCLUDED_H__
#define __COMO_VALUE_INCLUDED_H__

#include <stddef.h> /* for size_t */
#include <stdint.h>
#include <inttypes.h>

/*
 * These structures represent variable values
 */
typedef enum como_value_type {
	IS_STRING, IS_LONG, IS_DOUBLE, IS_NULL, IS_BOOL, IS_POINTER
} como_value_type;

typedef union como_internal_value {
	struct {
		size_t length;
		char*  value;
	} string_value;
	int64_t	long_value;
	double	double_value;
	void*	null_value;
	int64_t	bool_value;
	void*	pointer_value;
} como_internal_value;

typedef struct como_value {
	como_internal_value value;
	como_value_type	    type;
	unsigned int        flags;			
} como_value;

#define COMO_VALUE_TYPE(p) p->type
#define COMO_VALUE_STRING(p) p->value.string_value.value
#define COMO_VALUE_STRING_LENGTH(p) p->value.string_value.length
#define COMO_VALUE_LONG(p) p->value.long_value
#define COMO_VALUE_DOUBLE(p) p->value.double_value
#define COMO_VALUE_NULL(p) p->value.null_value
#define COMO_VALUE_BOOL(p) p->value.bool_value
#define COMO_VALUE_POINTER(p) p->value.pointer_value

#endif
