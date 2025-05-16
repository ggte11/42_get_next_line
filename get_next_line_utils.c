/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:37:54 by mcardoso          #+#    #+#             */
/*   Updated: 2025/05/16 13:46:29 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int	ft_findnewline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free (s1);
	return (res);
}

char	*ft_extract_line(char *stash)
{
	char	*res;
	size_t	i;
	int		size_line;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	size_line = ft_findnewline(stash);
	if (size_line == -1)
		size_line = ft_strlen(stash) - 1;
	res = malloc((size_line + 2) * sizeof(char));
	if (!res)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		res[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	free(stash);
	return (res);
}

void	ft_clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	int		new_start;

	if (!stash || !*stash)
		return ;
	new_start = ft_findnewline(stash);
	if (new_start == -1)
	{
		stash[0] = '\0';
		return ;
	}
	i = new_start + 1;
	j = 0;
	while (stash[i])
		stash[j++] = stash[i++];
	stash[j] = '\0';
	return ;
}
