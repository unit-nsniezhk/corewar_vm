/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_def.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 20:41:42 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 20:17:03 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_DEF_H

# define COREWAR_VIS_DEF_H

# include "SDL.h"
# include "SDL_ttf.h"
# include "corewar_settings.h"
# include "corewar_vis_prop.h"
# include "corewar_vis_color.h"
# include <stdbool.h>

# define WIN_NAME "CoreWars"
# define FONT_REG "fonts/Roboto-Regular.ttf"
# define FONT_BOLD "fonts/Roboto-Bold.ttf"

# define CYCLE_MS 50
# define MIN_CYCLE_MS 0
# define MAX_CYCLE_MS 100
# define D_CYCLE_MS 10

typedef struct		s_keydown
{
	bool			esk;
	bool			space;
	bool			lalt;
	bool			f;
	bool			mbl;
}					t_keydown;

typedef	struct		s_button
{
	bool			press;
	bool			hower;
	bool			state;
	char			*init_msg;
	char			*msg;
	char			*alt_msg;
	bool			bg_shown;
	SDL_Rect		bg;
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
	t_button		nxt;
}					t_buttons;

typedef struct		s_vis
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	unsigned int	cycle_ms;
	unsigned int	color[ARENA_SIZE];
	t_buttons		buttons;
	t_keydown		keydown;
}					t_vis;

#endif
