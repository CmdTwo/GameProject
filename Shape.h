#pragma once
#include <vector>
#include "Territory.h"
///////////////DEBUG ONLY/////////////////
#include "conio.h"
#include <iostream>
#include <string>
///////////////DEBUG ONLY/////////////////

class Shape
{
public:
	struct Point
	{
	public:
		int x;
		int y;

		Point(int, int);
	};
	enum Side
	{
		Left = 0,
		Up = 1,
		Right = 2,
		Down = 3
	};
	enum SidePosition
	{
		LeftPosition = 0,
		CenterPosition = 1,
		RightPosition = 2
	};
	struct ShapeGenerateOptions
	{
	private:
		std::vector<Shape::Side> Sides;
		std::vector<Shape::SidePosition> Positions;

	public:
		ShapeGenerateOptions();

		int ShapeGenerate;
		int ShapeMax_Height;
		int ShapeMin_Height;
		int ShapeMax_Weight;
		int ShapeMin_Weight;
		bool GenerateOn_LeftSide;
		bool GenerateOn_UpSide;
		bool GenerateOn_RightSide;
		bool GenerateOn_DownSide;
		bool GenerateOn_LeftPosition;
		bool GenerateOn_CenterPosition;
		bool GenerateOn_RightPosition;

		void ShapeGenerateOption(int);
		void HeightWeightOption(int, int, int, int);
		void GenerationOnSideOption(bool, bool, bool, bool);
		void GenerationOnSidePositionOption(bool, bool, bool);

		std::vector<Shape::Side>* GetSides();
		std::vector<Shape::SidePosition>* GetPositions();
	};
		
	Shape(int, int);

	static Shape* GenerateRandomShape(ShapeGenerateOptions);
	Territory* ConvertToTerritory();
	std::vector<Point*> Points;
	~Shape();
private:

	std::vector<Shape*> Shapes;

	int HeightBlocks;
	int WeightBlocks;
	int TotalHeightBlocks;
	int TotalWeightBlocks;
	int OffsetByY;
	int OffsetByX;

	void Join(Shape*, Side, SidePosition);
};