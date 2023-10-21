/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:28:08 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/16 14:48:46 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	g_minus0 = -0.0;

t_matrix33	*new_m33(t_vector3 *c0, t_vector3 *c1, t_vector3 *c2)
{
	t_matrix33	*res;

	res = ft_calloc(1, sizeof(t_matrix33));
	if (!res)
	{
		ft_printf("Error : zboubobro\n");
		exit (-1);
	}
	res->m00 = c0->x;
	res->m10 = c0->y;
	res->m20 = c0->z;
	res->m01 = c1->x;
	res->m11 = c1->y;
	res->m21 = c1->z;
	res->m02 = c2->x;
	res->m12 = c2->y;
	res->m22 = c2->z;
	return (res);
}

t_matrix32	*new_m32(t_vector2 *c0, t_vector2 *c1, t_vector2 *c2)
{
	t_matrix32	*res;

	res = ft_calloc(1, sizeof(t_matrix32));
	if (!res)
	{
		ft_printf("Error : zboubimax\n");
		exit (-1);
	}
	res->m00 = c0->x;
	res->m10 = c0->y;
	res->m01 = c1->x;
	res->m11 = c1->y;
	res->m02 = c2->x;
	res->m12 = c2->y;
	return (res);
}

t_matrix33	*new_diag_m33(double x, double y, double z)
{
	t_matrix33	*res;

	res = ft_calloc(1, sizeof(t_matrix33));
	if (!res)
	{
		ft_printf("Error : zboubinet\n");
		exit (-1);
	}
	res->m00 = x;
	res->m11 = y;
	res->m22 = z;
	return (res);
}

t_vector3	*new_v3(double x, double y, double z)
{
	t_vector3	*res;

	res = ft_calloc(1, sizeof(t_vector3));
	if (!res)
	{
		ft_printf("Error : zboub\n");
		exit (-1);
	}
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}

t_vector2	*new_v2(double x, double y)
{
	t_vector2	*res;

	res = ft_calloc(1, sizeof(t_vector2));
	if (!res)
	{
		ft_printf("Error : zboubibou\n");
		exit (-1);
	}
	res->x = x;
	res->y = y;
	return (res);
}
