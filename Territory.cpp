#include "Territory.h"
#include "Shape.h"

Territory::Territory(int mapHeight, int mapWeight)
{
	FirstCorrected = false;
	SecondCorrected = false;
	HeightMap = mapHeight;
	WeightMap = mapWeight;
	TerritoryMap = new int*[mapHeight];
	for (int i = 0; i < mapHeight; i++)
	{
		TerritoryMap[i] = new int[mapWeight];
		for (int j = 0; j < mapWeight; j++)
		{
			TerritoryMap[i][j] = 1;
		}
	}
}

void Territory::CheckAndCorrect(int* array, int* otherArray, int size) 
{
	//First array
	int lastIndex = ArrayWorker::FindLastIndexOnX(array, size, TERRITORY_NUMBER);	
	int firstIndex = 0;
	int secondIndex = 0;
	int nextFirstIndex = 0;
	//Second array
	int otherLastIndex = 0;
	int otherFirstIndex = 0;
	int otherSecondIndex = 0;
	int otherNextFirstIndex = 0;
	if (otherArray != NULL)
		otherLastIndex = ArrayWorker::FindLastIndexOnX(otherArray, size, TERRITORY_NUMBER);
	do
	{
		firstIndex = ArrayWorker::FindFirstIndexOnX(array, size, nextFirstIndex, TERRITORY_NUMBER);
		secondIndex = ArrayWorker::FindFirstIndexOnX(array, size, firstIndex + 1, TERRITORY_OUTSIDE) - 1;

		secondIndex = (secondIndex < 0) ? lastIndex : secondIndex;
		int offset = 0;

		//Check left side
		if (firstIndex <= MAX_OFFSET && firstIndex >= 1)
		{
			offset = firstIndex;
			int x = 0;
			int length = x + offset;
			for (; x < length; x++)
				array[x] = TERRITORY_NUMBER;
			FirstCorrected = true;
		}
		//Check right side
		if (size - 1 - secondIndex <= MAX_OFFSET && size - 1 - secondIndex >= 1)
		{
			offset = size - 1 - secondIndex;
			int x = size - offset;
			int length = x + offset;
			for (; x < length; x++)
				array[x] = TERRITORY_NUMBER;
			FirstCorrected = true;
		}
		//Check outside interval
		if (secondIndex != lastIndex)
		{
			nextFirstIndex = ArrayWorker::FindFirstIndexOnX(array, size, secondIndex + 1, TERRITORY_NUMBER);
			offset = nextFirstIndex - secondIndex - 1;

			if (offset <= MAX_OFFSET)
				for (int x = secondIndex + 1; x < secondIndex + offset + 1; x++)
					array[x] = TERRITORY_NUMBER;

			nextFirstIndex = ArrayWorker::FindFirstIndexOnX(array, size, nextFirstIndex + 1, TERRITORY_OUTSIDE) - 1;
			FirstCorrected = true;
		}
		//Check ledge
		if (otherArray != NULL)
		{
			CheckAndCorrect(otherArray, NULL, size);

			otherFirstIndex = ArrayWorker::FindFirstIndexOnX(otherArray, size, otherNextFirstIndex, TERRITORY_NUMBER);
			otherSecondIndex = ArrayWorker::FindFirstIndexOnX(otherArray, size, otherFirstIndex + 1, TERRITORY_OUTSIDE) - 1;

			otherSecondIndex = (otherSecondIndex < 0) ? otherLastIndex : otherSecondIndex;
			offset = 0;

			bool firstArrayLarger = (firstIndex >= otherFirstIndex) ? true : false;

			if ((firstArrayLarger ? secondIndex - otherSecondIndex : otherSecondIndex - secondIndex) <= MAX_OFFSET &&
				(firstArrayLarger ? firstIndex - otherFirstIndex : otherFirstIndex - firstIndex) > 0)
			{
				offset = firstArrayLarger ? firstIndex - otherFirstIndex : otherFirstIndex - firstIndex;
				int x = firstArrayLarger ? otherFirstIndex : firstIndex;
				int length = x + offset;

				int* largerArray = firstArrayLarger ? otherArray : array;

				for (; x < length; x++)
					largerArray[x] = TERRITORY_OUTSIDE;

				SecondCorrected = true;
			}

			firstArrayLarger = (secondIndex >= otherSecondIndex) ? true : false;

			//if ((firstArrayLarger ? secondIndex - otherSecondIndex : otherSecondIndex - secondIndex) <= 0)
			//	continue;
			if((firstArrayLarger ? secondIndex - otherSecondIndex : otherSecondIndex - secondIndex) <= MAX_OFFSET &&
				(firstArrayLarger ? secondIndex - otherSecondIndex : otherSecondIndex - secondIndex) > 0)
			{				
				offset = firstArrayLarger ? secondIndex - otherSecondIndex : otherSecondIndex - secondIndex;
				int x = firstArrayLarger ? secondIndex : otherSecondIndex;
				int length = x - offset;

				int* largerArray = firstArrayLarger ? array : otherArray;

				for (; x > length; x--)
					largerArray[x] = TERRITORY_OUTSIDE;
				
				SecondCorrected = true;
			}

			
		}
	} while (secondIndex != lastIndex && nextFirstIndex >= 0);
}

void Territory::MapCorrection()
{
	//Check Y row
	for (int x = 0; x < WeightMap; x++)
	{
		int* firstArray = new int[HeightMap];
		int* secondArray = new int[HeightMap];

		for (int i = 0; i < HeightMap; i++)
			firstArray[i] = TerritoryMap[i][x];

		if (x + 1 < WeightMap)
		{
			for (int i = 0; i < HeightMap; i++)
				secondArray[i] = TerritoryMap[i][x + 1];
			CheckAndCorrect(firstArray, secondArray, HeightMap);
		}
		else
			CheckAndCorrect(firstArray, NULL, HeightMap);
		
		if (FirstCorrected)
		{
			for (int i = 0; i < HeightMap; i++)
				TerritoryMap[i][x] = firstArray[i];
			FirstCorrected = false;
		}
		else if (SecondCorrected)
		{
			for (int i = 0; i < HeightMap; i++)
				TerritoryMap[i][x + 1] = secondArray[i];
			SecondCorrected = false;
		}
		delete firstArray;
		delete secondArray;
	}
	//Check X row
	for (int y = 0; y < HeightMap; y++)
	{
		if(y + 1 < HeightMap)
			CheckAndCorrect(TerritoryMap[y], TerritoryMap[y + 1], WeightMap);
		else
			CheckAndCorrect(TerritoryMap[y], NULL, WeightMap);
	}
}

void Territory::GenerateTerritory()
{
	Shape::ShapeGenerateOptions options = Shape::ShapeGenerateOptions();
	options.ShapeMax_Height = 10;
	options.ShapeMin_Height = 5;
	options.ShapeMax_Weight = 10;
	options.ShapeMin_Weight = 5;

	Shape* one = Shape::GenerateRandomShape(options);
	Territory* terr = one->ConvertToTerritory();
	terr->DebugDisplay();
	terr->MapCorrection();
	terr->DebugDisplay();
	//delete terr;

	//TEST_DEBUG_Display(terr->Shapes);
	//terr->Shapes.clear();
	//delete shapeOne;
	//system("pause");
	//system("cls");
	//system("pause");
}

int** Territory::GetTerritoryMap()
{
	return TerritoryMap;
}
int Territory::GetHeightMap()
{
	return HeightMap;
}
int Territory::GetWeightMap()
{
	return WeightMap;
}

Territory::~Territory()
{
	//for (int i = 0; i < Shapes.size(); i++)
	//	delete Shapes[i];
	//Shapes.clear();
}

