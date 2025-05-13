/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:38:09 by mcardoso          #+#    #+#             */
/*   Updated: 2025/05/13 13:25:41 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		ft_findnewline(char *str);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_clean_stash(char *stash);
char	*ft_extract_line(char *stash);

#endif