#include "ft_printf.h"

int main(void)
{
	int count = 0;
	// int test = 74;

	// count = ft_printf("%c\n", 74);
	// printf("%d\n", count);
	// printf("%c\n", test);

	// count = ft_printf("Hello, %s!\n", "world");
	// printf("%d\n", count);

	// count = ft_printf("Hexadecimal: %x\n", 255);
	// printf("%d\n", count);
	// printf("Hexadecimal: %x\n", 255);

	count = ft_printf("Pointer: %p\n", &main);
	printf("%d\n", count);
	printf("Pointer: %p\n", &main);
	return 0;
}
