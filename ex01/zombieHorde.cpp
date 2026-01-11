/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:36:14 by marvin            #+#    #+#             */
/*   Updated: 2026/01/10 23:36:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N];

    int i = 0;
    while (i < N)
    {
        horde[i].setName(name);
        i++;
    }
    return horde;
}
