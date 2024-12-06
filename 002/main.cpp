/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:10:33 by tmoragli          #+#    #+#             */
/*   Updated: 2024/12/07 00:54:15 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#define UNSAFE false
#define SAFE true
#define CLOSED 0

int err(std::ifstream &file) {
	file.close();
	return 1;
}

bool check_levels(std::vector<int> &levels)
{
	int level = 0;
	bool decreasing = false;
	bool increasing = false;

	for (size_t i = 0; i < levels.size(); i++)
	{
		if (level)
		{
			if (levels[i] > level)
				increasing = true;
			else if (levels[i] < level)
				decreasing = true;
			else
				return UNSAFE;
			if (decreasing && increasing)
				return UNSAFE;
			if (std::abs(levels[i] - level) < 1 || std::abs(levels[i] - level) > 3)
				return UNSAFE;
		}
		level = levels[i];
	}
	return SAFE;
}

long count_safe_levels(std::vector<std::vector<int>> &levels_list)
{
	long count = 0;
	for (size_t i = 0; i < levels_list.size(); i++)
	{
		if (check_levels(levels_list[i]))
			count++;
	}
	return count;
}

int main()
{
	std::vector<std::vector<int>> levels_list;
	std::ifstream file;
	std::string line;
	long safe_levels_count = 0;

	file.open("./data/levels_data.txt");
	if (file.is_open() == CLOSED || file.peek() == std::ifstream::traits_type::eof())
		return err(file);

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string word;
		std::vector<int> levels;
		std::cout << line << std::endl;
		while (iss >> word)
		{
			levels.push_back(std::stoi(word));
		}
		levels_list.push_back(levels);
	}
	safe_levels_count = count_safe_levels(levels_list);
	std::cout << "The number of safe levels is " << safe_levels_count << std::endl;
	std::cout << "The number of levels is " << levels_list.size() << std::endl;
	file.close();
	return 0;
}
