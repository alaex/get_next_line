/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:05:30 by aen-naas          #+#    #+#             */
/*   Updated: 2022/12/07 19:05:54 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
char	*ft_join(char *save, char *buffer);
void	*ft_memcpy(void *dest, void *src, int n);
int		ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *s);
#endif
