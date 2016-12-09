/*
** init_gen.c for adv in /home/ratouney/bswireframe/adv
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 27 16:07:41 2016 ratouney
** Last update Thu Dec  8 21:23:42 2016 John Doe
*/

#include "advanced.h"

sfUint8  *create_pixel_buffer(int width, int height)
{
  int i;
  sfUint8* pixels;

  pixels = malloc(width * height * 4 * sizeof(*pixels));
  if (pixels == NULL)
  {
    exit(EXIT_FAILURE);
  }
  i = 0;
  while (i < width * height * 4)
  {
    pixels[i] = 0;
    i = i + 1;
  }
  return (pixels);
}

t_my_framebuffer create_buffer_struct(int width, int height)
{
  t_my_framebuffer yo;

  yo.pixels = create_pixel_buffer(width, height);
  yo.width = width;
  yo.height = height;
  return (yo);
}

t_var *create_window(char* name, int width, int height, t_var *var)
{
  sfRenderWindow* window;
  sfVideoMode mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  var->window = sfRenderWindow_create(mode, name, sfDefaultStyle, NULL);
  if (var->window == NULL)
  exit(-1);
  return (var);
}
