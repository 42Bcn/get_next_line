/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvelasco <cvelasco@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:30:41 by cvelasco          #+#    #+#             */
/*   Updated: 2022/12/29 19:30:51 by cvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_with_buffer(int fd, char *aux)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		aux = ft_strjoin(aux, buffer);
	}
	aux = ft_strjoin(aux, buffer);
	free(buffer);
	return (aux);
}

char	*get_line(char *aux)
{
	char	*line;
	int		i;

	i = 0;
	while (aux[i] && aux[i] != '\n')
		i++;
	if (aux[i] != '\n')
		line = (char *)malloc(sizeof(char) * (i + 1));
	else
		line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (aux[i] && aux[i] != '\n')
	{
		line[i] = aux[i];
		i++;
	}
	if (aux[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*aux;
	char			*line;

	aux = get_line_with_buffer(fd, aux);
	line = get_line(aux);
	return (line);
}
