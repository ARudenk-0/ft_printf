#include "ft_printf.h"

int main()
{
	int count = 0;

	printf("Test 1, NULL\n");
	count += ft_printf("Ft_printf:\n1)%.03s\n", NULL);
	printf("Printf:\n1)%.03s\n", NULL);
	printf("%d\n", count);
	printf("_____________________________________________\n");
	printf("Test 2, NULL\n");
	count += ft_printf("Ft_printf:\n1)%3.1s\n", NULL);
	printf("Printf:\n1)%3.1s\n", NULL);
	printf("%d\n", count);
	printf("_____________________________________________\n");
	printf("Test 3, NULL\n");
	count += ft_printf("Ft_printf:\n1)%9.1s\n", NULL);
	printf("Printf:\n1)%9.1s\n", NULL);
	printf("%d\n", count);
	printf("_____________________________________________\n");
	printf("Test 4, NULL\n");
	count += ft_printf("Ft_printf:\n1)%-3.1s\n", NULL);
	printf("Printf:\n1)%-3.1s\n", NULL);
	printf("%d\n", count);
	printf("_____________________________________________\n");
	printf("Test 5, NULL\n");
	count += ft_printf("Ft_printf:\n1)%-9.1s\n", NULL);
	printf("Printf:\n1)%-9.1s\n", NULL);
	printf("%d\n", count);
}

// - [OUTPUT] ft_printf("%.03s", NULL)
//    expected: ""
//    actual:   "(nu"

// - [OUTPUT] ft_printf("%3.1s", NULL)
//    expected: "   "
//    actual:   "  ("

// - [OUTPUT] ft_printf("%9.1s", NULL)
//    expected: "         "
//    actual:   "        ("

// - [OUTPUT] ft_printf("%-3.1s", NULL)
//    expected: "   "
//    actual:   "(  "

// - [OUTPUT] ft_printf("%-9.1s", "Hello there")
//    expected: "         "
//    actual:   "(        "

// - [OUTPUT] ft_printf("p3 %.4s\n", "Hello there")
//    expected: "p3 \n"
//    actual:   "p3 (nul\n"

// - [OUTPUT] ft_printf("%50.2s", NULL)
//    expected: "                                                  "
//    actual:   "                                                (n"

