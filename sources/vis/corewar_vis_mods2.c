/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_mods2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:24:11 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 20:37:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis_def.h"

void	corewar_vis_nxt(t_vis *vis)
{
	vis->buttons.nxt.active = true;
	vis->buttons.run.active = false;
	vis->buttons.status.active = true;
}
