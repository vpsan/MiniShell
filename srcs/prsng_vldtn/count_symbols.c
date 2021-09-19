/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:12 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:54:13 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	count_symbols(const char *line, char c)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (line[++i])
		if (line[i] == c)
			counter += 1;
	return (counter);
}
