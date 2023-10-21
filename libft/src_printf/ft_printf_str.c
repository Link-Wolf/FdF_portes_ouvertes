/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:39:13 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/14 16:33:19 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_str(va_list args, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		(*count) += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		(*count) += ft_strlen(str);
	}
}
