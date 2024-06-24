/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ankamantatra.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamed <bhamed@student.42antananarivo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:11:01 by bhamed            #+#    #+#             */
/*   Updated: 2024/06/24 15:21:42 by bhamed           ###   ########.fr       */
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
# include <time.h>

typedef struct s_game
{
	char	*question;
	char	*answer;
}			t_game;

char	*get_line(char *file, int rand_num);
int		get_random_num(void);
void	play(t_game *game, char **av);

#endif
