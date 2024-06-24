/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamed <bhamed@student.42antananarivo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:24:15 by bhamed            #+#    #+#             */
/*   Updated: 2024/06/24 12:41:10 by bhamed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ankamantatra.h"

int	get_random_num(void)
{
	int	random;

	srand(time(0));
	random = rand();
	return ((random % 10) + 1);
}

char	*get_line(char *file, int rand_num)
{
	int		i;
	char	*quest;
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
		quest = get_next_line(fd);
		i++;
	}
	close(fd);
	return (quest);
}

int	main(int ac, char *av[])
{
	int		rand_num;
	t_game	game;
	char	*answer;

	if (ac != 3)
	{
		printf("Error: number of parameter");
		return (1);
	}
	rand_num = get_random_num();
	game.question = get_line(av[1], rand_num);
	game.answer = get_line(av[2], rand_num);
	printf("Inona ary izany?\n");
	printf("%s\n", game.question);
	answer = get_next_line(0);
	if (strncmp(answer, game.answer, strlen(answer)) == 0)
		printf(">>>success<<<\n");
	else
		printf(">>>fail<<<\n");
	return (0);
}
