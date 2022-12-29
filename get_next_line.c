// Comprovacions
/* Del ft_free() treure el *str = NULL (seguira havent-hi un string, pero retornarem null (a veure si passa paco)) */

char    *get_next_line(int fd)
{
    static char     *storage = NULL;
    char            *line;

    /* if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL); */
    
    if (!storage)
    {
        storage = ft_strdup("");
        /* if (!storage)
            return (NULL); */
    }
    storage = fd_read_file(fd, storage);
    /* if (!storage)
        return (NULL); */
    line = ft_get_line(storage);
    /* if (!line)
        return (ft_free(&storage)); */
    storage = ft_clean_storage
}

// storage = ft_read_file(fd, storage);
char    *ft_read_file(int fd,) 
{
    char    *buffer;
    int     bytes_read;
}