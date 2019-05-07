/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_prop.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 19:43:40 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/07 20:44:20 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VIS_PROP_H

# define COREWAR_VIS_PROP_H

# define WIN_WIDTH 1800
# define WIN_HEIGHT 1105
# define ARENA_W 1505
# define N_COLUMNS 75

# define BUTTON_W 10
# define BUTTON_H 5
# define BYTE_W 15
# define CHAR_W 12
# define BYTE_H 15
# define BYTE_X_PADD 5
# define BYTE_Y_PADD 5
# define ROW_H (BYTE_H + BYTE_Y_PADD)
# define COLUMN_W (BYTE_W + BYTE_X_PADD)
# define SHADOW_SIZE 2

# define STATUS_X (ARENA_W + 30)
# define STATUS_Y 20
# define STATUS_W (WIN_WIDTH - ARENA_W - 60)
# define STATUS_H 50

# define BAR_H 20
# define BAR_PADD 5
# define BAR_W (WIN_WIDTH - ARENA_W - 10)

# define TOP_BAR_X (ARENA_W + 5)
# define TOP_BAR_Y 100
# define D_TOP_BAR 30
# define TOP_BAR_EL_Y(N) (TOP_BAR_Y + (D_TOP_BAR * N))

# define MID_BAR_Y 230
# define MID_BAR_H 25
# define MID_BAR_D 50
# define MID_BAR_X (ARENA_W + BAR_PADD)

# define MID_BAR_EL_Y(I, N) (MID_BAR_Y + (MID_BAR_D * I) + (MID_BAR_H * N) + (MID_BAR_H * 3 * I))

# define PDB_SHADOW_W 3

# define BTM_BAR_Y 795
# define D_BTM_BAR 35
# define BTM_BAR_X (ARENA_W + 10)
# define BTM_BAR_W (WIN_WIDTH - ARENA_W - 215)
# define BTM_BAR_X1 (BTM_BAR_X + BTM_BAR_W + BUTTON_W + BAR_PADD)
# define BTM_BAR_EL_Y(N) (BTM_BAR_Y + (D_BTM_BAR * N))

#endif
