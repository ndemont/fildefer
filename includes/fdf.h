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
#define FOV M_PI/2
#define HEIGHT 1000
#define WIDTH 1200

typedef struct		s_img
{
	void			*img_ptr;
	unsigned char	*data_addr;
}					t_img;


typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
}				t_point;

typedef struct	s_wire
{
	t_point	a;
	t_point	b;
}				t_wire;

typedef struct	s_wireframe
{
	int				x_len;
	int				y_len;
	int				**altitudes;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				size;
	int				endian;
	int				bits_per_pixel;
	unsigned char	*data_addr;
	t_point			camera;
	float			direction;
}				t_wireframe;

t_wireframe	*parsing(char *file);
t_wireframe	*free_wireframe(t_wireframe *wireframe, int errno);
void		print_error(int errno);

void	fill_window(t_wireframe *wireframe);
int		ft_close_win(int keycode, t_scene *s);
int		ft_event(int keycode, t_wireframe *w);
int		ft_cross(int keycode, t_scene *s)

//void	init_images(t_wireframe *wireframe);
//void	*ft_load_imgs(t_wireframe *wireframe);
//void	ft_new_img(t_wireframe *wireframe);
//void	print_window(void *mlx_ptr, void *win_ptr, void *img_ptr);

#endif