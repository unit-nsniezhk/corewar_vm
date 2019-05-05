/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_key_handle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:03:57 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/05 20:19:41 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

void		corewar_vis_keydown(t_vis *vis, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
		vis->keydown.esk = 1;
	else if (event->key.keysym.sym == SDLK_SPACE)
		vis->keydown.space = 1;
	else if (event->key.keysym.sym == SDLK_LALT)
		vis->keydown.lalt = 1;
	else if (event->key.keysym.sym == SDLK_f)
		vis->keydown.f = 1;
}

static void	static_keyup2(t_vis *vis, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_LALT)
		vis->keydown.lalt = 0;
	else if (event->key.keysym.sym == SDLK_f)
	{
		vis->keydown.f = 0;
		if (vis->keydown.lalt && vis->mods.values)
		{
			vis->mods.values = 0;
			vis->mods.run = 1;
		}
		else if (vis->keydown.lalt)
		{
			vis->mods.values = 1;
			vis->mods.run = 0;
		}
	}
}

void		corewar_vis_keyup(t_vis *vis, SDL_Event *event)
{
	if (event->key.keysym.sym == SDLK_ESCAPE)
	{
		vis->keydown.esk = 0;
		if (vis->mods.quit)
			vis->mods.quit = 0;
		else
			vis->mods.quit = 1;
	}
	else if (event->key.keysym.sym == SDLK_SPACE)
	{
		vis->keydown.space = 0;
		if (!vis->keydown.lalt && vis->mods.run)
			vis->mods.run = 0;
		else if (!vis->keydown.lalt)
		{
			vis->mods.run = 1;
			vis->mods.values = 0;
		}
		else if (vis->keydown.lalt && vis->mods.reverse)
			vis->mods.reverse = 0;
		else if (vis->keydown.lalt && !vis->mods.reverse)
			vis->mods.reverse = 1;
	}
	else
		static_keyup2(vis, event);
}
