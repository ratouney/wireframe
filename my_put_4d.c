/*
** my_put_3d.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 27 16:49:00 2016 ratouney
** Last update Thu Dec  8 21:23:04 2016 John Doe
*/

#include "advanced.h"

sfVector2i my_isometric_projection(sfVector3f data, float deg)
{
  int xa;
  int ya;
  float angle;
  sfVector2i result;

  angle = deg / (180 / M_PI);

  xa = CENTER_X + data.x*cos(angle) + data.y*cos(angle + (M_PI / 3))
       + data.z*cos(angle - (M_PI /3));

  ya = CENTER_Y + data.x*sin(angle) + data.y*sin(angle + (M_PI / 3))
       + data.z*sin(angle - (M_PI /3));

  result.x = xa;
  result.y = ya;

  return (result);
}
