#include "fdf.h"

void	draw_pixel(t_wireframe *w, t_point	p)
{
	t_pixel	pixel;
	w->pixel.r = (char)255;
	w->pixel.g = (char)0;
	w->pixel.b = (char)255;
	//color_pixel(w, p.z);
	pixel.p = ((HEIGHT - (HEIGHT - p.y) - 1) * w->window.size) + ((WIDTH - (WIDTH - p.x)- 1) * 4);
	w->window.data_addr[pixel.p + 2] = pixel.r;
	w->window.data_addr[pixel.p + 1] = pixel.g;
	w->window.data_addr[pixel.p + 0] = pixel.b;
}

void	draw_wire(t_wireframe *w, t_point p1, t_point p2)
{
	float	dx;
	float	dy;
	float	e;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
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
						while ((int)p1.x < (int)p2.x)
						{
							draw_pixel(w, p1);
							e -= dy;
							if (e < 0)
							{
								p1.y += 1;
								e += dx;
							}
							p1.x += 1;
						}
					}
					else // vecteur oblique proche de la verticale, dans le 2d octant
					{
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while ((int)p1.y != (int)p2.y)
						{
							draw_pixel(w, p1);
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
						//printf("Step 9\n");
					if (dx >= -dy)
					{
						//printf("Step 10\n");
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while ((int)p1.x < (int)p2.x)
						{
						//printf("Step 11\n");
							draw_pixel(w, p1);
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
						//printf("Step 12\n");

						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while ((int)p1.y > (int)p2.y)
						{
						//printf("Step 13\n");
							draw_pixel(w, p1);
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
						//printf("Step 14\n");

				while ((int)p1.x < (int)p2.x)
				{
						//printf("Step 15\n");

					draw_pixel(w, p1);
					p1.x += 1;
				}
			}
		}
		else
		{
			//printf("Step 16\n");
			if (dy != 0)
			{
				//printf("Step 17\n");
				if (dy > 0)
				{
					//printf("Step 18\n");
					if (-dx >= dy)
					{
						//printf("Step 19\n");
						e = dx;
						dy = dy * 2;
						dx = dx * 2;
						while ((int)p1.x < (int)p2.x)
						{
							//printf("Step 20\n");
							//printf("x1 = %d\n", (int)p1.x);
							//printf("x2 = %d\n", (int)p2.x);
							draw_pixel(w, p1);
							e += dy;
							if (e >= 0)
							{
								p1.y += 1;
								e += dx;
							}
							p1.x += 1;
						}
					}
					else
					{
						//printf("Step 21\n");

						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while ((int)p1.y != (int)p2.y)
						{
						//printf("Step 22\n");
							draw_pixel(w, p1);
							e += dx;
							if (e <= 0)
							{
								p1.x += 1;
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
							draw_pixel(w, p1);
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
							draw_pixel(w, p1);
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
						printf("Step 29\n");

				while ((int)p1.x != (int)p2.x)
				{
						printf("Step 30\n");

					draw_pixel(w, p1);
					p1.x -= 1;
				}
			}
		}
	}
	else
	{
						printf("Step 31\n");

		if (dy != 0)
		{
						printf("Step 32\n");

			if (dy > 0)
			{
						printf("Step 33\n");

 				while ((int)p1.y != (int)p2.y)
				{
						printf("Step 34\n");

					draw_pixel(w, p1);
					p1.y += 1;
				}
			}
			else
			{
						printf("Step 35\n");

				while ((int)p1.y != (int)p2.y)
				{
						printf("Step 36\n");

					draw_pixel(w, p1);
					p1.y -= 1;
				}
			}
		}
	}
}