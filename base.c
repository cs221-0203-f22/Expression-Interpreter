#include "project04.h"

int string_to_int(char *string, int base) {

	int arr[32];

	for(int i = 0; i < strlen(string); i++) {
		arr[i] = (int)string[i] - 48;
	}

	if(sizeof(arr) == 1) {
		return arr[0];
	}
	if(sizeof(arr) == 2) {
		return arr[0] * 10 + arr[1];
	}
	if(sizeof(arr) == 3) {
		return arr[0] * 100 + arr[1] * 10 + arr[2];
	}
	if(sizeof(arr) == 4) {
		return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	}

	return arr[0];
	
}
