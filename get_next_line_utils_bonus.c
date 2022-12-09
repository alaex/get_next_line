/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:52:53 by aen-naas          #+#    #+#             */
/*   Updated: 2022/12/07 19:06:10 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, void *src, int n)
{
	int		i;
	char	*ds;
	char	*sr;

	ds = (char *)dest;
	sr = (char *)src;
	i = 0;
	if (dest == src)
		return (dest);
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *s)
{
	char	*ds;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s) + 1;
	ds = (char *)malloc(sizeof(char) * slen);
	if (ds)
		ft_memcpy(ds, s, slen);
	return (ds);
}

int	ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i + 1);
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	char	*jstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	jstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i])
	{
		jstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		jstr[i++] = s2[j++];
	jstr[i] = 0;
	free(s1);
	return (jstr);
}
