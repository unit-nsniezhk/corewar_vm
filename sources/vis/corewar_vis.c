/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:29:49 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 20:33:27 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"
#include "libft.h"

static void	static_init(t_vis *vis)
{
	unsigned int	i;

	i = 0;
	while (i < ARENA_SIZE)
	{
		vis->color[i] = RGBA_PLAYER0;
		++i;
	}
	vis->cycle_ms = CYCLE_MS;
	vis->keydown.esk = false;
	vis->keydown.space = false;
	vis->keydown.f = false;
	vis->keydown.lalt = false;
	vis->keydown.mbl = false;
	corewar_init_status(&vis->buttons.status);
	corewar_init_nxt(&vis->buttons.nxt);
	corewar_init_speedup(&vis->buttons.speedup);
	corewar_init_slowdown(&vis->buttons.slowdown);
	corewar_init_pause(&vis->buttons.pause);
	corewar_init_exit(&vis->buttons.exit);
	corewar_init_reverse(&vis->buttons.reverse);
	corewar_init_values(&vis->buttons.values);
}

int			corewar_vis_init(t_vis *vis)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1 || TTF_Init() == -1
	|| !(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG))
		return (0);
	if (!(vis->win = SDL_CreateWindow(WIN_NAME, 0, 0, WIN_W, WIN_H,
	SDL_WINDOW_RESIZABLE)))
		return (0);
	if (!(vis->rend =
	SDL_CreateRenderer(vis->win, -1, SDL_RENDERER_ACCELERATED)))
		return (0);
	SDL_SetWindowPosition(vis->win, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED);
	static_init(vis);
	return (1);
}

static void	static_handle_events(t_vis *vis, Uint32 start)
{
	SDL_Event	event;
	Uint32		finish;

	finish = 0;
	while (start > finish)
	{
		if (!SDL_WaitEventTimeout(&event, 0))
			;
		else if (event.type == SDL_QUIT)
			vis->buttons.exit.state = 1;
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
		finish = SDL_GetTicks();
	}
}

static void	static_render(t_vis *vis, t_data *data)
{
	static SDL_Rect		box = {ARENA_W, 0, WIN_W - ARENA_W, WIN_H};
	static SDL_Texture	*bg = NULL;
	bool				init;

	SDL_SetRenderDrawColor(vis->rend, R(RGBA_BG), G(RGBA_BG), B(RGBA_BG),
	A(RGBA_BG));
	SDL_RenderClear(vis->rend);
	SDL_SetRenderDrawBlendMode(vis->rend, SDL_BLENDMODE_BLEND);
	if (!bg)
		bg = IMG_LoadTexture(vis->rend, "images/menu_bg.jpg");
	SDL_RenderCopy(vis->rend, bg, NULL, &box);
	init = (data->cycle == 0 ? true : false);
	corewar_vis_render_arena(vis, data);
	corewar_vis_render_btmb(vis->rend, &vis->buttons, init, vis->cycle_ms);
	corewar_vis_render_mdlb(vis->rend, vis->color, data);
	corewar_vis_render_topb(vis->rend, &vis->buttons.status, data, init);
	SDL_RenderPresent(vis->rend);
	static_handle_events(vis, (SDL_GetTicks() + vis->cycle_ms));
}

void		corewar_vis(t_vis *vis, t_data *data)
{
	vis->buttons.nxt.state = false;
	if (vis->buttons.pause.state && !vis->buttons.exit.state)
		static_render(vis, data);
	else
	{
		while (!vis->buttons.pause.state && !vis->buttons.exit.state
		&& !vis->buttons.nxt.state)
			static_render(vis, data);
	}
}
