/*
** slinstr.c for PSU_2016_my_printf in /home/ratouney/PSU_2016_my_printf
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Thu Nov 17 07:39:51 2016 ratouney
** Last update Mon Dec  5 14:40:13 2016 John Doe
*/

#include <stdlib.h>

char			*slinstr(char *str, int from, int to)
{
  char *res;
  int i;
  int j;

  i = 0;
  j = from;
  res = malloc(sizeof(char) * (j - i + 2));
  while (j <= to)
  {
    res[i] = str[j];
    i++;
    j++;
  }
  res[i] = '\0';
  return (res);
}
