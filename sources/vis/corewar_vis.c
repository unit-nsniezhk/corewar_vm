/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:29:49 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/04 22:17:33 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

int		corewar_vis_init(t_vis *vis)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1 || TTF_Init() == -1)
		return (0);
	if (!(vis->win =
	SDL_CreateWindow(WIN_NAME, 0, 0, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN)))
		return (0);
	if (!(vis->rend =
	SDL_CreateRenderer(vis->win, -1, SDL_RENDERER_ACCELERATED)))
		return (0);
	if (!(vis->font = TTF_OpenFont("fonts/Roboto-Regular.ttf", 20))
	|| !(vis->font_bold = TTF_OpenFont("fonts/Roboto-Bold.ttf", 42)))
		return (0);
	SDL_SetWindowPosition(vis->win, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED);
	vis->run = 0;
	vis->quit = 0;
	vis->select = 0;
	vis->cycle_len = CYCLE_LEN;
	vis->keydown.esk = 0;
	vis->keydown.space = 0;
	vis->keydown.lalt = 0;
	vis->n_rows = ARENA_SIZE / N_COLUMNS;
	return (1);
}

static void	static_render_bg(t_vis *vis)
{
	SDL_SetRenderDrawColor(vis->rend, (RGB_BG >> 16) & 255, (RGB_BG >> 8) & 255,
	RGB_BG & 255, 255);
	SDL_RenderClear(vis->rend);
}

static void	static_render(t_vis *vis, t_data *data)
{
	static_render_bg(vis);
	corewar_vis_render_arena(vis, data);
	corewar_vis_render_menu(vis, data);
	SDL_RenderPresent(vis->rend);
	corewar_vis_handle_events(vis);
}

void		corewar_vis(t_vis *vis, t_data *data)
{
	if (vis->run && !vis->quit)
		static_render(vis, data);
	else
	{
		while (!vis->run && !vis->quit)
			static_render(vis, data);
	}
}
