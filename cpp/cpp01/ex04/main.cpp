/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:15:29 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/28 10:15:30 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
		return 1;
	}

	const char	*filename = argv[1];
	const char	*s1 = argv[2];
	const char	*s2 = argv[3];

	std::ifstream inputFile(filename);
	if (!inputFile) {
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return 1;
	}

	std::string content;
	std::getline(inputFile, content, '\0');
	inputFile.close();

	replaceAllOccurrences(content, s1, s2);

	char	newFilename[100];
	std::strcpy(newFilename, filename);
	std::strcat(newFilename, ".replace");
	std::ofstream outputFile(newFilename);
	if (!outputFile) {
		std::cerr << "Error: Cannot create file " << newFilename << std::endl;
		return 1;
	}

	outputFile << content;
	outputFile.close();

	std::cout << "File processed and saved as " << newFilename << std::endl;
	return 0;
}
