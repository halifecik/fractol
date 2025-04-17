/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:34:16 by hademirc          #+#    #+#             */
/*   Updated: 2025/04/17 15:34:30 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_check_before(char *str, int *i, int *before_dot)
{
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	if (str[*i] == '.')
		return (0);
	while (str[*i] && str[*i] != '.')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			*before_dot = 1;
		else
			return (0);
		(*i)++;
	}
	return (1);
}

static int	ft_check_after(char *str, int *i)
{
	int	after_dot;

	after_dot = 0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i])
		{
			if (str[*i] >= '0' && str[*i] <= '9')
				after_dot = 1;
			else
				return (0);
			(*i)++;
		}
	}
	return (after_dot || str[*i - 1] != '.');
}

static double	ft_decimal_parse(const char *str, int *i)
{
	double	decimal;
	double	multiplier;

	decimal = 0.0;
	multiplier = 10.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			decimal = decimal + (str[*i] - '0') / multiplier;
			multiplier *= 10.0;
			(*i)++;
		}
	}
	return (decimal);
}

int	ft_is_number(char *str)
{
	int	i;
	int	before_dot;

	i = 0;
	before_dot = 0;
	if (!ft_check_before(str, &i, &before_dot))
		return (0);
	if (str[i] == '.' && !before_dot)
		return (0);
	if (str[i] == '.' && !ft_check_after(str, &i))
		return (0);
	return (before_dot || str[i - 1] != '.');
}

double	ft_atod(const char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	decimal = ft_decimal_parse(str, &i);
	return (sign * (result + decimal));
}
