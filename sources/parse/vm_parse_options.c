/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parse_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:02:55 by dderevyn          #+#    #+#             */
/*   Updated: 2019/04/30 23:23:15 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm_parse.h"

static int	static_option_n(t_parse *parse, const char *value)
{
	unsigned int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] < '0' || value[i] > '9')
		{
			ft_printf("[redError:~] %s [yellow%c~]\n",
			"Invalid symbol in -n's value", value[i]);
			return (0);
		}
		++i;
	}
	parse->pos = (unsigned int)ft_atouibase(HEX, value);
	if (parse->pos == 0 || parse->pos > MAX_CHAMPIONS)
	{
		ft_printf("[redError:~] Invalid value of -n [yellowValue %u~]\n",
		parse->dump);
		return (0);
	}
	return (1);
}

static int	static_option_dump(t_parse *parse, const char *value)
{
	unsigned int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] < '0' || value[i] > '9')
		{
			ft_printf("[redError:~] %s [yellow%c~]\n",
			"Invalid symbol in -dump's value", value[i]);
			return (0);
		}
		++i;
	}
	if ((parse->dump = (unsigned int)ft_atouibase(HEX, value)) == 0)
	{
		ft_printf("[redError:~] Invalid value of -dump [yellowValue %u~]\n",
		parse->dump);
		return (0);
	}
	return (1);
}

int			corewar_parse_options(t_parse *parse, const char **argv,
			unsigned int i)
{
	if (argv[i][1] == 'n' && !argv[i][2] && !parse->pos)
	{
		if (!static_option_n(parse, argv[i + 1]))
			return (0);
	}
	else if (ft_strncmp(&(argv[i][1]), "dump", 5) && !parse->dump)
	{
		if (!static_option_dump(parse, argv[i + 1]))
			return (0);
	}
	else
	{
		if (parse->pos)
			ft_printf("[redError:~] %s [yellow%u~]\n",
			"Player's number is already specified to", parse->pos);
		if (parse->dump)
			ft_printf("[redError:~] %s [yellow%u~]\n",
			"-dump is already specified to", parse->dump);
		else
			ft_printf("[redError:~] %s [yellow%s~]\n",
			"Non existent option", argv[i]);
		return (0);
	}
	return (1);
}
