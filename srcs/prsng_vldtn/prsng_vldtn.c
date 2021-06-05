/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_vldtn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:02:01 by bhatches          #+#    #+#             */
/*   Updated: 2021/05/29 14:32:42 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

void	prsng_vldtn(t_shell *prmtrs)
{
	char	buf[2];
	int		n; 
	int		count;

	count = 1;
	n = 0;
	write(1, "vpsan>", 6);
	while (count)
	{

		count = (int) read(0, &buf, 1);
		buf[1] = '\0';
		if (*buf == '\n')
		{
			///отправляемся в путешествие, если встретили '\n'
			ft_find_n(prmtrs, buf);
		}
		else
			break;///вызов функции если не встретили '\n'
	}
}
