/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:50:15 by marvin            #+#    #+#             */
/*   Updated: 2026/01/11 11:50:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon)
    : name(name), weapon(weapon)
{
}

void HumanA::attack() const
{
    std::cout << name << " attacks with their "
              << weapon.getType() << std::endl;
}
