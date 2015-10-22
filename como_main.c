#include <stdio.h>
#include "como_value.h"
#include "como_value_functions.h"

int main(void)
{
	como_value* c = como_value_create_string("Ryan McCullagh");

	printf("%s (%zu)\n", COMO_VALUE_STRING(c), COMO_VALUE_STRING_LENGTH(c));	
	como_value_destroy(c);
	
	return 0;
}

