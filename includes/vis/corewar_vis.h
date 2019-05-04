/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:30:17 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/04 19:07:40 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_H

# define COREWAR_VIS_H

# include "corewar_vis_def.h"
# include "corewar_def.h"
# include "SDL_ttf.h"

int		corewar_vis_init(t_vis *vis);

void	corewar_vis(t_vis *vis, t_data *data);
void	corewar_vis_render_arena(t_vis *vis, t_data *data);
void	corewar_vis_render_menu(t_vis *vis, t_data *data);
void	corewar_vis_handle_events(t_vis *vis);

#endif
