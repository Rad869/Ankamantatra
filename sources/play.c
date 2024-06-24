/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:51:05 by bhamed            #+#    #+#             */
/*   Updated: 2024/06/24 23:18:55 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ankamantatra.h"

static int	check_answer(t_game *game, char *answer)
{
	lower_case(answer);
	lower_case(game->answer);
	if (strcmp(answer, game->answer) == 0)
	{
		printf(GRN"\nMarina\n\n"CRESET);
		return (1);
	}
	else
	{
		printf(RED"\nDiso\n\n"CRESET);
		return (0);
	}
	sleep(1);
	return(0);
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
	int				check;
	int				score;

	i = 0;
	check = 1;
	score = 3;
	while (check != -1 && score && i < 5)
	{
		system("clear");
		initialise_head(score);
		printf("==============================================\n Fanontaniana %d\n==============================================\n", i + 1);
		if (check == 1)
		{
			init_question(game);
			i++;
		}
		check = 2;
		printf("%s", game->question);
		fgets(answer, 100, stdin);
		if (answer[0] == 0x0E)
		{
			check = 1;
			score--;
			free_resources(*game);
			continue ;
		}
		if (answer[0] == 27)
		{
			check = -1;
			free_resources(*game);
			continue ;
		}
		if (check_answer(game, answer))
			check = 1;
	}
	system("clear");
	check_result(score, i);
}
