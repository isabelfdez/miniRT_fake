#include <stdio.h>
#include <math.h>

int		ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	else
		return (0);
}

int		count_nb(int nb)
{
	int				rtrn;
	long long int	i;

	rtrn = 0;
	i = 1;
	while (nb / i)
	{
		i = i * 10;
		rtrn++;
	}
	if (nb <= 0)
		rtrn = rtrn + 1;
	return (rtrn);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		nb;

	i = 0;
	neg = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		nb = nb * (-1);
	return (nb);
}

float		ft_atof(const char *aux, int i)
{
    float nb;

	nb = ft_atoi(aux + i);
	while (ft_isdigit(aux[i]))
		i++;
	if (aux[i] == '.' && nb >= 0)
		nb = nb + ((ft_atoi(aux + i + 1)) /
		(pow(10.0, count_nb(ft_atoi(aux + i + 1)))));
	else if (aux[i] == '.' && nb < 0)
		nb = nb - ((ft_atoi(aux + i + 1)) /
		(pow(10.0, count_nb(ft_atoi(aux + i + 1)))));
	return (nb);
}

int main()
{
    float a = ft_atof("0.0", 0);
    printf("%f\n", a);

    return (0);
}
