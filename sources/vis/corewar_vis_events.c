/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:58:45 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/04 21:26:06 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void	static_keydown(t_vis *vis, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
		vis->keydown.esk = 1;
	else if (event->key.keysym.sym == SDLK_SPACE)
		vis->keydown.space = 1;
	else if (event->key.keysym.sym == SDLK_LALT)
		vis->keydown.lalt = 1;
}

static void	static_keyup(t_vis *vis, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
	{
		vis->keydown.esk = 0;
		if (vis->quit)
			vis->quit = 0;
		else
			vis->quit = 1;
	}
	else if (event->key.keysym.sym == SDLK_SPACE)
	{
		vis->keydown.space = 0;
		if (!vis->keydown.lalt && vis->run)
			vis->run = 0;
		else if (!vis->keydown.lalt)
			vis->run = 1;
		else if (vis->keydown.lalt && vis->select)
			vis->select = 0;
		else if (vis->keydown.lalt && !vis->select)
			vis->select = 1;
		vis->keydown.lalt = 0;
	}
	else if (event->key.keysym.sym == SDLK_s)
		vis->keydown.lalt = 0;
}

static void	static_mousewheel(t_vis *vis, SDL_Event *event)
{
	if (vis->keydown.lalt && event->wheel.y > 0)
	{
		if (vis->cycle_len > 0)
			vis->cycle_len -= DELTA_CYCLE_LEN;
	}
	else if (vis->keydown.lalt && event->wheel.y < 0)
	{
		if (vis->cycle_len < MAX_CYCLE_LEN)
			vis->cycle_len += DELTA_CYCLE_LEN;
	}
}

void		corewar_vis_handle_events(t_vis *vis)
{
	SDL_Event	event;
	Uint32		start;
	Uint32		finish;

	finish = 0;
	start = SDL_GetTicks() + vis->cycle_len;
	while (start > finish)
	{
		if (!SDL_WaitEventTimeout(&event, 0))
			;
		else if (event.type == SDL_QUIT)
			vis->quit = 1;
		else if (event.type == SDL_KEYDOWN)
			static_keydown(vis, &event);
		else if (event.type == SDL_KEYUP)
			static_keyup(vis, &event);
		else if (event.type == SDL_MOUSEWHEEL)
			static_mousewheel(vis, &event);
//	else if (vis->event.type == SDL_MOUSEMOTION)
//		lemin_vis_mouse_motion(vis);
		finish = SDL_GetTicks();
	}
}
