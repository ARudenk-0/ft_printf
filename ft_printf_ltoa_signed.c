/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ltoa_signed.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:50:58 by arudenko          #+#    #+#             */
/*   Updated: 2024/12/27 12:46:39 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

/*
** 1) Convert the positive part to digits (ft_lltoa_no_sign).
** 2) Apply precision => zero-pad the digits if needed.
** 3) Prepend sign (-, +, or space).
** 4) If no precision => maybe zero-pad to width if (f.zero && !f.minus).
** 5) Pass to ft_format_output for final alignment.
*/

/* A small helper: create a new string of length 'needed' filled with '0'. */
char *ft_make_zeros(int needed)
{
	char *z = (char *)malloc(needed + 1);
	int i = 0;
	if (!z)
		return (NULL);
	while (i < needed)
	{
		z[i] = '0';
		i++;
	}
	z[i] = '\0';
	return (z);
}

/* Convert positive n => decimal string. E.g. 42 => "42". If 0 => "0". */
char *ft_lltoa_no_sign(long long n)
{
	char buffer[32];
	int  i;
	char *result;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	while (n > 0 && i < 31)
	{
		buffer[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	buffer[i] = '\0';
	/* reverse the partial buffer in place */
	ft_reverse(buffer, i);
	result = ft_strdup(buffer);
	return (result);
}

/* If precision=0 and the string is "0", => become "".
   Else if precision>length => zero-pad to 'precision' digits. */
char *ft_apply_precision(char *digits, t_format_info *info)
{
	int len = ft_strlen(digits);
	char *tmp;

	if (info->precision_specified && info->precision == 0
		&& digits[0] == '0' && digits[1] == '\0')
	{
		free(digits);
		return (ft_strdup(""));
	}
	if (info->precision_specified && info->precision > len)
	{
		int needed = info->precision - len;
		char *zeros = ft_make_zeros(needed);
		if (!zeros)
			return (digits); /* out of memory => fallback */
		tmp = digits;
		digits = ft_strjoin(zeros, digits);  /* e.g. "00" + "42" */
		free(tmp);
		free(zeros);
	}
	return (digits);
}

/* Prepend sign: '-' if negative, else '+' or ' ' if those flags. */
char *ft_add_sign(char *digits, t_format_info *info, int negative)
{
	char *result;

	if (negative)
		result = ft_strjoin("-", digits);
	else if (info->f.plus == 1)
		result = ft_strjoin("+", digits);
	else if (info->f.space == 1)
		result = ft_strjoin(" ", digits);
	else
		result = ft_strdup(digits);
	free(digits);
	return (result);
}

/*
** If zero-flag is active (f.zero==1), no precision is set, and no '-' flag:
**   zero-pad up to 'width'. 
** But we already have the sign at the front if negative or plus/space.
** e.g. width=5, final_str="-42" => length=3 => we want 2 zeros after '-': "-0042".
*/
char *ft_apply_zero_flag(char *final, t_format_info *info)
{
	int len = ft_strlen(final);
	int needed;
	char *zeros;
	char *digits;
	char sign;
	char *tmp;

	if (info->precision_specified || info->f.minus || !info->f.zero)
		return (final); /* do nothing if any condition overrides zero-flag. */

	if (info->width > len)
	{
		needed = info->width - len;
		/* if first char is sign, we'll keep that out front, then zero-pad the digits */
		if (final[0] == '-' || final[0] == '+' || final[0] == ' ')
		{
			sign = final[0];
			digits = &final[1]; /* skip sign */
			zeros = ft_make_zeros(needed);
			if (!zeros)
				return (final);
			/* e.g. zeros="00", digits="42" => "0042" => re-prepend sign => "-0042" */
			tmp = ft_strjoin(zeros, digits);
			free(zeros);
			char *old = final;
			final = (char *)malloc(ft_strlen(tmp) + 2);
			if (!final)
				return (old);
			final[0] = sign; /* put sign back */
			ft_strlcpy(final + 1, tmp, ft_strlen(tmp) + 1);
			/* e.g. final="-0042" */
			free(tmp);
			free(old);
		}
		else
		{
			/* no sign character => just zero-pad the whole thing */
			zeros = ft_make_zeros(needed);
			if (!zeros)
				return (final);
			tmp = ft_strjoin(zeros, final);
			free(zeros);
			free(final);
			final = tmp;
		}
	}
	return (final);
}

int	ft_print_number_signed(long long n, t_format_info *info)
{
	int  count;
	int  negative;
	char *digits;
	char *with_precision;
	char *with_sign;
	char *final_str;

	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	digits = ft_lltoa_no_sign(n);
	with_precision = ft_apply_precision(digits, info);  
	with_sign = ft_add_sign(with_precision, info, negative);
	final_str = ft_apply_zero_flag(with_sign, info);

	/* Now pass final_str to your existing alignment code. */
	info->s.string = 1;
	count = ft_format_output(final_str, info);
	info->s.string = 0;

	free(final_str);
	return (count);
}

// /*
// ** Convert a positive long long 'n' to a decimal string. If n=0 => "0".
// ** We do a local buffer[] to build digits in reverse, then reverse them at the end.
// */
// char	*ft_lltoa_no_sign(long long n)
// {
// 	char	buffer[32];
// 	int		i;
// 	char	*result;

// 	i = 0;
// 	if (n == 0)
// 		return (ft_strdup("0"));
// 	while (n > 0)
// 	{
// 		buffer[i] = (n % 10) + '0';
// 		n /= 10;
// 		i++;
// 	}
// 	buffer[i] = '\0';
// 	ft_reverse(buffer, i);
// 	result = ft_strdup(buffer);
// 	return (result);
// }

// /*
// ** Attach sign (minus, plus, or space) to the front of the numeric string.
// */
// char	*ft_add_sign(char *num_str, t_format_info *info, int is_neg)
// {
// 	char *final;

// 	final = NULL;
// 	if (is_neg)
// 		final = ft_strjoin("-", num_str);
// 	else if (info->f.plus == 1)
// 		final = ft_strjoin("+", num_str);
// 	else if (info->f.space == 1)
// 		final = ft_strjoin(" ", num_str);
// 	else
// 		final = ft_strdup(num_str);
// 	return (final);
// }

// /*
// ** If 'precision' is set => pad with zeroes up to 'precision'.
// ** If number == "0" and precision=0 => produce "".
// */
// char *ft_apply_precision(char *num_str, t_format_info *info)
// {
// 	int len;
// 	int needed;
// 	char *old;
// 	char *pad;

// 	// If "0" and precision=0 => empty string
// 	if (info->precision_specified && info->precision == 0
// 		&& num_str[0] == '0' && num_str[1] == '\0')
// 	{
// 		free(num_str);
// 		return (ft_strdup(""));
// 	}

// 	len = ft_strlen(num_str);
// 	if (info->precision_specified && info->precision > len)
// 	{
// 		needed = info->precision - len;
// 		pad = (char *)malloc(needed + 1);
// 		if (!pad)
// 			return (num_str);
// 		for (int i = 0; i < needed; i++)
// 			pad[i] = '0';
// 		pad[needed] = '\0';
// 		old = num_str;
// 		num_str = ft_strjoin(pad, num_str);
// 		free(old);
// 		free(pad);
// 	}
// 	return (num_str);
// }

// /*
// ** If we have no precision, but zero-flag is set => we do zero padding up to width
// ** *before* adding sign, because the minus sign should appear first:
// **   e.g. "%05d", -42 => "-0042"
// ** We'll do that after we decide sign though in real logic. This snippet is one approach.
// */
// char *ft_apply_zero_flag(char *num_str, t_format_info *info, int is_neg)
// {
// 	int len;
// 	int needed;
// 	char *pad;
// 	char *old;
// 	int sign_char;

// 	sign_char = 0;
// 	if (is_neg || info->f.plus == 1 || info->f.space == 1)
// 		sign_char = 1; // e.g. '-' or '+', or ' '

// 	len = ft_strlen(num_str);
// 	// If sign_char is 1, that means first char is sign => we skip that from zero-padding count for digits
// 	if (info->width > len && info->f.minus == 0 && info->f.zero == 1
// 		&& info->precision_specified == 0)
// 	{
// 		needed = info->width - len; 
// 		// example: width=5, len=3 => needed=2
// 		// but if the first char is sign, we only pad the digits, not the sign
// 		// so effectively we might want needed=2 for the digits 
// 		// or we do: needed = info->width - (len - sign_char)
// 		// But simpler approach: we handle sign separately.
// 		if (sign_char == 1)
// 			needed = info->width - (len);
// 		pad = malloc(needed + 1);
// 		if (!pad)
// 			return (num_str);
// 		for (int i = 0; i < needed; i++)
// 			pad[i] = '0';
// 		pad[needed] = '\0';

// 		// if sign_char => the sign is the first char of num_str
// 		if (sign_char == 1)
// 		{
// 			// e.g. num_str = "-42", we want => "-0042"
// 			char sign = num_str[0]; // '-','+',' ' 
// 			char *digits = num_str + 1; 
// 			old = num_str;
// 			num_str = ft_strjoin(pad, digits); // "00" + "42" => "0042"
// 			free(old);
// 			// re-insert sign at front
// 			char *temp = num_str;
// 			num_str = ft_strjoin_char(sign, num_str); 
// 			// e.g. '-' + "0042" => "-0042"
// 			free(temp);
// 		}
// 		else
// 		{
// 			old = num_str;
// 			num_str = ft_strjoin(pad, num_str);
// 			free(old);
// 		}
// 		free(pad);
// 	}
// 	return (num_str);
// }

// /*
// ** Join a single char + string. e.g. sign='-', digits="0042" => "-0042"
// */
// char	*ft_strjoin_char(char c, char *str)
// {
// 	char *res;
// 	int len = ft_strlen(str);

// 	res = (char *)malloc(len + 2);
// 	if (!res)
// 		return (NULL);
// 	res[0] = c;
// 	for (int i = 0; i < len; i++)
// 		res[i + 1] = str[i];
// 	res[len + 1] = '\0';
// 	return (res);
// }

// /*
// ** High-level function to print %d / %i from an *int* as a signed number.
// ** 1) detect sign
// ** 2) build digits ignoring negativity
// ** 3) apply precision => might zero-pad
// ** 4) attach sign (if negative, plus, or space)
// ** 5) if no precision => if zero-flag => do zero-padding up to width
// ** 6) pass final string to ft_format_output for left or right alignment with spaces
// */
// int	ft_print_number_signed(long long n, t_format_info *info)
// {
// 	int   count;
// 	int   is_neg;
// 	char  *digits;
// 	char  *with_precision;
// 	char  *with_sign;
// 	char  *final;

// 	count = 0;
// 	is_neg = 0;
// 	if (n < 0)
// 	{
// 		is_neg = 1;
// 		n = -n; // flip to positive
// 	}
// 	digits = ft_lltoa_no_sign(n); // "0", "42", "999", ...
// 	with_precision = ft_apply_precision(digits, info); 
// 	// with_precision might be same pointer or new if we added zeros
// 	free(digits);

// 	with_sign = ft_add_sign(with_precision, info, is_neg);
// 	// e.g. "-42", "+42", or " 42"
// 	free(with_precision);

// 	// now handle zero-flag (only if no precision).
// 	final = ft_apply_zero_flag(with_sign, info, is_neg);
// 	with_sign = ft_add_sign(with_precision, info, is_neg);
// 	free(with_precision);
// 	final = ft_apply_zero_flag(with_sign, info, is_neg);
// 	if (final != with_sign)
// 		free(with_sign);

// 	// pass final string to your existing ft_format_output => handles width and minus
// 	info->s.string = 1; 
// 	count = ft_format_output(final, info);
// 	info->s.string = 0;

// 	free(final);
// 	return (count);
// }

// int	ft_print_number_signed(long n, t_format_info *info)
// {
// 	int		count;
// 	char	*num_part;
// 	char	*final_str;
// 	int		len_num_part;
// 	long	tmp;

// 	count = 0;
// 	final_str = NULL;
// 	printf("Argument is: %ld\n", n);
// 	if (n < 0)
// 		tmp = ft_neg(n, info);
// 	else
// 		tmp = n;
// 	printf("Argument after becoming positive(tmp): %ld\n", tmp);
// 	printf("Argument itself(n): %ld\n", n);
// 	num_part = ft_ltoa_no_sign(tmp);
// 	printf("The string is: %s\n", num_part);
// 	num_part = ft_null(info, num_part);
// 	len_num_part = ft_strlen(num_part);
// 	if ((info->precision_specified == 1 || info->width > 0)
// 			&& info->precision > len_num_part)
// 		{
// 			num_part = ft_zero_pad(info, len_num_part, num_part);
// 			printf("Padded string: %s\n", num_part);
// 		}
// 	final_str = ft_signs(info, final_str, num_part);
// 	printf("And the final string (after '+- ' signs checked) is: %s\n", final_str);
// 	info->s.string = 1;
// 	count = ft_format_output(final_str, info);
// 	free_two(num_part, final_str);
// 	info->s.string = 0;
// 	return (count);
// }

// char	*ft_ltoa_no_sign(long n)
// {
// 	char	buffer[32];
// 	char	*result;
// 	int		i;
// 	long	tmp;
// 	char	*to_reverse;

// 	// printf("Ltoa in action\n");
// 	if (n == 0)
// 		return (ft_strdup("0"));
// 	i = 0;
// 	tmp = n;
// 	// printf("Value of tmp: %ld\n", tmp);
// 	while (tmp > 0)
// 	{
// 		// printf("Printing the reversed buffer %d\n", i);
// 		// printf("Buffer at position %d: %d\n", i, buffer[i]);
// 		buffer[i] = (tmp % 10) + '0';
// 		tmp = tmp / 10;
// 		i++;
// 	}
// 	buffer[i] = '\0';
// 	to_reverse = ft_reverse(buffer, i);
// 	result = ft_strdup(to_reverse);
// 	return (result);
// }

// char	*ft_signs(t_format_info *info, char *fin_str, char *n_part)
// {
// 	if (info->is_neg == 1)
// 		fin_str = ft_strjoin("-", n_part);
// 	else if (info->f.plus == 1)
// 		fin_str = ft_strjoin("+", n_part);
// 	else if (info->f.space == 1)
// 		fin_str = ft_strjoin(" ", n_part);
// 	else
// 		fin_str = ft_strdup(n_part);
// 	return (fin_str);
// }

// long	ft_neg(long n, t_format_info *info)
// {
// 	info->is_neg = 1;
// 	n = -n;
// 	return (n);
// }
