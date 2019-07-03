#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <float.h>







int main()
{
	printf("%100s\n" , "lalalalal");
	printf("%-100s" , NULL);
	printf("%100s" , NULL);
	printf("%100s" , 0);
	return (0);
}