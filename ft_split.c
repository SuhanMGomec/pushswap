/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 20:32:51 by sgomec            #+#    #+#             */
/*   Updated: 2026/10/11 20:32:54 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_wordcount(char const *s, char sep)
{
	size_t		count;
	size_t		word;

	word = 0;
	count = 0;
	while (*s)
	{
		if (*s != sep && !word)
		{
			word = 1;
			count++;
		}
		else if (*s == sep)
			word = 0;
		s++;
	}
	return (count);
}

static char	**ft_double_free(char **str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	*ft_word_dup(char const *s, size_t start, size_t len)
{
	char		*word;
	size_t		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_fill(char const *s, char sep, char **res, size_t *i)
{
	while (s[i[0]])
	{
		while (s[i[0]] && s[i[0]] == sep)
			i[0]++;
		i[1] = i[0];
		while (s[i[0]] && s[i[0]] != sep)
			i[0]++;
		if (i[0] > i[1])
		{
			res[i[2]] = ft_word_dup(s, i[1], i[0] - i[1]);
			if (!res[i[2]])
				return (ft_double_free(res));
			i[2]++;
		}
	}
	res[i[2]] = NULL;
	return (res);
}

char	**ft_split(char const *s, char sep)
{
	char		**res;
	size_t		i[3];

	if (!s)
		return (NULL);
	res = malloc((ft_wordcount(s, sep) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	return (ft_fill(s, sep, res, i));
}
