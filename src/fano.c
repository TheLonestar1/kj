#include"fano.h"

void count(char *text, int len, char *word){
	int counter[4];
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0; 
	counter[3] = 0;   
	for(int i = 0; i < len; i++){
		char buf  = text[i];
		
		for(int j = 0; j < 4; j++){
			if(buf == word[j]){
				counter[j]++;
				break;			
			} else if(counter[j] == 0){
			  	word[j] = buf;
				counter[j]++;
				break;		
			  }
		}
	}
	for(int j = 0; j < 4; j++){
		
		for(int i = 0; i < 3; i++) {
			if(counter[i] < counter[ i+ 1]){
				int buf_num = counter[i];
				char buf_char= word[i];
				counter[i] = counter[i + 1];
				word[i] = word[i + 1];
				counter[i+1] = buf_num;
				word[i+1] = buf_char;
			}
		}
	}
	
}

