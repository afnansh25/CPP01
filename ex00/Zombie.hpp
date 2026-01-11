/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:40:27 by marvin            #+#    #+#             */
/*   Updated: 2026/01/10 20:40:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
   private:
      std::string name;

   public:
      Zombie(std::string name);
      ~Zombie();

      void announce(void);

};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif