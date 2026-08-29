#include <unistd.h>

int	ft_is_uper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_is_alpha(char c)
{
	if (ft_is_uper(c) || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	ft_changecase(char *ptr)
{
	int	i;
	char	c;


	i = 0;
	while (*ptr)
	{
		c = *ptr;
		if (c && ft_is_alpha(c))
		{
			if (ft_is_uper(c))
			{
				if (i % 2 != 0)
					c += 32;
			}
			else
			{
				if (i % 2 == 0)
					c -= 32;
			}
			i++;
		}
		else
			i = 0;
		write(1, &c, 1);
		ptr++;
	}
}

int	main(int ac, char *av[])
{
	int	i;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (av[i])
	{
		ft_changecase(av[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
