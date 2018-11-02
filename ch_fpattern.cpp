
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int FindMaxPattern(int* dstPos, int* dstLen, const char* sSrc, int lenSrc)
{
	//char	sSrc[]="abcbabdbe";

	int		retMax = 0;			// ��¿� �ִ� ���� ����
	int		retCnt = 0;			// ��¿� �ִ� ���� ����
	int		retLen = 0;			// ��¿� ���� ���� Ű ����
	char*	retDst = NULL;		// ��¿� ���� ���� ���� ��ġ

	int		ptnCnt = 0;			// �ӽ� ���� ����
	int		ptnMax = 0;			// �ӽ� ���� �ִ� ����
	char*	ptnKey = NULL;		// ���� Ű
	char*	ptnBgn = NULL;		// ���� ���� ��ġ


	int		n=0, k=0, i=0;
	int		end = 0;
	int		lenKey = 0;			// ���� Ű ����


	char	sAsc[128]= {0};		// ���� �ϳ� üũ��.


	*dstPos = -1;
	*dstLen = 0;


	if(NULL == sSrc || 1>=lenSrc)
		goto END;



	// �Է� ���ڿ� ������ ���ݸ� ����
	for(n=0; n<lenSrc/2; ++n)
	{
		++lenKey;

		end = lenSrc - lenKey;	// ������ ���

		for(k=0; k<end; ++k)
		{

			// Key ����

			ptnBgn = (char*)(sSrc+k);

			//[A-Za-z0-9] �� �ƴϸ� �ǳʶڴ�.			
			if( ('A' > *ptnBgn || *ptnBgn > 'Z') &&
				('a' > *ptnBgn || *ptnBgn > 'z') &&
				('0' > *ptnBgn || *ptnBgn > '9') &&
				('A' > *ptnBgn || *ptnBgn > 'z')
				)
				continue;

			if(1 == lenKey)
			{
				if( 0 != sAsc[*ptnBgn])
					continue;

				sAsc[*ptnBgn] = 1;
			}


			// Key ��ġ ����
			ptnKey = ptnBgn;


			// ���� ���� �ʱ�ȭ
			ptnCnt = 0;
			ptnMax = 0;


			// Key �� ������� ��ġ+ Ű ���� �ٷ� �������� ã�� ����
			for(i= k+lenKey; i< end+1; )
			{
				if(0 == strncmp(sSrc+i, ptnKey, lenKey) )
				{
					++ptnCnt;
					 i += lenKey;	// Ű�� ã�Ҵٸ� ���̸�ŭ ����
				}
				else
					 ++i;			// ��ã���� 1����
			}

			if(0<ptnCnt)
			{
				++ptnCnt;	// ������ 2�� �̻� ���;� �ϹǷ�...
				ptnMax = ptnCnt * lenKey;
			}


			//M�� ���ٸ� �ݺ�Ƚ���� �� ���� �ݺ����ڿ��� ����Ѵ�.
			//M�� ���� �ݺ�Ƚ���� �����ϴٸ� �տ� ���� ���ڿ��� ����Ѵ�.

			// ���� ���� ū ������ ã�´�.
			if(    retMax < ptnMax
			//	|| (retMax == ptnMax && ptnLen < lenKey)
				)
			{
				retMax = ptnMax;
				retCnt = ptnCnt;

				retLen = lenKey;
				retDst = ptnKey;
			}

			// ���� ó���ϴ� ���ڿ����� ������ ������ �������� ����.
			if(1 == ptnCnt)
				goto END;
		}
	}


	if(0<retMax)
	{
		*dstPos = retDst - sSrc;
		*dstLen = retLen;
	}

END:
	return retCnt;
}


int PatternTest()
{
	char*	sExam[] =
	{
		"abcde ",
		"12aaaaaaaaaaaaaaaaaaaaaaaaaaaa",
		"ab12ab12abab1212 ",
		NULL,
	};



	for(int n=0; NULL != sExam[n]; ++n)
	{
		char*	src    = sExam[n];
		int		srcLen = strlen(src);
		int		dstPos = -1, dstLen = -1;

		int	r = FindMaxPattern(&dstPos, &dstLen, src, srcLen );

		if(0<r)
		{
			printf("Pattern: ");
			fwrite(src+ dstPos, sizeof(char), dstLen, stdout);
			printf(":%d\n", r);
		}

		else
			printf("Pattern: NULL\n");
	}


	return 0;
}



int PatternConsole()
{
	int		lenBuf = 1024 * 1024;
	int		lenRead = 1;

	char*	sSrc = NULL;


	sSrc = (char*)malloc(lenBuf +4);
	memset(sSrc, 0, lenBuf +4);


	while(1)
	{
		printf("���� ã��: �����Ϸ��� \'q\'�� �Է��ϼ���.\n");

		memset(sSrc, 0, lenRead);
		fgets(sSrc, lenBuf, stdin);

		lenRead = strlen(sSrc);

		if(2 >= lenRead)
		{
			if('q' == *sSrc)		// ���α׷� ����
				break;

			else					// ���̰� ª��
			{
				printf("���̰� ª�ƿ�.\n");
				continue;
			}
		}

		sSrc[lenRead] = 0;			// ���� ���� ó��
		--lenRead;


		int	dstPos = -1, dstLen = -1;
		int	r = FindMaxPattern(&dstPos, &dstLen, sSrc, lenRead );

		if(0<r)
		{
			printf("Pattern: ");
			fwrite(sSrc+ dstPos, sizeof(char), dstLen, stdout);
			printf(":%d\n", r);
		}

		else
			printf("Pattern: NULL\n\n");
	}


	printf("���α׷� ����\n");

	free(sSrc);

	return 0;
}



int PatternFile(int argc, char** argv)
{
	char*	sFileSrc = "F:/in.txt";
	char*	sFileDst = "F:/out.txt";

	char*	sSrc = NULL;
	FILE*	fi = NULL;			// source file
	FILE*	fo = NULL;			// dest file

	int		lenBuf = 0;
	int		lenRead = 1;


	if(3 > argc)
	{
		printf(	"Error:�μ��� �����ϴ�. "
				"�Է� ������ %s ��� ������ %s�� ��ó �մϴ�.\n"
				, sFileSrc, sFileDst
				);

		fi = fopen(sFileSrc, "rt");
		fo = fopen(sFileDst, "wt");
	}
	else
	{
		char*	sFileSrc = argv[1];
		char*	sFileDst = argv[2];

		fi = fopen(argv[1], "rt");	// source file
		fo = fopen(argv[2], "wt");	// dest file
	}


	if(NULL == fi)
	{
		printf("�Է� ������ �� �� �����ϴ�.\n");
		return 0;
	}


	if(NULL == fo)
	{
		printf("��� ������ �� �� �����ϴ�.\n");
		return 0;
	}

	fseek(fi, 0, SEEK_END);
	lenBuf = ftell(fi);
	fseek(fi, 0, SEEK_SET);


	sSrc = (char*)malloc( 4* ( (lenBuf +7)/4 ) );
	memset(sSrc, 0, 4* ( (lenBuf +7)/4 ) );


	lenRead = fread(sSrc, sizeof(char), lenBuf, fi);


	int	dstPos = -1, dstLen = -1;
	int	r = FindMaxPattern(&dstPos, &dstLen, sSrc, lenRead );


	if(0<r)
	{
		fwrite(sSrc+ dstPos, sizeof(char), dstLen, fo);
		fprintf(fo, ":%d\n", r);

		fwrite(sSrc+ dstPos, sizeof(char), dstLen, stdout);
		printf(":%d\n", r);
	}
	else
	{
		fprintf(fo, "NULL\n");
		printf("Pattern: NULL\n\n");
	}


	free(sSrc);

	fclose(fi);
	fclose(fo);

	return 0;
}




int main(int argc, char** argv)
{
	PatternTest();
	//PatternConsole();
	//PatternFile(argc, argv);

	return 0;
}

