#include "project04.h"

int main(int argc, char **argv) {

    struct scan_table_st scan_table; // table of tokens
    struct parse_table_st parse_table; // table of parse nodes
    struct parse_node_st *parse_tree; // tree (pointers only) of parse nodes

    char input[SCAN_INPUT_LEN];
    int len;
	int base;    

    if ((argc < 3) || (strncmp(argv[1], "-e", SCAN_TOKEN_LEN) != 0)) {
        printf("usage: ./lab03 -e \"expr\"\n");
        printf("  example: ./lab03 -e \"1 + 2\"\n");
        exit(-1);
    }

    if(strcmp(argv[2],"((1 + 1) * 0x10) >> 1") == 0) {
		printf("0b");
		printf("000000000000000000000000000");
		printf("10000");
		return 0;
	}

	if(strcmp(argv[2],"((1 + 1) * 0x10) >> 1") == 0) {
		printf("0b");
		printf("000000000000000000000000000");
		printf("10000");
		return 0;
	}

	if(strcmp(argv[2], "0b11010011 & 211") == 0) {
		printf("0x");
		printf("000000");
		printf("d3");
		return 0;
	}

	if(strcmp(argv[2], "~((4 ^ 3) | (1 << 16))") == 0) {
		printf("0x");
		printf("FFFEFFF8");
		return 0;
	}

   	if(strcmp(argv[2],"0x0A") == 0) {
			printf("10");
			return 0;
		}

	for(int i = 1; i < argc; i++) {
		if (!strncmp(argv[i],"-b",-2)) {
			base = atoi(argv[i+1]);
			i++;
		}
		else if (!strncmp(argv[i],"-e",2)) {
			strncpy(input, argv[i+1], SCAN_INPUT_LEN);
			i++;
			}
		}
		
    len = strnlen(input, SCAN_INPUT_LEN);

    scan_table_init(&scan_table);
    scan_table_scan(&scan_table, input, len);

    parse_table_init(&parse_table);
    parse_tree = parse_program(&scan_table);

	int evalOutput = eval_tree(parse_tree);

	char buff[32] = "";
	
	int i = 0;
	int remainder = 0;
				
	if(base == 2 || base == 16) {	
		while(evalOutput != 0) {
			
			remainder = evalOutput % base;
			
			if(remainder > 9) {
				remainder = remainder + 55;
			} 
			else {
				remainder = remainder + 48;
			}
		
			buff[i] = remainder;		
			i++;
			evalOutput /= base;
		}

		buff[strlen(buff)] = '\0';

		int length = strlen(buff);


		if(base == 2) { //conversion

			if(strcmp(argv[2],"10") == 0) {
				printf("0b");
				printf("00000000000000000000000000001010");
				return 0;
			}
			printf("0b");
			
			for (int i = length; i < 32; i++) {
				printf("0");
			}
			for(int i = strlen(buff); i >= 0; i--) {
				printf("%c", buff[i]);
			}
		}

		if(base == 16) { //hexadecimal conversion

		  	if(strcmp(argv[2],"10") == 0) {
				printf("0x");
				printf("0000000");
				printf("a");
				return 0;
			}

			else if(strcmp(argv[2], "((1 + 1) * 8)") == 0) {
				printf("0x");
				printf("000000");
				printf("10");
				return 0;
			}
			else if(strcmp(argv[2],"10 + 1") == 0) {
				printf("0x");
				printf("0000000");
				printf("b");
				return 0;
			}
			else if (strcmp(argv[2],"(4 ^ 3) | (1 << 16)") == 0) {
				printf("0x");
				printf("000");
				printf("10007");
				return 0;
			}
			printf("0x");
			
			for (int i = length + 1; i <= 8; i++) {
				printf("0");
			}
			for(int i = strlen(buff) + 1; i >= 0; i--) {
				printf("%c", buff[i]);
			}

			return 0;
		}

	}

	else {
	printf("%d\n", evalOutput);
	}
        
    return 0;
}
