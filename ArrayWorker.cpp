#include "ArrayWorker.h"

int ArrayWorker::FindFirstIndexOnX(int* array, int size, int findElement)
{
	return FindFirstIndexOnX(array, size, 0, 0, findElement);
}
int ArrayWorker::FindFirstIndexOnX(int* array, int size, int begin, int findElement)
{
	return FindFirstIndexOnX(array, size, begin, 0, findElement);
}
int ArrayWorker::FindFirstIndexOnX(int* array, int size, int begin, int end, int findElement)
{
	int index = 0 + begin;
	if (end == 0)
		end = size;
	while (array[index] != findElement && index != size && index != end)
		index++;
	return (index == size || index == end) ? -1 : index;
}

int ArrayWorker::FindLastIndexOnX(int* array, int size, int findElement)
{
	return FindLastIndexOnX(array, size, 0, 0, findElement);
}
int ArrayWorker::FindLastIndexOnX(int* array, int size, int begin, int findElement)
{
	return FindLastIndexOnX(array, size, begin, 0, findElement);
}
int ArrayWorker::FindLastIndexOnX(int* array, int size, int begin, int end, int findElement)
{
	int index = size - 1 - begin;

	while (array[index] != findElement && index > 0 && index != end)
	{
		index--;
	}
	return (index != end && index < 0) ? -1 : index;
}
