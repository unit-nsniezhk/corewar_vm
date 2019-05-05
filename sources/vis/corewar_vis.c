/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:29:49 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/05 23:34:09 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void	static_init(t_vis *vis)
{
	vis->n_rows = ARENA_SIZE / N_COLUMNS;
	vis->cycle_len = CYCLE_LEN;
	vis->mods.run = 0;
	vis->mods.quit = 0;
	vis->mods.values = 0;
	vis->mods.reverse = 0;
	vis->keydown.esk = 0;
	vis->keydown.space = 0;
	vis->keydown.f = 0;
	vis->keydown.lalt = 0;
	vis->keydown.mbl = 0;
}

int			corewar_vis_init(t_vis *vis)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1 || TTF_Init() == -1
	|| !(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG))
		return (0);
	if (!(vis->win =
	SDL_CreateWindow(WIN_NAME, 0, 0, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN)))
		return (0);
	if (!(vis->rend =
	SDL_CreateRenderer(vis->win, -1, SDL_RENDERER_ACCELERATED)))
		return (0);
	if (!(vis->fonts.bold = TTF_OpenFont("fonts/Roboto-Bold.ttf", 60))
	|| !(vis->fonts.regular = TTF_OpenFont("fonts/Roboto-Regular.ttf", 30)))
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
			vis->mods.quit = 1;
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
	SDL_SetRenderDrawColor(vis->rend, (RGB_BG >> 16) & 255, (RGB_BG >> 8) & 255,
	RGB_BG & 255, 255);
	SDL_RenderClear(vis->rend);
	corewar_vis_render_arena(vis, data);
	corewar_vis_render_menu(vis, data);
	SDL_RenderPresent(vis->rend);
	static_handle_events(vis, (SDL_GetTicks() + vis->cycle_len));
}

void		corewar_vis(t_vis *vis, t_data *data)
{
	if (vis->mods.run && !vis->mods.quit)
		static_render(vis, data);
	else
	{
		while (!vis->mods.run && !vis->mods.quit)
			static_render(vis, data);
	}
}
