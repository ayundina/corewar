/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   and.c                               	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			get_value_at_indirect(t_vm *vm, t_cursor *cursor)
{
	int			pos;

	if (cursor->operation.check[0] == 3)
	{
		pos = cursor->position + (cursor->operation.arg[0] % IDX_MOD);
		pos = (modulo(pos, MEM_SIZE));
		cursor->operation.arg[0] = get_value_at_address(vm, pos);
	}
	if (cursor->operation.check[1] == 3)
	{
		pos = cursor->position + (cursor->operation.arg[1] % IDX_MOD);
		pos = (modulo(pos, MEM_SIZE));
		cursor->operation.arg[1] = get_value_at_address(vm, pos);
	}
	return ;
}

void			and_op(t_vm *vm, t_cursor *cursor)
{
	get_value_at_indirect(vm, cursor);
	cursor->reg[cursor->operation.arg[2]] =
	cursor->operation.arg[0] & cursor->operation.arg[1];
	if (cursor->reg[cursor->operation.arg[2]] == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	return ;
}
