/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_render_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:35:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 18:35:55 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	corewar_vis_pct(int min, int max, int eval)
{
	double	pos;
	double	pct;
	double	dist;

	dist = max - min;
	pos = eval - min;
	if (dist == 0)
		pct = 1.0;
	else
		pct = pos / dist;
	return (pct);
}
