#include "fdf.h"

void	draw_pixel(t_wireframe *w, t_point	p, char	*s)
{

	w->pixel.r = (char)255;
	w->pixel.g = (char)255;
	w->pixel.b = (char)255;
	color_pixel(w, p.z);
	w->pixel.p = ((HEIGHT - ((int)p.y)) * w->window.size) + ((WIDTH - ((int)p.x)) * 4);
	w->window.data_addr[w->pixel.p + 2] = w->pixel.r;
	w->window.data_addr[w->pixel.p + 1] = w->pixel.g;
	w->window.data_addr[w->pixel.p + 0] = w->pixel.b;
}

void	draw_wire(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	if (dx != 0)
	{
		if (dx > 0)
		{
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = dx * 2 ;
						dy = dy * 2 ;
						while ((int)p1.x != (int)p2.x)
						{
							draw_pixel(w, p1, 0);
							e -= dy;
							if (e < 0)
							{
								p1.y += 1;
								e += dx;
							}
							p1.x += 1;
						}
					}
					else
					{
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while ((int)p1.y != (int)p2.y)
						{
							draw_pixel(w, p1, 0);
							e -= dx;
							if (e < 0)
							{
								p1.x += 1;
								e += dy;
							}
							p1.y += 1;
						}
					}
				}
				else // dy < 0 (et dx > 0)
				{
					if (dx >= -dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while ((int)p1.x != (int)p2.x)
						{
							draw_pixel(w, p1, 0);
							e += dy;
							if (e < 0)
							{
								p1.y -= 1;
								e += dx;
							}
							p1.x += 1;
						}
					}
					else
					{
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while ((int)p1.y != (int)p2.y)
						{
							draw_pixel(w, p1, 0);
							e += dx;
							if (e > 0)
							{
								p1.x += 1;
								e += dy;
							}
							p1.y -= 1;
						}
					}
				}
			}
			else
			{
				while ((int)p1.x != (int)p2.x)
				{
					draw_pixel(w, p1, 0);
					p1.x += 1;
				}
			}
		}
		else
		{
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dy = dy * 2;
						dx = dx * 2;
						while ((int)p1.x != (int)p2.x)
						{
							draw_pixel(w, p1, 0);
							e += dy;
							if (e >= 0)
							{
								p1.y += 1;
								e += dx;
							}
							p1.x -= 1;
						}
					}
					else
					{
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while ((int)p1.y != (int)p2.y)
						{
							draw_pixel(w, p1, 0);
							e += dx;
							if (e <= 0)
							{
								p1.x -= 1;
								e += dy;
							}
							p1.y += 1;
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while ((int)p1.x != (int)p2.x)
						{
							draw_pixel(w, p1, 0);
							e -= dy;
							if (e >= 0)
							{
								p1.y -= 1;
								e += dx;
							}
							p1.x -= 1;
						}
					}
					else
					{
						e = dy;
						dx = dx * 2;
						dy = dy * 2;
						while ((int)p1.y != (int)p2.y)
						{
							draw_pixel(w, p1, 0);
							e -= dx;
							if (e >= 0)
							{
								p1.x -= 1;
								e += dy;
							}
							p1.y -= 1;
						}
					}
				}
			}
			else
			{
				while ((int)p1.x != (int)p2.x)
				{
					draw_pixel(w, p1, 0);
					p1.x -= 1;
				}
			}
		}
	}
	else
	{
		if (dy != 0)
		{
			if (dy > 0)
			{
 				while ((int)p1.y != (int)p2.y)
				{
					draw_pixel(w, p1, 0);
					p1.y += 1;
				}
			}
			else
			{
				while ((int)p1.y != (int)p2.y)
				{
					draw_pixel(w, p1, 0);
					p1.y -= 1;
				}
			}
		}
	}
}