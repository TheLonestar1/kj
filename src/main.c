#include"fano.h"

int main(int argc,char **argv) {

	if(argc != 5) {
		printf("Example fill:\n1)encode: sfcompress -c -o name.sfc name.txt\n2)decode: sfcompress -d -o name.txt name.sfc\n");
		return 1;
	}
	if(argv[1][1] == 'c'){
			FILE * input, * output;
			input = fopen(argv[4],"r");
			if(input == NULL) {
				printf("Error opening file %s \n", argv[4]);
				return 1;
			}
			char words[100];
			char *coder  = (char*) malloc(sizeof(char));
			fread(words, sizeof(char), 100, input);
			fclose(input);
			char count_word[100];
			count(words, 10, count_word);
			output = fopen(argv[3],"wb");
			if(output == NULL) {
				printf("Error opening file %s \n", argv[4]);
				return 1;
			}
			coder << 8;
			for(int i = 0; i < 10; i++){
				for(j = 0; j < 4; j++){
					if(words[i] == count_word[j]) {
											
					}
				}
			}



			}
			fclose(output);
			return 0;
	}
	if( argv[1][1] == 'd') return 0;
	return 1;
}
