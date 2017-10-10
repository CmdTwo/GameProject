#pragma once
///////////////DEBUG ONLY/////////////////
#include "conio.h"
#include <iostream>
#include <string>
///////////////DEBUG ONLY/////////////////
#include "ArrayWorker.h"

class Territory
{
private:
	const int MAX_OFFSET = 5;
	bool FirstCorrected;
	bool SecondCorrected;

	int** TerritoryMap;
	int HeightMap;
	int WeightMap;

	void MapCorrection();
	void CheckAndCorrect(int*, int*, int);

public:
	const int TERRITORY_NUMBER = 0;
	const int TERRITORY_OUTSIDE = 1;
	
	Territory(int, int);

	static /*Territory*/ void GenerateTerritory();


	int** GetTerritoryMap();
	int GetHeightMap();
	int GetWeightMap();

	//DEBUG//

	void DebugDisplay(int* array, int size)
	{
		for (int i = 0; i < HeightMap; i++)
			std::cout << array[i];
		std::cout << std::endl;
	}
	void DebugDisplay()
	{
		std::string s;
		for (int y = 0; y < HeightMap; y++)
		{
			for (int x = 0; x < WeightMap; x++)
			{
				s = (TerritoryMap[y][x] == 7) ? "*" : (TerritoryMap[y][x] == TERRITORY_OUTSIDE) ? " " : std::to_string(TerritoryMap[y][x]);
				std::cout << s;
			}
			std::cout << std::endl;
		}
		system("pause");
	}

	//DEBUG//

	~Territory();
};