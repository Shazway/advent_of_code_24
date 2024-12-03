/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:10:33 by tmoragli          #+#    #+#             */
/*   Updated: 2024/12/04 00:40:39 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#define CLOSED 0

int err(std::ifstream &file) {
	file.close();
	return 1;
}

int main()
{
	std::vector<int> left;
	std::vector<int> right;
	std::ifstream file;
	std::string line;
	long result = 0;

	file.open("./data/chief_list.txt");
	if (file.is_open() == CLOSED || file.peek() == std::ifstream::traits_type::eof())
		return err(file);

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string word;
		if (iss >> word)
			left.push_back(std::stoi(word));
		if (iss >> word)
			right.push_back(std::stoi(word));
	}
	if (left.size() != right.size())
		return err(file);

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());
	for (size_t i = 0; i < left.size(); i++)
	{
		result += std::abs(left[i] - right[i]);
	}
	std::cout << "Result is: " << result << std::endl;
	file.close();
	return 0;
}
