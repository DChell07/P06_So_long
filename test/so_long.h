/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchellen <dchellen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:02:19 by dchellen          #+#    #+#             */
/*   Updated: 2025/01/26 19:02:15 by dchellen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx_mac/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define BALL_SIZE 50

typedef struct s_data {
    void *mlx_ptr;
    void *win_ptr;
    void *img;
    int x;
    int y;
    int dx;
    int dy;
} t_data;

#endif
