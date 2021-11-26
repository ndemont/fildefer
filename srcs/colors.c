#include "fdf.h"

void		color_pixel(t_wireframe *w,  t_point p1, t_point pt, t_point p2, float ratio)
{
	float	scale;
	float	coef;
	float	diff_total;
	float	diff_to_zero;
	float	diff_to_quarter;
	float	limit_min;
	float	limit_max;
	float	quarter;
	char	*str;

	limit_min = 0;
	limit_max = 0.2;
	pt.z = p1.z + (ratio * (p2.z - p1.z));
	diff_to_zero = 0 - w->min.z;
	diff_total = w->max.z - w->min.z;
	pt.z += diff_to_zero;
	quarter = pt.z / (w->max.z + diff_to_zero);
	str = &w->window.data_addr[w->pixel.p];
	*(unsigned int *)str = 0xFF0000;
	while (limit_max < quarter)
	{
		limit_min += 0.2;
		limit_max += 0.2;
	}
	// printf("coef sur 1 = %f	| ", quarter);
	if (quarter < 0.2)
	{
		quarter = quarter / 0.2;
		w->window.data_addr[w->pixel.p + 2] = (char)(255 * (1 - quarter));
	 	w->window.data_addr[w->pixel.p + 1] = 0;
	 	w->window.data_addr[w->pixel.p + 0] = (char)255;
		printf("color = %x\n", *str);

	}
	else if (quarter < 0.4)
	{
		quarter = (quarter - 0.2) / 0.2;
		w->window.data_addr[w->pixel.p + 2] = 0;
	 	w->window.data_addr[w->pixel.p + 1] = (char)(255 * quarter);
	 	w->window.data_addr[w->pixel.p + 0] = (char)255;
		printf("color = %x\n", *str);


	}
	else if (quarter < 0.6)
	{
		quarter = (quarter - 0.4) / 0.2;
		w->window.data_addr[w->pixel.p + 2] = 0;
	 	w->window.data_addr[w->pixel.p + 1] = (char)255;
	 	w->window.data_addr[w->pixel.p + 0] = (char)(255 * (1 - quarter));
		printf("color = %x\n", *str);
	}
	else if (quarter < 0.8)
	{
		quarter = (quarter - 0.6) / 0.2;
		w->window.data_addr[w->pixel.p + 2] = (char)(255 * quarter);
	 	w->window.data_addr[w->pixel.p + 1] = (char)255;
	 	w->window.data_addr[w->pixel.p + 0] = 0;
		printf("color = %x\n", *str);

	}
	else
	{
		quarter = (quarter - 0.8) / 0.2;
		w->window.data_addr[w->pixel.p + 2] = (char)255;
	 	w->window.data_addr[w->pixel.p + 1] = (char)(255 * (1 - quarter));
	 	w->window.data_addr[w->pixel.p + 0] = 0;
		printf("color = %x\n", *str);

	}
}