#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void output_number(int number)
{
		if(number == 0)
		{
			system("echo 0 > /dev/myled0");
		}
		else if(number == 1)
		{
			system("echo 1 > /dev/myled0");
		}
		else if(number == 2)
		{
			system("echo 2 > /dev/myled0");
		}
		else if(number == 3)
		{
			system("echo 3 > /dev/myled0");
		}
		else if(number == 4)
		{
			system("echo 4 > /dev/myled0");
		}
		else if(number == 5)
		{
			system("echo 5 > /dev/myled0");
		}
		else if(number == 6)
		{
			system("echo 6 > /dev/myled0");
		}
		else if(number == 7)
		{
			system("echo 7 > /dev/myled0");
		}
		else if(number == 8)
		{
			system("echo 8 > /dev/myled0");
		}
		else if(number == 9)
		{
			system("echo 9 > /dev/myled0");
		}
}

void random_number(void)
{
	srand((unsigned int)time(NULL));
	system("echo r > /dev/myled0");
	output_number(rand() % 10);
}

int main(void)
{
	char command[100];
	int number;
	system("clear");
	printf("myledをロードします...\n");
	system("sudo insmod myled.ko");
	system("sudo chmod 666 /dev/myled0");
	printf("出力したい数値を入力してください\n");
	printf("*[0 ~ 9]まで出力できます\n");
	printf("*[0]を出力させる場合は[zero]と入力してください\n");
	printf("*[random]を入力する今日のラッキーナンバーが出力されます\n");
	printf("*[exit]を入力すると終了\n");

	while(1)
	{
		scanf("%s", command);

		if(!strcmp(command, "exit"))
		{
			break;
		}
		else if(!strcmp(command, "random"))
		{
			random_number();
			continue;
		}
		else if(!strcmp(command, "zero"))
		{
			output_number(0);
			continue;
		}

		number = atoi(command);
		if(number < 10 && number > 0)
		{
			output_number(number);
		}
		else
		{
			printf("対応した数字または文字ではありません\n");
		}
	}

	system("echo c > /dev/myled0");
	system("sudo rmmod myled");
	printf("myledをアンロードしました\n");
	return 0;
}
