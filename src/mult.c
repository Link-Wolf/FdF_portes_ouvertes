/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:17:23 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/31 13:22:28 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix32	*mult_m32_m33(t_matrix32 *a, t_matrix33 *b)
{
	t_matrix32	*res;

	res = ft_calloc(1, sizeof (t_matrix32));
	if (!res)
		return (NULL);
	res->m00 = a->m00 * b->m00 + a->m01 * b->m10 + a->m02 * b->m20;
	res->m10 = a->m10 * b->m00 + a->m11 * b->m10 + a->m12 * b->m20;
	res->m01 = a->m00 * b->m01 + a->m01 * b->m11 + a->m02 * b->m21;
	res->m11 = a->m10 * b->m01 + a->m11 * b->m11 + a->m12 * b->m21;
	res->m02 = a->m00 * b->m02 + a->m01 * b->m12 + a->m02 * b->m22;
	res->m12 = a->m10 * b->m02 + a->m11 * b->m12 + a->m12 * b->m22;
	free(a);
	free(b);
	return (res);
}

t_matrix33	*mult_m33_m33(t_matrix33 *a, t_matrix33 *b)
{
	t_matrix33	*res;

	res = ft_calloc(1, sizeof (t_matrix33));
	if (!res)
		return (NULL);
	res->m00 = a->m00 * b->m00 + a->m01 * b->m10 + a->m02 * b->m20;
	res->m10 = a->m10 * b->m00 + a->m11 * b->m10 + a->m12 * b->m20;
	res->m20 = a->m20 * b->m20 + a->m21 * b->m10 + a->m22 * b->m20;
	res->m01 = a->m00 * b->m01 + a->m01 * b->m11 + a->m02 * b->m21;
	res->m11 = a->m10 * b->m01 + a->m11 * b->m11 + a->m12 * b->m21;
	res->m21 = a->m20 * b->m21 + a->m21 * b->m11 + a->m22 * b->m21;
	res->m02 = a->m00 * b->m02 + a->m01 * b->m12 + a->m02 * b->m22;
	res->m12 = a->m10 * b->m02 + a->m11 * b->m12 + a->m12 * b->m22;
	res->m22 = a->m20 * b->m22 + a->m21 * b->m12 + a->m22 * b->m22;
	free(a);
	free(b);
	return (res);
}

t_vector2	*mult_m32_v3(t_matrix32 *a, t_vector3 *v)//musnt free v
{
	t_vector2	*res;

	res = ft_calloc(1, sizeof (t_vector2));
	if (!res)
		return (NULL);
	res->x = v->x * a->m00 + v->y * a->m01 + v->z * a->m02;
	res->y = v->x * a->m10 + v->y * a->m11 + v->z * a->m12;
	free(a);
	return (res);
}

t_vector3	*mult_m33_v3(t_matrix33 *a, t_vector3 *v)
{
	t_vector3	*res;

	res = ft_calloc(1, sizeof (t_vector3));
	if (!res)
		return (NULL);
	res->x = v->x * a->m00 + v->y * a->m01 + v->z * a->m02;
	res->y = v->x * a->m10 + v->y * a->m11 + v->z * a->m12;
	res->z = v->x * a->m20 + v->y * a->m21 + v->z * a->m22;
	free(a);
	free(v);
	return (res);
}

t_vector2	*mult_k_v2(double k, t_vector2 *v)
{
	t_vector2	*res;

	res = ft_calloc(1, sizeof (t_vector2));
	if (!res)
		return (NULL);
	res->x = v->x * k;
	res->y = v->y * k;
	free(v);
	return (res);
}
