/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_processes.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:29:14 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 19:31:16 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static int	static_shown(t_carriage *carr_tmp, t_carriage **carr_selected)
{
	int	n_shown;

	*carr_selected = NULL;
	n_shown = 0;
	while (carr_tmp)
	{
		if (carr_tmp->shown)
		{
			if (!*carr_selected)
			{
				carr_tmp->selected = 1;
				*carr_selected = carr_tmp;
			}
			++n_shown;
		}
		carr_tmp = carr_tmp->next;
	}
	return (n_shown);
}

static void	static_render_msg(SDL_Renderer *rend, t_carriage *carr, int n_shown,
			SDL_Rect box)
{
	SDL_SetRenderDrawColor(rend, R(RGBA_BUTTON), G(RGBA_BUTTON), B(RGBA_BUTTON),
	A_PS_INF);
	SDL_RenderFillRect(rend, &box);
	box.x += SHADOW_SIZE;
	box.y += SHADOW_SIZE;
	box.w -= (SHADOW_SIZE * 2);
	box.h -= (SHADOW_SIZE * 2);
	SDL_SetRenderDrawColor(rend, R(RGBA_BG), G(RGBA_BG), B(RGBA_BG), A_PS_INF);
	SDL_RenderFillRect(rend, &box);
	corewar_vis_render_pc_id(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + PAD, 0, 0});
	corewar_vis_render_pc_lastlive(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + (PROCESS_H * 1) + PAD, 0, 0});
	corewar_vis_render_pc_carry(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + (PROCESS_H * 2) + PAD, 0, 0});
	corewar_vis_render_pc_op(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + (PROCESS_H * 3) + PAD, 0, 0});
	corewar_vis_render_pc_timeout(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + (PROCESS_H * 4) + PAD, 0, 0});
	corewar_vis_render_pc_regs(rend, carr,
	(SDL_Rect){box.x + PAD, box.y + (PROCESS_H * 5) + PAD, 0, 0});
}

static void	static_handle_msg(SDL_Renderer *rend, t_carriage *carr)
{
	static SDL_Rect	box = {0, 0, 200, 485};
	int 			n_shown;
	t_carriage		*carr_s;

	if ((n_shown = static_shown(carr, &carr_s)))
	{
		if (carr_s->box.x > (ARENA_W / 2))
			box.x = carr_s->box.x - box.w;
		else
			box.x = carr_s->box.x + carr_s->box.w;

		if (carr_s->box.y > (WIN_H / 2))
			box.y = carr_s->box.y + carr_s->box.h - box.h;
		else
			box.y = carr_s->box.y;
		static_render_msg(rend, carr_s, n_shown, box);
	}
}

void		corewar_vis_render_processes(t_vis *vis, t_data *data)
{
	t_carriage		*carr_tmp;
	SDL_Rect		rect;
	unsigned int	color;

	if (vis->buttons.reverse.active)
		color = RGBA_RCARR;
	else
		color = RGBA_CARR;
	rect.w = BYTE_SIZE + (BYTE_SHADOW * 2);
	rect.h = BYTE_SIZE + (BYTE_SHADOW * 2);
	carr_tmp = data->carr;
	while (carr_tmp)
	{
		rect.x = ((carr_tmp->pos % N_COLUMNS) * (BYTE_SIZE + PAD)) + PAD
		- BYTE_SHADOW;
		rect.y = ((carr_tmp->pos / N_COLUMNS) * (BYTE_SIZE + PAD)) + PAD
		- BYTE_SHADOW;
		carr_tmp->box = (SDL_Rect){rect.x, rect.y, rect.w, rect.h};
		SDL_SetRenderDrawColor(vis->rend, R(color), G(color), B(color),
		A(color));
		SDL_RenderFillRect(vis->rend, &rect);
		carr_tmp = carr_tmp->next;
	}
	if (!vis->buttons.run.active)
		static_handle_msg(vis->rend, data->carr);
}
