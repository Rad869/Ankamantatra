#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_game {
	char *question;
	char *answer;
}	t_game;

/*utils*/
int	str_len(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
