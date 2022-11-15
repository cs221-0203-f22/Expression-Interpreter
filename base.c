#include "project04.h"

int string_to_int(char *string, int base) {

	for(int i = strlen(string) - 1; i>= 0; i--) {
		base = string[i];
		base = base - 48;
	}
	
    return base;
}
