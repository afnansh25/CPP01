/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:19:37 by marvin            #+#    #+#             */
/*   Updated: 2026/01/10 21:19:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    randomChump("StackZombie");

    Zombie* z = newZombie("HeapZombie");
    z->announce();
    delete z;

    return 0;
}
