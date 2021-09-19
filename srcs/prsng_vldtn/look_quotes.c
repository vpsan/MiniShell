/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:25:47 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/17 01:25:49 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

bool	find_quotes(const char *line, int *i)
{
	while (line[++(*i)])
	{
		if (line[(*i)] == '"')
			return (true);
	}
	return (false);
}

bool	find_quote(const char *line, int *i)
{
	while (line[++(*i)])
	{
		if (line[(*i)] == '\'')
			return (true);
	}
	return (false);
}

int	look_quotes(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '"')
		{
			if (find_quotes(line, &i) == true)
				continue ;
			else
				return (NOT_EXECUTE);
		}
		if (line[i] == '\'')
		{
			if (find_quote(line, &i) == true)
				continue ;
			else
				return (NOT_EXECUTE);
		}
	}
	return (EXECUTE);
}
