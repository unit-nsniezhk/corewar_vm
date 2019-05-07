/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_buttons2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:08:23 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/07 20:43:47 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void	corewar_init_slowdown(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->state = 0;
	button->text = ft_strndup("  SlowDown  ", -1);
	button->alt_text = NULL;
	button->init_text = NULL;
	button->text_rect.x = BTM_BAR_X;
	button->text_rect.y = BTM_BAR_EL_Y(3);
	button->text_rect.w = BTM_BAR_W;
	button->text_rect.h = BAR_H;
	button->bg = 1;
	button->button_rect.x = BTM_BAR_X - BUTTON_W;
	button->button_rect.y = BTM_BAR_EL_Y(3) - BUTTON_H;
	button->button_rect.w = BTM_BAR_W + (BUTTON_W * 2);
	button->button_rect.h = BAR_H + (BUTTON_H * 2);
}

void	corewar_init_pause(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->state = 0;
	button->text = ft_strndup("   Resume   ", -1);
	button->alt_text = ft_strndup("   Pause   ", -1);
	button->init_text = ft_strndup("  Start   ", -1);
	button->text_rect.x = BTM_BAR_X;
	button->text_rect.y = BTM_BAR_EL_Y(7);
	button->text_rect.w = BTM_BAR_W;
	button->text_rect.h = BAR_H;
	button->bg = 1;
	button->button_rect.x = BTM_BAR_X - BUTTON_W;
	button->button_rect.y = BTM_BAR_EL_Y(7) - BUTTON_H;
	button->button_rect.w = BTM_BAR_W + (BUTTON_W * 2);
	button->button_rect.h = BAR_H + (BUTTON_H * 2);
}

void	corewar_init_exit(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->state = 0;
	button->text = ft_strndup("   QUIT   ", -1);
	button->alt_text = NULL;
	button->init_text = NULL;
	button->text_rect.x = BTM_BAR_X;
	button->text_rect.y = BTM_BAR_EL_Y(8);
	button->text_rect.w = BTM_BAR_W;
	button->text_rect.h = BAR_H;
	button->bg = 1;
	button->button_rect.x = BTM_BAR_X - BUTTON_W;
	button->button_rect.y = BTM_BAR_EL_Y(8) - BUTTON_H;
	button->button_rect.w = BTM_BAR_W + (BUTTON_W * 2);
	button->button_rect.h = BAR_H + (BUTTON_H * 2);
}

void	corewar_init_reverse(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->state = 0;
	button->text = ft_strndup("  Reverse  ", -1);
	button->alt_text = NULL;
	button->init_text = NULL;
	button->text_rect.x = BTM_BAR_X;
	button->text_rect.y = BTM_BAR_EL_Y(5);
	button->text_rect.w = BTM_BAR_W;
	button->text_rect.h = BAR_H;
	button->bg = 1;
	button->button_rect.x = BTM_BAR_X - BUTTON_W;
	button->button_rect.y = BTM_BAR_EL_Y(5) - BUTTON_H;
	button->button_rect.w = BTM_BAR_W + (BUTTON_W * 2);
	button->button_rect.h = BAR_H + (BUTTON_H * 2);
}

void	corewar_init_values(t_button *button)
{
	button->press = 0;
	button->hower = 0;
	button->state = 0;
	button->text = ft_strndup("   Details   ", -1);
	button->alt_text = NULL;
	button->init_text = NULL;
	button->text_rect.x = BTM_BAR_X;
	button->text_rect.y = BTM_BAR_EL_Y(6);
	button->text_rect.w = BTM_BAR_W;
	button->text_rect.h = BAR_H;
	button->bg = 1;
	button->button_rect.x = BTM_BAR_X - BUTTON_W;
	button->button_rect.y = BTM_BAR_EL_Y(6) - BUTTON_H;
	button->button_rect.w = BTM_BAR_W + (BUTTON_W * 2);
	button->button_rect.h = BAR_H + (BUTTON_H * 2);
}
