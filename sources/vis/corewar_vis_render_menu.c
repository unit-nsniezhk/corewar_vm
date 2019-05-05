/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_menu.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:36:11 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/05 22:51:54 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void	static_render_tips(t_vis *vis, SDL_Rect *text_box)
{
	vis->ptr = text_box;
	text_box->y = SPEEDUP_Y;
	corewar_vis_render_text(vis, "Hold LALT & mousewheel up  ", g_yellow,
	vis->fonts.bold);
	text_box->y = SLOWDOWN_Y;
	corewar_vis_render_text(vis, "Hold LALT & mousewheel down", g_yellow,
	vis->fonts.bold);
	text_box->y = VALUES_Y;
	corewar_vis_render_text(vis, "Hold LALT & press f              ", g_yellow,
	vis->fonts.bold);
	text_box->y = REVERSE_Y;
	corewar_vis_render_text(vis, "Hold LALT & press SPACE    ", g_yellow,
	vis->fonts.bold);
	text_box->y = PAUSE_Y;
	corewar_vis_render_text(vis,
	"Press SPACE                       ", g_yellow, vis->fonts.bold);
	text_box->y = EXIT_Y;
	corewar_vis_render_text(vis,
	"Press ESC                         ", g_yellow, vis->fonts.bold);
	text_box->y = INF_Y;
	text_box->w = LOW_BAR_W1 + LOW_BAR_W + 5;
	text_box->x = LOW_BAR_X - 8;
	corewar_vis_render_text(vis,
	"To get more information select process with a mouse",
	g_yellow, vis->fonts.bold);
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

static void	static_init(t_vis *vis, SDL_Texture **bg)
{
	*bg = IMG_LoadTexture(vis->rend, "images/menu_bg.jpg");
	corewar_init_status(&vis->buttons.status);
	corewar_init_speedup(&vis->buttons.speedup);
	corewar_init_slowdown(&vis->buttons.slowdown);
	corewar_init_pause(&vis->buttons.pause);
	corewar_init_exit(&vis->buttons.exit);
	corewar_init_reverse(&vis->buttons.reverse);
	corewar_init_values(&vis->buttons.values);
}

void		corewar_vis_render_menu(t_vis *vis, t_data *data)
{
	static SDL_Rect		img_box =
	{
		ARENA_WIDTH,
		0,
		WIN_WIDTH - ARENA_WIDTH,
		WIN_HEIGHT,
	};
	static SDL_Texture	*bg = NULL;
	SDL_Rect			text_box;

	if (!bg)
		static_init(vis, &bg);
	SDL_RenderCopy(vis->rend, bg, NULL, &img_box);
	static_render_buttons(vis);
	text_box.x = LOW_BAR_X1;
	text_box.w = LOW_BAR_W1;
	text_box.h = LOW_BAR_H;
	static_render_tips(vis, &text_box);
}
