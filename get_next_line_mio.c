/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvelasco <cvelasco@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:59:07 by cvelasco          #+#    #+#             */
/*   Updated: 2023/01/02 11:59:10 by cvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char    *ft_free(char **str)
{
    free(*str);
    *str = NULL;
    return (NULL);
}

static char    *ft_get_file(int fd, char *aux)
{
    char *buffer;
    int   nread;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        //return (NULL); --> ft_free(&aux);
    nread = 1;
    //buffer[0] = '\0';
    while (nread > 0 && !ft_strchr(buffer, '\n'))
    {
        nread = read(fd, buffer, BUFFER_SIZE);
        if (nread == -1)
        {
            free(buffer);
            return (ft_free(&aux));
        }
        buffer[nread] = '\0';
        aux = ft_strjoin(aux, buffer);
        if (!aux)
        {
            //free(buffer); --> ''
            return (ft_free(&aux));
        }
    }
    free(buffer);
    return (aux);
}


static char    *ft_get_line(char *aux)
{
    char    *line;
    int     i;

    i = 0;
    //line = NULL; -> ''
    //if (aux[i] == '\0')
    //    return (NULL);
    while (aux[i] && aux[i] != '\n')
        i++;
    if (aux[i] != '\n')
        line = (char *)malloc(sizeof(char) * (i + 1));
    else
        line = (char *)malloc(sizeof(char) * (i + 2));
    if (!line)
        //return (ft_free(&aux)); --> return (NULL);
    i = 0;
    while (aux[i] && aux[i] != '\n')
    {
        line[i] = aux[i];
        i++;
    }
    //if (aux[i] == '\n')
    //    line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

static char    *ft_trim_aux(char *aux)
{
    char    *new_aux;
    int     i;
    int     j;

    i = 0;
    while (aux[i] && aux[i] != '\n')
        i++;
    if (aux[i] == '\0')
        return (ft_free(&aux));
    new_aux = (char *)malloc(sizeof(char) * (ft_strlen(aux) /* + 1 */ - i));
    if (!new_aux)
        return (ft_free(&aux));
    i++;
    j = 0;
    while (aux[i])
        new_aux[j++] = aux[i++];
    //if (j > 0)
        new_aux[j] = '\0';
    /*else
    {
        free(new_aux);
        return (ft_free(&aux)):
    }*/
    ft_free(&aux);
    return (new_aux);
}

char    *get_next_line(int fd)
{
    static char *aux;
    char        *line;

    /*if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    if (!aux)
	{
		aux = ft_strdup("");
		if (!aux)
			return (NULL);
	}
    (ANTERIOR) -->
    if (!aux)
        aux = ft_strdup("");
    */
    aux = ft_get_file(fd, aux);
    if (!aux)
        return (NULL);
    line = ft_get_line(aux);
    if (!line)
        return (ft_free(&aux));
    aux = ft_trim_aux(aux);
    /*
    del
    if (!aux)
        return (ft_free(&line));
    */
    return (line);
}

/*
int main()
{
    int fd;

   fd = open("leear.txt", O_RDONLY); 

    printf("RESULT(1): %s\n", get_next_line(fd));
    printf("RESULT(2): %s\n", get_next_line(fd));
    printf("RESULT(3): %s\n", get_next_line(fd));
    printf("RESULT(4): %s\n", get_next_line(fd));
    printf("RESULT(5): %s\n", get_next_line(fd));

   close(fd);
   return (0);
}
*/

