/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_menu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:36:11 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/07 20:46:37 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void	static_render_tips(t_vis *vis)
{
	corewar_vis_render_btext(vis, "Tip: select process with a mouse",
	RGBA_TEXT2, (SDL_Rect){BTM_BAR_X, BTM_BAR_EL_Y(0), 260, BAR_H});
	corewar_vis_render_btext(vis, "Hold LALT & wheel UP", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_X1, BTM_BAR_EL_Y(2), 180, BAR_H});
	corewar_vis_render_btext(vis, "Hold LALT & wheel DOWN", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_X1, BTM_BAR_EL_Y(3), 180, BAR_H});
	corewar_vis_render_btext(vis, "Hold LALT & press F", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_X1, BTM_BAR_EL_Y(5), 160, BAR_H});
	corewar_vis_render_btext(vis, "Hold LALT & press SPACE", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_X1, BTM_BAR_EL_Y(6), 180, BAR_H});
	corewar_vis_render_btext(vis, "Press SPACE", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_X1, BTM_BAR_EL_Y(7), 100, BAR_H});
	corewar_vis_render_btext(vis, "Press ESC", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_X1, BTM_BAR_EL_Y(8), 95, BAR_H});
}

static void	static_render_buttons(t_vis *vis, t_data *data)
{
	SDL_SetRenderDrawBlendMode(vis->rend, SDL_BLENDMODE_BLEND);
	corewar_vis_render_button(vis, data, &vis->buttons.status);
	corewar_vis_render_button(vis, data, &vis->buttons.speedup);
	corewar_vis_render_button(vis, data, &vis->buttons.slowdown);
	corewar_vis_render_button(vis, data, &vis->buttons.pause);
	corewar_vis_render_button(vis, data, &vis->buttons.exit);
	corewar_vis_render_button(vis, data, &vis->buttons.reverse);
	corewar_vis_render_button(vis, data, &vis->buttons.values);
}

void		corewar_vis_render_menu(t_vis *vis, t_data *data)
{
	static SDL_Rect		box =
	{
		ARENA_W,
		0,
		WIN_WIDTH - ARENA_W,
		WIN_HEIGHT,
	};
	static SDL_Texture	*bg = NULL;

	if (!bg)
		bg = IMG_LoadTexture(vis->rend, "images/menu_bg.jpg");
	SDL_RenderCopy(vis->rend, bg, NULL, &box);
	static_render_buttons(vis, data);
	static_render_tips(vis);
}
