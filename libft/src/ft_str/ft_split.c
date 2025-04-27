/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthottap <mthottap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:16:24 by mthottap          #+#    #+#             */
/*   Updated: 2025/04/21 12:08:39 by mthottap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	count_words(const char *strg, char c)
{
	size_t		count;
	int			i;

	count = 0;
	i = 0;
	while (strg[i])
	{
		while (strg[i] == c)
			i++;
		if (strg[i] != '\0')
			count++;
		while (strg[i] && strg[i] != c)
			i++;
	}
	return (count);
}

static char	*get_word(const char *str, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c)
		len++;
	word = malloc(len + 1 * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

void	free_all(char **res, int j)
{
	while (0 <= j)
		free(res[--j]);
	free(res);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			result[j] = get_word(&s[i], c);
			if (!result[j])
				return (free_all(result, j), NULL);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	result[count_words(s, c)] = NULL;
	return (result);
}
