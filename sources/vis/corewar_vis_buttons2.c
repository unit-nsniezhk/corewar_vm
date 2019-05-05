/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_buttons2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:08:23 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/05 23:03:41 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void	corewar_init_slowdown(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->pressed = 0;
	button->text = ft_strndup("SpeedDown", -1);
	button->alt_text = NULL;
	button->text_rect.x = LOW_BAR_X;
	button->text_rect.y = SLOWDOWN_Y;
	button->text_rect.w = LOW_BAR_W;
	button->text_rect.h = LOW_BAR_H;
	button->bg = 1;
	button->button_rect.x = LOW_BAR_X - BUTTON_W;
	button->button_rect.y = SLOWDOWN_Y - BUTTON_H;
	button->button_rect.w = LOW_BAR_W + (BUTTON_W * 2);
	button->button_rect.h = LOW_BAR_H + (BUTTON_H * 2);
}

void	corewar_init_pause(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->pressed = 0;
	button->text = ft_strndup("Pause", -1);
	button->alt_text = ft_strndup("Start", -1);
	button->text_rect.x = LOW_BAR_X;
	button->text_rect.y = PAUSE_Y;
	button->text_rect.w = LOW_BAR_W;
	button->text_rect.h = LOW_BAR_H;
	button->bg = 1;
	button->button_rect.x = LOW_BAR_X - BUTTON_W;
	button->button_rect.y = PAUSE_Y - BUTTON_H;
	button->button_rect.w = LOW_BAR_W + (BUTTON_W * 2);
	button->button_rect.h = LOW_BAR_H + (BUTTON_H * 2);
}

void	corewar_init_exit(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->pressed = 0;
	button->text = ft_strndup("EXIT", -1);
	button->alt_text = NULL;
	button->text_rect.x = LOW_BAR_X;
	button->text_rect.y = EXIT_Y;
	button->text_rect.w = LOW_BAR_W;
	button->text_rect.h = LOW_BAR_H;
	button->bg = 1;
	button->button_rect.x = LOW_BAR_X - BUTTON_W;
	button->button_rect.y = EXIT_Y - BUTTON_H;
	button->button_rect.w = LOW_BAR_W + (BUTTON_W * 2);
	button->button_rect.h = LOW_BAR_H + (BUTTON_H * 2);
}

void	corewar_init_reverse(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->pressed = 0;
	button->text = ft_strndup("Reverse", -1);
	button->alt_text = NULL;
	button->text_rect.x = LOW_BAR_X;
	button->text_rect.y = REVERSE_Y;
	button->text_rect.w = LOW_BAR_W;
	button->text_rect.h = LOW_BAR_H;
	button->bg = 1;
	button->button_rect.x = LOW_BAR_X - BUTTON_W;
	button->button_rect.y = REVERSE_Y - BUTTON_H;
	button->button_rect.w = LOW_BAR_W + (BUTTON_W * 2);
	button->button_rect.h = LOW_BAR_H + (BUTTON_H * 2);
}

void	corewar_init_values(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->pressed = 0;
	button->text = ft_strndup("Values", -1);
	button->alt_text = NULL;
	button->text_rect.x = LOW_BAR_X;
	button->text_rect.y = VALUES_Y;
	button->text_rect.w = LOW_BAR_W;
	button->text_rect.h = LOW_BAR_H;
	button->bg = 1;
	button->button_rect.x = LOW_BAR_X - BUTTON_W;
	button->button_rect.y = VALUES_Y - BUTTON_H;
	button->button_rect.w = LOW_BAR_W + (BUTTON_W * 2);
	button->button_rect.h = LOW_BAR_H + (BUTTON_H * 2);
}
