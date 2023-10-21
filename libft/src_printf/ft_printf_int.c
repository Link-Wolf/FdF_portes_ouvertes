/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 07:38:33 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/14 16:33:03 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_int(va_list args, int *count)
{
	char	*str;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return ;
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
