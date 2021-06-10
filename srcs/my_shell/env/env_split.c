/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:42:28 by bhatches          #+#    #+#             */
/*   Updated: 2021/06/10 11:42:30 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_shell.h"

void	count_words_check_equality(char const *s,
										 int *n_words, int *flag_empty_second)
{
	*n_words = 1;
	while (*s != '\0')
	{
		if (*s == '=' /*&& *s != '\0'*/)
		{
			*n_words = 2;
			s++;
			if (*s == '\0')
				*flag_empty_second = true;
			else
				*flag_empty_second = false;
			break ;
		}
		else
			s++;
	}
}

static char	**malloc_arr(char const *s, int *n_words, int *flag_empty_second)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	count_words_check_equality(s, n_words, flag_empty_second);
	arr = (char **)malloc(sizeof(char *) * (*n_words + 1));
	if (arr == NULL)
		return (NULL);
	return (arr);
}

char 	**env_split(char const *s)
{
//	char	**arr;
//	char 	**begin;
//	int 	flag_empty_second;
//	int 	n_words;
//	int 	i;
//
//	arr = malloc_arr(s, &n_words, &flag_empty_second);
//	arr[n_words] = NULL;
//	if (n_words == 1)
//	{
//		arr[0] = (char*) malloc(sizeof(char) * ft_strlen_sep(s, '=') + 1);
//		while (*s != '\0' && *s != '=')
//		{
//			arr[0] = *s;
//			s++;
//		}
//	}
//	if (n_words == 2 && flag_empty_second == false)
//	{
//		arr[0] = (char*) malloc(sizeof(char) * (ft_strlen_sep(s, '=') + 1));
//		i = 0;
//		while (*s != '\0' && *s != '=')
//		{
//			arr[0][i] = *s;
//			s++;
//			i++;
//		}
//		s++;
//		arr[1] = (char*) malloc(sizeof(char) * (ft_strlen(s) + 1));
//		while (*s != '\0')
//		{
//			arr[1] = *s;
//			s++;
//		}
//	}
//	if (n_words == 2 && flag_empty_second == true)
//	{
//		arr[0] = (char*) malloc(sizeof(char) * ft_strlen_sep(s, '=') + 1);
//		while (*s != '\0' && *s != '=')
//		{
//			(*arr)[0] = *s;
//			s++;
//		}
//		s++;
//		arr[1] = (char*) malloc(sizeof(char) * 1);
//		arr[1][0] = '\0';
//	}
//	return (arr);
	return (NULL);
}

void 	test_env_split(t_main prmtrs)
{
//	char *s = ft_strdup("A=2");
//	char **arr = env_split(s);
//
//	while (*arr != NULL)
//	{
//		printf("|%s|\n", *arr);
//		arr++;
//	}

	char *s = ft_strdup("ABCD_ABCD");

	char *b = ft_strdup_sep(s, '_');
	char *b_begin = b;
	while (*b != '\0')
	{
		ft_putchar_fd(*b, 1);
		b++;
	}
	free(s);
//	free(b_begin);
	return ;
}
