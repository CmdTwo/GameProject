#include "conio.h"
#include "cstdlib"
#include <fstream>
#include <iostream>
#include "vector"
#include "string"
#include "time.h"
#include <algorithm>
#include "Territory.h"
#include "Shape.h"
#include "ArrayWorker.h"

using namespace std;

int main()
{
	setlocale(0, "Russian");
	srand(time(0));	

	system("color 02");	

	int count = 0;
	//while (true)
	//{
	//	Shape::ShapeGenerateOptions options = Shape::ShapeGenerateOptions();
	//	options.ShapeMax_Height = 10;
	//	options.ShapeMin_Height = 5;
	//	options.ShapeMax_Weight = 10;
	//	options.ShapeMin_Weight = 5;

	//	Shape* one = Shape::GenerateRandomShape(options);
	//	cout << "Count: " << ++count << endl;
	//}

	while (true)
	{
		Territory::GenerateTerritory();

	}
	_getch();
	return 0;
}