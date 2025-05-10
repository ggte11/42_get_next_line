/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:37:41 by mcardoso          #+#    #+#             */
/*   Updated: 2025/05/10 16:20:49 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer_cont[BUFFER_SIZE + 1];
	static char *stash;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (ft_findnewline(stash) == -1)
	{
		bytes_read = read(fd, buffer_cont, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0 && stash[0] == '\0')
			break;
		buffer_cont[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buffer_cont);
	}
	line = ft_extract_line(stash);
	stash = ft_clean_stash(stash);
	return (line);
}

int main(void)
{
	int	fd = open("ficheiro.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)))
	{
		printf("Linha: %s|\n", line);
		free(line);
	}
	close(fd);
}