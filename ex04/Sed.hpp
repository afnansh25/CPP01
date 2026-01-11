/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:38:36 by marvin            #+#    #+#             */
/*   Updated: 2026/01/11 16:38:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <string>

bool read_text_file(const std::string& filename, std::string& out);
std::string build_replaced(const std::string& text,
                           const std::string& s1,
                           const std::string& s2);
bool write_text_file(const std::string& filename, const std::string& text);

#endif
