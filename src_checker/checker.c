
#include "checker.h"
#include "../includes/push_swap.h"

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

int	main(int ac, char **av)
{
	t_number	*stack_a;
	t_number	*stack_b;
	int			size_a;
	int			size_b;
	char	*line;
	char	*message;

	line = get_next_line(STDIN_FILENO);
	stack_a = init_stack(ac, av);
	stack_b = malloc(sizeof (t_number) * ac - 1);
	size_a = ac - 1;
	size_b = 0;
	while (line != NULL)
	{
		if (ft_strncmp(line, "sa", 2))
			swap(stack_a, size_a);
		else	if (ft_strncmp(line, "sb", 2))
			swap(stack_b, size_b);
		else if (ft_strncmp(line , "ss", 2))
		{
			swap(stack_a, size_a);
			swap(stack_b, size_b);
		}
		else if (ft_strncmp(line, "ra", 2))
			rotate(stack_a, size_a);
		else	if (ft_strncmp(line, "rb", 2))
			rotate(stack_b, size_b);
		else if (ft_strncmp(line , "rr", 2))
		{
			rotate(stack_a, size_a);
			rotate(stack_b, size_b);
		}
		else if (ft_strncmp(line, "rra", 3))
			reverse_rotate(stack_a, size_a);
		else	if (ft_strncmp(line, "rrb", 3))
			reverse_rotate(stack_b, size_b);
		else if (ft_strncmp(line , "rrr", 3))
		{
			reverse_rotate(stack_a, size_a);
			reverse_rotate(stack_b, size_b);
		}
		else if (ft_strncmp(line, "pb", 2))
			push(stack_a, stack_b, &size_a, &size_b);
		else if (ft_strncmp(line, "pa", 2))
			push(stack_b, stack_a, &size_b, &size_a);
		else
		{
			ft_putstr_fd("Error\n", 1);
			return (free(stack_a), free(stack_b), 0);
		}
		line = get_next_line(STDIN_FILENO);
	}
	message = "OK\n";
	while (--size_a > 0)
		if (stack_a[size_a].number < stack_a[size_a - 1].number)
			message = "KO\n";
	ft_putstr_fd(message, 1);
	return (free(stack_a), free(stack_b), 0);
}


