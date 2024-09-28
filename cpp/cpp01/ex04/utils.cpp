/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:15:43 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/28 10:15:45 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	stringReplace(size_t pos, size_t s1Len, const std::string &s2, std::string &content) {
	content.erase(pos, s1Len);
	content.insert(pos, s2);
}

void replaceAllOccurrences(std::string &content, const std::string &s1, const std::string &s2) {
	size_t pos = 0;

	if (s1.empty()) {
		if (content.empty()) {
			content.insert(pos, s2);
		}
		return ;
	}
	while ((pos = content.find(s1, pos)) != std::string::npos) {
		stringReplace(pos, s1.length(), s2, content);
		pos += s2.length();
	}
}
