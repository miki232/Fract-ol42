/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:52:11 by mtoia             #+#    #+#             */
/*   Updated: 2022/09/26 15:51:05 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <math.h>
# include <stdlib.h>

typedef struct t_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			btxp;
	int			line_length;
	int			endian;
	double		maxiterations;
	int			which_fract;
	int			key;
	int			y;
	int			x;
	int			ih;
	int			iw;
	int			i;
	int			p;
	int			mouse_x;
	int			mouse_y;
	double		ore;
	double		oim;
	double		newre;
	double		newim;
	double		pi;
	double		pr;
	double		zo;
	double		zoc;
	double		mmx;
	double		movex;
	double		mvy;
	double		inc;
	double		cre;
	double		cim;
	double		fac;
	double		cy;
	double		cx;
	double		ra;
	double		xx;
	double		yy;
	double		incy;
	double		incx;
	double		y2;
	double		x2;
}	t_frt;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_hsl
{
	int		h;
	float	s;
	float	l;
}	t_hsl;

typedef struct t_arg
{
	int		argc;
	char	**argv;
}	t_args;

typedef enum e_keys
{
	KB_PAGE_UP = 116,
	KB_PAGE_DOWN = 121,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53,
	PLUS = 69,
	MINUS = 78,
	RIGHT = 123,
	LEFT = 124,
	UP = 125,
	DOWN = 126,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_keys;

void	input(t_frt *d, t_args *arg);
void	init_para(t_frt *d);
void	init_mlx(t_frt *d);
void	mand_init(t_frt *d, t_args *arg);
void	jul_init(t_frt *d, t_args *arg);
void	new_init(t_frt *d, t_args *arg);
void	whichfract(t_frt *d);
void	my_mlx_pixel_put(t_frt *data, int x, int y, int color);
void	put2screen(t_frt *data);
void	error(void);
void	print_command(void);
void	e_string(void);
void	errormand(void);
void	ff(t_frt *d);
void	errornewt(void);
int		ftsclose(void *data);
int		check(char *str);
int		keypress(int key, t_frt *data);
int		mandel(t_frt *d);
int		julia(t_frt *d);
int		clear(t_frt *data);
int		colosr(float i, int p);
int		color(int inter, t_frt *data);
int		pal_mkg(int p, int i, t_frt *d);
int		zoom(t_frt *data);
int		zoomout(t_frt *data);
int		left(t_frt *data);
int		right(t_frt *data);
int		up(t_frt *data);
int		pro(int x, int y, t_frt *d);
int		mouse(int button, t_frt *param);
int		mouseclick(int keycode, int x, int y, t_frt *e);
int		color2(int inter, t_frt *t_data);
double	doubleatoi(const char *str);

#endif