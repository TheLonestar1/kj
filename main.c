#include"fano.h"

int main(int argc,char **argv) {

	if(argc != 5) {
		printf("Example fill:\n1)encode: sfcompress -c -o name.sfc name.txt\n2)decode: sfcompress -d -o name.txt name.sfc\n");
		return 1;
	}
	if(argv[1][1] == 'c'){
			FILE * input, *output;
			struct bstree *tree;
			char *coder  = (char*) malloc(sizeof(char) * 4);
			input = fopen(argv[4],"r");
			if(input == NULL) {
				printf("Error opening file %s \n", argv[4]);
				return 1;
			}
			char words[100] = {0};
			
			fread(words, sizeof(char), 100, input);
			fclose(input);
			struct kluch counters[10];
			count(words, 10, counters);
			char wordes[100] = {0};
		
			for(int i = 0; i < 4; i++){
				wordes[i] = counters[i].word;
			}
			tree = bstree_create(wordes, 0 );
			output = fopen(argv[3],"wb");
			if(output == NULL) {
				printf("Error opening file %s \n", argv[4]);
				return 1;
			}
			sfcompress(counters,4,4,tree);
			int shift = 0;
			
			//int byte = 1;
			int v = 0;	
			int i = 0;
			for(; i < 10; i++){
			    int minus = 1;	
			    struct bstree *parent = tree;
			    for(;;){
				struct bstree *leftt,*righ;
				leftt = parent->left;
				righ = parent->right;
				if((leftt->key[0] == words[i])){
					
					shift = shift  + minus ;
					if(shift >= 8) {
					//byte = byte + 1;
					v++;
					//(char*) realloc(coder,sizeof(char) * byte);					
					shift = shift - 8;
					shift = shift  + minus - 1;
					}
					coder[v] = coder[v] << minus;
					coder[v] = coder[v] + 1;
					break;				
				} else if((righ->key[0] == words[i]) && (righ->key[1] == EOF)){
					shift = shift  + minus ;
					if(shift >= 8) {
					//byte = byte + 1;
					v++;
					//realloc(coder,sizeof(char) * byte);					
					shift = shift - 8;
					shift = shift  + minus - 1 ;
					}
					coder[v] = coder[v] << minus;
					break;	
				 } else {
					minus = minus + 1;
					parent = parent->right;	
				  }
			    }
			}
			coder[v]  = coder[v] << (7 - shift);
			fwrite(wordes,1,3,output);
			fwrite(coder,1,v+1,output);
			
			fclose(output);
			return 0;
	}
	if( argv[1][1] != 'd') return 1;
	FILE * input, *output;
	struct bstree *tree;
	input = fopen(argv[4],"r");
	if(input == NULL) {
		printf("Error opening file %s \n", argv[4]);
		return 1;
	}
	char coder[100] = {0};
	int cod[100] = {0};
	char words[100] = {0};
	char result[100];
	char wordes[10] = {0};
	struct kluch counter[3];
	char word[3];
	fread(word,sizeof(char),3,input);
	fread(coder,sizeof(char),100,input);	
	for(int j = 0; j < 3; j++) counter[j].word = word[j];
	for(int i = 0; i < 3; i++){
		wordes[i] = counter[i].word;
	}
	tree = bstree_create(wordes, 0 );
	sfcompress(counter,4,4,tree);
	int j = 0;
	int shift = 7;
	for(int i = 0; i < 100; i++){
		cod[i] = ((coder[j] >> shift) & 1);
		shift--;
		if(shift == -1){
			j++;
			shift = 7;
		}
		if(coder[j] == 0) break;		
	
	}
	
	struct bstree *parent;
	j = 0;
	for(int i = 0; i < 100; i++){
		parent = tree;
		for(;j < 100; j++){
			if(cod[j] == 1){
				result[i] = parent->left->key[0];
				j++;
				break;			
			}
			else if(parent->right == NULL){
				result[i] = parent->key[0];
				j++;
				break;
			}  else parent = parent->right;
		}
	}
	output = fopen(argv[3],"w");
		
	fwrite(result,1,10,output);	
	return 0;
}
