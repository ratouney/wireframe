/*
** my_put_3d.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 27 16:49:00 2016 ratouney
** Last update Thu Dec  8 19:06:18 2016 John Doe
*/

#include "advanced.h"

sfVector2i my_parallel_projection(sfVector3f data, float deg)
{
  int xa;
  int ya;
  float angle;
  sfVector2i result;

  angle = deg / (180 / M_PI);
  xa = CENTER_X + cos(angle)*data.x - tan(angle)*data.y;
  ya = CENTER_Y + cos(angle)*data.y - data.z;

  result.x = xa;
  result.y = ya;

  return (result);
}
