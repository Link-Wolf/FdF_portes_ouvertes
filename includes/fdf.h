/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:19:39 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/03/31 14:11:07 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# ifndef T_VECTOR2
#  define T_VECTOR2

typedef struct s_vector2 {
	double	x;
	double	y;
}			t_vector2;
# endif

# ifndef T_VECTOR3
#  define T_VECTOR3

typedef struct s_vector3 {
	double	x;
	double	y;
	double	z;
}			t_vector3;
# endif

# ifndef T_MATRIX33
#  define T_MATRIX33

typedef struct s_matrix33 {
	double	m00;
	double	m01;
	double	m02;
	double	m10;
	double	m11;
	double	m12;
	double	m20;
	double	m21;
	double	m22;
}			t_matrix33;
# endif

# ifndef T_MATRIX32
#  define T_MATRIX32

typedef struct s_matrix32 {
	double	m00;
	double	m01;
	double	m10;
	double	m11;
	double	m02;
	double	m12;
}			t_matrix32;
# endif

# ifndef T_FDF
#  define T_FDF

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			line_bytes;
	int			pixel_bits;
	int			endian;
	int			*px_addr;
	t_vector3	***tab;
	t_vector2	***vec;
	int			proj;
	int			fd;
	int			h;
	int			w;
	double		z;
	double		a;
	double		b;
	double		c;
	int			dx;
	int			dy;
	int			x;
	int			y;
	int 		bg_color;
}		t_fdf;
# endif

# ifndef T_H
#  define T_H

typedef struct s_h {
	double	a;
	double	b;
}			t_h;
# endif

void		super_free(t_fdf *fdf);
t_vector3	*new_v3(double x, double y, double z);
t_vector2	*new_v2(double x, double y);
t_matrix32	*new_m32(t_vector2 *c0, t_vector2 *c1, t_vector2 *c2);
t_matrix33	*new_m33(t_vector3 *c0, t_vector3 *c1, t_vector3 *c2);
t_matrix33	*new_diag_m33(double x, double y, double z);
void		draw_tab(t_fdf *fdf);
t_matrix32	*mult_m32_m33(t_matrix32 *a, t_matrix33 *b);
t_matrix33	*mult_m33_m33(t_matrix33 *a, t_matrix33 *b);
t_vector2	*mult_m32_v3(t_matrix32 *a, t_vector3 *v);
t_vector3	*mult_m33_v3(t_matrix33 *a, t_vector3 *v);
t_vector2	*mult_k_v2(double k, t_vector2 *v);
int			tab_tab_vector3_size(t_vector3 ***tab);
int			tab_vec_s(t_vector3 **tab);
int			keydown(int keycode, t_fdf *vars);
int			close_fdf(t_fdf *vars);
int			mousedown(int button, int x, int y, t_fdf *vars);
int			get_color(double high, t_fdf *fdf);
void		free_3d(void ***tab);
void		go_line_go(t_h h, t_fdf *fdf, int i, int j);
void		draw_line(t_vector2	*a, t_vector2 *b, t_fdf *fdf, t_h h);

#endif
