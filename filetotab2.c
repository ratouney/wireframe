/*
** filetotab2.c for bswireframe in /home/ratouney/bswireframe
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Fri Dec 09 16:43:18 2016 ratouney
** Last update Fri Dec  9 16:43:58 2016 John Doe
*/

#include "advanced.h"

char		*getbuffalobill(char *filepath)
{
  int count;
  int fd;
  char *buffer;

  count = 0;
  fd = open(filepath, O_RDONLY);
  if (fd == -1)
  return (NULL);
  buffer = malloc(BUFFSIZE);
  if (buffer == NULL)
  return (NULL);
  read(fd, buffer, BUFFSIZE - 1);
  buffer[BUFFSIZE - 1] = '\0';
  close(fd);
  return (buffer);
}

int		*selectline(char *buffer, int rank, int linelen)
{
  int		*tab;
  int		count;
  int		cunt;
  char	*temp;

  count = 0;
  cunt = 0;
  temp = slinstr(buffer, (linelen * rank) + rank,
  (linelen * (rank + 1) + rank));
  tab = malloc(sizeof(int) * (linelen / 2));
  while (count < linelen)
  {
    if (temp == NULL)
    return (NULL);
    tab[cunt] = temp[count] - '0';
    cunt  += 1;
    count += 2;
  }
  return (tab);
}

int		getlinelen(char *buffer)
{
  int count;
  int total;

  count = 0;
  total = 0;
  while (buffer[count] == ',' || buffer[count] == '-' ||
  (buffer[count] > 47 && buffer[count] < 58))
  {
    if (buffer[count] == ',')
    total++;
    count++;
  }
  return (count);
}

int			*yolo(int size)
{
  int *data;
  int count;

  count = 0;
  data = malloc(sizeof(int) * size);
  while (count < size)
  {
    data[count] = 0;
    count++;
  }
  return (data);
}

int			linecount(char *buffer)
{
  int count;
  int cunt;

  count = 0;
  cunt = 0;
  while (buffer[count] != '\0')
  {
    if (buffer[count] == '\n')
    cunt++;
    count++;
  }
  return (cunt);
}
