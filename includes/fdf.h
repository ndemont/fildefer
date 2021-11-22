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
#  define SWITCH_CAM 0x31
#  define FILTER 0x03
#  define ESC 0x35
#endif


typedef struct		s_img
{
	void			*img_ptr;
	unsigned char	*data_addr;
}					t_img;

typedef struct		s_pixel
{
	int				p;
	char			r;
	char			g;
	char			b;
}					t_pixel;

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
}				t_point;

typedef struct		s_matrix
{
	t_point		r1;
	t_point		r2;
	t_point		r3;
	t_point		r4;
}					t_matrix;

typedef struct s_ray
{
	t_point	origin;
	t_point	direction;
}				t_ray;

typedef struct	s_wire
{
	t_point	start;
	t_point	end;
}				t_wire;

typedef struct	s_wireframe
{
	int				point_nbr;
	int				x_shift;
	int				y_shift;
	int				x_max;
	int				x_min;
	int				z_max;
	int				z_min;
	int				y_max;
	int				y_min;
	t_point			**map;
	int				x_len;
	int				y_len;
	t_ray			ray;
	float			**altitudes;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				size;
	int				endian;
	int				bits_per_pixel;
	unsigned char	*data_addr;
	t_ray			camera;
	float			direction;
	t_pixel			pixel;
	float			zoom;
	float			pos[2];
	float			amplitude;
	t_point**		map;
}				t_wireframe;

t_wireframe	*parsing(char *file);
t_wireframe	*free_wireframe(t_wireframe *wireframe, int errno);
void		print_error(int errno);

void	fill_window(t_wireframe *wireframe);
int		ft_close_win(int keycode, t_wireframe *s);
int		ft_event(int keycode, t_wireframe *w);
int		ft_cross(int keycode, t_wireframe *s);

void	display_window(t_wireframe *wireframe);
void	ft_move_cam(int keycode, t_wireframe *w);

void	print_z(t_wireframe *w);
void	color_pixel(t_wireframe *wireframe, float altitude);
void	draw_wire(t_wireframe *w, t_point p1, t_point p2);

void	move_y(t_wireframe *w, int shift);
void	move_x(t_wireframe *w, int shift);

#endif