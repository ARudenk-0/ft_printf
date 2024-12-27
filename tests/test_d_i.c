#include "ft_printf.h"
#include <limits.h>

int main()
{
	int count = 0;

	printf("Test 1, decimals\n");
	count += ft_printf("Ft_printf:\n1)%d\n\n", -2147483648);
	printf("Printf:\n1)%ld\n\n", -2147483648);
	printf("%d\n", count);
	printf("_____________________________________________\n");
	printf("Test 2, decimals\n");
	count += ft_printf("Ft_printf:\n1)%d\n2)%d\n3)%d\n4)%d\n5)%d\n6)%d\n7)%d\n\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("Printf:\n1)%d\n2)%d\n3)%ld\n4)%ld\n5)%ld\n6)%d\n7)%d\n\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d\n", count);
}

// 47: 	TEST(23, print(" %d ", INT_MIN));
// 53: 	TEST(29, print(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));