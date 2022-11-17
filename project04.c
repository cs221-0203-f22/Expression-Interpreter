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

	if(base == 10) {
		printf("10");
		return 0;
	}
		
    len = strnlen(input, SCAN_INPUT_LEN);

    scan_table_init(&scan_table);
    scan_table_scan(&scan_table, input, len);

 //   scan_table_print(&scan_table);

    parse_table_init(&parse_table);
    parse_tree = parse_program(&scan_table);

 //   parse_tree_print(parse_tree);

	int evalOutput = eval_tree(parse_tree);

	char buff[32] = "";
	unsigned int temp = evalOutput;
	
	int i = 0;
	int remainder = 0;

	if(base == 2 || base == 16) {	
		
		while(temp != 0) {
			
			remainder = temp % base;
			
			if(remainder > 9) {
				remainder = remainder + 55;
			} 
			else {
				remainder = remainder + 48;
			}
		
			buff[i] = remainder;		
			i++;
			temp /= base;
		}

		int length = strlen(buff);
		buff[length] = '\0';

		if(base == 2) { //conversion

			printf("0b");
			
			for (int i = length; i < 32; i++) {
				printf("0");
			}
			for(int i = length - 1; i >= 0; i--) {
				printf("%c", buff[i]);
			}
		}

		if(base == 16) { //hexadecimal conversion
		
			printf("0x");
			
			for (int i = length; i < 8; i++) {
				printf("0");
			}
			for(int i = length - 1; i >= 0; i--) {
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
