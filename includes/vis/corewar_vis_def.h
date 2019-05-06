/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_def.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:41:42 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/06 21:51:21 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_DEF_H

# define COREWAR_VIS_DEF_H

#include "SDL.h"
# include "SDL_ttf.h"
# include "corewar_settings.h"
# include "corewar_vis_prop.h"
# include "corewar_vis_colors.h"

# define WIN_NAME "CoreWars"
# define WIN_WIDTH 1800
# define WIN_HEIGHT 1105

# define CYCLE_MS 50
# define MIN_CYCLE_MS 0
# define MAX_CYCLE_MS 100
# define D_CYCLE_MS 10

//TODO add all carriage counter to get good ides

typedef struct		s_keydown
{
	unsigned int	esk : 1;
	unsigned int	space : 1;
	unsigned int	lalt : 1;
	unsigned int	f : 1;
	unsigned int	mbl : 1;
}					t_keydown;

typedef	struct		s_button
{
	unsigned int	press : 1;
	unsigned int	hower : 1;
	unsigned int	state : 1;
	char			*text;
	char			*alt_text;
	SDL_Rect		text_rect;
	unsigned int	bg : 1;
	SDL_Rect		button_rect;
}					t_button;

typedef struct		s_buttons
{
	t_button		status;
	t_button		speedup;
	t_button		slowdown;
	t_button		pause;
	t_button		exit;
	t_button		reverse;
	t_button		values;
}					t_buttons;

typedef struct		s_fonts
{
	TTF_Font		*bold;
	TTF_Font		*regular;
}					t_fonts;

typedef struct		s_vis
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	unsigned int	cycle_ms;
	unsigned int	color[ARENA_SIZE];
	t_buttons		buttons;
	t_keydown		keydown;
	t_fonts			fonts;
}					t_vis;

#endif
