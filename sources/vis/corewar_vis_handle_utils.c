/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_handle_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:48:36 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/06 15:13:00 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis_def.h"

bool	corewar_vis_hitbox(Sint32 x, Sint32 y, SDL_Rect *button)
{
	if (x > button->x && x < button->x + button->w
		&& y > button->y && y < button->y + button->h)
		return (true);
	return (false);
}

void	corewar_vis_set_hower(t_vis *vis, t_button *button)
{
	vis->buttons.values.hower = false;
	vis->buttons.reverse.hower = false;
	vis->buttons.exit.hower = false;
	vis->buttons.pause.hower = false;
	vis->buttons.slowdown.hower = false;
	vis->buttons.speedup.hower = false;
	vis->buttons.status.hower = false;
	vis->buttons.nxt.hower = false;
	if (button)
		button->hower = true;
}

void	corewar_vis_set_press(t_vis *vis, t_button *button)
{
	vis->buttons.values.press = false;
	vis->buttons.reverse.press = false;
	vis->buttons.exit.press = false;
	vis->buttons.pause.press = false;
	vis->buttons.slowdown.press = false;
	vis->buttons.speedup.press = false;
	vis->buttons.status.press = false;
	vis->buttons.nxt.press = false;
	if (button)
		button->press = true;
}
