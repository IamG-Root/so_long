/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:24:24 by scastagn          #+#    #+#             */
/*   Updated: 2023/03/04 10:09:11 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_getline(int fd, char *line);
char	*ft_clearline(char *line);
char	*ft_nextline(char *line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *line, int c);
size_t	ft_strlen(char *str);

#endif
