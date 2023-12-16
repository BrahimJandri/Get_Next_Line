/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjandri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:08:45 by bjandri           #+#    #+#             */
/*   Updated: 2023/12/16 11:08:49 by bjandri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_first_line(int fd, char *str)
{
	char	*buf;
	int		ret;

	buf = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret != 0 && !ft_strchr(str, '\n'))
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
		if (!str)
			return (NULL);
	}
	free(buf);
	return (str);
}

char	*ft_next_line(char *str)
{
	char	*next_line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	next_line = malloc(sizeof(char) * (i + 2));
	if (!next_line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		next_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		next_line[i++] = '\n';
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_new_str(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free(str));
	new_str = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return (ft_free(str));
	i++;
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[1024];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buffer[fd] = ft_first_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	next_line = ft_next_line(buffer[fd]);
	buffer[fd] = ft_new_str(buffer[fd]);
	if (next_line[0] == '\0')
	{
		free(next_line);
		next_line = NULL;
	}
	return (next_line);
}

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;

// 	fd1 = open("baha", O_RDONLY);
// 	fd2 = open("braha", O_RDONLY);
// 	fd3 = open("bihi", O_RDONLY);
// 	line1 = get_next_line_bonus(fd1);
// 	line2 = get_next_line_bonus(fd2);
// 	line3 = get_next_line_bonus(fd3);
// 	printf("%s\n", line1);
// 	printf("%s\n", line2);
// 	printf("%s", line3);
// 	free(line1);
// 	free(line2);
// 	free(line3);
// 	return (0);
// }
