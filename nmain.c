#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

int main()
{
	char *line;
	int	fd;

	fd = open("leaer.txt", O_RDONLY);

    
    printf("%d", fd);
    if (fd = -1)
    {
        printf("No he podido abrir el archivo.");
        return (0);
    }
    printf("prova");


	close(fd);
	return (0);
}