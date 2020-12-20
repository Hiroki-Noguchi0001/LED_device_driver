#include <stdio.h>
#include <stdlib.h>

void output_number(char a)
{
		if(a == '0')
		{
			system("echo 0 > /dev/myled0");
		}
		else if(a == '1')
		{
			system("echo 1 > /dev/myled0");
		}
		else if(a == '2')
		{
			system("echo 2 > /dev/myled0");
		}
		else if(a == '3')
		{
			system("echo 3 > /dev/myled0");
		}
		else if(a == '4')
		{
			system("echo 4 > /dev/myled0");
		}
		else if(a == '5')
		{
			system("echo 5 > /dev/myled0");
		}
		else if(a == '6')
		{
			system("echo 6 > /dev/myled0");
		}
		else if(a == '7')
		{
			system("echo 7 > /dev/myled0");
		}
		else if(a == '8')
		{
			system("echo 8 > /dev/myled0");
		}
		else if(a == '9')
		{
			system("echo 9 > /dev/myled0");
		}
}

void random_number(void)
{
	system("echo r > /dev/myled0");
}

int main(void)
{
	char a;
	printf("myledをロードします...\n");
	system("sudo insmod myled.ko");
	system("sudo chmod 666 /dev/myled0");
	printf("出力したい数値を入力してください\n");
	printf("0 ~ 9まで出力できます\n");
	printf("cを入力すると終了します\n");

	while(1)
	{
		scanf("%c", &a);

		output_number(a);
		if(a == 'c')
		{
			break;
		}
		else if(a == 'r')
		{
			random_number();
		}

	}
	
	system("echo c > /dev/myled0");
	system("sudo rmmod myled");
	printf("myledをアンロードしました\n");
		return 0;
}
