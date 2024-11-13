/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/07/09 11:30:20 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_nbr(int nbr)
{
	unsigned int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		size = size + 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

static void	ft_itoa_helper(char *str, long long int nbr, int len)
{
	if (nbr == 0)
		str[0] = '0';
	str[len] = '\0';
	while (nbr != 0)
	{
		str[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	long long int	nbr;
	int				len;

	len = ft_get_nbr(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	nbr = n;
	if (n == INT_MIN)
	{
		free(str);
		return (ft_strdup("-2147483648"));
	}
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	ft_itoa_helper(str, nbr, len);
	return (str);
}

// #include "libft.h"

// static unsigned int	ft_number_size(int number)
// {
// 	unsigned int	length;

// 	length = 0;
// 	if (number == 0)
// 		return (1);
// 	if (number < 0)
// 		length += 1;
// 	while (number != 0)
// 	{
// 		number /= 10;
// 		length++;
// 	}
// 	return (length);
// }

// static char	*special_cases(int n, char	*string)
// {
// 	int	number;

// 	number = n;
// 	if (n == -2147483648)
// 		return (ft_strdup("-2147483648"));
// 	if (number < 0)
// 	{
// 		string[0] = '-';
// 		number = -n;
// 	}
// 	else
// 		number = n;
// 	return (ft_itoa(number));
// }

// char	*ft_itoa(int n)
// {
// 	char			*string;
// 	int				number;
// 	unsigned int	length;

// 	length = ft_number_size(n);
// 	number = n;
// 	string = (char *)malloc(sizeof(char) * (length + 1));
// 	if (string == NULL)
// 		return (NULL);
// 	string = special_cases(n, string);
// 	if (number == 0)
// 		string[0] = '0';
// 	string[length] = '\0';
// 	while (number != 0)
// 	{
// 		string[--length] = (number % 10) + '0';
// 		number = number / 10;
// 	}
// 	return (string);
// }

// int main ()
// {
// 	int a = 54681387;
// 	ft_itoa(a);
// }

// #include <stdlib.h>
// #include <unistd.h>

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int		main(int argc, const char *argv[])
// {
// 	int		arg;

// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 	{
// 		char *res = ft_itoa(0);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 2)
// 	{
// 		char *res = ft_itoa(9);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 3)
// 	{
// 		char *res = ft_itoa(-9);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 4)
// 	{
// 		char *res = ft_itoa(10);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 5)
// 	{
// 		char *res = ft_itoa(-10);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 6)
// 	{
// 		char *res = ft_itoa(8124);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 7)
// 	{
// 		char *res = ft_itoa(-9874);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 8)
// 	{
// 		char *res = ft_itoa(543000);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 9)
// 	{
// 		char *res = ft_itoa(-2147483648LL);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 10)
// 	{
// 		char *res = ft_itoa(2147483647);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	return (0);
// }
