/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hademirc <hademirc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:25:52 by hademirc          #+#    #+#             */
/*   Updated: 2024/12/24 17:30:19 by hademirc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_id_printer(int nb);
int	ft_u_printer(unsigned int nb);
int	ft_px_printer(unsigned long nb, char *base, int flag);

int	ft_flag_check(char c, va_list a);
int	ft_printf(const char *str, ...);

#endif