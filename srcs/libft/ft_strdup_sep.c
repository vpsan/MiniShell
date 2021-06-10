/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_sep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:36:45 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/10 13:36:47 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_sep(const char *s1, int value)
{
	size_t		s1_len;
	char		*s_copy;

	s1_len = ft_strlen_sep(s1, value);
	s_copy = malloc(s1_len * sizeof(char) + 1);
	if (s_copy == NULL)
	{
		return (NULL);
	}
	ft_memcpy(s_copy, s1, s1_len);
	*(s_copy + s1_len) = '\0';
	return (s_copy);
}
