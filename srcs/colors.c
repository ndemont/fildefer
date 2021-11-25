#include "fdf.h"

void		color_pixel(t_wireframe *wireframe, float altitude)
{
	float	scale;
	float	coef;
	float	diff;
	float	limit;
	float	level;
	float	z_min;
	float	z_max;

	z_min = 0;
	z_max = 10;
	diff = z_max - z_min;
	level = altitude + diff;
	scale = diff / 4;
	if (altitude < (z_min + scale))
	{
		limit = z_min + (scale * 4) + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)0;
		wireframe->pixel.g = (char)(255 * (1 - coef));
		wireframe->pixel.g = (char)255;

	}
	else if (altitude < (z_min + scale * 2))
	{
		limit = z_min + (scale * 3) + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)0;
		wireframe->pixel.g = (char)255;
		wireframe->pixel.g = (char)(255 * coef);
	}
	else if (altitude < (z_min + scale * 3))
	{
		limit = z_min + (scale * 2) + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)(255 * (1 - coef));
		wireframe->pixel.g = (char)255;
		wireframe->pixel.g = (char)0;
	}
	else
	{
		limit = z_min + scale + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)255;
		wireframe->pixel.g = (char)(255 * coef);
		wireframe->pixel.b = (char)0;
	}
}