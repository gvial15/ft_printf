/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvial <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:27:35 by gvial             #+#    #+#             */
/*   Updated: 2022/04/06 15:27:40 by gvial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	find_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_itox(long n, int caps)
{
	int		len;
	char	*hex;
	char	*result;

	if (n == -2147483648)
		write(1, "80000000", 8);
	len = find_len(n);
	hex = "0123456789abcdef";
	result = ft_calloc(len + 1, sizeof(char));
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = hex[n % 16];
		if (caps == 1)
			result[len] = ft_toupper(hex[n % 16]);
		n /= 16;
	}
	return (result);
}
