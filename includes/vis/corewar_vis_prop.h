/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_prop.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:43:40 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 21:08:55 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_PROP_H

# define COREWAR_VIS_PROP_H

# define WIN_W 1800
# define WIN_H 1105
# define PAD 5
# define ARENA_W (1500)
# define N_COLUMNS 75

# define CHAR_H 50
# define CHAR_W 25
# define S_CHAR_H 20
# define S_CHAR_W 12
# define XS_CHAR_H 14
# define XS_CHAR_W 8
# define BAR_W (WIN_W - ARENA_W - (PAD * 2))
# define BAR_X (ARENA_W + PAD)

# define BYTE_SIZE 15
# define BYTE_SHADOW 2

# define BUTTON_W (WIN_W - ARENA_W - (PAD * 2))
# define BUTTON_H 70
# define S_BUTTON_W 100
# define S_BUTTON_H 30
# define MESSAGE_W(BTN_H) (BTN_H == BUTTON_H ? CHAR_W : S_CHAR_W)
# define MESSAGE_H(BTN_H) (BTN_H == BUTTON_H ? CHAR_H : S_CHAR_H)
# define BUTTON_MSG_X(BTN_W, MSG_W) ((BTN_W / 2) - (MSG_W / 2))
# define BUTTON_MSG_Y(BTN_H, MSG_H) ((BTN_H / 2) - (MSG_H / 2))

# define TOP_BAR_D 30
# define TOP_BAR_POS_Y PAD
# define TOP_BAR_Y(N) (TOP_BAR_POS_Y + (TOP_BAR_D * N) + (N > 0 ? BUTTON_H : 0))

# define MID_BAR_POS_Y 230
# define MID_BAR_H 25
# define MID_BAR_D 50
# define N_MID_BAR_EL 3
# define MID_BAR_I_Y(I) ((MID_BAR_D * I) + (MID_BAR_H * N_MID_BAR_EL * I))
# define MID_BAR_Y(I, N) (MID_BAR_POS_Y + (MID_BAR_H * N + 1) + MID_BAR_I_Y(I))

# define PDB_SHADOW 3

# define BTM_BAR_POS_Y 790
# define BTM_BAR_D 35
# define BTM_BAR_Y(N) (BTM_BAR_POS_Y + (BTM_BAR_D * N))
# define BTM_BAR_MSG_X (BAR_X + S_BUTTON_W + PAD)
# define BTM_BAR_MSG_Y(N, CHR_H) (BTM_BAR_Y(N) + (CHR_H / 2))

#endif
