#ifndef CHECKER_H
# define CHECKER_H

# define MAX_I 214748364
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define SIZE 8
#define BUFF_SIZE 100

typedef struct s_list
{
	int		len;
	char	*str;
	struct	s_list *next;
}	t_list;

int		ft_atoi_err(char *str, int *err);
int		ft_atoi(char *str);
int     check_av(int ac, char **av, int *err);
char	*ft_read(void);
int		ft_strlen(char *str);
void	ft_bzero(char *str, int len);
// t_list	*gnl(void);

#endif
