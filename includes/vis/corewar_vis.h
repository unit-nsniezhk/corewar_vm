/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:30:17 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 21:20:32 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_H

# define COREWAR_VIS_H

# include "corewar_vis_def.h"
# include "corewar_def.h"
# include "SDL_ttf.h"
# include "SDL_image.h"
# include "SDL_mixer.h"

int		corewar_vis_init(t_vis *vis);

void	corewar_vis(t_vis *vis, t_data *data, bool endgame);
void	corewar_vis_render_arena(t_vis *vis, t_data *data);
void	corewar_vis_render_processes(t_vis *vis, t_data *data);

void	corewar_vis_endgame_set(t_buttons *btns);
void	corewar_vis_render_endgame(t_vis *vis, t_data *data);

void	corewar_vis_keyup(t_vis *vis, SDL_Event *event);
void	corewar_vis_keydown(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousewheel(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousemotion(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousebuttondown(t_vis *vis, SDL_Event *event);
void	corewar_vis_mousebuttonup(t_vis *vis, SDL_Event *event);

void	corewar_vis_set_press(t_vis *vis, t_button *button);
void	corewar_vis_set_hower(t_vis *vis, t_button *button);
bool	corewar_vis_hitbox(Sint32 x, Sint32 y, SDL_Rect *button);


void	corewar_vis_render_pc_regs(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);
void	corewar_vis_render_pc_timeout(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);
void	corewar_vis_render_pc_lastlive(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);
void	corewar_vis_render_pc_op(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);
void	corewar_vis_render_pc_carry(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);
void	corewar_vis_render_pc_id(SDL_Renderer *rend, t_carriage *carr,
		SDL_Rect box);

void	corewar_vis_process_shown(Sint32 x, Sint32 y, t_carriage *carr_tmp);

void	corewar_vis_speed(t_vis *vis, unsigned int state);
void	corewar_vis_reverse(t_vis *vis);
void	corewar_vis_quit(t_vis *vis);
void	corewar_vis_values(t_vis *vis);
void	corewar_vis_run(t_vis *vis);
void	corewar_vis_nxt(t_vis *vis);
void	corewar_mousebuttondown_left(t_vis *vis, Sint32 x, Sint32 y);

void	corewar_init_status(t_button *btn);
void	corewar_init_speedup(t_button *btn);
void	corewar_init_slowdown(t_button *btn);
void	corewar_init_pause(t_button *btn);
void	corewar_init_exit(t_button *btn);
void	corewar_init_reverse(t_button *btn);
void	corewar_init_values(t_button *btn);
void	corewar_init_nxt(t_button *btn);

void	corewar_vis_render_rtext(SDL_Renderer *rend, const char *msg,
		unsigned int color, SDL_Rect box);
void	corewar_vis_render_btext(SDL_Renderer *rend, const char *msg,
		unsigned int color, SDL_Rect box);
void	corewar_vis_render_button(SDL_Renderer *rend, t_button *btn, bool init);
void	corewar_vis_render_btmb(SDL_Renderer *rend, t_buttons *btns, bool init,
		unsigned int cycle_ms);
void	corewar_vis_render_mdlb(SDL_Renderer *rend, const unsigned int *arena,
		t_data *data);
void	corewar_vis_render_topb(SDL_Renderer *rend, t_button *status,
		t_data *data, bool init);
double	corewar_vis_pct(int min, int max, int eval);

#endif
