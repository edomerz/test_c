#include <assert.h>
#include "test_c.h"

typedef struct
{
	int i;
	char c;
	short s;
	int j;
}S1;

typedef struct
{
	int i:2;
	char c:1;
	short s:3;
	int j;
	char x:2;
}S2;

typedef union
{
	char arr[7];
	int i;
	short s;
}jack;
	
int main(int argc, char* argv[], char** envp)
{
	unsigned int input = 0;
	unsigned int flip = 0;
	unsigned char mir = 0;
	unsigned int tog = 0;
	int x = 1;
	int y = 9;
	int *px = &x;
	int *py = &y;
	char *str1 = "abcd";
	char *str2 = "abcde";
	char *str3 = (char*)malloc(20);	
	char *str4 = NULL;
			
	if(argc != 2)
	{
		printf("Usage:./test_c (int)input\n");
		return(-1);
	}
	input = atoi(argv[1]);
	printf("var: %d\n", input);
	PrintBinaryint(input);
	
/*############# flip ################*/
	printf("\nLINE:20 \n"); 
	PrintBinaryint(input);
	flip = flipval(input);
	printf("\nflip: %d \n", flip);
	PrintBinaryint(flip);
	
/*############# mirror ################*/	
	printf("\nLINE:27 \n"); 
	PrintBinaryChar(1);
	mir = mirror(1);
	printf("\n mirror: %d\n", (unsigned char)mir);
	PrintBinaryChar(mir);
	
/*############# toggle ################*/
	printf("\nLINE:34 \n"); 
	PrintBinaryint((unsigned int)0);
	tog = toggle((unsigned int)0, 5);
	printf("\ntoogle: %u\n", tog);
	PrintBinaryint((unsigned int)tog);
	
/*############# countOn ################*/
	printf("\nLINE:41 \n"); 
	PrintBinaryChar((unsigned char)input);
	printf("\ncountOn:%d\n", countOn((unsigned char)input));
	
/*############# rotateLeft ################*/
	printf("\nLINE: 46 \n");
	printf("mir:%i\n", mir);
	PrintBinaryChar(mir);
	mir = rotateLeft(mir, 7);
	printf("mir:%i\n", mir);
	PrintBinaryChar(mir);
	
/*############# rotateRight ################*/
	printf("\nLINE: 54\n"); 
	printf("mir:%i\n", mir);
	PrintBinaryChar(mir);
	mir = rotateRight(mir, 2);
	printf("mir:%i\n", mir);
	PrintBinaryChar(mir);
	
/*############# swap ################*/
	printf("\nLINE:62 \n"); 
	printf("x:%i, y:%i\n", x, y);		
	printf("swapping...\n");
	swap(&x, &y);
	printf("x:%i, y:%i\n", x, y);
	
/*############# swap_ptr ################*/
	printf("\nLINE:71 \n"); 
	printf("px:%p, py:%p\n", (void*)px, (void*)py);		
	printf("swapping...\n");
	swap_ptr(&px, &py);
	printf("px:%p, py:%p\n", (void*)px, (void*)py);

/*############# strlen ################*/
	printf("\nLINE:83 \n"); 
	printf("string1:%s, strlen:%i\n", str1, len(str1));
	printf("string2:%s, strlen:%i\n", str2, len(str2));
/*############# strcmp ################*/
	printf("\nLINE:87 \n"); 
	printf("strcmp:%i\n", cmp(str1, str2));
	
/*############# strncmp ################*/
	printf("\nLINE:91 \n"); 
	printf("strncmp:%i\n",  ncmp(str1, str2, 4));
	
/*############# strcpy ################*/
	printf("\nLINE:95 \n"); 
	printf("str1:%s\n", str1);
	cpy(str3, str1);
	printf("str3:%s\n", str3);

/*############# strncpy ################*/
	printf("\nLINE:101 \n"); 
	printf("str2:%s\n", str2);	
	printf("n:%i\n", ncpy(str3, str2, 3));
	printf("str3:%s\n", str3);

/*############# strcat ################*/
	printf("\nLINE:107 \n"); 
	printf("str1:%s, 	str2:%s\n",str1, str2);	
	str4 = cat(str1, str2);
	printf("str4:%s\n", str4);
	
/*############# fib ################*/
	printf("\nLINE:115 \n"); 
	printf("fib %i:%i\n", 10, fib(10));

/*############# int_to_str ################*/	
	printf("\nLINE:119 \n"); 
	printf("str4:%s\n", str4);		
	str4 = its(123456789, str4);
	printf("str4:%s\n", str4);		
	
/*############# S1 ################*/
	printf("\nLINE:149 \n"); 
	printf("sizeof(S1):%lu\n", sizeof(S1));
	
/*############# S2 ################*/
	printf("\nLINE:153 \n"); 
	printf("sizeof(S2):%lu\n", sizeof(S2));
	
/*############# union ################*/
	printf("\nLINE:157 \n"); 
	printf("sizeof(jack):%lu\n", sizeof(jack));
	printf("sizeof(union jack):%lu\n", sizeof(jack));
	
	free(str4);
	free(str3);
	return(0);	
}
