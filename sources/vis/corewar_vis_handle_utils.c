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

int		corewar_vis_hitbox(Sint32 x, Sint32 y, SDL_Rect *button)
{
	if (x > button->x && x < button->x + button->w
		&& y > button->y && y < button->y + button->h)
		return (1);
	return (0);
}

void	corewar_vis_set_hower(t_vis *vis, t_button *button)
{
	vis->buttons.values.hower = 0;
	vis->buttons.reverse.hower = 0;
	vis->buttons.exit.hower = 0;
	vis->buttons.pause.hower = 0;
	vis->buttons.slowdown.hower = 0;
	vis->buttons.speedup.hower = 0;
	vis->buttons.status.hower = 0;
	if (button)
		button->hower = 1;
}

void	corewar_vis_set_press(t_vis *vis, t_button *button)
{
	vis->buttons.values.press = 0;
	vis->buttons.reverse.press = 0;
	vis->buttons.exit.press = 0;
	vis->buttons.pause.press = 0;
	vis->buttons.slowdown.press = 0;
	vis->buttons.speedup.press = 0;
	vis->buttons.status.press = 0;
	if (button)
		button->press = 1;
}
