#include "printf.h"

int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}