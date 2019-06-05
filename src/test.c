#include <stdio.h>
# define MAX_INT 214748364

int		ft_atoi(char *str, int *err)
{
	unsigned long int	res;
	int					sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if ((res > MAX_INT || (res == MAX_INT && (*str - '0') > 7)) &&
				sign == 1)
		{
			*err = 1;
			return (-1);
		}
		else if ((res > MAX_INT || (res == MAX_INT && (*str - '0') > 8)) &&
				sign == -1)
		{
			*err = 1;
			return (0);
		}
		res = 10 * res + (int)(*str - '0');
		str++;
		printf("%d\n", res);
	}
	if ((*str > 32 && *str < 48) || (*str > 57 && *str < 127))
		*err = 1;
	return ((int)(sign * res));
}

int main (void)
{
	int err;

	err = 0;    
	printf("atoi = %d\n", ft_atoi("aaa", &err));
	printf("err = %d\n", err);
}