/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2021/09/05 14:05:59 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*copy_line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	copy_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!copy_line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		copy_line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		copy_line[i] = save[i];
		i++;
	}
	copy_line[i] = '\0';
	return (copy_line);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*new_line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	new_line = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!new_line)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		new_line[c++] = save[i++];
	new_line[c] = '\0';
	free(save);
	return (new_line);
}

char	*ft_copy_buffer(int fd, char *save)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[257];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	save[fd] = ft_copy_buffer(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_get_line(save[fd]);
	save[fd] = ft_save(save[fd]);
	return (line);
}
/*
# ifdef __GNU__
#  define PATH_MAX 4096
#  define MAXPATHLEN 4096
#  define OPEN_MAX 256 -> We define a reasonable limit.
# endif
*/
