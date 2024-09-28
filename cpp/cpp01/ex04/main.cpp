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

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Open the input file
	std::ifstream inputFile(filename);
	if (!inputFile) {
		std::cerr << "Error: Cannot open file " << filename << "\n";
		return 1;
	}

	// Read the file content into a string
	std::string content;
	std::getline(inputFile, content, '\0');
	inputFile.close();

	// Perform the replacement
	replaceAllOccurrences(content, s1, s2);

	// Create the new output file with .replace extension
	std::string newFilename = filename + ".replace";
	std::ofstream outputFile(newFilename);
	if (!outputFile) {
		std::cerr << "Error: Cannot create file " << newFilename << "\n";
		return 1;
	}

	// Write the modified content to the new file
	outputFile << content;
	outputFile.close();

	std::cout << "File processed and saved as " << newFilename << "\n";

	return 0;
}
