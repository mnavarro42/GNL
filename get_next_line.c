/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnavarro <navarrobonetm@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:07:29 by mnavarro          #+#    #+#             */
/*   Updated: 2020/03/03 15:21:19 by mnavarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_nl(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] != '\n')
		return (-1);
	return (i);
}

int		get_line(char **str, char **line, int i)
{
	int		len;

	*line = ft_substr(*str, 0, i);
	++i;
	len = ft_strlen(*str + i) + 1;
	ft_memmove(*str, *str + i, len);
	if (*str && *str[0] == '\0')
	{
		free(*str);
		*str = NULL;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*str;
	int				ret;
	int				i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (str && (((i = find_nl(str)) != -1)))
		return (get_line(&str, line, i));
	while (((ret = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[ret] = '\0';
		str = ft_strjoin_free(str, buff);
		if (((i = find_nl(str)) != -1))
			return (get_line(&str, line, i));
	}
	if (str)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (ret);
	}
	*line = ft_strdup("");
	return (ret);
}
