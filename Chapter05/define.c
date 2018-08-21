#include <stdio.h>
#include <string.h>


#define UPPER_LETTER(ch) ((ch > 64) && (ch < 91))
#define LOWER_LETTER(ch) ((ch > 96) && (ch < 123))
#define ADD_HEAD '+'
#define ADD_TAIL '*'


int main(int argc, char* argv[]){
	printf("start...\n");
	if (1<0<1){
		printf("FCKNG SHIT!!!\n");
	}

	unsigned x;
	const char* str = argv[1];
	printf("<%s> input str\n", str);

	while((*str)!= '\0'){

		if (UPPER_LETTER(*str)){
			printf("%c is upper letter. code=%d\n", *str, (int) *str);
		}
		else if(LOWER_LETTER(*str)){
			printf("%c is lower letter. code=%d\n", *str, (int) *str);
		}
		str++;
	}
	printf("exit...\n");
	return 0;
}