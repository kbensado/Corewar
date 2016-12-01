/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 22:22:09 by kbensado          #+#    #+#             */
/*   Updated: 2016/10/07 05:16:16 by niborrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"
# include <fcntl.h>
# include <sys/errno.h>

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NUMBERS 				"0123456789"

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char					t_args_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

/*
**	my Define bullshit
*/

# define BUFFER core->buffer
# define LEN_B core->len_buff
# define PROG_N core->header->name->prog_name
# define STR_B core->str_buff
# define MAGIC core->header->magic
# define STRING_TEST str[i] == sep[0] || str[i] == sep[1] || str[i] == sep[2]
# define IS_ALPHA ft_str_is_alpha(str[i])
# define ERRORB "Error !\n"
# define CHECK_A g_op_tab[get_data(tree->str, 2, 0) - 1].type_arg[i]
# define LEN ft_strlen(tree->str)

typedef struct		s_header
{
	char			magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
	char			*exec_name;
}					t_header;

typedef struct		s_build
{
	int				key;
	int				type;
	int				nb_oct;
	int				nb_arg;

}					t_build;

/*
**	1 = label: , 2 = op, 3 = arg(dir)
**	4 = arg(und), 5 arg(reg), 6 arg(dirlabel)
** 	7 = arg(undir_label)
*/

typedef struct		s_tree
{
	unsigned int	key;
	unsigned int	type;
	unsigned int	nb_oct;
	unsigned int	nb_arg;
	int				value;
	char			*str;
	struct s_tree	*next;
	unsigned int	i;
}					t_tree;

typedef struct		s_op
{
	char			*op;
	int				op_id;
	int				type_arg[3];
	unsigned int	nb_arg;
	unsigned int	label_size;
	unsigned int	octet;
	unsigned int	nb_octet;

}					t_op;

typedef struct		s_core
{
	int				fd;
	t_header		*header;
	unsigned int	buff_i;
	char			**tab;
	char			*path;
	unsigned int	len_buff;
	unsigned int	file_size;
	unsigned int	size;
	unsigned int	tmp;

}					t_core;

int					launch(int ac, char **av, t_core *core, t_tree *tree);
t_core				*get_file(t_core *core, int fd, unsigned int i, int flag);
int					dat_s(char *str, int len);
int					dat_core(char *str, int len);
void				free_double_char(char **str, unsigned int len);
int					reg_is_clean(t_tree *tree, t_tree *begin);
int					arg_is_clean(t_tree *tree, t_tree *tmp, unsigned int nb);
int					label_is_clean(t_tree *tree, t_tree *tmp,
					t_tree *begin, char *str_tmp);
int					check_arg(int type, int op);
int					create_file(t_core *core);
int					is_label(char *c);
int					ft_addrrev4(unsigned int val1);
char				**ft_strsplit2(char *str, char c, char b, char **tab);
int					match(char *s1, char *s2);
int					get_data(char *str, unsigned int index,
					unsigned int i);
int					line_clean(char *str, unsigned int i, unsigned int j);
int					ft_error(char *str, char *data, t_tree *tree);
int					ft_addrrev(int val, int flag);
int					warp_it(t_tree *tree, int key, int foo, int bar);
void				clean_label(t_tree *tree);
int					true_key(int key, int oct);
int					set_file(t_core *core, t_tree *tree, int flag);
void				ajust_label(t_tree *tree, t_core *core,
					unsigned int tmp, t_tree *begin_tree);
char				*sub_way(char *str, unsigned int i, unsigned int flag);
t_tree				*set_arg(t_tree *tree, t_core *core, char *str);
t_tree				*set_op(t_tree *tree, t_core *core, char *str, char *line);
void				ft_list_p_front(t_tree **begin_list,
					t_build build[1], char *str);
t_tree				*parse_line(t_core *core, char *line,
					t_tree *tree, unsigned int i);
t_tree				*set_label_post(t_tree *tree, t_core *core, char *str);
t_tree				*parse_file(t_core *core, unsigned int i);
void				print_prog_name(t_core *core);
void				print_error(t_tree *tree);
int					retard_error(t_tree *tree, t_tree *begin);
int					ft_strcmpl(char *str, char *str2, unsigned int i,
					unsigned int j);
char				*create_path(char *str, unsigned int len);
unsigned int		nb_line(int fd);
int					check_char(char *str, unsigned int i, int flag);
int					ft_strstrl(char *str, char *str2, int i, int j);
void				free_list(t_core *core, t_tree *tree, t_tree *tmp);
int					check_char_label(char *str, unsigned int i);
int					test_f(char *line);
int					brain_check(t_tree *tree, int flag);
int					first_n(char *str, int i);
char				**check_double_lift(char **str);

static t_op			g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 4, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 4, 1, 0},
	{"st", 3, {T_REG, T_IND | T_REG}, 2, 2, 1, 0},
	{"add", 4, {T_REG, T_REG, T_REG}, 3, 0, 1, 0},
	{"sub", 5, {T_REG, T_REG, T_REG}, 3, 0, 1, 0},
	{"and", 6, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		3, 4, 1, 0},
	{"or", 7, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		3, 4, 1, 0},
	{"xor", 8, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		3, 4, 1, 0},
	{"zjmp", 9, {T_DIR}, 1, 2, 0, 0},
	{"ldi", 10, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 3, 2, 1, 0},
	{"sti", 11, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 3, 2, 1, 0},
	{"fork", 12, {T_DIR}, 1, 2, 0, 0},
	{"lld", 13, {T_DIR | T_IND, T_REG}, 2, 4, 1, 0},
	{"lldi", 14, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 3, 2, 1, 0},
	{"lfork", 15, {T_DIR}, 1, 2, 0, 0},
	{"aff", 16, {T_REG}, 1, 0, 1, 0},
	{0, 0, {0}, 0, 0, 0, 0}
};
#endif
