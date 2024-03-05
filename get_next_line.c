/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:08:12 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/04 10:07:52 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(int fd, char *line)
{
	char	*buffer;
	ssize_t	byteletti;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byteletti = 1;
	while (!(ft_strchr(line, '\n')) && byteletti > 0)
	{
		byteletti = read(fd, buffer, BUFFER_SIZE);
		if (byteletti == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byteletti] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_cleanline(char *line)
{
	int		i;
	char	*linecleaned;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	linecleaned = (char *)malloc(i + i);
	if (!linecleaned)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		linecleaned[i] = line[i];
		i++;
	}
	linecleaned[i] = '\0';
	return (linecleaned);
}

char	*ft_nextline(char *line)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	string = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!string)
		return (NULL);
	j = 0;
	i++;
	while (line[i])
		string[j++] = line[i++];
	string[j] = '\0';
	free(line);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_getline(fd, line);
	if (!line)
		return (NULL);
	next_line = ft_cleanline(line);
	line = ft_nextline(line);
	return (next_line);
}
