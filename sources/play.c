/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamed <bhamed@student.42antananarivo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:51:05 by bhamed            #+#    #+#             */
/*   Updated: 2024/06/24 15:17:53 by bhamed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ankamantatra.h"

static void	check_answer(t_game *game, char *answer)
{
	if (strcmp(answer, game->answer) == 0)
		printf(GRN"\nTrue\n\n"CRESET);
	else
		printf(RED"\nFalse\n\n"CRESET);
	sleep(1);
}

static void	init_question(t_game *game, char **av)
{
	int	rand_num;

	rand_num = get_random_num();
	game->question = get_line(av[1], rand_num);
	game->answer = get_line(av[2], rand_num);
}

void	play(t_game *game, char **av)
{
	unsigned int	i;
	char			answer[100];

	i = 0;
	while (++i <= 5)
	{
		printf("================\n Fanontaniana %d\n================\n", i);
		init_question(game, av);
		printf("%s", game->question);
		fgets(answer, 100, stdin);
		check_answer(game, answer);
	}
}
