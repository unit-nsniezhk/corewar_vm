/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:30:17 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/05 23:34:09 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_H

# define COREWAR_VIS_H

# include "corewar_vis_def.h"
# include "corewar_def.h"
# include "SDL_ttf.h"
# include "SDL_image.h"

int		corewar_vis_init(t_vis *vis);

void	corewar_vis(t_vis *vis, t_data *data);
void	corewar_vis_render_arena(t_vis *vis, t_data *data);
void	corewar_vis_render_menu(t_vis *vis, t_data *data);

void	corewar_vis_keyup(t_vis *vis, SDL_Event *event);
void	corewar_vis_keydown(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousewheel(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousemotion(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousebuttondown(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousebuttonup(t_vis *vis, SDL_Event *event);

void	corewar_vis_slowdown(t_vis *vis);
void	corewar_vis_speedup(t_vis *vis);


void	corewar_init_status(t_button *button);
void	corewar_init_speedup(t_button *button);
void	corewar_init_slowdown(t_button *button);
void	corewar_init_pause(t_button *button);
void	corewar_init_exit(t_button *button);
void	corewar_init_reverse(t_button *button);
void	corewar_init_values(t_button *button);

void	corewar_vis_render_value(t_vis *vis, SDL_Rect rect, unsigned char value,
		unsigned int bg_color);
void	corewar_vis_render_text(t_vis *vis, const char *text, SDL_Color color,
		TTF_Font *font);
void	corewar_vis_render_button(t_vis *vis, t_button *button);

#endif
