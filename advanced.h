/*
** advanced.h for adv_wireframe in /home/ratouney/bswireframe
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Nov 20 11:37:31 2016 ratouney
** Last update Fri Dec  9 16:48:54 2016 John Doe
*/

#ifndef MY_H_
# define MY_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include "cipher.h"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define CENTER_X 400
#define CENTER_Y 400
#define PRECISION 0
#define PIXELDECAL 1
#define ANGLEDECAL M_PI/400
#define SCREEN_CLEAR sfBlack
#define SCALEDECAL 0.2
#define GRIDCOLOR sfBlue
#define WIRECOLOR sfWhite
#define HEIGHTCOLOR sfRed
#define HEIGHTVERTEX sfGreen
#define BUFFSIZE 500000

typedef struct		s_my_framebuffer
{
  sfUint8 				*pixels;
  int							width;
  int							height;
}									t_my_framebuffer;

typedef struct 		s_var
{
  sfUint8 				*pixels;
  int							width;
  int							height;

  sfRenderWindow	*window;
  sfTexture				*texture;
  sfSprite				*sprite;
  sfEvent					event;
  sfVector2i			base;
  sfVector2i			proj;
}									t_var;

typedef struct    s_parse
{
  int i;
  int j;
  int k;
  int m;
  int size_x;
  int size_y;
  char *nombre;
}                 t_v;

typedef struct		s_cam
{
  int x;
  int y;
  int z;
  float scale;
  int toggle_grid;
  int toggle_link;
  int toggle_proj;
  int toggle_shake;
  int toggle_vertex;
  float angle;
}									t_cam;

typedef struct    s_triche
{
  int i;
  int j;
  float deg;
  float rad;
}                 t_ct;

typedef struct		s_vertex
{
  sfVector2i from;
  sfVector2i to;
  sfColor		 srccol;
  sfColor		 descol;
}									t_vertex;

sfUint8  						*create_pixel_buffer(int width, int height);
sfVector2i					dotgen(int x, int y);
sfVector2i					my_parallel_projection(sfVector3f data, float angle);

sfVector3f					coordgen(int x,int y, int z, t_cam *data);
sfColor							colorgen(int r, int g, int b, int a);
sfColor							randcolorgen(int a);
t_vertex			*vertex_gen(sfVector2i source, sfVector2i destination, sfColor src, sfColor org);

t_my_framebuffer 		create_buffer_struct(int width, int height);
t_var 							*create_window(char* name, int width, int height, t_var *var);

void								draw_vertex(t_my_framebuffer *buffer, t_vertex *data);
void								drawloop(t_my_framebuffer *buffer, t_var *var);
void								draw(t_my_framebuffer *buffer, t_var *var, t_cam *camera);
void 								my_put_pixel(t_my_framebuffer *buffer, int x, int y, sfColor color);
void 								my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from, sfVector2i to, sfColor color);
t_mx			*parse(char *path);
void	drawdots(t_my_framebuffer *buffer, t_cam *data, t_mx *points);
sfVector2i my_isometric_projection(sfVector3f data, float deg);
void my_draw_line_opti(t_my_framebuffer *framebuffer, sfVector2i *from,
  sfVector2i *to, sfColor color);
  sfVector3f	*coordgen_opti(int x,int y, int z, t_cam *camera);
  sfVector2i *my_prproj(sfVector3f *data, float deg);
void	drawdots_opti(t_my_framebuffer *buffer, t_var *var, t_cam *data, t_mx *points);
t_vertex		*gen_heightvertex(sfVector2i source, sfVector2i end, sfColor init, sfColor final);
void		draw_height(t_my_framebuffer *buffer, t_cam *data, sfVector2i dot_2d, sfVector2i proj_2d);
void    draw_projlink(t_my_framebuffer *buffer, t_cam *data, t_mx *points, t_ct var);
void    draw_baselink(t_my_framebuffer *buffer, t_cam *data, t_mx *points, t_ct var);
void		fmls(t_my_framebuffer *buffer, t_cam *data, t_mx *points);
void        *loop2(char *buffer, int **tab, t_v *v);
void        *loop1(char *buffer, t_v *v);
int			linecount(char *buffer);
int			*yolo(int size);
int		getlinelen(char *buffer);
int		*selectline(char *buffer, int rank, int linelen);
char		*getbuffalobill(char *filepath);
void		writetomx(t_mx *main, int **tab, int x, int y);
t_mx			*parse(char *path);
t_mx			*nbronline(char *buffer, int rank);
void      countplus_ijk(int i, int j, int k, t_v *v);
void          countplus_ikm(int i, int k, int m, t_v *v);




  #endif /* !MY_H_ */
