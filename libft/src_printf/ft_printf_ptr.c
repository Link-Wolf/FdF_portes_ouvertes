/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:39:08 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/14 16:33:15 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_ptr(va_list args, int *count)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr_fd("0x0", 1);
		(*count) += 3;
	}
	else
	{
		str = ft_ultoa_base((unsigned long) ptr, "0123456789abcdef");
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
		*count += (2 + ft_strlen(str));
		free(str);
	}
}
