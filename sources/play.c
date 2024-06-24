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
	int	i;

	i = 0;
	lower_case(answer);
	lower_case(game->answer);
	while (game->answer[i] != '\n')
		i++;
	game->answer[i] = '\0';
	if (strcmp(answer, game->answer) == 0)
		printf(GRN"\nMarina\n\n"CRESET);
	else
		printf(RED"\nDiso - %s anefa izany!\n\n"CRESET, game->answer);
	sleep(1);
}

static void	init_question(t_game *game)
{
	int	rand_num;
	
	rand_num = get_random_num();
	game->question = get_line("data/questions.txt", rand_num);
	game->answer = get_line("data/responses.txt", rand_num);
}

void	empty_buf()
{
	int	c;

	c = 0;
	while (c != '\n' && c != EOF)
		c = getc(stdin);
}

void	read_answer(char *str, int len)
{
	char	*pos_line_break;

	pos_line_break = NULL;
	if (fgets(str, len, stdin) != NULL)
	{
		pos_line_break = strchr(str, '\n');
		if (pos_line_break != NULL)
			*pos_line_break = '\0';
		else
			empty_buf();
	}
	else
		empty_buf();
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
		read_answer(answer, 100);
		check_answer(game, answer);
		free_resources(*game);
	}
}
