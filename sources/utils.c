/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:03:54 by bhamed            #+#    #+#             */
/*   Updated: 2024/06/24 23:11:02 by rrabeari         ###   ########.fr       */
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
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: reading file");
		return (NULL);
	}
	while (i < rand_num)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (line == NULL)
			return (NULL);
		i++;
	}
	close(fd);
	return (line);
}

void	free_resources(t_game game)
{
	free(game.question);
	free(game.answer);
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

void	initialise_head(int score)
{
	const char	*hackamantatra;
	const char	*doc;
	const char	*score_char;


	hackamantatra = 
"/*============================================================================================================*\\\n"
"*                                                                                                              *\n"
"| ██   ██  █████  ███████ █   ██  █████ █ ██    ███  █████  ███    ███ ███████ ██████ ████████ ██████    ████  |  \n"
"| ██   ██ ██   ██ ██      ██  ██  ██   ██ ████  ███ ███   █ █████   ██    ██   ██   ██   ██    ██   ██ ██   ██ |   \n"
"| ███████ ███████ ██      █████   ███████ ██ ████ █ ███████ ███ ██  ██    ██   ███████   ██    █████   ███████ |   \n"
"| ██   ██ ██   ██ ██      ██  ██  ██   ██ ██  ██  █ ███   █ ███  ██ ██    ██   ██   ██   ██    ██   ██ ██   ██ |   \n"
"| ██   ██ ██   ██  ██████ ██   ██ ██   ██ ██      █ ███   █ ███   ████    ██   ██   ██   ██    ██   ██ ██   ██ |   \n"
"*                                                                                                              *    \n"
" \\*===========================================================================================================*/ \n";

	doc = 
"****************************************************************************************************************\n"
"*    Lalao natao ialana voly fahiny ny Ankamantatra, nentina ampivoharana ny sain'i ankizy mba hikaroka sy     *\n"
"*    sy hatsilo saina. Mila mamaly ny fanotaniana izay apetraka ianao ka raha tsy misy diso ny fanoratanao     *\n"
"*    ny valiny dia marina izany. Lalao natao mba hamerenana indray ny hasin'i tsipelina malagasy ity lalao     *\n"
"*    ity sy natao ampianarana ny malagasy zavatra vaovao raha tsy fantany taloha. Raha anova ankamantatra      *\n"
"*    ianao nefa tsy nahamarina akory ilay teo aloha dia very ny isa anananao. Mahazo mamerina foana anefa      *\n"
"*    raha toha ka tsy mbola afa-po. Raha anova ankamantatra dia tsindrio ny \"CTRL + D\", raha tsy ilalao      *\n"
"*    intsony dia tsindrio ny \"ESC\". Mahazoa fafinaretana ary o.                                              *\n\n";

	score_char = 
"                                                                                                isa(score) : ";
	printf("%s", hackamantatra);
	printf("%s", doc);
	printf("%s%d\n", score_char, score);
}

void	check_result(int score, int i)
{
	char	*succes;
	char	*fail;

	succes = 
"                                 ,.        ,.      ,.\n"
"                                ||        ||      ||  ()\n"
" ,--. ,-. ,.,-.  ,--.,.,-. ,-.  ||-.,.  ,.|| ,-.  ||-.,. ,-. ,.,-.  ,--.\n"
"//`-'//-\\||/|| //-||||/`'//-\\ ||-'||  ||||//-\\ ||-'||//-\\||/|| ((`-'\n"
"||   || |||| ||||  ||||   || || ||  || /|||||| || ||  |||| |||| ||  ``.\n"
"\\,-.\\-//|| || \\-||||   \\-|| ||  ||//||||\\-|| ||  ||\\-//|| || ,-.))\n"
" `--' `-' `' `'  `-,|`'    `-^-``'  `-' `'`' `-^-``'  `' `-' `' `' `--'\n"
"                  //           .--------.\n"
"              ,-.//          .: : :  :___`.\n"
"              `--'         .'!!:::::  \\\\_\\ `.\n"
"                      : . /%O!!::::::::\\\\_\\. \\             \n"
"                     [\"\"]/%%O!!:::::::::  : . \\            \n"
"                     |  |%%OO!!::::::::::: : . |            \n"
"                     |  |%%OO!!:::::::::::::  :|            \n"
"                     |  |%%OO!!!::::::::::::: :|            \n"
"            :       .'--`.%%OO!!!:::::::::::: :|           \n"
"          : .:     /`.__.'\\%%OO!!!::::::::::::/              \n"
"         :    .   /        \\%OO!!!!::::::::::/              \n"
"        ,-'``'-. ;          ;%%OO!!!!!!:::::'                \n"
"        |`-..-'| |   ,--.   |`%%%OO!!!!!!:'                           \n"
"        | .   :| |_.','`.`._|  `%%%OO!%%'                               \n"
"        | . :  | |--'    `--|    `%%%%'                                      \n"
"        |`-..-'| ||   | | | |     /__\\`-.                                    \n"
"        \\::::::/ ||)|/|)|)|\\|           /                                    \n"
"---------`::::'--|._ ~**~ _.|----------( -----------------------               \n"
"           )(    |  `-..-'  |           \\    ______                           \n"
"           )(    |          |,--.       ____/ /  /\\ ,-._.-'                \n"
"        ,-')('-. |          |\\`;/   .-()___  :  |`.!,-'`'/`-._               \n"
"       (  '  `  )`-._    _.-'|;,|    `-,    \\_\\__\\`,-'>-.,-._               \n"
"        `-....-'     ````    `--'      `-._       (`- `-._`-.               \n\n";

	fail = 
"                      ⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠋⠉⠉⠉⠙⠛⢿⠿⠛⠛⠛⠛⠛⠿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⢀⡀⠤⠤⢄⣀⠐⡄⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿\n"
"                      ⣿⣿⣿⣿⣿⠟⠀⠀⠀⠐⠁⠀⠀⢀⣀⣀⣉⣒⣄⠉⠉⠉⢉⣀⣂⠈⠙⠻⣿⣿\n"
"                      ⣿⣿⣿⠟⠉⡄⠀⠀⠀⠠⠤⣐⠭⠒⠉⠉⠉⠉⣒⣳⠈⠛⠂⠀⠀⣒⣛⡢⠈⢿n"
"                      ⣿⣿⠁⠀⠀⠃⠀⠀⠈⠛⠛⠠⣤⣶⠖⠙⠀⡉⢻⡿⣶⣿⣿⠁⡂⠠⠈⢿⠗⢸\n"
"                      ⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠂⠭⠤⠤⠤⣤⠄⠊⠀⠀⠈⠀⠀⠀⠀⢀⣶⣿\n"
"                      ⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠉⠀⠀⠀⠈⠁⠒⠂⠈⠁⠘⢿⣿⣿\n"
"                      ⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿\n"
"                      ⡇⠀⠀⠀⠀⠀⠀⠀⠀⣾⣟⣛⣛⣻⡶⠶⠶⣶⣤⣤⣤⣤⣤⣤⣤⡶⠾⢃⣼⣿\n"
"                      ⣷⡀⠀⠀⠀⠀⠀⠘⢄⡀⠀⠀⠉⠉⠙⠛⠛⠛⠓⠛⠻⠿⠿⠷⠿⠟⢃⣼⣿⣿\n"
"                      ⣿⣿⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣿⣿⣿⣿⣿\n"
"                      ⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⡿⠁⠀⠀⢠⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡶⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⠃⠀⠀⢀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣇⠀⢠⢶⣿⣿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⡄⠀⢠⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠋⢸⣿⣿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⣿⣿⡏⠀⠀⠀⠀⢰⣶⣤⣤⣤⣤⣤⣴⣦⡀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
"                      ⣿⣿⣿⣷⣄⣀⣀⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣄⣀⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\n";


	initialise_head(score);
	if (score == 0)
	{
		printf("=============================>Lany ny isa anananao<=============================\n\n\n");
		printf(RED"%s"CRESET, fail);
	}
	if (i == 5)
	{
		printf("======>Arabaina fa nahavita atraminy farany ianao ary mbola manana isa %d <======\n\n\n", score);
		printf(GRN"%s"CRESET, succes);
	}
}
