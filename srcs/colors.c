#include "fdf.h"

void	fill_pixel(t_wireframe *w, char r, char g, char b)
{
	w->window.data_addr[w->pixel.p + 2] = r;
	w->window.data_addr[w->pixel.p + 1] = g;
	w->window.data_addr[w->pixel.p + 0] = b;
}

void	find_gradient(t_wireframe *w, float color_coef)
{
	if (color_coef < 0.2)
	{
		color_coef = color_coef / 0.2;
		fill_pixel(w, 255 * (1 - color_coef), 0, (char)255);
	}
	else if (color_coef < 0.4)
	{
		color_coef = (color_coef - 0.2) / 0.2;
		fill_pixel(w, 0, 255 * color_coef, (char)255);
	}
	else if (color_coef < 0.6)
	{
		color_coef = (color_coef - 0.4) / 0.2;
		fill_pixel(w, 0, (char)255, 255 * (1 - color_coef));
	}
	else if (color_coef < 0.8)
	{
		color_coef = (color_coef - 0.6) / 0.2;
		fill_pixel(w, 255 * color_coef, (char)255, 0);
	}
	else
	{
		color_coef = (color_coef - 0.8) / 0.2;
		fill_pixel(w, (char)255, 255 * (1 - color_coef), 0);
	}
}

void	color_pixel(t_wireframe *w, t_point pt)
{
	float	diff;
	float	color_coef;

	diff = 0 - w->min.z;
	pt.z += diff;
	color_coef = pt.z / (w->max.z + diff);
	find_gradient(w, color_coef);
}

void	draw_pixel(t_wireframe *w, t_point p1, t_point pt, t_point p2)
{
	float	total_diff;
	float	temp_diff;
	float	ratio;
	char	*str;

	total_diff = (p2.x - p1.x);
	temp_diff = (p2.x - pt.x);
	ratio = 1 -(temp_diff / total_diff);
	pt.z = p1.z + (ratio * (p2.z - p1.z));
	color_pixel(w, pt);
	w->pixel.p = ((HEIGHT - ((int)pt.y)) * w->window.size);
	w->pixel.p += ((WIDTH - ((int)pt.x)) * 4);
}
