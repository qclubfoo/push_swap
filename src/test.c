#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_list
{
	int len;
	int *str;
}	t_list;

int main (void)
{
	t_list a;

	a.len = 10;
	a.str = (int*)malloc(sizeof(int) * 10);
	a.str[0] = 1;
}