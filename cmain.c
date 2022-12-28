/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvelasco <cvelasco@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:26:02 by cvelasco          #+#    #+#             */
/*   Updated: 2022/12/28 15:26:21 by cvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char *line;
	int	fd;

	fd = open("leer.txt", O_RDONLY);
	printf("return open %d\n", fd);
	char datos[1024];
	ssize_t bytes_leidos;

	while ((bytes_leidos = read(fd, datos, 23)) > 0) 
	{
		printf(" | %d | ", (int)bytes_leidos);
		printf("%.*s", (int)bytes_leidos,  datos);
	}
	printf("%s", datos);
	print("%d", OPEN_MAX);

	if (bytes_leidos == -1)
	{
		perror("Error al leer el archivo");
		return (1);
	}

	close(fd);
	//get_next_line(fd1, &line);
	//printf("%s\n", line);
	return (0);
}