/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:37:41 by mcardoso          #+#    #+#             */
/*   Updated: 2025/05/16 13:48:18 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer_count[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (*buffer_count != '\0')
		line = ft_strjoin_free(line, buffer_count);
	while (ft_findnewline(buffer_count) == -1)
	{
		bytes_read = read(fd, buffer_count, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			buffer_count[0] = '\0';
			return (free(line), NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer_count[bytes_read] = '\0';
		line = ft_strjoin_free(line, buffer_count);
	}
	line = ft_extract_line(line);
	ft_clean_stash(buffer_count);
	return (line);
}

int main(void)
{
	int	i;
	int	fd = open("text.txt", O_RDONLY);
	char *line;

	i = 0;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
}
