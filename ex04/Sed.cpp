/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:38:33 by marvin            #+#    #+#             */
/*   Updated: 2026/01/11 16:38:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <fstream>

bool read_text_file(const std::string& filename, std::string& out)
{
    std::ifstream in(filename.c_str());
    std::string line;
    std::string text;

    if (!in.is_open())
        return false;
    text = "";
    while (std::getline(in, line))
    {
        text += line;
        if (!in.eof())
            text += "\n";
    }
    out = text;
    return true;
}

std::string build_replaced(const std::string& text,
                           const std::string& s1,
                           const std::string& s2)
{
    std::string out;
    std::size_t pos;
    std::size_t hit;

    out = "";
    pos = 0;
    hit = text.find(s1, pos);
    while (hit != std::string::npos)
    {
        out += text.substr(pos, hit - pos);
        out += s2;
        pos = hit + s1.length();
        hit = text.find(s1, pos);
    }
    out += text.substr(pos);
    return out;
}

bool write_text_file(const std::string& filename, const std::string& text)
{
    std::ofstream out((filename + ".replace").c_str());

    if (!out.is_open())
        return false;
    out << text;
    return true;
}
