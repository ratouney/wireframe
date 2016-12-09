/*
** show_mx.c for 102cipher in /home/ratouney/102cipher
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Sun Dec 04 21:03:19 2016 ratouney
** Last update Thu Dec  8 21:03:58 2016 John Doe
*/

#include "cipher.h"

void		show_tab(int **tab, int x, int y)
{
  int count = 0;

  while (count < y)
  {
    shintab(tab[count], x);
    count++;
  }
}

void	shintab(int *tab, int size)
{
  int count;

  count = 0;
  my_printf("| ");
  while (count < size)
  {
    my_printf("%-d | ", tab[count]);
    count++;
  }
}
