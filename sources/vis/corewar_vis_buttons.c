/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_buttons.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:12:34 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/07 20:28:16 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void	corewar_init_status(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->state = 0;
	button->text = ft_strndup("  Pause  ", -1);
	button->alt_text = ft_strndup("CoreWars", -1);
	button->init_text = ft_strndup("  Start  ", -1);
	button->text_rect.x = STATUS_X;
	button->text_rect.y = STATUS_Y;
	button->text_rect.w = STATUS_W;
	button->text_rect.h = STATUS_H;
	button->bg = 0;
	button->button_rect.x = STATUS_X - (BUTTON_W * 2);
	button->button_rect.y = STATUS_Y - (BUTTON_H * 2);
	button->button_rect.w = STATUS_W + (BUTTON_W * 4);
	button->button_rect.h = STATUS_H + (BUTTON_H * 4);
}

void	corewar_init_speedup(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->state = 0;
	button->text = ft_strndup("  SpeedUp  ", -1);
	button->alt_text = NULL;
	button->init_text = NULL;
	button->text_rect.x = BTM_BAR_X;
	button->text_rect.y = BTM_BAR_EL_Y(2);
	button->text_rect.w = BTM_BAR_W;
	button->text_rect.h = BAR_H;
	button->bg = 1;
	button->button_rect.x = BTM_BAR_X - BUTTON_W;
	button->button_rect.y = BTM_BAR_EL_Y(2) - BUTTON_H;
	button->button_rect.w = BTM_BAR_W + BUTTON_W * 2;
	button->button_rect.h = BAR_H + BUTTON_H * 2;
}
