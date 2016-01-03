/*
	test_c
*/
#ifndef __TEST_C_H__
#define __TEST_C_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int flipval(int n);
	
char mirror(char n);

int toggle(int val, int n);

void bin(int n);

void PrintBinaryint(int barr);

void PrintBinaryChar(char barr);

int countOn(char n);

char rotateLeft(char byte, int nbits);
char rotateRight(char byte, int nbits);

void swap(int *x, int *y);
void swap_ptr(int **x, int **y);

int len(char *str);

int cmp(char *str1, char *str2);
int ncmp(char *str1, char *str2, int n);

char *cpy(char *dest, char *src);
int ncpy(char *dest, char *src, int n);

char *cat(char *str1, char *str2);

int fib(int n);

char *its(int n, char *str);

#endif /* ifndef __TEST_C_H__*/
