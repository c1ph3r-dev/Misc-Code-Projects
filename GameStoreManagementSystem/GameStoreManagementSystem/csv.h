#pragma once
#ifndef CSV_H_
#define CSV_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

template<typename T>
std::vector<T> ReadFile(std::string FilePath)
{
	std::ifstream file;
	file.open(FilePath);

	if (!file.is_open())
		throw std::logic_error("Could not open file!");

	std::vector<T> data;

	std::string line;
	std::getline(file, line);
	line = "";

	while (std::getline(file, line))
	{
		T temp;
		temp.Read(line);
		data.push_back(temp);
		line = "";
	}

	return data;
}

#endif // !CSV_H_
