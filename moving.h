
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int movingCount(int threshold,int rows,int cols);
int movingCountCore(int threshold,int rows,int cols,int row,int col,int* visited);
int GetDigitSum(int number);
int check(int threshold,int rows,int cols,int row,int col,int * visited);
