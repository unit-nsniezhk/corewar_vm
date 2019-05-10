/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:29:49 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/10 20:07:31 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "corewar_vis_prop.h"
#include "corewar_vis_color.h"

static void	static_handle_events(t_data *data, t_vis *vis, Uint32 timeout)
{
	SDL_Event	event;
	Uint32		time;

	time = 0;
	while (timeout > time)
	{
		if (!SDL_WaitEventTimeout(&event, 0))
			;
		else if (event.type == SDL_QUIT)
			vis->btns.quit.active = true;
		else if (event.type == SDL_KEYDOWN)
			corewar_vis_keydown(vis, &event);
		else if (event.type == SDL_KEYUP)
			corewar_vis_keyup(vis, &event);
		else if (event.type == SDL_MOUSEWHEEL)
			corewar_vis_mousewheel(vis, &event);
		else if (event.type == SDL_MOUSEMOTION)
			corewar_vis_mousemotion(vis, &event);
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			corewar_vis_mousebuttondown(vis, &event);
		else if (event.type == SDL_MOUSEBUTTONUP)
			corewar_vis_mousebuttonup(vis, &event);
		corewar_vis_pc_shown(vis, data->carr);
		time = SDL_GetTicks();
	}
}

void	static_cover_arena(t_vis *vis, t_data *data)
{
	static SDL_Rect	box = {0, 0, ARENA_W + PAD, WIN_H};

	SDL_SetRenderDrawColor(vis->rend, R(RGBA_BG), G(RGBA_BG), B(RGBA_BG),
	PROCESS_INF_OP);
	SDL_RenderFillRect(vis->rend, &box);
	if (vis->game_start)
		corewar_vis_render_gamestart(vis, data);
	else if (vis->game_over)
		corewar_vis_render_gameover(vis, data);
}

static void	static_render(t_data *data, t_vis *vis)
{
	static SDL_Rect		box = {ARENA_W, 0, WIN_W - ARENA_W, WIN_H};
	static SDL_Texture	*bg = NULL;
	Uint32				timeout;

	if (!bg)
		bg = IMG_LoadTexture(vis->rend, IMG_BG);
	SDL_SetRenderDrawColor(vis->rend, R(RGBA_BG), G(RGBA_BG), B(RGBA_BG),
	A(RGBA_BG));
	SDL_RenderClear(vis->rend);
	SDL_SetRenderDrawBlendMode(vis->rend, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(vis->rend, bg, NULL, &box);
	corewar_vis_render_arena(data, vis);
	corewar_vis_render_pc(data, vis);
	corewar_vis_render_topb(data, vis);
	corewar_vis_render_mdlb(data, vis);
	corewar_vis_render_btmb(vis);
	if (vis->game_start || vis->game_over)
		static_cover_arena(vis, data);
	SDL_RenderPresent(vis->rend);
	timeout = SDL_GetTicks() + vis->timeout;
	static_handle_events(data, vis, timeout);
}

void		corewar_vis(t_data *data, t_vis *vis)
{
	static Mix_Music	*music = NULL;

	vis->btns.next.active = false;
	if (vis->game_start)
	{
		if (!music)
			music = Mix_LoadMUS(MUSIC_BG);
		else
		{
			vis->game_start = false;
			Mix_PlayMusic(music, -1);
		}
	}
	else if (vis->game_over)
		corewar_vis_gameover_lock(&vis->btns);
	if (vis->btns.run.active && !vis->btns.quit.active)
		static_render(data, vis);
	else
	{
		while (!vis->btns.run.active && !vis->btns.quit.active
		&& !vis->btns.next.active)
			static_render(data, vis);
	}
}
