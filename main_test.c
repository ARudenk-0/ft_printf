#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void test_single_specifier();
void test_flags_and_specifiers();
void test_precision_and_specifiers();
void test_width_and_specifiers();
void test_mixed_flags_width_precision();
void test_edge_cases();

int main() {
    test_single_specifier();
    test_flags_and_specifiers();
    test_precision_and_specifiers();
    test_width_and_specifiers();
    test_mixed_flags_width_precision();
    test_edge_cases();
    return 0;
}

void test_single_specifier() {
    printf("==== Testing Single Specifiers ====\n");
    ft_printf("ft_printf: %%c => %c\n", 'A');
    printf("printf   : %%c => %c\n", 'A');

    ft_printf("ft_printf: %%s => %s\n", "Hello");
    printf("printf   : %%s => %s\n", "Hello");

    ft_printf("ft_printf: %%p => %p\n", (void *)1234);
    printf("printf   : %%p => %p\n", (void *)1234);

    ft_printf("ft_printf: %%d => %d\n", 42);
    printf("printf   : %%d => %d\n", 42);

    ft_printf("ft_printf: %%i => %i\n", -42);
    printf("printf   : %%i => %i\n", -42);

    ft_printf("ft_printf: %%u => %u\n", 42);
    printf("printf   : %%u => %u\n", 42);

    ft_printf("ft_printf: %%x => %x\n", 255);
    printf("printf   : %%x => %x\n", 255);

    ft_printf("ft_printf: %%X => %X\n", 255);
    printf("printf   : %%X => %X\n", 255);

    ft_printf("ft_printf: %%%% => %%\n");
    printf("printf   : %%%% => %%\n");
    printf("====================================\n\n");
}

void test_flags_and_specifiers() {
    printf("==== Testing Flags with Specifiers ====\n");
    ft_printf("ft_printf: %%-c => %-c\n", 'A');
    printf("printf   : %%-c => %-c\n", 'A');

    ft_printf("ft_printf: %%0d => %0d\n", 42);
    printf("printf   : %%0d => %0d\n", 42);

    ft_printf("ft_printf: %%+d => %+d\n", 42);
    printf("printf   : %%+d => %+d\n", 42);

    ft_printf("ft_printf: %% d => % d\n", 42);
    printf("printf   : %% d => % d\n", 42);

    ft_printf("ft_printf: %%#x => %#x\n", 255);
    printf("printf   : %%#x => %#x\n", 255);

    ft_printf("ft_printf: %%#X => %#X\n", 255);
    printf("printf   : %%#X => %#X\n", 255);
    printf("========================================\n\n");
}

void test_precision_and_specifiers() {
    printf("==== Testing Precision with Specifiers ====\n");
    ft_printf("ft_printf: %%.5d => %.5d\n", 42);
    printf("printf   : %%.5d => %.5d\n", 42);

    ft_printf("ft_printf: %%.3s => %.3s\n", "Hello");
    printf("printf   : %%.3s => %.3s\n", "Hello");

    ft_printf("ft_printf: %%.4x => %.4x\n", 255);
    printf("printf   : %%.4x => %.4x\n", 255);
    printf("===========================================\n\n");
}

void test_width_and_specifiers() {
    printf("==== Testing Width with Specifiers ====\n");
    ft_printf("ft_printf: %%5d => %5d\n", 42);
    printf("printf   : %%5d => %5d\n", 42);

    ft_printf("ft_printf: %%8s => %8s\n", "Hi");
    printf("printf   : %%8s => %8s\n", "Hi");

    ft_printf("ft_printf: %%10x => %10x\n", 255);
    printf("printf   : %%10x => %10x\n", 255);
    printf("======================================\n\n");
}

void test_mixed_flags_width_precision() {
    printf("==== Testing Mixed Flags, Width, and Precision ====\n");
    ft_printf("ft_printf: %%+-10.5d => %+-10.5d\n", 42);
    printf("printf   : %%+-10.5d => %+-10.5d\n", 42);

    ft_printf("ft_printf: %%#8.4x => %#8.4x\n", 255);
    printf("printf   : %%#8.4x => %#8.4x\n", 255);

    ft_printf("ft_printf: %%08.5u => %08.5u\n", 42);
    printf("printf   : %%08.5u => %08.5u\n", 42);
    printf("===============================================\n\n");
}

void test_edge_cases() {
    printf("==== Testing Edge Cases ====\n");
    ft_printf("ft_printf: %%s => %s\n", NULL);
    printf("printf   : %%s => %s\n", NULL);

    ft_printf("ft_printf: %%p => %p\n", NULL);
    printf("printf   : %%p => %p\n", NULL);

    ft_printf("ft_printf: %%d => %d\n", INT_MIN);
    printf("printf   : %%d => %d\n", INT_MIN);

    ft_printf("ft_printf: %%d => %d\n", INT_MAX);
    printf("printf   : %%d => %d\n", INT_MAX);

    ft_printf("ft_printf: %%d => %d\n", -12345);
    printf("printf   : %%d => %d\n", -12345);

    ft_printf("ft_printf: %%i => %i\n", -67890);
    printf("printf   : %%i => %i\n", -67890);

    ft_printf("ft_printf: %%u => %u\n", UINT_MAX);
    printf("printf   : %%u => %u\n", UINT_MAX);

    ft_printf("ft_printf: %%x => %x\n", 0);
    printf("printf   : %%x => %x\n", 0);

    ft_printf("ft_printf: %%X => %X\n", 0);
    printf("printf   : %%X => %X\n", 0);

    ft_printf("ft_printf: %%lu => %lu\n", ULONG_MAX);
    printf("printf   : %%lu => %lu\n", ULONG_MAX);

    ft_printf("ft_printf: %%.03s => %.03s\n", NULL);
    printf("printf   : %%.03s => %.03s\n", NULL);

    ft_printf("ft_printf: %%3.1s => %3.1s\n", NULL);
    printf("printf   : %%3.1s => %3.1s\n", NULL);

    ft_printf("ft_printf: %%9.1s => %9.1s\n", NULL);
    printf("printf   : %%9.1s => %9.1s\n", NULL);

    ft_printf("ft_printf: %%-3.1s => %-3.1s\n", NULL);
    printf("printf   : %%-3.1s => %-3.1s\n", NULL);

    ft_printf("ft_printf: %%-9.1s => %-9.1s\n", NULL);
    printf("printf   : %%-9.1s => %-9.1s\n", NULL);

    ft_printf("ft_printf: p3 %%.4s => %.4s\n", NULL);
    printf("printf   : p3 %%.4s => %.4s\n", NULL);

    ft_printf("ft_printf: %%-50.2s => %-50.2s\n", NULL);
    printf("printf   : %%-50.2s => %-50.2s\n", NULL);
}
