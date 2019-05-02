/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:55:00 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 18:29:00 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_VM_OPERATIONS_H

# define VM_VM_OPERATIONS_H

typedef struct				s_player
{
	unsigned int			pos;
	char					*name;
	char					*comment;
}							t_player;

typedef struct				s_carriage
{
	unsigned int			id;
	unsigned int			carry : 1;
	char					operation;
	unsigned int			cycle_live;
	unsigned int			cycle_timeout;
	int						pos;
	unsigned int			delta_pos;
	int						args_values[3];
	char					args_types[3];
	int						registers[REGISTERS + 1];
	struct s_carriage		*next;
}							t_carriage;

typedef struct				s_game_data
{
	unsigned int			dump;
	unsigned int			check;
	unsigned int			cycle;
	int						cycles_to_die;
	unsigned int			live;
	unsigned int			leading_player;//TODO rm
	unsigned int			n_carriage;
	t_player				players[MAX_CHAMPIONS];
	char					arena[ARENA_SIZE];
	t_carriage				*carriage;
}							t_game_data;

typedef void				(*t_function)(t_game_data *data,
										  t_carriage *carriage);

void	corewar_operation1(t_game_data *data, t_carriage *carriage);
void	corewar_operation2(t_game_data *data, t_carriage *carriage);
void	corewar_operation3(t_game_data *data, t_carriage *carriage);
void	corewar_operation4(t_game_data *data, t_carriage *carriage);
void	corewar_operation5(t_game_data *data, t_carriage *carriage);
void	corewar_operation6(t_game_data *data, t_carriage *carriage);
void	corewar_operation7(t_game_data *data, t_carriage *carriage);
void	corewar_operation8(t_game_data *data, t_carriage *carriage);
void	corewar_operation9(t_game_data *data, t_carriage *carriage);
void	corewar_operation10(t_game_data *data, t_carriage *carriage);
void	corewar_operation11(t_game_data *data, t_carriage *carriage);
void	corewar_operation12(t_game_data *data, t_carriage *carriage);
void	corewar_operation13(t_game_data *data, t_carriage *carriage);
void	corewar_operation14(t_game_data *data, t_carriage *carriage);
void	corewar_operation15(t_game_data *data, t_carriage *carriage);
void	corewar_operation16(t_game_data *data, t_carriage *carriage);

#endif
