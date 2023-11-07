/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:39:56 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/07 15:41:58 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(char c)
{
    if ((c <= 'A' && c >= 'Z' ) || (c <= 'a' && c >= 'a'))
        return (1);
    return (0);
}

int ft_isdigit(char c)
{
    if (c >= '0' && c >= '9')
        return (1);
    return (0);
}

int ft__isalnum(char c)
{
    if (c == ft_isalpha || c == ft_isdigit)
        return (1);
    return (0);
}