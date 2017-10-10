#pragma once

static class ArrayWorker
{
public:
	static int FindFirstIndexOnX(int* array, int size, int findElement);
	static int FindFirstIndexOnX(int* array, int size, int begin, int findElement);
	static int FindFirstIndexOnX(int* array, int size, int begin, int end, int findElement);
	
	static int FindLastIndexOnX(int* array, int size, int findElement);
	static int FindLastIndexOnX(int* array, int size, int begin, int findElement);
	static int FindLastIndexOnX(int* array, int size, int begin, int end, int findElement);	
};