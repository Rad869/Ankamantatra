/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:51:05 by bhamed            #+#    #+#             */
/*   Updated: 2024/06/25 12:35:33 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ankamantatra.h"

static int	check_answer(t_data *data, char *answer)
{
	char	*give_up;
	int	i;

	i = 0;
	give_up = "/afa-po\0";
	lower_case(answer);
	while (data->answer[i] != '\n')
		i++;
	data->answer[i] = '\0';
	if (strcmp(answer, data->answer) == 0)
	{
		printf(GRN"\nMarina\n\n"CRESET);
		return (1);
	}
	else if (strcmp(answer, give_up) == 0)
	{
		printf(RED"\n%s anefa izany!\n\n"CRESET, data->answer);
		return (2);
	}
	else
	{
		printf(RED"\nDiso\n\n"CRESET);
		return (0);
	}
	sleep(1);
	return (0);
}

static void	init_question(t_data *data)
{
	int	rand_num;

	rand_num = get_random_num();
	data->question = get_line("data/questions.txt", rand_num);
	data->answer = get_line("data/responses.txt", rand_num);
}

static void	empty_buf(void)
{
	int	c;

	c = 0;
	while (c != '\n' && c != EOF)
		c = getc(stdin);
}

static void	read_answer(char *str, int len)
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

void	play(t_data *data)
{
	size_t	i;
	char	answer[100];
	int		check;
	int		score;
	int		result_chk;

	i = 0;
	check = 1;
	score = 3;
	while (check != -1 && score)
	{
		write(STDOUT_FILENO, "\x1b[2J", 4);
		write(STDOUT_FILENO, "\x1b[H", 3);
		initialise_head(score);
		if (check == 1)
		{
			init_question(data);
			i++;
		}
		printf("================\n Fanontaniana %ld\n================\n", i);
		check = 2;
		printf("%s", data->question);
		read_answer(answer, 100);
		if (answer[0] == 0x0E)
		{
			check = 1;
			score--;
			free_resources(*data);
			continue ;
		}
		if (!strcmp(answer, "/q\0") || !strcmp(answer, "/hiala\0"))
		{
			check = -1;
			free_resources(*data);
			continue ;
		}
		if ((result_chk = check_answer(data, answer)) == 1)
		{
			check = 1;
			score++;
		}
		if (result_chk == 2 || result_chk == 0)
		{
			if (result_chk == 2)
			{
				check = 1;
				free_resources(*data);
			}
			score--;
		}
		sleep(2);
	}
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
	check_result(score, i);
}
