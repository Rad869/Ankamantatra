/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hratsima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:20:26 by hratsima          #+#    #+#             */
/*   Updated: 2024/03/13 15:23:13 by hratsima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
int		ft_strchr(char *buf, char c);
void	ft_check_and_free(char **temp, char **buf);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strlen_to_lb(char *s);

#endif
