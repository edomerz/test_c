#include <assert.h>
#include "test_c.h"



void PrintBinaryChar(char barr)
{
	unsigned char i = sizeof(barr) * 8;
	while(i--)
	{
		(barr >> i) & (char)1 ? (printf("1")) : (printf("0"));
	}
	printf("\n");
}

void PrintBinaryint(int barr)
{
	unsigned int i = sizeof(barr) * 8 - 1;
	while(i--)
	{
		(barr >> i) & (int)1 ? (printf("1")) : (printf("0"));
	}
	printf("\n");
}

void bin(int n)
{
	printf("binary:");
	
	while(n)
	{
		printf( "%u", ((unsigned int)n) & ((unsigned int)1) );
		n >>= 1; 
	}
	printf("\n\n");
}
		
int flipval(int n)
{
	int new_n = 0;
/*	int i = 0;*/
	int sign = n >= 0 ? 1 : -1;

	n = abs(n);
	while(n)
	{
		new_n = (10 * new_n) + (n % 10);
		n /= 10;
	}
	return(sign * new_n);
}

char mirror(char n)
{
	char new_n = n;
	char zeros = sizeof(n) * 8 - 1;
	
	for(n >>= 1; n; n >>= 1)
	{
		new_n <<= 1;
		new_n |= (n&1);
		--zeros;
	}
	new_n <<= zeros;
	
	return(new_n);
}

int toggle(int val, int n)
{
	return(val ^ (1 << n));
}

int countOn(char n)
{
	int count = 0;
	while(n)
	{
		count += n & (char)1;
		n >>= 1;
	}
	return(count);
}

char rotateLeft(char byte, int nbits)
{
	unsigned char mask = sizeof(byte) * 8 - 1;
	nbits &= mask;
	printf("mask:%i		nbits:%i\n", mask, nbits);
/*	PrintBinary(byte);*/
	return( ((unsigned char)byte << nbits) | ((unsigned char)byte) >> (8 - nbits) );
}

char rotateRight(char byte, int nbits)
{
	unsigned char mask = sizeof(byte) * 8 - 1;
	nbits &= mask;
	return( ((unsigned char)byte >> nbits) | ((unsigned char)byte << (mask + 1 - nbits)));
}

void swap(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

void swap_ptr(int **x, int **y)
{
	int *tmp = *y;
	*y = *x;
	*x = tmp;
}

int len(char *str)
{
	int count = 0;
	for(; *str; ++str, ++count)
	{}
	return(count);
}
/*############# strcmp ################*/
int cmp(char *str1, char *str2)
{
	for( ;(*str1) && (*str1 == *str2); ++str1, ++str2)
	{}
	return(*str1 - *str2);
}
/*############# strncmo ################*/
int ncmp(char *str1, char *str2, int n)
{
	for( ;(*str1) && (*str1 == *str2) && (n); --n, ++str1, ++str2)
	{}
	return(*str1 - *str2);
}
/*############# strcpy ################*/
char *cpy(char *dest, char *src)
{
	int i = 0;
	for( ;src[i]; ++i)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	
	return(dest);
}
/*############# strncpy ################*/
int ncpy(char *dest, char *src, int n)
{
	while((*src) && (n))
	{
		*dest = *src;
		++dest;
		--n;
		++src;
	}
	*dest = '\0';
	return(n);
}
/*############# strcat ################*/
char *cat(char *str1, char *str2)
{
	char *ret = NULL;
	char *tmp = (char*)malloc(strlen(str1) + strlen(str2) + 1);
	assert(tmp);
	
	ret = strcpy(tmp, str1);
	tmp += strlen(str1);
	
	strcpy(tmp, str2);
	
	return(ret);
}
/*############# fibonacci ################*/
int fib(int n)
{
	int prev = 1;
	int next = 1;
	int sum = 0;
	if(n <= 2)
	{
		return(1);
	}
	while(n > 2)
	{
		sum = prev + next;
		prev = next;
		next = sum;
		--n;
	}
	return(sum);
/*	while(n > 2)*/
/*	int start = 1;*/
/*	if(n <= 2)*/
/*	{*/
/*		return(start);*/
/*	}*/
/*	return(fib(n - 2) + fib(n -1));*/
}
/*############# int_to_str ################*/
char *its(int n, char *str)
{
	int i = 0;
	int j = 0;
	while(n)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		++i;
	}
	str[i] = '\0';
	
	for(--i; j < i; ++j, --i)
	{
		str[j] = str[j] + str[i];
		str[i] = str[j] - str[i];
		str[j] = str[j] - str[i];
	}
	str[i + j + 1] = '\0';
	return(str);
}


