/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_menu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:36:11 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/06 21:39:10 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void	static_render_tips(t_vis *vis, SDL_Rect box)
{
	box.y = SPEEDUP_Y;
	corewar_vis_render_btext(vis, "Hold LALT & wheel UP",
	RGBA_TEXT2, &box);
	box.y = SLOWDOWN_Y;
	corewar_vis_render_btext(vis, "Hold LALT & wheel DOWN",
	RGBA_TEXT2, &box);
	box.y = VALUES_Y;
	corewar_vis_render_btext(vis, "Hold LALT & press F    ",
	RGBA_TEXT2, &box);
	box.y = REVERSE_Y;
	corewar_vis_render_btext(vis, "Hold LALT & press SPACE",
	RGBA_TEXT2, &box);
	box.y = PAUSE_Y;
	corewar_vis_render_btext(vis, "Press SPACE                     ",
	RGBA_TEXT2, &box);
	box.y = EXIT_Y;
	corewar_vis_render_btext(vis, "Press ESC                   ",
	RGBA_TEXT2, &box);
	box.y = INF_Y;
	box.w = LOW_BAR_W1 + LOW_BAR_W + 5;
	box.x = LOW_BAR_X - 8;
	corewar_vis_render_btext(vis, "Tip:  select process with a mouse",
	RGBA_TEXT2, &box);
}

static void	static_render_buttons(t_vis *vis)
{
	SDL_SetRenderDrawBlendMode(vis->rend, SDL_BLENDMODE_BLEND);
	corewar_vis_render_button(vis, &vis->buttons.status);
	corewar_vis_render_button(vis, &vis->buttons.speedup);
	corewar_vis_render_button(vis, &vis->buttons.slowdown);
	corewar_vis_render_button(vis, &vis->buttons.pause);
	corewar_vis_render_button(vis, &vis->buttons.exit);
	corewar_vis_render_button(vis, &vis->buttons.reverse);
	corewar_vis_render_button(vis, &vis->buttons.values);
}

void		corewar_vis_render_menu(t_vis *vis)
{
	static SDL_Rect		img_box =
	{
		ARENA_W,
		0,
		WIN_WIDTH - ARENA_W,
		WIN_HEIGHT,
	};
	static SDL_Rect		message_box =
	{
		LOW_BAR_X1,
		LOW_BAR_Y,
		LOW_BAR_W1,
		LOW_BAR_H
	};
	static SDL_Texture	*bg = NULL;

	if (!bg)
		bg = IMG_LoadTexture(vis->rend, "images/menu_bg.jpg");
	SDL_RenderCopy(vis->rend, bg, NULL, &img_box);
	static_render_buttons(vis);
	static_render_tips(vis, message_box);
}
