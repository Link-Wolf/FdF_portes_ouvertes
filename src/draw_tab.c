/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:51:34 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/31 15:10:11 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vector2	*calculate_pos_cav(t_fdf *fdf, int i, int j);
static t_vector2	*calculate_pos_iso(t_fdf *f, int i, int j);
static void			draw_all(t_fdf *fdf);

void	draw_tab(t_fdf *fdf)
{
	int			i;
	int			j;

	i = -1;
	fdf->vec = ft_calloc(tab_tab_vector3_size(fdf->tab), sizeof (t_vector2 **));
	while (fdf->tab[++i])
	{
		fdf->vec[i] = ft_calloc(tab_vec_s(fdf->tab[i]), sizeof (t_vector2 *));
		if (!(fdf->vec[i]))
		{
			super_free(fdf);
			perror("Error :");
			exit (-1);
		}
		j = -1;
		while ((fdf->tab)[i][++j])
		{
			if (fdf->proj)
				fdf->vec[i][j] = calculate_pos_iso(fdf, i, j);
			else
				fdf->vec[i][j] = calculate_pos_cav(fdf, i, j);
		}
	}
	draw_all(fdf);
	return (free(fdf->vec));
}

static t_vector2	*calculate_pos_iso(t_fdf *f, int i, int j)
{
	return (mult_k_v2(f->z, mult_m32_v3(mult_m32_m33(new_m32(new_v2(-sqrt(3)
							/ 3, -sqrt(6) / 6), new_v2(sqrt(3) / 3, -sqrt(6)
							/ 6), new_v2(0, 1)), new_m33(new_v3((cos(f->a
									+ f->b) + cos(f->a - f->b)) / 2, sin(f->b),
							(-sin(f->a + f->b) - sin(f->a - f->b)) / 2), new_v3(
							(-2 * cos (f->a + f->c) + 2 * cos(f->a - f->c)
								- sin(f->a + f->b + f->c) + sin (f->a - f->b
									+ f->c) - sin(f->a + f->b - f->c) + sin(f->a
									- f->b - f->c))
							/ 4, (cos(f->b + f-> c) + cos(f->b - f->c))
							/ 2, (-cos(f->a + f->b + f->c) + cos(f->a
									- f->b + f->c) - cos(f->a + f->b
									- f->c) + cos(f->a - f->b - f->c)
								+ 2 * sin (f->a + f->c) - 2 * sin(f->a
									- f->c)) / 4), new_v3((-cos(f->a
									+ f->b + f->c) + cos(f->a - f->b
									+ f->c) + cos (f->a + f->b - f->c)
								- cos(f->a - f->b - f->c) + 2 * sin(f->a
									+ f->c) + 2 * sin(f->a - f->c)) / 4,
							(-sin(f->b + f->c) + sin (f->b - f->c)) / 2,
							(2 * cos(f->a + f->c) + 2 * cos(f->a - f->c)
								+ sin(f->a + f->b + f->c) - sin(f->a
									- f->b + f->c) - sin(f->a + f->b
									- f->c) + sin(f->a - f->b - f->c))
							/ 4))), f->tab[i][j])));
}

static t_vector2	*calculate_pos_cav(t_fdf *f, int i, int j)
{
	return (mult_k_v2(f->z, mult_m32_v3(mult_m32_m33(new_m32(new_v2(1, 0),
						new_v2(sqrt(2) / 2, -sqrt(2)
							/ 2), new_v2(0, 1)), new_m33(new_v3((cos(f->a
									+ f->b) + cos(f->a - f->b)) / 2, sin(f->b),
							(-sin(f->a + f->b) - sin(f->a - f->b)) / 2), new_v3(
							(-2 * cos (f->a + f->c) + 2 * cos(f->a - f->c)
								- sin(f->a + f->b + f->c) + sin (f->a - f->b
									+ f->c) - sin(f->a + f->b - f->c) + sin(f->a
									- f->b - f->c))
							/ 4, (cos(f->b + f-> c) + cos(f->b - f->c))
							/ 2, (-cos(f->a + f->b + f->c) + cos(f->a
									- f->b + f->c) - cos(f->a + f->b
									- f->c) + cos(f->a - f->b - f->c)
								+ 2 * sin (f->a + f->c) - 2 * sin(f->a
									- f->c)) / 4), new_v3((-cos(f->a
									+ f->b + f->c) + cos(f->a - f->b
									+ f->c) + cos (f->a + f->b - f->c)
								- cos(f->a - f->b - f->c) + 2 * sin(f->a
									+ f->c) + 2 * sin(f->a - f->c)) / 4,
							(-sin(f->b + f->c) + sin (f->b - f->c)) / 2,
							(2 * cos(f->a + f->c) + 2 * cos(f->a - f->c)
								+ sin(f->a + f->b + f->c) - sin(f->a
									- f->b + f->c) - sin(f->a + f->b
									- f->c) + sin(f->a - f->b - f->c))
							/ 4))), f->tab[i][j])));
}

static void	draw_all(t_fdf *fdf)
{
	int	i;
	int	j;
	t_h	h;

	i = 0;
	while (fdf->vec[++i])
	{
		j = 0;
		while (fdf->vec[i][++j])
		{
			if (i == 1)
			{
				h.a = fdf->tab[i - 1][j]->z;
				h.b = fdf->tab[i - 1][j - 1]->z;
				draw_line(fdf->vec[i - 1][j], fdf->vec[i - 1][j - 1], fdf, h);
			}
			if (j == 1)
			{
				h.a = fdf->tab[i][j - 1]->z;
				h.b = fdf->tab[i - 1][j - 1]->z;
				draw_line(fdf->vec[i][j - 1], fdf->vec[i - 1][j - 1], fdf, h);
			}
			go_line_go(h, fdf, i, j);
		}
	}
}

void	draw_line(t_vector2	*a, t_vector2 *b, t_fdf *fdf, t_h h)
{
	double	t;
	int color;


	t = 0;
	while (t < 1)
	{
		if (fdf->dx + (int) floor((a->x * t + b->x * (1 - t))) > 0
			&& fdf->dx + (int) floor((a->x * t + b->x * (1 - t))) < fdf->w
			&& fdf->h - (int) floor((a->y * t + b->y * (1 - t))) - fdf->dy > 0
			&& fdf->h - (int) floor((a->y * t + b->y * (1 - t))) - fdf->dy
			< fdf->h){
			 color = get_color(t * h.a
			 		+ (1 - t) * h.b, fdf);
			if (color)
				*(fdf->px_addr
						+ fdf->dx + (int) floor((a->x * t + b->x * (1 - t)))
						+ (fdf->h - (int) floor((a->y * t + b->y * (1 - t)))
							- fdf->dy) * fdf->line_bytes / 4)
					= mlx_get_color_value(fdf->mlx_ptr, fdf->bg_color);
			}

		t += 0.005;
	}
}
