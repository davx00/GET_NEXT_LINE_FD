#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
   int fd = open("prueba.txt", O_RDONLY);

   char *line;

   while((line = get_next_line(fd)) != NULL)
   {
    printf("%s", line);
   }
   close(fd);
}
