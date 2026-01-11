/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:11:07 by marvin            #+#    #+#             */
/*   Updated: 2026/01/11 15:11:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <iostream>

int main(int ac, char **av)
{
    std::string filename;
    std::string s1;
    std::string s2;
    std::string text;
    std::string replaced;

    if (ac != 4)
    {
        std::cout << "Usage: ./sedlosers <filename> <s1> <s2>\n";
        return 1;
    }

    filename = av[1];
    s1 = av[2];
    s2 = av[3];

    if (s1.empty())
    {
        std::cout << "Error: s1 cannot be empty\n";
        return 1;
    }

    if (!read_text_file(filename, text))
    {
        std::cout << "Error: cannot open input file\n";
        return 1;
    }

    replaced = build_replaced(text, s1, s2);
    if (!write_text_file(filename, replaced))
    {
        std::cout << "Error: cannot create output file\n";
        return 1;
    }
    return 0;
}
