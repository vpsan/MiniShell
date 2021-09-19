/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 09:43:51 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 09:59:02 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	del_lst_wrd(t_main *prmtrs)
{
	int			i;
	t_cmd_list	*tmp;

	tmp = prmtrs->cmd_head;
	while (tmp)
	{
		i = 0;
		if (tmp->is_double_l == true || tmp->is_double_r == true
			|| tmp->is_single_l == true || tmp->is_single_r == true)
		{
			while (tmp->cmnd_words[i + 1])
				i++;
			ft_free_str(&(tmp->cmnd_words[i]));
		}
		tmp = tmp->next;
	}
	return (EXECUTE);
}

int	helper_3(t_main *prmtrs)
{
	ft_free_str(&prmtrs->copy_line_input);
	return (NOT_EXECUTE);
}

int	check_input(char *line, t_main *prmtrs)
{
	prmtrs->copy_line_input = line;
	if (check_line(line) == NOT_EXECUTE)
		return (helper_3(prmtrs));
	if (check_pipe(prmtrs, prmtrs->copy_line_input)
		== NOT_EXECUTE || check_redirect(prmtrs->copy_line_input)
		== NOT_EXECUTE || look_quotes(prmtrs->copy_line_input)
		== NOT_EXECUTE)
	{
		prmtrs->exit_status = 258;
		printf("my_shell: syntax error near unexpected token\n");
		ft_free_str(&prmtrs->copy_line_input);
		return (NOT_EXECUTE);
	}
	creat_cmd_list(prmtrs);
	if (handle_quotes(prmtrs) == NOT_EXECUTE)
	{
		prmtrs->exit_status = 1;
		free_prmtrs(prmtrs, DONT_CLEAN_ENV);
		return (NOT_EXECUTE);
	}
	del_lst_wrd(prmtrs);
	ft_free_str(&prmtrs->orig_line_input);
	return (EXECUTE);
}
