/*
** coordgen.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Mon Nov 28 09:07:09 2016 ratouney
** Last update Thu Dec  8 21:25:52 2016 John Doe
*/

#include "advanced.h"

sfVector3f	coordgen(int x, int y, int z, t_cam *camera)
{
  sfVector3f	data;

  data.x = (x + camera->x) * camera->scale;
  data.y = (y + camera->y) * camera->scale;
  data.z = (z + camera->z) * camera->scale;
  return (data);
}

sfVector3f	*coordgen_opti(int x, int y, int z, t_cam *camera)
{
  sfVector3f	*data;

	data = malloc(sizeof(sfVector3f));
  data->x = (x + camera->x) * camera->scale;
  data->y = (y + camera->y) * camera->scale;
  data->z = (z + camera->z) * camera->scale;
  return (data);
}
