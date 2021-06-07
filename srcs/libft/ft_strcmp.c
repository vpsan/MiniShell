/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:47:04 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/07 17:11:50 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	ptr_str1 = (unsigned char *)str1;
	ptr_str2 = (unsigned char *)str2;
	while (*ptr_str1 != '\0' && *ptr_str2 != '\0')
	{
		if (*ptr_str1 != *ptr_str2)
			return (*ptr_str1 - *ptr_str2);
		ptr_str1++;
		ptr_str2++;
	}
	if (*ptr_str1 == '\0' && *ptr_str2 == '\0')
		return (0);
	else
		return (*ptr_str1 - *ptr_str2);
}
