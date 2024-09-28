/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:27:31 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/28 10:27:32 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	stringReplace(size_t pos, size_t s1Len, const std::string &s2, std::string &content);
void	replaceAllOccurrences(std::string &content, const std::string &s1, const std::string &s2);
