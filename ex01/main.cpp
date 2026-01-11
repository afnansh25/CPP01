/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:42:09 by marvin            #+#    #+#             */
/*   Updated: 2026/01/10 23:42:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;

    Zombie* horde = zombieHorde(N, "HordeZombie");
    if (!horde)
        return 1;

    int i = 0;
    while (i < N)
    {
        horde[i].announce();
        i++;
    }

    delete[] horde;
    return 0;
}
