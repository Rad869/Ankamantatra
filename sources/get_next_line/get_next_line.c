/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hratsima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:16:32 by hratsima          #+#    #+#             */
/*   Updated: 2024/06/24 12:22:19 by bhamed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ankamantatra.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		s1len;
	int		s2len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	r = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (r == NULL)
		return (NULL);
	ft_memcpy(r, s1, s1len);
	ft_memcpy(r + s1len, s2, s2len);
	r[s1len + s2len] = '\0';
	free((void *)s1);
	return (r);
}

static char	*ft_get_first_part(char *temp)
{
	char	*str;
	int		pos_lb;

	if (temp == NULL)
		return (NULL);
	pos_lb = ft_strlen_to_lb(temp);
	str = (char *)malloc(sizeof(char) * (pos_lb + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, temp, pos_lb);
	str[pos_lb] = '\0';
	return (str);
}

static char	*ft_get_remain(char *temp)
{
	char	*str;
	int		temp_len;
	int		pos_lb;

	if (temp == NULL)
		return (NULL);
	temp_len = ft_strlen(temp);
	pos_lb = ft_strlen_to_lb(temp);
	if (temp_len == pos_lb)
		return (free(temp), NULL);
	str = (char *)malloc(sizeof(char) * (temp_len - pos_lb + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, temp + pos_lb, temp_len - pos_lb + 1);
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			nb_read;
	static char	*temp;

	nb_read = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || fd < 0 || BUFFER_SIZE <= 0)
		return (ft_check_and_free(&temp, &buf), NULL);
	while (ft_strchr(temp, '\n') == 0 && nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read < 0 || (!temp && nb_read == 0))
			return (ft_check_and_free(&temp, &buf), NULL);
		buf[nb_read] = '\0';
		if (nb_read > 0)
			temp = ft_strjoin(temp, buf);
	}
	free(buf);
	buf = ft_get_first_part(temp);
	temp = ft_get_remain(temp);
	return (buf);
}
