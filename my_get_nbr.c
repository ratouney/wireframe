/*
** gtnbr.c for slkfgjsdlfjd in /home/ratouney/CPool_Day08/lib/my
**
** Made by ratouney ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Fri Oct 14 11:33:32 2016 ratouney ratouney
** Last update Thu Dec  8 21:23:23 2016 John Doe
*/

int	my_strlen(char *);

int	my_get_nbr(char *str)
{
  int	length;
  int	count;
  int	nbr;
  int	moins;

  count = 0;
  nbr = 0;
  moins = 0;
  length = my_strlen(str);
  while (str[count] && (str[count] == '+' || str[count] == '-'))
    {
      if (str[count] == '-')
	moins = moins + 1;
      count = count + 1;
    }
  while (str[count] && (str[count] <= 57 && str[count] >= 48))
    {
      nbr = (nbr * 10) + (str[count] - 48);
      count = count + 1;
    }
  if (moins % 2 == 1)
    nbr = nbr * (-1);
  return (nbr);
}
