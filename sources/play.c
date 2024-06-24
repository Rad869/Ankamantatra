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
	lower_case(answer);
	lower_case(game->answer);
	if (strcmp(answer, game->answer) == 0)
		printf(GRN"\nMarina\n\n"CRESET);
	else
		printf(RED"\nDiso\n\n"CRESET);
	sleep(1);
}

static void	init_question(t_game *game)
{
	int	rand_num;
	
	rand_num = get_random_num();
	game->question = get_line("data/questions.txt", rand_num);
	game->answer = get_line("data/responses.txt", rand_num);
}

void	play(t_game *game)
{
	unsigned int	i;
	char			answer[100];

	i = 0;
	while (++i <= 5)
	{
		printf("================\n Fanontaniana %d\n================\n", i);
		init_question(game);
		printf("%s", game->question);
		fgets(answer, 100, stdin);
		check_answer(game, answer);
		free_resources(*game);
	}
}
