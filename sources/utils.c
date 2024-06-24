/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamed <bhamed@student.42antananarivo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:03:54 by bhamed            #+#    #+#             */
/*   Updated: 2024/06/24 15:05:14 by bhamed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ankamantatra.h"

int	get_random_num(void)
{
	int	random;

	srand(time(0));
	random = rand();
	return ((random % NBR_QUEST) + 1);
}

char	*get_line(char *file, int rand_num)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: reading file");
		return (NULL);
	}
	while (i < rand_num)
	{
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (line);
}

void	free_resources(t_game game)
{
	free(game.question);
	free(game.answer);
	game.question = NULL;
	game.answer = NULL;
}

void	lower_case(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = tolower(str[i]);
		i++;
	}
}
