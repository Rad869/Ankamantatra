/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hratsima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:19:39 by hratsima          #+#    #+#             */
/*   Updated: 2024/03/13 15:24:14 by hratsima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_and_free(char **temp, char **buf)
{
	if (temp)
	{
		free(*temp);
		*temp = NULL;
	}
	if (buf)
	{
		free(*buf);
		*buf = NULL;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_to_lb(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long unsigned int	i;
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	i = 0;
	temp_dest = dest;
	temp_src = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < (n / sizeof(temp_src[0])))
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}
