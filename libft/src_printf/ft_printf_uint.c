/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:39:19 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/14 16:33:23 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_uint(va_list args, int *count)
{
	char	*str;

	str = ft_utoa(va_arg(args, unsigned int));
	if (!str)
		return ;
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
