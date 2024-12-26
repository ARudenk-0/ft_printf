#include "ft_printf.h"

int main ()
{
	int count = 0;

	// printf("Test 1, width\n");
	// count += ft_printf("%04d\n", -14);
	// printf("%04d\n", -14);
	// printf("%d\n", count);

	printf("Test 1, precision\n");
	count += ft_printf("Ftprintf: %.2d\n", -1);
	printf("Printf: %.2d\n", -1);
	printf("%d\n", count);

	return (0);
}

// 36: 	TEST(11, print(" %.2d ", -1));
// 44: 	TEST(19, print(" %.1d ", 99));
// 45: 	TEST(20, print(" %.2d ", 100));
// 47: 	TEST(22, print(" %.1d ", -9));
// 48: 	TEST(23, print(" %.2d ", -10));
// 49: 	TEST(24, print(" %.3d ", -11));
// 50: 	TEST(25, print(" %.4d ", -14));
// 51: 	TEST(26, print(" %.1d ", -15));
// 52: 	TEST(27, print(" %.2d ", -16));
// 53: 	TEST(28, print(" %.3d ", -99));
// 54: 	TEST(29, print(" %.3d ", -100));
// 55: 	TEST(30, print(" %.4d ", -101));