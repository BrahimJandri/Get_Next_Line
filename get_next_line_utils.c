#include "get_next_line.h"

size_t    ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char    *ft_strchr(char *s, int c)
{
    while (s && *s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char	*str;
    size_t	i;
    size_t	j;

    if(!s1)
    {
        s1 = malloc(sizeof(char));
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = -1;
    j = 0;
    if(s1)
        while (s1[++i])
            str[i] = s1[i];
    while (s2[j])
        str[i++] = s2[j++];
    str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    free(s1);
    return (str);
}

