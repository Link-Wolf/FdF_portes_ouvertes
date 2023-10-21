/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_vector_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:21:35 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/31 14:13:51 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	tab_tab_vector3_size(t_vector3 ***tab)
{
	int	i;

	i = 0;
	while (tab[i++])
		;
	return (i);
}

int	tab_vec_s(t_vector3 **tab)
{
	int	i;

	i = 0;
	while (tab[i++])
		;
	return (i);
}

void	super_free(t_fdf *fdf)
{
	free_3d((void ***) fdf->tab);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
}

int	get_color(double high, t_fdf *fdf)
{
	(void) fdf;
	if (high < 0)
		return 0;
	return (fdf->bg_color);
}

void	free_3d(void ***tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
	free(tab);
}
