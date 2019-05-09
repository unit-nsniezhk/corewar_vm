/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_buttons.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:12:34 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 16:59:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

void	corewar_init_status(t_button *btn)
{
	btn->press = false;
	btn->hower = false;
	btn->active = false;
	btn->msg = ft_strndup("  Pause  ", -1);
	btn->alt_msg = ft_strndup("CoreWars", -1);
	btn->init_msg = ft_strndup("  Start  ", -1);
	btn->bg_shown = false;
	btn->bg = (SDL_Rect){BAR_X, TOP_BAR_Y(0), BUTTON_W, BUTTON_H};
}

void	corewar_init_speedup(t_button *btn)
{
	btn->press = false;
	btn->hower = false;
	btn->active = false;
	btn->msg = ft_strndup("SpeedUp", -1);
	btn->alt_msg = NULL;
	btn->init_msg = NULL;
	btn->bg_shown = true;
	btn->bg = (SDL_Rect){BAR_X, BTM_BAR_Y(2), S_BUTTON_W, S_BUTTON_H};
}

void	corewar_init_nxt(t_button *btn)
{
	btn->press = false;
	btn->hower = false;
	btn->active = false;
	btn->msg = (char*)"Next cycle";
	btn->alt_msg = NULL;
	btn->init_msg = NULL;
	btn->bg_shown = true;
	btn->bg = (SDL_Rect){BAR_X, BTM_BAR_Y(1), BUTTON_W, S_BUTTON_H};
}
