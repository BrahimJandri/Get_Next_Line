#include "get_next_line.h"

char    *ft_first_line(int fd, char *str)
{
    char    *buf;
    int     ret;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    ret = 1;
    while (!ft_strchr(str, '\n') && ret != 0)
    {
        ret = read(fd, buf, BUFFER_SIZE);
        if (ret == -1)
        {
            free(buf);
            free(str);
            return (NULL);
        }
        buf[ret] = '\0';
        str = ft_strjoin(str, buf);
    }
    free(buf);
    return (str);
}

char    *ft_next_line(char *str)
{
    char    *next_line;
    int     i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    next_line = malloc(sizeof(char) * (i + 1));
    if (!next_line)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        next_line[i] = str[i];
        i++;
    }
    next_line[i] = '\0';
    return (next_line);
}

char    *ft_new_str(char *str)
{
    char    *new_str;
    int     i;
    int     j;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    new_str = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    if (!new_str)
        return (NULL);
    i++;
    j = 0;
    while (str[i])
        new_str[j++] = str[i++];
    new_str[j] = '\0';
    free(str);
    return (new_str);
}

char    *get_next_line(int fd)
{
    static char *str;
    char    *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = ft_first_line(fd, str);
    if (!str)
        return (NULL);
    next_line = ft_next_line(str);
    str = ft_new_str(str);
    return (next_line);
}