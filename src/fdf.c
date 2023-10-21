/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:26:10 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/31 15:26:00 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vector3	***init_tab(t_fdf *fdf, char *file);
static t_vector3	***malloc_tab(int i, int j, char *file);
static t_vector3	***fill_tab(t_vector3 ***tab, int i, int j, char *file);
static void			init_fdf(t_fdf *fdf);
static int tourner_dans_le_vide_vide(t_fdf *fdf);

#include <time.h>

int	main(int argc, char *argv[])
{
	t_fdf		fdf;

	srand(time(NULL));
	if (argc != 2 || !ft_strrchr(argv[1], '.')
		|| ft_strcmp(ft_strrchr(argv[1], '.') + 1, "fdf"))
		return (ft_printf("Usage : ./fdf [fdf file location]\n"));
	fdf.fd = open(argv[1], O_RDONLY);
	if (fdf.fd < 0)
	{
		perror("Error ");
		return (-1);
	}
	fdf.tab = init_tab(&fdf, argv[1]);
	if (!fdf.tab)
		return (ft_printf("Error : get shreked by malloc\n"));
	init_fdf(&fdf);
	draw_tab(&fdf);
	mlx_put_image_to_window(fdf.img_ptr, fdf.win_ptr, fdf.img_ptr, 0, 0);
	mlx_hook(fdf.win_ptr, ON_KEYDOWN, 1, keydown, &fdf);
	mlx_hook(fdf.win_ptr, ON_DESTROY, 0, close_fdf, &fdf);
	//after here
	mlx_loop_hook(fdf.mlx_ptr, tourner_dans_le_vide_vide, &fdf);
	//before here
	mlx_loop(fdf.mlx_ptr);
}

static int tourner_dans_le_vide_vide(t_fdf *fdf)
{
	int qwerty;
	static unsigned char r, g, b;

	r = rand();
	g = rand();
	b = rand();
	qwerty = rand() % 2;
	if (qwerty)
		r++;
	else
		r--;
	qwerty = rand() % 2;
	if (qwerty)
		g++;
	else
		g--;
	qwerty = rand() % 2;
	if (qwerty)
		b++;
	else
		b--;
	fdf->bg_color = r << 16 | g << 8 | b;
	fdf->a += .042;
	fdf->b += .018;
	fdf->c += .069;
	qwerty = rand() % 2;
	if (qwerty && fdf->z <= 25)
		fdf->z *= 1.01;
	else if (!qwerty && fdf->z > 8)
		fdf->z /= 1.01;
	//mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_bzero(fdf->px_addr, fdf->line_bytes * fdf->h);
	draw_tab(fdf);
	mlx_put_image_to_window(fdf->img_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 50, 50, mlx_get_color_value(fdf->mlx_ptr, 0x00FFFFFF), "\"Retrospective de premiere mensualite a 42Mulhouse\"");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 130, 80, mlx_get_color_value(fdf->mlx_ptr, 0x00FFFFFF), "2022 - iCARUS & xxxxxxx");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 90, 110, mlx_get_color_value(fdf->mlx_ptr, 0x00FFFFFF), "Students since 21/02/2022");
	usleep(16000);
	return (0);
}

static void	init_fdf(t_fdf *fdf)
{
	fdf->z = sqrt(25 * 8);
	fdf->w = 2560;
	fdf->h = 1440;
	//5120 x 2880)
	fdf->dx = fdf->w / 2;
	fdf->dy = fdf->h / 2;
	fdf->a = 0;
	fdf->c = 0;
	fdf->b = 0;
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->w, fdf->h, "Portes ouvertes 42 Mulhouse");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->w, fdf->h);
	fdf->px_addr = (int *) mlx_get_data_addr(fdf->img_ptr, &fdf->pixel_bits,
			&fdf->line_bytes, &fdf->endian);
}

static t_vector3	***fill_tab(t_vector3 ***tab, int i, int j, char *file)
{
	char	*tmp;
	char	**temp;
	int		fd;
	int		i_bis;
	int		j_bis;

	fd = open(file, O_RDONLY);
	i_bis = i + 1;
	while (--i_bis)
	{
		j_bis = j + 1;
		tmp = get_next_line(fd);
		temp = ft_split(tmp, ' ');
		if (ft_tab_size(temp) != j)
		{
			perror("Error ");
			exit(-1);
		}
		while (--j_bis)
			tab[i - i_bis][j_bis - 1] = (t_vector3 *) new_v3(i
					- i_bis - 19, j_bis - 1 - 8, ft_atoi(temp[j_bis - 1]));
		free(tmp);
		free(temp);
	}
	return (tab);
}

static t_vector3	***malloc_tab(int i, int j, char *file)
{
	t_vector3	***tab;
	int			index;

	tab = ft_calloc(sizeof (t_vector3 **), i + 1);
	if (!tab)
		return (NULL);
	index = 0;
	while (index < i)
	{
		tab[index] = ft_calloc(sizeof (t_vector3 *), j + 1);
		if (!tab[index++])
		{
			index = 0;
			while (tab[index])
				free (tab[index++]);
			return (NULL);
		}
	}
	return (fill_tab(tab, i, j, file));
}

static t_vector3	***init_tab(t_fdf *fdf, char *file)
{
	char	**temp;
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = get_next_line(fdf->fd);
	temp = ft_split(tmp, ' ');
	if (!temp)
		return (NULL);
	j = ft_tab_size(temp);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fdf->fd);
		i++;
	}
	close(fdf->fd);
	free(tmp);
	free(temp);
	fdf->x = i;
	fdf->y = j;
	return (malloc_tab(i, j, file));
}
