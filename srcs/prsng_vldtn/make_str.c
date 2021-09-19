/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:52 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:54:53 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	make_str(char *line, int i, t_cmd_list **tmp, int *ind)
{
	int	len;

	len = len_of_str(line, i);
	if (len == -1)
		return (-1);
	if (len == 0)
		return (-2);
	(*tmp)->cmnd_words[++(*ind)] = (char *)malloc(sizeof(char) * (len + 1));
	(*tmp)->cmnd_words[(*ind)][len] = '\0';
	return (EXECUTE);
}
