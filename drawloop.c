/*
** drawloop.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 27 16:20:15 2016 ratouney
** Last update Sun Nov 27 16:20:24 2016 John Doe
*/

#include "advanced.h"

void	drawloop(t_my_framebuffer *buffer, t_var *var)
{
  sfVector2i	va;
  sfVector2i	vb;
  sfVector2i	temp;
  sfColor			color;
  static int count = 0;

  if (count++)
  {
    va = dotgen(rand() % 1000, rand() % 1000);
    vb = dotgen(rand() % 1000, rand() % 1000);
    color = randcolorgen(255);
    my_draw_line(buffer, va, vb, color);
  }
}
