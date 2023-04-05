#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20		/*���ܴ������������*/
#define MAX_INPUT 1000  /*�����������������*/


/*
 *�������ж�ȡ�ַ���
*/
int read_column_numbers(int columns[], int max)
{
	/*
	 *�ڶ������������ʱ��û�ж�������ĳ��ȣ��⵼�º����ᴦ���ָ��֮������ⳤ��
	 *���ڴ��е����ݣ����ǲ���ȫ�ģ�����һ�㶼��ͬʱ����һ����ʾ�����鳤�ȵı���
	*/

	int num = 0;
	int ch;  /*��ֹ������ַ����ⱻ���ͳ�EOF��������int����*/

	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] > 0)
		/*
		 *����scanf������˵�����˴ӱ�׼����ж�ȡһ���ַ���֮�⣬��������£�
		 *����Ҫ�ڱ���֮ǰ��һ��&����
		*/
	{
		num++;/*ʹ��whileʱͨ��������++����*/
	}

	if (num % 2 != 0)/*num���Ա�ʾ�Ѿ���ȡ�ĸ���*/
	{
		puts("Last column number is not paired!");
		/*
		 *gets������汾�����ַ����������׼����У�����ĩβ���һ������
		 *gets�������з��������ַ�����ĩβ��һ��NUL��Ϊ��ֹ��
		*/
		exit(EXIT_FAILURE);/*ֱ���˳��޷���ֵ*/
	}

	while ((ch = getchar()) != EOF && ch != '\n');/*���˵������������*/

	return num;
}

/*
 *����������ַ���
*/
void rearrange(char* output, char* const input, int const columns[], int num_column)
{
	int length = strlen(input);
	int output_column = 0;     /*output������±�*/

	for (int column = 0; column < num_column; column += 2)
		/*
		 * forѭ���е�һ���ֳ�ʼ��ִֻ��һ�Σ��ڶ�������ÿ��ѭ��֮ǰִ�У�
		 * ����������ÿ��ѭ��֮��ִ��
		*/
	{
		int nchars = columns[column + 1] - columns[column] + 1;
		/*
		 *������н�������������������Ѿ�����(ͨ�������±����ж�)
		*/
		if (output_column > MAX_INPUT - 1 || columns[column] > length)
		{
			break;
		}

		/*
		 *���������Ŀռ䲻�����ܴ���پʹ����
		*/
		if (nchars > MAX_INPUT - output_column - 1)
		{
			nchars = MAX_INPUT - output_column - 1;
		}

		strncpy(output + output_column, input + columns[column], nchars);
		output_column += nchars;
	}

	output[output_column] = '\0';/*�ַ�������*/
}

int main()
{
	int columns[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];

	int num = read_column_numbers(columns, MAX_COLS);
	int index = 0;

	while (fgets(input, sizeof(input), stdin) != NULL && input[0] != '\n')
	{
		/*
		*ɾȥ����Ҫ�Ļ���
		*/
		if (input[strlen(input) - 1] == '\n')
			input[strlen(input) - 1] = '\0';
		printf("�����ַ�����%s\n", input);
		rearrange(output, input, columns, num);
		printf("����ַ�����%s\n", output);
	}
	return EXIT_SUCCESS;
}