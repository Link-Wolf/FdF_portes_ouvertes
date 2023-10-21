/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:10:05 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/31 14:10:52 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	refresh_window(t_fdf *fdf);

int	keydown(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		close_fdf(fdf);
	return (refresh_window(fdf));
}

int	close_fdf(t_fdf *fdf)
{
	super_free(fdf);
	exit (1);
}
//
// int	mousedown(int button, int x, int y, t_fdf *fdf)
// {
// 	(void) x;
// 	(void) y;
// 	if (button == 5)
// 		(fdf->z) *= 1.1;
// 	if (button == 4)
// 		(fdf->z) /= 1.1;
// 	refresh_window(fdf);
// 	return (1);
// }

static int	refresh_window(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero(fdf->px_addr, fdf->line_bytes * fdf->h);
	draw_tab(fdf);
	mlx_put_image_to_window(fdf->img_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	return (1);
}

void	go_line_go(t_h h, t_fdf *fdf, int i, int j)
{
	h.a = fdf->tab[i][j]->z;
	h.b = fdf->tab[i][j - 1]->z;
	draw_line(fdf->vec[i][j], fdf->vec[i][j - 1], fdf, h);
	h.a = fdf->tab[i - 1][j]->z;
	h.b = fdf->tab[i][j]->z;
	draw_line(fdf->vec[i - 1][j], fdf->vec[i][j], fdf, h);
}
