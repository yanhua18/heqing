#include"sort.h"

int main()
{
	int a[] = { 2, 4, 5, 23, 54, 14, 78 };
	quickSort(a, ARRSIZE(a));
	printArray(a, ARRSIZE(a));

	system("pause");
	return 0;
}

//int *data = (int *)malloc(n*sizeof(int));
//Srand((unsigned int)time(NULL));
//int i;
//for (;)//在目录文件下找到exe,然后shift+右键（powershell）打印到文件中