/*
** filetotab3.c for bswireframe in /home/ratouney/bswireframe
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Fri Dec 09 16:44:21 2016 ratouney
** Last update Fri Dec  9 16:44:40 2016 John Doe
*/

#include "advanced.h"

void        *loop1(char *buffer, t_v *v)
{
  int start;

  while (buffer[v->i] != '\0')
  {
    if (buffer[start = v->i] == ',')
    v->i += 1;
    else if (buffer[v->i] == '-' && !(buffer[v->i+1] < 48
    && buffer[v->i+1] > 57))
    {
      while (buffer[++v->i] >= 48 && buffer[v->i] <= 57);
      countplus_ijk(1, 1, 0, v);
    }
    else if (buffer[v->i] >= 48 && buffer[v->i] <= 57)
    {
      while (buffer[v->i] >= 48 && buffer[v->i] <= 57)
      v->i++;
      countplus_ijk(1, 1, 0, v);
    }
    else if (buffer[v->i] == '\n')
    v->i++;
  }
}

void        *loop2(char *buffer, int **tab, t_v *v)
{
  int start;

  while (buffer[v->i] != '\0')
  {
    if (buffer[v->i] == ',')
    v->i += 1;
    else if (buffer[v->i] == '-' && !(buffer[v->i+1] < 48
    && buffer[v->i+1] > 57))
    {
      start = v->i;
      while (buffer[++v->i] >= 48 && buffer[v->i] <= 57);
      tab[v->k][v->m] = my_get_nbr(slinstr(buffer, start, v->i - 1));
      countplus_ikm(1, 0, 1, v);
    }
    else if (buffer[v->i] >= 48 && buffer[v->i] <= 57)
    {
      start = v->i;
      while (buffer[v->i] >= 48 && buffer[v->i] <= 57)
      v->i++;
      tab[v->k][v->m] = my_get_nbr(slinstr(buffer, start, v->i - 1));
      countplus_ikm(1, 0, 1, v);
    }
    else if (buffer[v->i] == '\n')
      countplus_ikm(1, 1, -1, v);
  }
}
