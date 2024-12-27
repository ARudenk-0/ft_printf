#include "ft_printf.h"

int main()
{
	int count = 0;

	printf("Test 1, str\n");
	count += ft_printf("Ft_printf:\n1)%.03s\n", "Hello there");
	printf("Printf:\n1)%.03s\n", "Hello there");
	printf("%d\n", count);
	printf("_____________________________________________\n");
	printf("Test 2, str\n");
	count += ft_printf("Ft_printf:\n1)%3.1s\n", "Hello there");
	printf("Printf:\n1)%3.1s\n", "Hello there");
	printf("%d\n", count);
	printf("_____________________________________________\n");
	printf("Test 3, str\n");
	count += ft_printf("Ft_printf:\n1)%9.1s\n", "Hello there");
	printf("Printf:\n1)%9.1s\n", "Hello there");
	printf("%d\n", count);
	printf("_____________________________________________\n");
	printf("Test 4, str\n");
	count += ft_printf("Ft_printf:\n1)%-3.1s\n", "Hello there");
	printf("Printf:\n1)%-3.1s\n", "Hello there");
	printf("%d\n", count);
	printf("_____________________________________________\n");
	printf("Test 5, str\n");
	count += ft_printf("Ft_printf:\n1)%-9.1s\n", "Hello there");
	printf("Printf:\n1)%-9.1s\n", "Hello there");
	printf("%d\n", count);
}
