/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:19:26 by aen-naas          #+#    #+#             */
/*   Updated: 2022/12/08 15:50:56 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub)
	{
		while (s[i] && i < len)
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}

char	*ft_format(char *save)
{
	int		i;
	int		j;
	char	*holder;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	i = ft_strchr(save, '\n');
	if (!i)
		return (NULL);
	holder = ft_strdup(save + i);
	free(save);
	return (holder);
}

char	*ft_extract(char *save, char **savead)
{
	int		i;
	char	*holder;

	i = 0;
	if (ft_strlen(save) == 0)
	{
		free(save);
		*savead = NULL;
		return (NULL);
	}
	i = ft_strchr(save, '\n');
	if (!i)
		return (save);
	holder = ft_substr(save, 0, i);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*result;
	int			r;

	r = 1;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	while (r && !ft_strchr(save, '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
			return (free(buffer), free(save), save = NULL, NULL);
		buffer[r] = 0;
		save = ft_join(save, buffer);
	}
	free(buffer);
	result = ft_extract(save, &save);
	save = ft_format(save);
	return (result);
}
