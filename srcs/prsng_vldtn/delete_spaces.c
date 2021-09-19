/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:54:17 by bhatches          #+#    #+#             */
/*   Updated: 2021/09/16 09:54:18 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

char	*delete_spaces(char *str)
{
	int		i;
	int		j;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str)
	{
		i = -1;
		j = -1;
		while (str[++i])
			if (ft_isalpha(str[i]))
				ret[++j] = str[i];
		ret[++j] = '\0';
	}
	ft_free_str(&str);
	return (ret);
}
