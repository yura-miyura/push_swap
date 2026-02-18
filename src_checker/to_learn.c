
// # define FT_SWAP_OP_SA 0x6173 /* *(int *)"sa" */
// # define FT_SWAP_OP_SB 0x6273
// # define FT_SWAP_OP_SS 0x7373
// # define FT_SWAP_OP_PA 0x6170
// # define FT_SWAP_OP_PB 0x6270
// # define FT_SWAP_OP_RA 0x6172
// # define FT_SWAP_OP_RB 0x6272
// # define FT_SWAP_OP_RR 0x7272
// # define FT_SWAP_OP_RRA 0x617272
// # define FT_SWAP_OP_RRB 0x627272
// # define FT_SWAP_OP_RRR 0x727272
//
// typedef enum command
// {
// 	SA = FT_SWAP_OP_SA,
// 	sb = FT_SWAP_OP_SB,
// 	ss = FT_SWAP_OP_SS,
// 	pa = FT_SWAP_OP_PA,
// 	pb = FT_SWAP_OP_PB,
// 	ra = FT_SWAP_OP_RA,
// 	rb = FT_SWAP_OP_RB,
// 	rr = FT_SWAP_OP_RR,
// 	rra = FT_SWAP_OP_RRA,
// 	rrb = FT_SWAP_OP_RRB,
// 	rrr = FT_SWAP_OP_RRR
// }			t_command;
//
// char *ft_strchrnul(const char *s, int c)
// {
// 	return __builin_strchrnull(s, c);
// }
//
// typedef struct s_entry {
// 	t_command cmd;
// 	void *ptr;
// }	t_entry;
//
// void	*get_comm(t_command cmd)
// {
// 	static t_entry map[CMD_MAX] = {
// 		{ .cmd = SA, .ptr = swap}
// 	}
//
// 	void *func = NULL;
//
//
// 	int i = 0;
// 	while (i < sizeof(map) / sizeof(map[0]))
// 	{
// 		if (cmd == map[i].cmd)
// 		{
// 			func = map[i].ptr;
// 			break ;
// 		}
// 	}
// 	return func;
//
// }
//
// int	main(int ac, char **av)
// {
// 	t_command cmd;
// 	char *line;
//
// 	line = get_next_line(STDIN_FILENO);
//
// 	while (line != NULL) {
// 		char *end = ft_strchrnul(line, '\n');
//
// 		*end = '\0';
//
// 		ft_strncpy(&(char [4])cmd, line, 4);
// 		void *apply = get_comm(cmd);
//
// 		if (apply != NULL)
// 			apply();
// 	}
//
// 	if (errno = -1) {
// 		; //FIXME: implement error handling logic
// 	}
// }

// char *ft_strchrnul(const char *s, int c)
// {
// 	return __builin_strchrnull(s, c);
// }
