/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_buttons2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:08:23 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 16:59:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void	corewar_init_slowdown(t_button *btn)
{
	btn->press = false;
	btn->hower = false;
	btn->active = false;
	btn->msg = ft_strndup("SlowDown", -1);
	btn->alt_msg = NULL;
	btn->init_msg = NULL;
	btn->bg_shown = true;
	btn->bg = (SDL_Rect){BAR_X, BTM_BAR_Y(3), S_BUTTON_W, S_BUTTON_H};
}

void	corewar_init_pause(t_button *btn)
{
	btn->press = false;
	btn->hower = false;
	btn->active = false;
	btn->msg = ft_strndup("Resume", -1);
	btn->alt_msg = ft_strndup(" Pause ", -1);
	btn->init_msg = ft_strndup(" Start ", -1);
	btn->bg_shown = true;
	btn->bg = (SDL_Rect){BAR_X, BTM_BAR_Y(7), S_BUTTON_W, S_BUTTON_H};
}

void	corewar_init_exit(t_button *btn)
{
	btn->press = false;
	btn->hower = false;
	btn->active = false;
	btn->msg = ft_strndup("Quit", -1);
	btn->alt_msg = NULL;
	btn->init_msg = NULL;
	btn->bg_shown = true;
	btn->bg = (SDL_Rect){BAR_X, BTM_BAR_Y(8), S_BUTTON_W, S_BUTTON_H};
}

void	corewar_init_reverse(t_button *btn)
{
	btn->press = false;
	btn->hower = false;
	btn->active = false;
	btn->msg = ft_strndup("Reverse", -1);
	btn->alt_msg = NULL;
	btn->init_msg = NULL;
	btn->bg_shown = true;
	btn->bg = (SDL_Rect){BAR_X, BTM_BAR_Y(5), S_BUTTON_W, S_BUTTON_H};
}

void	corewar_init_values(t_button *btn)
{
	btn->press = false;
	btn->hower = false;
	btn->active = false;
	btn->msg = ft_strndup("Details", -1);
	btn->alt_msg = NULL;
	btn->init_msg = NULL;
	btn->bg_shown = true;
	btn->bg = (SDL_Rect){BAR_X, BTM_BAR_Y(6), S_BUTTON_W, S_BUTTON_H};
}
