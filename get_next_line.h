/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnavarro <navarrobonetm@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:43:07 by mnavarro          #+#    #+#             */
/*   Updated: 2020/03/03 14:44:31 by mnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

int			get_next_line(int fd, char **line);
char		*ft_strjoin_free(char *s1, char *s2);
int			find_index(const char *s, int c);
int			get_line(char **str, char **line, int i);
char		*ft_substr(char const *s, int start, int len);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);

#endif
