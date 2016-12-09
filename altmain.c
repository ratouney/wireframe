/*
** altmain.c for rework_wireframe in /home/ratouney/bswireframe
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 20 11:36:28 2016 ratouney
** Last update Fri Dec  9 16:41:11 2016 John Doe
*/

#include "advanced.h"

t_cam 	*camgen()
{
  t_cam *data;

  data = malloc(sizeof(t_cam));
  data->x = 0;
  data->y = 0;
  data->z = 0;
  data->scale = 1;
  data->toggle_link = 1;
  data->toggle_proj = 1;
  data->toggle_grid = -1;
  data->toggle_shake = -1;
  data->toggle_vertex = -1;
  data->angle = M_PI / 5;
  return (data);
}

void		camupdate(t_cam *camera, sfEvent event, t_var *var)
{
  if (event.type == sfEvtKeyPressed)
  {
    if (event.key.code == 36)
      sfRenderWindow_close(var->window);
    camera->toggle_vertex *= (event.key.code == 1 ? -1 : 1);
    camera->toggle_proj *= (event.key.code == 2 ? -1 : 1);
    camera->toggle_shake *= (event.key.code == 21 ? -1 : 1);
    camera->toggle_link *= (event.key.code == 22 ? -1 : 1);
    camera->toggle_grid *= (event.key.code == 23 ? -1 : 1);
    camera->angle -= (event.key.code == 7 ? ANGLEDECAL : 0);
    camera->angle += (event.key.code == 24 ? ANGLEDECAL : 0);
    camera->scale -= (event.key.code == 6 ? SCALEDECAL : 0);
    camera->scale += (event.key.code == 19 ? SCALEDECAL : 0);
    camera->x += (event.key.code == 71 ? PIXELDECAL : 0 );
    camera->x -= (event.key.code == 72 ? PIXELDECAL : 0 );
    camera->y += (event.key.code == 73 ? PIXELDECAL : 0 );
    camera->y -= (event.key.code == 74 ? PIXELDECAL : 0 );
  }
}

void		setvar(t_var *var, t_my_framebuffer buffer)
{
  var = create_window("Yo", SCREEN_WIDTH, SCREEN_HEIGHT, var);
  var->sprite = sfSprite_create();
  var->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  buffer = create_buffer_struct(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(var->sprite, var->texture, sfTrue);
}

void      resetbuffer(t_my_framebuffer *buffer)
{
  int i;

  i = 0;
  while (i < SCREEN_WIDTH * SCREEN_HEIGHT * 4)
  {
    buffer->pixels[i] = 0;
    i = i + 1;
  }
}

int main(int argc, char **argv)
{
  t_var		*var;
  t_cam		*camera;
  sfEvent  event;
  t_mx *points;
  t_my_framebuffer buffer;

  var = malloc(sizeof(*var));
  points = parse(argv[1]);
  camera = camgen();
  setvar(var, buffer);
  buffer = create_buffer_struct(SCREEN_WIDTH, SCREEN_HEIGHT);
  while (sfRenderWindow_isOpen(var->window))
  {
    while (sfRenderWindow_pollEvent(var->window, &event))
      camupdate(camera, event, var);
    sfRenderWindow_clear(var->window, SCREEN_CLEAR);
    resetbuffer(&buffer);
    fmls(&buffer, camera, points);
    sfTexture_updateFromPixels(var->texture, buffer.pixels,
                               SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(var->window, var->sprite, NULL);
    sfRenderWindow_display(var->window);
  }
  return (0);
}
