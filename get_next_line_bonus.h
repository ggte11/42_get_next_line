/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcardoso <mcardoso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:18:52 by mcardoso          #+#    #+#             */
/*   Updated: 2025/06/05 12:23:47 by mcardoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# ifndef BUFFER_MAXFD
#  define BUFFER_MAXFD 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

char	*get_next_line_bonus(int fd);
size_t	ft_strlen(const char *str);
int		ft_findnewline(char *str);
char	*ft_strjoin_free(char *s1, char const *s2);
void	ft_clean_stash(char *stash);
char	*ft_extract_line(char *stash);

#endif