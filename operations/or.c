/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   or.c                               	            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:25:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/21 12:25:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			or_op(t_vm *vm, t_cursor *cursor)
{
	get_value_at_indirect(vm, cursor);
	cursor->reg[cursor->operation.arg[2]] =
	cursor->operation.arg[0] | cursor->operation.arg[1];
	if (cursor->reg[cursor->operation.arg[2]] == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	return ;
}
