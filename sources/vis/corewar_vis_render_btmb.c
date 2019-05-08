/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_btmb.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:36:11 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 20:46:18 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void	static_render_tips(SDL_Renderer *rend)
{
	corewar_vis_render_btext(rend, "Tip: select process with a mouse",
	RGBA_TEXT2, (SDL_Rect){BAR_X, BTM_BAR_MSG_Y(0, S_CHAR_H), XS_CHAR_W,
	S_CHAR_H});
	corewar_vis_render_btext(rend, "Hold LALT & wheel UP", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BTM_BAR_MSG_Y(2, S_CHAR_H), XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, "Hold LALT & wheel DOWN", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BTM_BAR_MSG_Y(3, S_CHAR_H), XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, "Hold LALT & press F", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BTM_BAR_MSG_Y(5, S_CHAR_H), XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, "Hold LALT & press SPACE", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BTM_BAR_MSG_Y(6, S_CHAR_H), XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, "Press SPACE", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BTM_BAR_MSG_Y(7, S_CHAR_H), XS_CHAR_W, S_CHAR_H});
	corewar_vis_render_btext(rend, "Press ESC", RGBA_TEXT2,
	(SDL_Rect){BTM_BAR_MSG_X, BTM_BAR_MSG_Y(8, S_CHAR_H), XS_CHAR_W, S_CHAR_H});
}

static void	static_render_buttons(SDL_Renderer *rend, t_buttons *btns,
			bool init)
{
	SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
	corewar_vis_render_button(rend, &btns->speedup, init);
	corewar_vis_render_button(rend, &btns->slowdown, init);
	corewar_vis_render_button(rend, &btns->nxt, init);
	corewar_vis_render_button(rend, &btns->pause, init);
	corewar_vis_render_button(rend, &btns->exit, init);
	corewar_vis_render_button(rend, &btns->reverse, init);
	corewar_vis_render_button(rend, &btns->values, init);
}


static void	static_speed_bar(SDL_Renderer *rend, unsigned int cycle_ms,
			SDL_Rect box)
{
	SDL_SetRenderDrawColor(rend, R(RGBA_SHADOW), G(RGBA_SHADOW), B(RGBA_SHADOW),
	A(RGBA_SHADOW));
	SDL_RenderFillRect(rend, &box);
	box.x += PDB_SHADOW;
	box.y += PDB_SHADOW;
	box.h -= (PDB_SHADOW * 2);
	box.w -= (PDB_SHADOW * 2);
	SDL_SetRenderDrawColor(rend, R(RGBA_BUTTON), G(RGBA_BUTTON), B(RGBA_BUTTON),
	A(RGBA_BUTTON));
	SDL_RenderFillRect(rend, &box);
	box.w =
	(Sint32)(box.w * corewar_vis_pct(MAX_CYCLE_MS, MIN_CYCLE_MS, cycle_ms));
	SDL_SetRenderDrawColor(rend, R(RGBA_TEXT2), G(RGBA_TEXT2), B(RGBA_TEXT2),
	A(RGBA_TEXT2));
	SDL_RenderFillRect(rend, &box);
	corewar_vis_render_btext(rend, "Speed", RGBA_TEXT,
	(SDL_Rect){BTM_BAR_MSG_X, BTM_BAR_Y(4) + 5, S_CHAR_W, S_CHAR_H});
}

void		corewar_vis_render_btmb(SDL_Renderer *rend, t_buttons *btns,
			bool init, unsigned int cycle_ms)
{
	static_render_buttons(rend, btns, init);
	static_render_tips(rend);
	static_speed_bar(rend, cycle_ms,
	(SDL_Rect){BAR_X, BTM_BAR_Y(4), BAR_W, S_BUTTON_H});
}
