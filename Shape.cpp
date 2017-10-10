#include "Shape.h"

Shape::ShapeGenerateOptions::ShapeGenerateOptions()
{
	////Default options////
	ShapeGenerateOption(5);
	HeightWeightOption(10, 1, 10, 1);
	GenerationOnSideOption(true, true, true, true);
	GenerationOnSidePositionOption(true, true, true);
}

void Shape::ShapeGenerateOptions::ShapeGenerateOption(int ShapeGenerate)
{
	this->ShapeGenerate = ShapeGenerate;

	if (this->ShapeGenerate < 1 && this->ShapeGenerate > 5)
		this->ShapeGenerate = rand() % 5 + 1;

}
void Shape::ShapeGenerateOptions::HeightWeightOption(int ShapeMax_Height, int ShapeMin_Height, int ShapeMax_Weight, int ShapeMin_Weight)
{
	this->ShapeMax_Height = ShapeMax_Height;
	this->ShapeMin_Height = ShapeMin_Height;
	this->ShapeMax_Weight = ShapeMax_Weight;
	this->ShapeMin_Weight = ShapeMin_Weight;
}
void Shape::ShapeGenerateOptions::GenerationOnSideOption(bool GenerateOn_LeftSide = true, bool GenerateOn_UpSide = true, bool GenerateOn_RightSide = true, bool GenerateOn_DownSide = true)
{
	////Reset////
	Sides.clear();

	if (GenerateOn_LeftSide)
		Sides.push_back(Shape::Side::Left);
	if (GenerateOn_UpSide)
		Sides.push_back(Shape::Side::Up);
	if (GenerateOn_RightSide)
		Sides.push_back(Shape::Side::Right);
	if (GenerateOn_DownSide)
		Sides.push_back(Shape::Side::Down);
}
void Shape::ShapeGenerateOptions::GenerationOnSidePositionOption(bool GenerateOn_LeftPosition = true, bool GenerateOn_CenterPosition = true, bool GenerateOn_RightPosition = true)
{
	////Reset////
	Positions.clear();

	if (GenerateOn_LeftPosition)
		Positions.push_back(Shape::SidePosition::LeftPosition);
	if (GenerateOn_CenterPosition)
		Positions.push_back(Shape::SidePosition::CenterPosition);
	if (GenerateOn_RightPosition)
		Positions.push_back(Shape::SidePosition::RightPosition);
}

std::vector<Shape::Side>* Shape::ShapeGenerateOptions::GetSides()
{
	return &Sides;
}
std::vector<Shape::SidePosition>* Shape::ShapeGenerateOptions::GetPositions()
{
	return &Positions;
}

Shape::Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

Shape::Shape(int WeightBlocks, int HeightBlocks)
{
	Points.push_back(new Shape::Point(0, 0));
	Points.push_back(new Shape::Point(0, HeightBlocks));
	Points.push_back(new Shape::Point(WeightBlocks, HeightBlocks));
	Points.push_back(new Shape::Point(WeightBlocks, 0));

	this->HeightBlocks = HeightBlocks;
	this->WeightBlocks = WeightBlocks;

	TotalHeightBlocks = this->HeightBlocks;
	TotalWeightBlocks = this->WeightBlocks;

	OffsetByX = 0;
	OffsetByY = 0;
}
Shape* Shape::GenerateRandomShape(Shape::ShapeGenerateOptions Options)
{
	///////////////DEBUG ONLY/////////////////
	std::vector<std::string> DebugVector;
	///////////////DEBUG ONLY/////////////////

	//Shape* ownerShape = new Shape(rand() % Options.ShapeMax_Weight + Options.ShapeMin_Weight, rand() % Options.ShapeMax_Height + Options.ShapeMin_Height);

	//for (int i = 0; i < Options.ShapeGenerate - 1; i++)
	//{
	//	int height = rand() % Options.ShapeMax_Height + Options.ShapeMin_Height;
	//	int weight = rand() % Options.ShapeMax_Weight + Options.ShapeMin_Weight;
	//	Shape::Side side = Options.GetSides()->at(rand() % Options.GetSides()->size() + 0);
	//	Options.GetSides()->erase(std::find(Options.GetSides()->begin(), Options.GetSides()->end(), side));
	//	Shape::SidePosition position = static_cast<Shape::SidePosition>(rand() % Options.GetPositions()->size() + 0);

	//	ownerShape->Join(new Shape(weight, height), static_cast<Shape::Side>(side), static_cast<Shape::SidePosition>(position));

	//	/////////////DEBUG ONLY/////////////////
	//	DebugVector.push_back(std::to_string(height));
	//	DebugVector.push_back(std::to_string(weight));
	//	DebugVector.push_back(std::to_string(side));
	//	DebugVector.push_back(std::to_string(position));
	//	/////////////DEBUG ONLY/////////////////
	//}

	///////////////DEBUG ONLY/////////////////
	Shape* ownerShape = new Shape(8, 14);
	ownerShape->Join(new Shape(12, 12), Shape::Side::Left, Shape::SidePosition::RightPosition);
	ownerShape->Join(new Shape(6, 11), Shape::Side::Up, Shape::SidePosition::RightPosition);
	ownerShape->Join(new Shape(10, 13), Shape::Side::Right, Shape::SidePosition::RightPosition);
	ownerShape->Join(new Shape(14, 9), Shape::Side::Down, Shape::SidePosition::RightPosition);

	///////////////DEBUG ONLY/////////////////

	///////////////DEBUG ONLY/////////////////
	std::string* sides = new std::string[4];
	sides[0] = "left";
	sides[1] = "up";
	sides[2] = "right";
	sides[3] = "down";
	std::string* positions = new std::string[3];
	positions[0] = "left";
	positions[1] = "center";
	positions[2] = "right";
	//for each (Shape* shape in ownerShape->Shapes)
	//{
	//	for each (Point* point in shape->Points)
	//	{
			/*if (point->y > ownerShape->TotalHeightBlocks || point->x > ownerShape->TotalWeightBlocks)
			{*/
			/*	std::cout << "Total Y: " << ownerShape->TotalHeightBlocks << std::endl << "Y: " << point->y << std::endl << std::endl;
				std::cout << "Total X: " << ownerShape->TotalWeightBlocks << std::endl << "X: " << point->x << std::endl << std::endl;*/

				//std::cout << "Owner: " << std::endl <<
				//	"Height: " << ownerShape->HeightBlocks << std::endl
				//	<< "Weght: " << ownerShape->WeightBlocks << std::endl << std::endl;
				//	
				//for (int i = 0; i < 13; i += 4)
				//{
				//	std::cout << "Height: " << DebugVector[i] << std::endl
				//		<< "Weght: " << DebugVector[i + 1] << std::endl
				//		<< "Side: " << sides[atoi(DebugVector[i + 2].c_str())] << std::endl
				//		<< "Position: " << positions[atoi(DebugVector[i + 3].c_str())] << std::endl << std::endl;
				//}
				//system("pause");
		//	}
		//}
	//}
	//bool am = cpplinq::from(ownerShape->Shapes) >> cpplinq::first([total](Shape x) { 
	//	return cpplinq::from(x.Points) >> cpplinq::first([total](Point p) {
	//		return p.y > total; 
	//	}); 
	//});


	///////////////DEBUG ONLY/////////////////
	//system("pause");
	return ownerShape;
}
Territory* Shape::ConvertToTerritory()
{
	//DEBUG
	Shapes.insert(Shapes.begin(), this);

	Territory* terr = new Territory(this->TotalHeightBlocks, this->TotalWeightBlocks);
	int** map = terr->GetTerritoryMap();
	for each (Shape* shape in Shapes)
	{
		for (int y = shape->Points[0]->y; y < shape->Points[2]->y; y++)
		{
			for (int x = shape->Points[0]->x; x < shape->Points[2]->x; x++)
			{
				map[y][x] = terr->TERRITORY_NUMBER;
			}
		}
	}
	return terr;
	//DEBUG

	//Shapes.insert(Shapes.begin(), this);

	//Territory* terr = new Territory(this->TotalHeightBlocks, this->TotalWeightBlocks);
	//int** map = terr->GetTerritoryMap();
	//for each (Shape* shape in Shapes)
	//{
	//	for (int y = shape->Points[0]->y; y < shape->Points[2]->y; y++)
	//	{			
	//		for (int x = shape->Points[0]->x; x < shape->Points[2]->x; x++)
	//		{
	//			map[y][x] = TERRITORY_NUMBER;
	//		}
	//	}
	//}
	//return terr;
}
void Shape::Join(Shape *OtherShape, Shape::Side JoinSide, Shape::SidePosition JoinSidePosition)
{
	int addYToOtherShape = OffsetByY;
	int addXToOtherShape = OffsetByX;
	int addYToCurrentShape = 0;
	int addXToCurrentShape = 0;

	if (JoinSide == Shape::Side::Left || JoinSide == Shape::Side::Right)
	{
		if (JoinSidePosition == Shape::CenterPosition)
		{
			if (OtherShape->HeightBlocks <= this->HeightBlocks)
				addYToOtherShape += (this->HeightBlocks / 2) - (OtherShape->HeightBlocks / 2);
			else
			{
				addYToCurrentShape = (OtherShape->HeightBlocks / 2) - (this->HeightBlocks / 2);
				if (addYToCurrentShape <= OffsetByY)
				{
					addYToOtherShape -= addYToCurrentShape;
					addYToCurrentShape = 0;
				}
				else
				{
					addYToOtherShape -= OffsetByY;
					addYToCurrentShape -= OffsetByY;
				}
			}
		}
		else if (JoinSidePosition == Shape::RightPosition)
		{
			if (OtherShape->HeightBlocks <= this->HeightBlocks)
				addYToOtherShape += this->HeightBlocks - OtherShape->HeightBlocks;
			else
			{
				addYToCurrentShape = (OtherShape->HeightBlocks - this->HeightBlocks);
				if (addYToCurrentShape <= OffsetByY)
				{
					addYToOtherShape -= addYToCurrentShape;
					addYToCurrentShape = 0;
				}
				else
				{
					addYToOtherShape -= OffsetByY;
					addYToCurrentShape -= OffsetByY;
				}
			}
		}
	}
	else if (JoinSide == Shape::Side::Up || JoinSide == Shape::Side::Down)
	{
		if (JoinSidePosition == Shape::CenterPosition)
		{
			if (OtherShape->WeightBlocks <= this->WeightBlocks)
				addXToOtherShape += (this->WeightBlocks / 2) - (OtherShape->WeightBlocks / 2);
			else
			{
				addXToCurrentShape = (OtherShape->WeightBlocks / 2) - (this->WeightBlocks / 2);
				if (addXToCurrentShape <= OffsetByX)
				{
					addXToOtherShape -= addXToCurrentShape;
					addXToCurrentShape = 0;
				}
				else
				{
					addXToOtherShape -= OffsetByX;
					addXToCurrentShape -= OffsetByX;
				}
			}
		}
		else if (JoinSidePosition == Shape::RightPosition)
		{
			if (OtherShape->WeightBlocks <= this->WeightBlocks)
				addXToOtherShape += this->WeightBlocks - OtherShape->WeightBlocks;
			else
			{
				addXToCurrentShape = (OtherShape->WeightBlocks - this->WeightBlocks);
				if (addXToCurrentShape <= OffsetByX)
				{
					addXToOtherShape -= addXToCurrentShape;
					addXToCurrentShape = 0;
				}
				else
				{
					addXToOtherShape -= OffsetByX;
					addXToCurrentShape -= OffsetByX;
				}
			}
		}
	}

	switch (JoinSide)
	{
	case Shape::Side::Left:
		for (int i = 0; i < Points.size(); i++)
		{
			OtherShape->Points[i]->x += (OtherShape->WeightBlocks >= OffsetByX) ? 0 : OffsetByX - OtherShape->WeightBlocks;//addXToOtherShape - OffsetByX;
			OtherShape->Points[i]->y += addYToOtherShape;
			Points[i]->x += (OtherShape->WeightBlocks - OffsetByX <= 0) ? 0 : OtherShape->WeightBlocks - OffsetByX;// OtherShape->WeightBlocks - OffsetByX;
			Points[i]->y += addYToCurrentShape;
			for (int j = 0; j < this->Shapes.size(); j++)
			{
				this->Shapes[j]->Points[i]->x += (OtherShape->WeightBlocks - OffsetByX <= 0) ? 0 : OtherShape->WeightBlocks - OffsetByX;
				this->Shapes[j]->Points[i]->y += addYToCurrentShape;
			}
		}
		break;
	case Shape::Side::Up:
		for (int i = 0; i < Points.size(); i++)
		{
			OtherShape->Points[i]->x += addXToOtherShape;
			OtherShape->Points[i]->y += (OtherShape->HeightBlocks >= OffsetByY) ? 0 : OffsetByY - OtherShape->HeightBlocks;
			Points[i]->x += addXToCurrentShape;
			Points[i]->y += (OtherShape->HeightBlocks - OffsetByY <= 0) ? 0 : OtherShape->HeightBlocks - OffsetByY;
			for (int j = 0; j < this->Shapes.size(); j++)
			{
				this->Shapes[j]->Points[i]->x += addXToCurrentShape;
				this->Shapes[j]->Points[i]->y += (OtherShape->HeightBlocks - OffsetByY <= 0) ? 0 : OtherShape->HeightBlocks - OffsetByY;
			}			
		}
		break;
	case Shape::Side::Right:
		for (int i = 0; i < Points.size(); i++)
		{
			OtherShape->Points[i]->y += addYToOtherShape;
			OtherShape->Points[i]->x += Points[3]->x;
			Points[i]->y += addYToCurrentShape;
			for (int j = 0; j < this->Shapes.size(); j++)
			{
				this->Shapes[j]->Points[i]->y += addYToCurrentShape;
			}
		}
		break;
	case Shape::Side::Down:
		for (int i = 0; i < Points.size(); i++)
		{
			OtherShape->Points[i]->x += addXToOtherShape;
			OtherShape->Points[i]->y += Points[2]->y;
			Points[i]->x += addXToCurrentShape;
			for (int j = 0; j < this->Shapes.size(); j++)
			{
				this->Shapes[j]->Points[i]->x += addXToCurrentShape;
			}
		}
		break;
	}
	Shapes.push_back(OtherShape);
	OffsetByY = Points[0]->y;
	OffsetByX = Points[0]->x;
	for each (Shape* shape in Shapes)
	{
		for (int i = 0; i < 4; i++)
		{
			if (TotalHeightBlocks < shape->Points[i]->y)
				TotalHeightBlocks = shape->Points[i]->y;
			if (TotalWeightBlocks < shape->Points[i]->x)
				TotalWeightBlocks = shape->Points[i]->x;
		}
	}
	if (TotalHeightBlocks < Points[2]->y)
		TotalHeightBlocks = Points[2]->y;
	if (TotalWeightBlocks < Points[2]->x)
		TotalWeightBlocks = Points[2]->x;

}

Shape::~Shape()
{
	for (int i = 0; i < Points.size(); i++)
		delete Points[i];
	for (int i = 1; i < Shapes.size(); i++)
		delete Shapes[i];
	Shapes.clear();
	Points.clear();
}