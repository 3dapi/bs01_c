////////////////////////////////////////////////////////////////////////////////
//
// Explain: Pointer�� ���� �Ҵ�
// Alias '&'�� ȥ���ؼ� ����ϴ� ���� �� ����.


#include <stdio.h>
#include <memory.h>

int main()
{
	printf("new�� �̿��� �����Ҵ�\n\n");

	int array1[100];

	for(int i=0; i<100; ++i)
	{
		array1[i] = i;
	}

	int	*p = NULL;							// �������� ��� �׻� �� �����ͷ� �ʱ�ȭ �ϴ� ������ ������
	int iSize=100;
	(int*)p = (int*) new int[iSize];		// ĳ������ �ʿ��� ���� �ִ�.


	memcpy(p, array1, sizeof(int) * iSize);


	for(i=0; i<100; ++i)
	{
		printf("p[%d] = %d\n", i, p[i]);
	}


	if(p)
	{
		delete [] p;
		p = NULL;
	}


	int iWidth  = 100;
	int iHeight = 50;

	int **pp = NULL;


	pp = new int*[100];						//pp = (int**)new int[100]; �Ѵ� ����.

	for(i=0; i<100; ++i)
		pp[i] = new int[50];


	if(pp)
	{
		for(int i=0; i<100; ++i)
			delete [] pp[i];

		delete [] pp;
		pp = NULL;
	}



	int array3[10][5][2];


	for(i=0; i<10; ++i)
	{
		for(int j=0; j<5; ++j)
		{
			for(int k=0; k<2; ++k)
				array3[i][j][k] = k + j*2 + i*5*2;
		}
	}


//	for(i=0; i<10; ++i)
//	{
//		for(int j=0; j<5; ++j)
//		{
//			for(int k=0; k<2; ++k)
//				printf("array3[%d][%d][%d] = %d\n", i, j, k, array3[i][j][k]);
//		}
//	}


	printf("\n------------------------------------------------------------\n\n");

	iWidth  = 10;
	iHeight = 5;
	int iDepth	= 2;

	int ***ppp = NULL;

	ppp = (int***)new int[iWidth];

	for(i=0; i<iWidth; ++i)
	{
		ppp[i] = (int**)new int[iHeight];

		for(int j=0; j<iHeight; ++j)
		{
			ppp[i][j] = (int*)new int[iDepth];

			for(int k=0; k<iDepth; ++k)
				ppp[i][j][k] = k + j*2 + i*5*2;
		}
	}


// memcpy�� ���������� �޸𸮰� �Ҵ�� �������� �����ϴ�. �׷��� ��������
// �迭�� ��, ��, ���� ���� �޸𸮸� �������� �Ҵ������� �̵��� �ּҰ�
// ��� �޸𸮰� �������� �Ҵ������ �ʴ�.
// ���� ������ �ּ��� ������ �ݵ�� ����Ų��.

//	memcpy(ppp, array3, sizeof(int) * iWidth * iHeight * iDepth);

	for(i=0; i<iWidth; ++i)
	{
		for(int j=0; j<iHeight; ++j)
		{
			for(int k=0; k<iDepth; ++k)
				printf("array3[%d][%d][%d] = %d\n", i, j, k, ppp[i][j][k]);
		}
	}


	if(ppp)
	{
		for(int i=0; i<10; ++i)
		{
			for(int j=0; j<5; ++j)
			{
				delete [] ppp[i][j];
			}


			delete [] ppp[i];
		}

		delete [] ppp;
		ppp = NULL;
	}



	// ���� int x = 20 int y = 10 int z= 5 int w= 2���� �־��� ��
	// int array4[20][10][5][2]�� ������ 4�� ������ ****pppp�� �޸𸮸� �Ҵ��ϰ� �����϶�.

	return 1;
}