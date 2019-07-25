//#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>    
#include<string.h>
#include<Windows.h>
//day1#######################################################################
//1.1打印100~200之间的素数
int IsPrime(int x)
{
	int i = 2;
	for (; i < x; i++)
	{
		if (x%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int x = 100;
	for (; x <= 200; x++)
	{
		if (IsPrime(x))
		{
			printf(" %d ", x);
		}
	}
	system("pause");
}
//1.1*************************************************
#include<stdio.h>
#include<Windows.h>
int IsPrime(int x)
{
	int i = 2;
	for (; i < x / 2; i++)
	{
		if (x%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int x = 100;
	for (; x <= 200; x++)
	{
		if (IsPrime(x))
		{
			printf(" %d ", x);
		}
	}
	system("pause");
}


//1.2输出乘法口诀表
#include<stdio.h>
#include<Windows.h>
void Show(int n)
{
	int i = 1;
	for (; i <= n; i++)
	{
		int j = 1;
		for (; j <= i; j++)
		{
			printf(" %d*%d=%d ", j, i, j*i);
		}
		printf("\n");
	}
}

int main()
{
	Show(9);
	system("pause");
	return 0;
}

//1.3判断1000年—2000年之间的闰年
#include<stdio.h>
#include<Windows.h>
int IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int year = 1000;
	for (; year <= 2000; year++)
	{
		if (IsLeapYear(year))
		{
			printf(" %d ", year);
		}
	}
	system("pause");
	return 0;
}

//day2#######################################################################
//2.1用异或来交换两个变量的值，不借助临时变量
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
int main()
{
	int i, j;
	printf("输入两个要交换的数据：\n");
	scanf("%d%d", &i, &j);
	//i*i=0,j*j=0
	//任何数与0异或都是其本身
	//异或支持交换律
	i = i^j; //i=i^j;
	j = i^j; //j=i^j^j=i^0=i;
	i = j^i; //i=i^i^j=0^j=j;
	printf("交换后得到的数据为：\n");
	printf("%d %d", i, j);
	system("pause");
}

//2.2求10个整数中的最大值
#include<stdio.h>
#include<Windows.h>
int Max()
{
	int  a[] = { 1, 11, 111, 2, 22, 222, 3, 33, 333, 4 };
	int num = sizeof(a) / sizeof(a[0]);
	int i = 1;
	int max = a[0];
	for (; i < num; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}
int main()
{
	printf("%d\n", Max());
	system("pause");
}

//2.3比较三个数的大小
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
void ThreeData(int x, int y, int z)
{
	if (x > y){
		if (z > x){
			printf("%d %d %d \n", z, x, y);
		}
		else if (z > y){
			printf("%d %d %d \n", x, z, y);
		}
		else{
			printf("%d %d %d \n", x, y, z);
		}
	}
	else{
		if (z > y){
			printf("%d %d %d \n", z, y, x);
		}
		else if (z > x){
			printf("%d %d %d \n", y, z, x);
		}
		else{
			printf("%d %d %d \n", y, x, z);
		}
	}
}
int main()
{
	ThreeData(34, 35, 56);
	system("pause");
}



//2.4求两个数的最大公约数
//way1*************************************
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
int CommonDivisor(int x, int y)
{
	int min = x > y ? y : x;
	while (min > 1){
		if (y % min == 0 && x % min == 0){
			break;
		}
		min--;
	}
	return min;
}
int main()
{
	int x = CommonDivisor(21, 32);
	printf("%d ", x);
	system("pause");
}

//way2更相减损术*************************************
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
int CommonDivisor(int x, int y)
{
	while (x != y){
		if (x > y){
			x = x - y;
		}
		else {
			y = y - x;
		}
	}
	return y;
}
int main()
{
	int x = CommonDivisor(21, 32);
	printf("%d ", x);
	system("pause");
}
//way3辗转相除法,x>y ——> x / y = z…n ——>x = zy + n ——> x - zy = n,余数n中含有最大公约数
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
int CommonDivisor(int x, int y)
{
	while (x*y != 0){
		if (x > y){
			x = x % y;
		}
		else {
			y = y % x;
		}
	}
	return x == 0 ? y : x;
}
int main()
{
	int x = CommonDivisor(21, 32);
	printf("%d ", x);
	system("pause");
}

//day3#######################################################################
//3.1将一元数组A中的内容和数组B中的内容进行交换，数组一样大
#include<stdio.h>
#include<Windows.h>
void ShowArray(int a[], int num)
{
	int i = 0;
	for (; i < 5; i++)
	{
		printf(" %d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 6, 7, 8, 9, 10 };
	int num = sizeof(a) / sizeof(a[0]);
	int i = 0;
	for (; i < 5; i++)
	{
		a[i] ^= b[i];
		b[i] ^= a[i];
		a[i] ^= b[i];
	}
	ShowArray(a, num);
	ShowArray(b, num);
	system("pause");
}

//3.2计算1/1-1/2+1/3-1/4+1/5 ⋯⋯ + 1/99 - 1/100 的值
#include<stdio.h>
#include<Windows.h>
double Cal(int top)
{
	int i;
	double result = 0;
	int flag = 1;
	for (i = 1; i < 100; i++)
	{
		result += 1.0 / (i*flag);
		flag = -flag;
	}
	return result;
}
int main()
{
	double d = Cal(100);
	printf(" %f \n", d);
	system("pause");
}

//3.3数一下 1到 100 的所有整数中出现多少个数字9
#include<stdio.h>
#include<Windows.h>
void Count()
{
	int i;
	int k = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			k++;
		}
		if (i / 10 == 9)
		{
			k++;
		}
	}
	printf("%d", k);
}
int main()
{
	Count();
	system("pause");
}

//day4#######################################################################
//4.1在屏幕上输出以下图案：
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************
// ***********
//  *********
//   *******
//    *****
//     ***
//      *
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
void Show(int line)
{
	int i = 1;
	for (; i <= line; i++)
	{
		int j = 0;
		for (; j < line - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i < line; i++)
	{
		int j = 0;
		for (; j < i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
int main()
{
	int line = 0;
	scanf("%d", &line);
	Show(line);
	system("pause");
	return 0;
}

//4.2求出0〜999之间的所有“水仙花数”并输出。“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝13＋53＋3 ^ 3，则153是一个“水仙花数”。
#include<stdio.h>
#include<Windows.h>
#include<math.h>
int narcissistic(int x)
{
	int count = 0;
	int sum = 0;
	int tmp = x;
	while (tmp != 0)
	{
		count++;
		tmp = tmp / 10;
	}
	tmp = x;
	while (tmp != 0)
	{
		sum = sum + pow((double)(tmp % 10), count);
		tmp = tmp / 10;
	}
	if (sum == x)
	{
		printf("%d\n", x);
	}
}
int main()
{
	int i = 100;
	for (; i < 10000; i++)
	{
		narcissistic(i);
	}
	system("pause");
	return 0;
}

//4.3求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，例如：2 + 22 + 222 + 2222 + 22222
#include<stdio.h>
#include<windows.h>
int Sum(int n, int x)
{
	int sum = 0;
	int tmp = 0;
	int i = 0;
	for (; i < x; i++)
	{
		tmp = tmp * 10 + n;
		sum += tmp;
	}
	printf("%d", sum);
}
int main()
{
	Sum(2, 5);
	system("pause");
	return 0;
}

//day5#######################################################################
//5.1猜数字游戏
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<time.h>
void play()
{
	srand((unsigned long)time(NULL));
	int random = rand() % 200 + 1;
	int data = 0;
	while (1)
	{
		printf("Input Data:\n");
		scanf("%d", &data);
		if (data > random){
			printf("猜大了！\n");
		}
		else if (data < random){
			printf("猜小了！\n");
		}
		else
		{
			printf("恭喜你猜对了！\n");
			break;
		}
	}
}
int game()
{
	while (1)
	{
		int select = 0;
		printf("1.play\n");
		printf("2.exit\n");
		printf("请选择：\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:play();
			break;
		case 2:printf("Good Bye!\n");
			return 0;
		default:
			printf("Input Error,Please Try Again !\n");
			break;
		}
	}
}
int main()
{
	game();
	system("pause");
	return 0;
}

//写代码可以在整型有序数组中查找想要的数字， 找到了返回下标，找不到返回-1.（折半查找）
#include<stdio.h>
#include<windows.h>
int binarysearch(int arr[], int key, int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] == key)
		{
			return mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = len - 1;
	int index = binarysearch(arr, 8, left, right);
	printf("%d", index);
	system("pause");
	return 0;
}

//5.3编写代码模拟三次密码输入的场景。 最多能输入三次密码，密码正确，提示“登录成功”,密码错误， 可以重新输入，最多输入三次。三次均错，则提示退出程序。
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<Windows.h>
const char Name[] = "limeng";
const char Password[] = "123456";
void Login()
{
	int count = 3;
	while (count > 0){
		char name[32], password[32];
		printf("Input Your Login Name:");
		scanf("%s", &name);
		printf("Input Your Password:");
		scanf("%s", &password);
		if (strcmp(name, Name) == 0 && strcmp(password, Password) == 0)
		{
			printf("login success!");
			break;
		}
		else{
			printf("Input Error!\n");
			count--;
			printf("You Have %d times!\n", count);
		}
	}
}
int main()
{
	Login();
	system("pause");
	return 0;
}

//day7#######################################################################

//1.递归和非递归分别实现求第n个斐波那契数。
//
//2.编写一个函数实现n^k，使用递归实现
//
//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//
//5.递归和非递归分别实现strlen
//6.递归和非递归分别实现求n的阶乘
//7.递归方式实现打印一个整数的每一位

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
/*
递归：大问题化解为小问题
1、有一个趋近于终止的条件
2、调用自己本身
*/
int Pow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else
	{
		return n*Pow(n, k - 1);
	}
}
//1729  ==》1+7+2+9
int DigitSum(unsigned int n)
{
	//return DigitSum(n/10)+n%10;
	//9  10  11  12
	if (n > 9)
	{
		return DigitSum(n / 10) + n % 10;
	}
	else
	{
		return n;
	}

}
int main()
{
	printf("%d\n", DigitSum(1729));
	return 0;
}



//1 1 2 3 5 8 13
/*
递归：大问题化解为小问题
1、有一个趋近于终止的条件
2、调用自己本身
F(n) = F(n-1)+F(n-2);

*/
int Fabonico1(int n)//4
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fabonico1(n - 1) + Fabonico1(n - 2);
	}
}
//循环的版本
int Fabonico(int n)
{
	int f1 = 1;
	int f2 = 1;
	int f3 = 0;
	int i = 0;
	for (i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}
int main()
{
	int result = Fabonico(40);
	printf("%d\n", result);
	return 0;
}

//day10#######################################################################
//10.1写一个函数返回参数二进制中 1 的个数 比如： 15 0000 1111 中有4 个 1
#include<stdio.h>
#include<windows.h>
int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		value &= value - 1;
		count++;
	}
	return count;
}
int main()
{
	int count = count_one_bits(255);
	printf("%d\n", count);
	system("pause");
	return 0;
}
//10.2获取一个数二进制序列中所有的偶数位和奇数位， 分别输出二进制序列。
#include<stdio.h>
#include<windows.h>
void Get_bits(int x)
{
	int i = 31;
	printf("输出偶数位：");
	for (; i > 0; i -= 2)
	{
		printf("%d", (x >> i) & 1);
	}
	printf("\n输出奇数位：");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", (x >> i) & 1);
	}
}
int main()
{
	Get_bits(20);
	system("pause");
	return 0;
}


//10.3编程实现： 两个int（32位）整数m和n的二进制表达中， 有多少个位(bit)不同？输入例子:1999 2299输出例子 : 7
#include<stdio.h>
#include<windows.h>
int Difer_bit(int x, int y)
{
	int count = 0;
	int i = 0;
	for (; i < 32; i++)
	{
		if (((x >> i) & 1) != ((y >> i) & 1))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	printf("%d", Difer_bit(1999, 2299));
	system("pause");
	return 0;
}

int Differ(int m, int n)
{
	int count = 0;
	int tmp = 0;
	tmp = m^n;//异或运算的出m和n中不同的位，两比特位异或不同的为1.
	while (tmp != 0)//求tmp中1的个数
	{
		tmp &= tmp - 1;
		count++;
	}
	return count;
}
int main()
{
	printf("%d", Differ(1999, 2299));
	system("pause");
	return 0;
}

//day11#######################################################################
//11.15位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
#include<stdio.h>
#include<Windows.h>
void Rank(void)
{
	int A = 0， B = 0， C = 0，D = 0，E = 0;
	for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				for (D = 1; D <= 5; D++)
				{
					for (E = 1; E <= 5; E++)
					{
						if (((B == 2) + (A == 3) == 1) &&
							((B == 2) + (E == 4) == 1) &&
							((C == 1) + (D == 2) == 1) &&
							((C == 5) + (D == 3) == 1) &&
							((E == 4) + (A == 1) == 1))
						{
							if (120 == A*B*C*D*E)
							{
								printf("A=%d B=%d C=%d D=%d E=%d\n", A, B, C, D, E);
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	Rank();
	system("pause");
	return 0;
}
//11.2日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
#include<stdio.h>
#include<Windows.h>
void Judge(void)
{
	int i = 0;
	for (i = 'A'; i <= 'D'; i++)
	{
		if ((i != 'A') + (i == 'C') + (i == 'D') + (i != 'D') == 3)
		{
			printf("%c", i);
		}
	}
}
int main()
{
	Judge();
	system("pause");
	return 0;
}

//day12关于位运算的一些习题#################################################
//12.1编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值是value的二进制位模式从左到右翻转后的值。
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
#include<stdio.h>
#include<Windows.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	double sum = 0;
	int i = 0;
	for (; i < 32; i++)
	{
		//sum += ((value >> i) & 1)*pow((double)2, 31 - i);先右移除每一位，再对右移出的每一位乘以其翻转后相对应位数的权值
		sum += ((value >> i) & 1) << (31 - i);//先右移出每一位，在对每一位左移到其对应的翻转后的位置
	}
	return sum;
}
int main()
{
	printf("%u", reverse_bit(25));
	system("pause");
	return 0;
}

//12.2不使用（a+b）/2这种方式，求两个数的平均值
#include<stdio.h>
#include<Windows.h>
int Get_Arverage(int m, int n)
{
	return (m&n) + (m^n) / 2;
}
int main()
{
	printf("%d", Get_Arverage(2, 5));
	system("pause");
	return 0;
}

//12.3一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。请找出这个数字。（使用位运算）
#include<stdio.h>
#include<Windows.h>
int Get_number(int *arr, int len)
{
	int i = 0;
	int result = 0;
	for (; i < len; i++)
	{
		result ^= arr[i];
	}
	return result;
}
int main()
{
	int arr[] = { 1, 3, 5, 1, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int result = 0;
	result = Get_number(arr, len);
	printf("%d", result);
	system("pause");
	return 0;
}
//12.4有一个字符数组的内容为:"student a am i", 将数组的内容改为"i am a student".
#include<stdio.h>
#include<Windows.h>
void reverse(char *start, char *end)
{
	char tmp = 0;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}
void String_reveverse(char *arr, int len)
{
	char *left = arr;
	char *right = arr + len - 1;
	char *cur = arr;
	reverse(left, right);
	while (*cur != '\0')
	{
		left = cur;
		while (*cur != ' '&& *cur != '\0')
		{
			cur++;
		}
		reverse(left, cur - 1);
		if (*cur == ' ')
		{
			cur++;
		}
	}
}
int main()
{
	int i = 0;
	char arr[] = "student a am i";
	int len = sizeof(arr) / sizeof(arr[0]) - 1;//需要减去\0字符
	String_reveverse(arr, len);
	for (i = 0; i < len; i++)
	{
		printf("%c", arr[i]);
	}
	system("pause");
	return 0;
}
//day13###########################################################################
//13.1杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在，并返回其地址。
//时间复杂度小于O(N);
void Search(int arr[][3], int *px, int *py, int num)
{
	int j = *py - 1;
	int i = 0;
	while (i < *px && j >= 0)
	{
		if (num > arr[i][j])
		{
			i++;
		}
		else if (num < arr[i][j])
		{
			j--;
		}
		else
		{
			*px = i;
			*py = j;
			return;
		}
	}
	*px = -1;
	*py = -1;
}

int main()
{
	int x = 3;
	int y = 3;
	int arr[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	Search(arr, &x, &y, 5);
	printf("得到该数字下标为<%d,%d>\n", x, y);
	system("pause");
	return 0;
}
//13.2输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。
void Function(int *arr, int len)
{
	int left = 0;
	int right = len - 1;
	int tmp = 0;
	while (left < right)
	{
		while (left < right && arr[right] % 2 == 0)
		{
			right--;
		}
		while (left < right && arr[left] % 2 == 1)
		{
			left++;
		}
		if (left < right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
int main()
{
	int i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Function(arr, len);
	for (i = 0; i < len; i++)
	{
		printf(" %d ", arr[i]);
	}
	system("pause");
	return 0;
}
//day14######################################################################################################
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC


//14.2
#include<string.h>
int Left_Reverse(char *arr,const char *_arr,int len)
{
	char arr_1[30] = { 0 };
	strcpy(arr_1, arr);
	strcat(arr_1, arr);
	if (strstr(arr_1, _arr) == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	char arr[] = "ABCDEFG";
	const char _arr[] = "CDEFGAB";
	int len = sizeof(arr) / sizeof(arr[0])-1;
	int x = Left_Reverse(arr,_arr,len);
	if (x == 0)
	{
		printf("不是该字符串的旋转字符！\n");
	}
	else
	{
		printf("是该字符串的旋转字符！\n");
	}
	system("pause");
	return 0;
}

//14.1
void reverse(char *left, char *right)
{
	char tmp = 0;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void Left_Reverse(char *arr, int len, int k)
{
	//防御性检查
assert(arr != NULL || k <= len);//Debug
if (arr == NULL || k > len)
{
	return;
}
	reverse(&arr[0], &arr[k - 1]);
	reverse(&arr[k], &arr[len - 1]);
	reverse(&arr[0], &arr[len - 1]);
}
void Left_Reverse(char *arr,int len, int k)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < k; i++)
	{
		tmp = arr[0];
		for (j = 0; j < len-1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[len - 1] = tmp;
	}
}
int main()
{
	char arr[] = "ABCDEFG";
	int len = sizeof(arr) / sizeof(arr[0])-1;
	Left_Reverse(arr,len,4);
	printf("%s", arr);
	system("pause");
	return 0;
}

//day15############################################################################3
//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。
//
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
//
//3.模拟实现strcpy
//4.模拟实现strcat


//15.4*****
char * _Strcat(char *strDest, const char *strSrc)
{
	char *cp = strDest;
	while (*cp != '\0')
	{
		cp++;
	}
	while (*cp++ = *strSrc++)
		;
	return strDest;
}
int main()
{
	char strdest[20] = "ABCDEFG";
	const char strsrc[20] = "abcdefg";
	_Strcat(strdest, strsrc);
	printf("%s", strdest);
	system("pause");
	return 0;
}

//15.3*******
char * _Strcpy(char *strDest, const char *strSrc)
{
	char *cp = strDest;
	while (*cp++ = *strSrc++)
		;
	return strDest;
}
char * My_Strcpy(char *strDest, const char *strSrc)
{
	int i = 0;
	for (i = 0; strSrc[i] != '\0'; i++)
	{
		strDest[i] = strSrc[i];
	}
	strDest = '\0';
	return (strDest);
}
int main()
{
	char strdest[20] = { 0 };
	const char strsrc[20] = "abcdefg";
	_Strcpy(strdest, strsrc);
	printf("%s", strdest);
	system("pause");
	return 0;
}

//15.1********
void Find_Number(int *arr, int len, int *num_1, int *num_2)
{
	int i = 0;
	int sum = 0;
	int differ_bit = 0;//用来存放找到的不同比特位
	for (i = 0; i < len; i++)
	{
		sum ^= arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if ((sum >> i) & 1)
		{
			differ_bit = i;
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		if ((arr[i] >> differ_bit) & 1)
		{
			*num_1 ^= arr[i];
		}
		else
		{
			*num_2 ^= arr[i];
		}
	}
}
int main()
{
	int arr[] = { 23, 23, 45, 49, 78, 78 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int num_1 = 0;
	int num_2 = 0;
	Find_Number(arr, len, &num_1, &num_2);
	printf("%d %d", num_1, num_2);
	system("pause");
	return 0;
}

//15.2***
int Drink(int money)
{
	int count = money;
	int empty = money;
	while (empty >= 2)
	{
		count += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	return count;
}
int main()
{
	printf("可以喝到%d瓶饮料\n", Drink(20));
	system("pause");
	return 0;
}

//day16#############################################################################
//1.实现strcpy
//2.实现strcat
//3.实现strstr
//4.实现strchr
//5.实现strcmp
//6.实现memcpy
//7.实现memmove

//16.7*
void *_memmove(void *dst, const void *src, int num)
{
	if ((dst == NULL) && (src == NULL))
	{
		return NULL;
	}
	char *pdst = (char *)dst;
	char *psrc = (char *)src;
	if (psrc < pdst)
	{
		while (num--)
		{
			*pdst++ = *psrc++;
		}
	}
	else if (psrc > pdst)
	{
		psrc += num - 1;
		pdst += num - 1;
		while (num--)
		{
			*pdst-- = *psrc--;
		}
	}
	*pdst = '\0';
	return dst;
}

int main()
{
	char dst[20];
	char src[20] = "123456";
	char *p = _memmove(dst, src, 5);
	printf("%s", p);
	system("pause");
	return 0;
}

//16.6*
void *_memcpy(void *str1, const void *str2, int num)
{
	if ((str1 == NULL) && (str2 == NULL))
	{
		return NULL;
	}
	char *pstr1 = (char *)str1;
	char *pstr2 = (char *)str2;
	while (num--)
	{
		*pstr1++ = *pstr2++;
	}
	*pstr1 = '\0';
	return str1;
}
int main()
{
	char str1[20];
	char str2[20] = "123456";
	char *p = _memcpy(str1, str2, 5);
	printf("%s", p);
	system("pause");
	return 0;
}


//16.5*
int _strcmp(const char *str1, const char *str2)
{
	while ((*str1 == *str2) && *str1 != '\0')
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main()
{
	char str1[10] = "abcdef";
	char str2[10] = "abcdef";
	int num = _strcmp(str1, str2);
	if (num == 0)
	{
		printf("两个字符串相等！\n");
	}
	else if (num < 0)
	{
		printf("str1<str2\n");
	}
	else
	{
		printf("str1>str2\n");
	}
	system("pause");
	return 0;
}

//16.4*
char *_strchr(char *str, char ch)
{
	if (str == NULL)
	{
		return NULL;
	}
	while (str != '\0')
	{
		if (*str == ch)
		{
			return str;
		}
		else
		{
			str++;
		}
	}
	return NULL;
}
int main()
{
	char str[20] = "abcdefg";
	char ch = 'd';
	char *p = 0;
	p = _strchr(str, ch);
	if (p)
	{
		printf("%s", p);
	}
	else
	{
		printf("not find %c", ch);
	}
	system("pause");
	return 0;
}

//16.3*
char *_strstr(char *str1, const char *str2)
{
	while (str1 != '\0')
	{
		char *p = str1;
		while (*str1 == *str2 && str1 != '\0')
		{
			str1++;
			str2++;
		}
		if (!*str2)
		{
			return p;
		}
		if (!*str1)
		{
			return NULL;
		}
		str1++;
	}
	return NULL;
}
int main()
{
	char str_1[10] = "abcdef";
	const char str_2[10] = "cde";
	char *p = _strstr(str_1, str_2);
	if (p)
	{
		printf("%s", p);
	}
	else
	{
		printf("不是该串的字串！");
	}
	system("pause");
	return 0;
}