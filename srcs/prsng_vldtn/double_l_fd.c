/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_l_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:22 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:54:23 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	double_l_fd(t_cmd_list *tmp)
{
	char	*line;
	int		fd;

	fd = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	line = readline("> ");
	while (ft_strcmp(line, tmp->after_redirect))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		ft_free_str(&line);
		line = readline("> ");
	}
	ft_free_str(&line);
	close(fd);
	tmp->fd_out = open(".tmp", O_RDONLY);
	return (EXECUTE);
}
