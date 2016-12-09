/*
** filetotab.c for CPE_2016_BSQ_bootstrap in /home/ratouney/CPE_2016_BSQ_bootstrap
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Mon Dec 05 14:13:58 2016 ratouney
** Last update Fri Dec  9 16:49:24 2016 John Doe
*/

#include "advanced.h"

void          countplus_ikm(int i, int k, int m, t_v *v)
{
  if (i == 1)
    v->i++;
  if (k == 1)
    v->k++;
  if (m == 1)
    v->m++;
  if (i == -1)
    v->i = 0;
  if (k == -1)
    v->k = 0;
  if (m == -1)
    v->m = 0;
}

void      countplus_ijk(int i, int j, int k, t_v *v)
{
  if (i == 1)
    v->i++;
  if (j == 1)
    v->j++;
  if (k == 1)
    v->k++;
  if (i == -1)
    v->i = 0;
  if (j == -1)
    v->j = 0;
  if (k == -1)
    v->k = 0;
}

t_mx			*nbronline(char *buffer, int rank)
{
  t_v *v;
  int start;
  int **tab;
  t_mx *data;

  v = malloc(sizeof(t_v));
  countplus_ijk(-1, -1, -1, v);
  loop1(buffer, v);
  countplus_ikm(0, -1, 0, v);
  tab = malloc(sizeof(int *) * rank);
  while (v->k < rank)
  {
    tab[v->k] = yolo(v->j/rank);
    v->k++;
  }
  countplus_ikm(-1, -1, -1, v);
  loop2(buffer, tab, v);
  data = malloc(sizeof(t_mx));
  writetomx(data, tab, v->j/rank, rank);
  return (data);
}

void		writetomx(t_mx *main, int **tab, int x, int y)
{
  main->tab = tab;
  main->x = x;
  main->y = y;
}

t_mx			*parse(char *path)
{
  char *data;
  t_mx *result;
  int **tab;
  int count;
  int lnlen;
  int lncount;

  data = getbuffalobill(path);
  lncount = linecount(data);
  result = nbronline(data, lncount);
  return (result);
}
