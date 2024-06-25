/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ankamantatra.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:11:01 by bhamed            #+#    #+#             */
/*   Updated: 2024/06/25 12:53:06 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANKAMANTATRA_H
# define ANKAMANTATRA_H

# define CRESET "\33[0m"
# define RED "\33[0;31m"
# define GRN "\33[0;32m"
# define NBR_QUEST 32

# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <time.h>

typedef struct s_data
{
	char	*question;
	char	*answer;
}			t_data;

char	*get_line(char *file, int rand_num);
int		get_random_num(void);
void	play(t_data *data);
void	free_resources(t_data data);
void	lower_case(char *str);
void	initialise_head(int score);
void	check_result(int score, int i);

#endif
