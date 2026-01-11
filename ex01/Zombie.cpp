/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:27:02 by marvin            #+#    #+#             */
/*   Updated: 2026/01/10 23:27:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
   std::cout << "A zombie is born." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}

void Zombie::setName(std::string new_name)
{
   name = new_name;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

