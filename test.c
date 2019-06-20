#include "ctest.h"
#include "fano.h"


CTEST(test_on_enter_date,fano_tests){
	int argc = 5;
	char words[10] = "name.sfc";
	char argv[5][10];
	argv[1][1] = 'd';
	for(int i = 0; i < 10; i++) argv[4][i] = words[i];
	FILE *input;
	int flag = 0;
	if(argc != 5) {
		printf("Example fill:\n1)encode: sfcompress -c -o name.sfc name.txt\n2)decode: sfcompress -d -o name.txt name.sfc\n");
		flag  = 1;
	}
	if(argv[1][1] == 'c'){
		input = fopen(argv[4],"r");
			if(input == NULL) {
			printf("Error opening file %s \n", argv[4]);
			flag = 1;
		}
	} 
	if( argv[1][1] != 'd') flag = 1;
	input = fopen(argv[4],"r");
			if(input == NULL) {
			printf("Error opening file %s \n", argv[4]);
			flag = 1;
		}
	ASSERT_EQUAL(0,flag);
}

