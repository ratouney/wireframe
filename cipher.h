/*
** include.h for include.h in /home/ratouney/102cipher
**
** Made by ratouney
** Login   <ratouney@epitech.net>
**
** Started on  Mon Nov 21 18:32:26 2016 ratouney
** Last update Mon Dec  5 22:07:04 2016 John Doe
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


typedef struct	s_matrice
{
  int **tab;
  int x;
  int y;
  int determ;
}		t_mx;

struct		s_size
{
  int mx_msg_x;
  int mx_msg_y;
  int mx_key_x;
  int mx_key_y;
};

double *asciiconv(char *str);
struct s_size *get_size(int lenkey, int lenmsg);
t_mx *create_matrix(int x, int y, double *values, int);
t_mx		*skipinmx(t_mx *origin, int colone, int ligne, int size);
void	FlagError(int argc,  char **argv);
void	EncryptionError(int argc, char **argv);
void	translate(t_mx *data, int mod);
void		show_encrypt(t_mx *data, t_mx *key);
t_mx		*multmx(t_mx *msg, t_mx *key);
double		determ(t_mx *data, int size);
t_mx		*skipinmx(t_mx *origin, int colone, int ligne, int size);
t_mx		*mxgen(int x, int y);
t_mx		*slmatrix(t_mx *origin, int colone, int ligne, int size);
t_mx	*create_matrix(int x, int y, double *values, int len);
void		matrix_result(t_mx *data);
struct s_size *get_size(int lenkey, int lenmsg);
double			*recupligne(t_mx *data, int ligne, int colone);
double			*recupcolone(t_mx *data, int colone, int ligne);
t_mx		*comatrix(t_mx *data);
t_mx		*mxmulcoef(t_mx *data, double coef);
t_mx	*mxadjoin(t_mx *data);
char			*slinstr(char *str, int from, int to);
void	shintab(int *tab, int size);
void		writetomx(t_mx *main, int **tab, int x, int y);
int			my_get_nbr(char *);
void		show_tab(int **tab, int x, int y);
