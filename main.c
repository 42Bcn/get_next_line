/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvelasco <cvelasco@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:26:02 by cvelasco          #+#    #+#             */
/*   Updated: 2022/12/28 14:58:07 by cvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

int main()
{
	char *line;
	int	fd;
	static char *str;

	str = {0};
	fd = open("leer.txt", O_RDONLY);



/* 
	char datos[1024];
	ssize_t bytes_leidos;

	while ((bytes_leidos = read(fd, datos, 10)) > 0) 
	{
		//printf(" | %d | ", (int)bytes_leidos);
		//printf("%.*s", (int)bytes_leidos, datos);
	}
	printf("%s", str);

	if (bytes_leidos == -1)
	{
		perror("Error al leer el archivo");
		return (1);
	} 
	//get_next_line(fd1, &line);
	//printf("%s\n", line); */


	close(fd);
	return (0);
}
