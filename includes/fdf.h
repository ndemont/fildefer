/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:39:26 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/28 15:45:22 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HPP
#define FDF_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"
#include "get_next_line.h"

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#define FOV (70 * (M_PI / 180))
#define HEIGHT 1000
#define WIDTH 1000
#define	X_SHIFT 350
#define	Y_SHIFT 200
# if LINUX == 1
#  define MOVE_R 65363
#  define MOVE_L 65361
#  define MOVE_F 65362
#  define MOVE_B 65364
#  define SWITCH_CAM 32
#  define FILTER 41
#  define ESC 65307
# else
#  define MOVE_R 0x7C
#  define MOVE_L 0x7B
#  define MOVE_F 0x7E
#  define MOVE_B 0x7D
#  define ZOOM_IN 0x18
#  define ZOOM_OUT 0x1B
#  define SWITCH_CAM 0x31
#  define FILTER 0x03
#  define ESC 0x35
#endif

typedef struct	s_pixel
{
	int			p;
	char		r;
	char		g;
	char		b;
}				t_pixel;

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
}				t_point;

typedef struct	s_window
{
	int				size;
	int				endian;
	int				bits_per_pixel;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_addr;
}				t_window;

typedef struct	s_wireframe
{
	float			x_center;
	float			y_center;
	float			x_len;
	float			y_len;
	t_point			min;
	t_point			max;
	t_pixel			pixel;
	t_window		window;
	t_point			**map;
}				t_wireframe;

/* ************************************************************************** */
/*                           Initialization                                   */
/* ************************************************************************** */

void		init_wireframe(t_wireframe *wireframe);
void		init_window(t_window *window);
void		init_pixel(t_pixel *pixel, int r, int g, int b);

/* ************************************************************************** */
/*                           Parsing                                          */
/* ************************************************************************** */

int			get_dimensions(char *file, t_wireframe *wireframe);

/* ************************************************************************** */
/*                           Parsing                                          */
/* ************************************************************************** */

int			parsing(char *file, t_wireframe *wireframe);

/* ************************************************************************** */
/*                           Map Settings                                     */
/* ************************************************************************** */

void	set_map(t_wireframe *w);
void	center_map(t_wireframe*w);
void	zoom_map(t_wireframe *w, float zoom);
void	zoom2_map(t_wireframe *w, float zoom);
void	move_x(t_wireframe *w, int shift);
void	move_y(t_wireframe *w, int shift);
void	zoom(t_wireframe*w, int	zoom);
void	update_limits(t_wireframe *w, float x, float y, float z);
float	set_zoom(t_wireframe *w);
/* ************************************************************************** */
/*                           Window Settings                                  */
/* ************************************************************************** */

void	fill_window(t_wireframe *w);
void	display_window(t_wireframe *wireframe);

/* ************************************************************************** */
/*                         Bresenham Algorithm                                */
/* ************************************************************************** */

void	first_octant(t_wireframe *w, t_point p1, t_point p2);
void	second_octant(t_wireframe *w, t_point p1, t_point p2);
void	third_octant(t_wireframe *w, t_point p1, t_point p2);
void	forth_octant(t_wireframe *w, t_point p1, t_point p2);
void	fifth_octant(t_wireframe *w, t_point p1, t_point p2);
void	sixth_octant(t_wireframe *w, t_point p1, t_point p2);
void	seventh_octant(t_wireframe *w, t_point p1, t_point p2);
void	eighth_octant(t_wireframe *w, t_point p1, t_point p2);
void	first_dial(t_wireframe *w, t_point p1, t_point p2);
void	second_dial(t_wireframe *w, t_point p1, t_point p2);
void	third_dial(t_wireframe *w, t_point p1, t_point p2);
void	forth_dial(t_wireframe *w, t_point p1, t_point p2);

/* ************************************************************************** */
/*                          Color Settings                                    */
/* ************************************************************************** */

void		color_pixel(t_wireframe *w, t_point pt);
void		draw_wire(t_wireframe *w, t_point p1, t_point p2);
void		draw_pixel(t_wireframe *w, t_point p1, t_point pt, t_point p2);


/* ************************************************************************** */
/*                           Events                                           */
/* ************************************************************************** */

int			ft_close_win(int keycode, t_wireframe *s);
int			ft_event(int keycode, t_wireframe *w);
int			ft_cross(int keycode, t_wireframe *s);
void		ft_move_cam(int keycode, t_wireframe *w);
void		move_y(t_wireframe *w, int shift);
void		move_x(t_wireframe *w, int shift);

/* ************************************************************************** */
/*                           Errors                                           */
/* ************************************************************************** */

void		print_error(int errno);

/* ************************************************************************** */
/*                           Memory                                           */
/* ************************************************************************** */

t_wireframe	*free_wireframe(t_wireframe *wireframe, int errno);

#endif