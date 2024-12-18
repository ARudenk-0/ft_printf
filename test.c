#include "ft_printf.h"

int main(void)
{
	int count = 0;

	count = ft_printf("%s\n", 45, 55, 65);
	printf("%d\n", count);
	// ft_printf("Hello, %s!\n", "world");
	// ft_printf("Hexadecimal: %x\n", 255);
	// ft_printf("Pointer: %p\n", &main);
	return 0;
}
