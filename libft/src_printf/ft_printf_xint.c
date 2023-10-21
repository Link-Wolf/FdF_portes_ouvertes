/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:39:30 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/14 16:33:32 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_xint(va_list args, int *count)
{
	unsigned int	a;
	char			*str;

	a = (unsigned int) va_arg(args, int);
	str = ft_utoa_base(a, "0123456789abcdef");
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
