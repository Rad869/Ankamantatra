/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:51:05 by bhamed            #+#    #+#             */
/*   Updated: 2024/06/25 06:54:24 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ankamantatra.h"

static int	check_answer(t_game *game, char *answer)
{
	int	i;

	i = 0;
	lower_case(answer);
	lower_case(game->answer);
	while (game->answer[i] != '\n')
		i++;
	game->answer[i] = '\0';
	if (strcmp(answer, game->answer) == 0)
	{
		printf(GRN"\nMarina\n\n"CRESET);
		return (1);
	}
	else
	{
		printf(RED"\nDiso - %s anefa izany!\n\n"CRESET, game->answer);
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
	int				check;
	int				score;

	i = 0;
	check = 1;
	score = 3;
	while (check != -1 && score && i < 5)
	{
		system("clear");
		initialise_head(score);
		if (check == 1)
		{
			init_question(game);
			i++;
		}
		printf("==============================================\n Fanontaniana %d\n==============================================\n", i);
		check = 2;
		printf("%s", game->question);
		read_answer(answer, 100);
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
