/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:18:25 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/05 12:37:12 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	static char	buffer_count[BUFFER_MAXFD][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd > BUFFER_MAXFD || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (*buffer_count[fd] != '\0')
		line = ft_strjoin_free(line, buffer_count[fd]);
	while (ft_findnewline(buffer_count[fd]) == -1)
	{
		bytes_read = read(fd, buffer_count[fd], BUFFER_SIZE);
		if (bytes_read < 0)
		{
			buffer_count[fd][0] = '\0';
			return (free(line), NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer_count[fd][bytes_read] = '\0';
		line = ft_strjoin_free(line, buffer_count[fd]);
	}
	line = ft_extract_line(line);
	ft_clean_stash(buffer_count[fd]);
	return (line);
}

int main(void)
{
	int	i;
	int	fd = open("text.txt", O_RDONLY);
	char *line;

	i = 0;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	// while ((line = get_next_line_bonus(fd)))
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	i++;
	// }
	close(fd);
}
