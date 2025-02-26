/*
Assignment name : get_next_line
Expected files : get_next_line.c (42_EXAM can't take .h for now)
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:
char *get_next_line(int fd);


Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

Calling your function get_next_line() in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...

No call to another function will be done on the file descriptor between 2 calls of get_next_line(). Finally we consider that get_next_line() has an undefined behaviour when reading from a binary file.
*/

#include "get_next_line.h"

static char *join_char(char *str, char c, int len)
{
    char *new_str;
    int i;

    new_str = (char *)malloc(len + 2);
    if(!new_str)
        return NULL;
    i = 0;
    while(i < len)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i++] = c;
    new_str[i] = '\0';
    free(str);
    return new_str;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int buffer_size = 0;
    static int buffer_index = 0;
    char *line = NULL;
    int i = 0;

    if(BUFFER_SIZE < 1 || fd < 0)
        return NULL;
    
    line = (char *)malloc(1);
    if(!line)
        return NULL;
    line[0] = '\0';
    while(1)
    {
        if(buffer_index >= buffer_size)
        {
            buffer_size = read(fd, buffer, BUFFER_SIZE);
            buffer_index = 0;
            if(buffer_size <= 0)
            {
                if(i == 0)
                {
                    free(line);
                    return NULL;
                }
            }
            break;
        }
        line = join_char(line, buffer[buffer_index++], i);
        if(!line)
            return NULL;
        if(line[i++] == '\n')
            break;
    }
    return line;
}

/* 
#include <stdio.h>
int main(int ac, char *av[])
{

    int fd;
    char *path;
    char *str;
    
    (void)ac;
    path = av[1];
    fd = open(path, O_RDONLY);
    if(fd < 0)
    {
        printf("Error with file\n");
        return 0;
    }
    while((str = get_next_line(fd)))
    {
        printf("%s", str);
        free(str);
    }
    return 0;
}
*/
