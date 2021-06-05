#include "my_shell.h"

/*
**	c_arg - command argument; For example in "echo -n hello",c_arg is "-n hello"
**	fd - file descriptor
*/

int n_checker(char *c_arg)
{
	int i;
	int n_count;

	i = 0;
	if (c_arg[i] != '-')
		return (0);
	i++;
	n_count = 0;
	while (c_arg[i] != '\0')
	{
		if (c_arg[i] == 'n')
			n_count++;
		i++;
	}
	return (n_count);
}

int	echo(char *c_arg, int fd)
{
	int		i;
	int 	n_count;

	if (c_arg == NULL)
		return (0);
	n_count = n_checker(c_arg);
	i = n_count + 1;
	while (c_arg[i] != '\0')
	{
		ft_putchar_fd(c_arg[i], fd);
		i++;
	}
	if (n_count == 0)
		write(1, "\n", 1);
	return (0);
}
