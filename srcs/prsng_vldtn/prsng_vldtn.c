/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_vldtn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:02:01 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 01:22:50 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	prsng_vldtn(t_main *prmtrs)
{
	char	*line;

	setup_terminal();
	prmtrs->orig_line_input = readline("my_shell$ ");
	if (prmtrs->orig_line_input == NULL)
	{
		printf("my_shell$ exit\n");
		free_prmtrs(prmtrs, SUCCESSFUL_EXIT);
		exit(prmtrs->exit_status);
		return (NOT_EXECUTE);
	}
	line = ft_strdup(prmtrs->orig_line_input);
	if (ft_strlen(prmtrs->orig_line_input) == 0)
	{
		ft_free_str(&(prmtrs->orig_line_input));
		ft_free_str(&line);
		return (NOT_EXECUTE);
	}
	add_history(prmtrs->orig_line_input);
	if (check_input(line, prmtrs) == NOT_EXECUTE)
	{
		ft_free_str(&(prmtrs->orig_line_input));
		return (NOT_EXECUTE);
	}
	return (EXECUTE);
}
