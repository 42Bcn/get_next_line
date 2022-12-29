#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include "get_next_line.h"



int main() 
{
  int fd = open("leer.txt", O_RDONLY);
  char *aux;
  char *aux2;
  aux2 = get_line_with_buffer(fd, aux);


  printf("\033[0;92mRetorn get_line_with_buffer\n");
  printf("%s", aux2);
  printf("\033[0m\n");

  printf("\n");

  printf("\033[0;95mRetorn get_line\n");
  printf("%s", get_line(aux2));
  printf("\033[0m\n");

  close(fd);
  return (0);
}




//funcion main

//open(documento, permisos)

//get_next_line()

//close(fd)