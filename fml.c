/*
** fml.c for bswireframe in /home/ratouney/bswireframe
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Thu Dec 08 15:02:09 2016 ratouney
** Last update Fri Dec  9 16:29:57 2016 John Doe
*/

#include "advanced.h"

t_vertex		*gen_heightvertex(sfVector2i source, sfVector2i end,
                              sfColor init, sfColor final)
{
  t_vertex *data;

  data = malloc(sizeof(t_vertex));
  data->from = source;
  data->to = end;
  data->srccol = init;
  data->descol = final;
  return (data);
}

void		draw_height(t_my_framebuffer *buffer, t_cam *data,
                    sfVector2i dot_2d, sfVector2i proj_2d)
{
  t_vertex *fade;

  if (data->toggle_vertex == 1)
  {
    fade = gen_heightvertex(dot_2d, proj_2d, HEIGHTVERTEX, HEIGHTCOLOR);
    draw_vertex(buffer, fade);
  }
  if (data->toggle_vertex == -1)
  my_draw_line(buffer, dot_2d, proj_2d, HEIGHTCOLOR);
}

void    draw_projlink(t_my_framebuffer *buffer, t_cam *data,
                      t_mx *points, t_ct var)
{
  sfVector3f dot;
  sfVector2i dot2d;
  sfVector3f nxcl;
  sfVector2i nxcl2d;
  sfVector3f nxln;
  sfVector2i nxln2d;

  dot = coordgen(var.i, var.j, points->tab[var.i][var.j], data);
  dot2d = my_parallel_projection(dot, data->angle * (180 / M_PI));

  if (var.i + 1 < points->y)
  {
    nxcl = coordgen(var.i + 1, var.j, points->tab[var.i + 1][var.j], data);
    nxcl2d = my_parallel_projection(nxcl, data->angle * (180 / M_PI));
    my_draw_line(buffer, dot2d, nxcl2d, WIRECOLOR);
  }

  if (var.j + 1 < points->x)
  nxln = coordgen(var.i, var.j + 1, points->tab[var.i][var.j + 1], data);
  else
  nxln = dot;

  nxln2d = my_parallel_projection(nxln, data->angle * (180 / M_PI));

  my_draw_line(buffer, dot2d, nxln2d, WIRECOLOR);
}

void    draw_baselink(t_my_framebuffer *buffer, t_cam *data,
                      t_mx *points, t_ct var)
{
  sfVector3f dot;
  sfVector2i dot2d;
  sfVector3f nxcl;
  sfVector2i nxcl2d;
  sfVector3f nxln;
  sfVector2i nxln2d;

  dot = coordgen(var.i, var.j, 0, data);
  dot2d = my_parallel_projection(dot, data->angle * (180 / M_PI));

  if (var.i + 1 < points->y)
  {
    nxcl = coordgen(var.i + 1, var.j, 0, data);
    nxcl2d = my_parallel_projection(nxcl, data->angle * (180 / M_PI));
    my_draw_line(buffer, dot2d, nxcl2d, GRIDCOLOR);
  }

  if (var.j + 1 < points->x)
  {
    nxln = coordgen(var.i, var.j + 1, 0, data);
    nxln2d = my_parallel_projection(nxln, data->angle * (180 / M_PI));
    my_draw_line(buffer, dot2d, nxln2d, GRIDCOLOR);
  }
}

void		fmls(t_my_framebuffer *buffer, t_cam *data, t_mx *points)
{
  sfVector3f dot;
  sfVector2i dot_2d;
  sfVector3f proj;
  sfVector2i proj_2d;
  t_ct var;

  var.i = -1;
  while (++var.i < points->y)
  {
    var.j = -1;
    while (++var.j < points->x)
    {
      dot = coordgen(var.i, var.j, points->tab[var.i][var.j], data);
      dot_2d = my_parallel_projection(dot, data->angle * (180 / M_PI));
      proj = coordgen(var.i, var.j, 0, data);
      proj_2d = my_parallel_projection(proj, data->angle * (180 / M_PI));
      if (dot.z != 0 && data->toggle_link == 1)
      draw_height(buffer, data, dot_2d, proj_2d);
      if (data->toggle_grid == 1)
      draw_baselink(buffer, data, points, var);
      if (data->toggle_proj == 1)
      draw_projlink(buffer, data, points, var);
    }
  }
}
