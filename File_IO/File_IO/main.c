#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	
#include <string.h>



//���� �����
/*  

File�̶� ? 
1. ���� ���� �������� ���� (1)- mp3, avi, txt ... >> ������ ����
						 (2)- exe, dll���� >> ��������

2. USERMODE���� Ŀ�θ��� ������ �� �ִ� �������̽�

<FILE�� Ư¡>
- ���ϸ��� ������ I/O���۰� �ִ�. 

<FILE SYSTEM>
- ������ ����, ���� ���ϵ��� �����ϴ� ü�踦 ���Ѵ�.
 
 ex) FAT, NTFS
 FAT = File Allocation Table  >> USB�����͵�

NTFS = ������ 

<HDD>
- �ڱ� ���� = �ݼӼ��� �Ǿ��־� HARD DISK DIVER�̴� .

<���ٹ��>
 - �÷��ǵ�ũ
 - ���� ó�� ���� Ʈ�������ͷ� ��������.
 - ��Ʈ���� ������ �ѷ��ΰ��ִ� ������ ���̸�
 - ���ʹ� ���ǳ��θ� �ڸ������� �������̴�.
 - ���� ���ʹ� 512BYTE�̴�

 TEST.AVI ������ ������ ����
 ���������� �������� �̾ ������ ������ ������ ���� ����ؾ��ϴ� ������ �ڸ��� �̹� �ٸ� �����Ͱ� 
 ����Ǿ��ִٸ� �� �����͸� �پ�Ѿ ����ȴ�. 
 FAT = �����Ͱ� ���۵� ������ ��Ÿ�� ���̺� 
 TEST.AVI�� ũ�Ⱑ 32BIT�̸� FAT32
				  16BIT�̸� FAT16�̴�. 


				  <�ü�� ��ġ�� ��>
				  1. FILE SYSTEM �� �������� �� �� ����
				  2. NFTS -> C,D����̺� ������
				  3. ���� -> �ֺ� ��ũ�� Ʈ���� ���ͷ� �����־� �����Ҽ� �ֵ��� �ϴ°�

				  
*�� å������ ������, ����, TEXT > FILE SYSTEM�� ���� ( Ŀ�ο� �����Ѵ� ) �� �ٷ�� ����� �����Ѵ�.

�ٷ�� ��� > 1. ����, 2. ���, 3. I/O




<���� ����>

FILE = �������� '���� ����'�̴� ������ STREAMING�� �ȴ�.

TMI... STREAMING �̾߱Ⱑ ������ �Ӹ��ӿ� BUFFER�� �����ϰ� BUFFER�� ������ QUEUE������ �����ؾ��Ѵ�
- ���� QUEUE������ �Ǿ��ִ�.
��, FILE STREAM > BUFFER > QUEUE����

FILE�̶�� �ϴ°��� DISK(���� �����ġ)�� ����ϴ� ��� �� �ϳ�
> DISK�� ���� ���ؼ� FILE�� ����Ѵ�.

<DISK>
- ���� ũ�� : �д�
- �ӵ� : ������

<RAM>
- ���� ũ�� : �۴�
- �ӵ� : ������.


* ���� ������ �Ǿ��ִ� ��ũ�� ���ٷ� �� �̾��ָ� ���� ������ �ȴ�.
(�⺻������ DISK, ��, �޸𸮵��� ���������� ������.)


<FILE I/O����>

FILE�� I/������ �ִ�.
1. ��������������
      ��
	  ��  (��������)    �̷��� ��ũ�� ���������� �ִ�

2. �����������κ��� ����(����)�Ѵ�.
3. ����(����) ����� ������ ũ�� = 0
4. ũ�Ⱑ 0�̸� ������ �ִٴ� ���ΰ�?
������������ >> �� ��ü�� ������

ũ�Ⱑ 0�� ������ WRITE�� �ϰ� �Ǹ� ��ũ ��ü �������� 
����� ������ŭ ���ش�.

����7������
	��
	�� (��������)
5. FILE�� ���Ͱ��� WRITE�� �Ͼ��
I/O������ ��ĭ �и���. 
6. ���� �޸𸮿� �̾ WRITE�ǰ� ũ��� �ڵ����� Ŀ���� ���ִ�.


* ����, �޸� ���� = RAM
* FILE             = DISK  
�� ����ϴ� ����̴�

*����, ���� '����'�� �ƴ� '���丮'���µ� ������ 95���� �ٲ����
*/














//int main(void)
//{
//	//���� �����
//	//FileOpen.c
//
//	//���� ��� �ʿ��� FILE����ü�� ���� ������ ���� ���� �� ����
//	FILE* fp = NULL;
//	//test.txt������ ���� ���� ����.
//	//��, ���� �̸��� ������ �̹� �����ϸ� ����(ũ�⸦ 0���� �����ϰ�) ������ ����
//	//���ٸ� ���� ����
//
//	//fp = fopen( "Test.txt", "w"); // "w" = ������ ������ ������ ����� ���� �ۼ�
//	//if (fp == NULL)
//	//{
//	//	puts("Error : Falied to open file!");
//	//	return;
//	//}
//	////TODO : File I/O
//
//	////������ ������ �ݴ´�.
//	//fclose(fp);
//
//
//
//
//	///�Ʒ� ���� _fcloseall()�Լ��� ������ ����
//
//	int nClosed = 0;
//	fopen_s(&fp,"Test1.txt", "w");
//	fopen_s(&fp,"Test2.txt", "w");
//	fopen_s(&fp,"Test3.txt", "w");
//
//	//���ݱ��� ������ ���ϵ��� ��� �ݴ´�.
//	//FILE*�� �ʿ����
//
//	nClosed = _fcloseall();
//	printf("%d\n", nClosed);
//
//
//
//
//
//
//
//
//
//
//
//
//	return 0;
//}
//
//int main(void)
//{
//	//'w' -> ������ ����. �̹� �����ϸ� �����ϰ� ����.
//	//FILE* fp = fopen_s(&fp, "Test.txt", "w");
//
//	FILE *fp = fopen( "TXT", "w");  //�߰� �Ű������� CON�� ���´ٸ�
//										 //������ �������ʰ� �ֿܼ� �ۼ��� ���ڰ� ��µȴ�. 
//										//CON = �ܼ��̶�� �߻����� �ܾ�
//										//PRN = �����ͷ� ��°�
//										//COM1 = �ø��� ��Ʈ�� �����ͳ�����. 
//	//�̷����� ����̽� �����̴�.
//
//										
//
//	fprintf(fp,  "HelloFile I/O");
//	fclose(fp);
//	//system("Text.txt");
//
//
//
//
//	return 0;
//}


//Fileopen01.c
//void main()
//{
//	//���� ��� �ʿ��� FILE����ü�� ���� ������ ���� ���� �� ����
//	FILE* fp = NULL;
//	//test.txt ������ ���� ���� ����. ��, ���� �̸��� ������ �̹�
//	//�����ϸ� ����(ũ�⸦ 0���� ����) �ϰ� �� ������ �����Ѵ�.
//	//���ٸ� ���� �����Ѵ�.
//	fp = fopen("Test.txt", "w");
//	if (fp == NULL)
//	{
//		puts("ERROR : Failed to open file!");
//		return;
//	}
//
//	//TODO : FILE I/O
//
//
//	//������ ������ �ݴ´�.
//	fclose(fp);
//}




// _fcloseall()

//void main()
//{
//	FILE* fp = NULL;
//	int nClosed = 0;
//
//	fopen("Test1.txt", "w");
//	fopen("Test2.txt", "w");
//	fopen("Test3.txt", "w");
//
//	//���ݱ��� ������ ���ϵ��� '���'�ݴ´�.
//	nClosed = _fcloseall();
//	printf("%d", nClosed);
//
//}





//filefprint01.c
//void main()
//{
//	FILE* fp = NULL;
//	//���� ��ο� Test.txt������ �����Ѵ�.
//	fp = fopen("Test.txt", "w");
//	fprintf(fp, "%s\n", "Test string");
//	fprintf(fp, "%s\n", "Hello world!");
//
//	//������ �ݰ� �޸������� Ȯ���Ѵ�.
//	fclose(fp);
//	system("notepad.exe test.txt");
//
//}


//filefscanf01.c
//
//void main()
//{
//	int nData = 0;
//	char szBuffer[128] = { 0 };
//	FILE* fp = NULL;
//
//	//'�б�' ������ ���� ������ �����ϰ� 'Test'��� ���ڿ��� ����.
//	fp = fopen("fscanfTest.txt", "w");
//	fprintf(fp, "%d,%s\n", 20, "Test");
//	fclose(fp);
//
//	//������ �ٽ� ���� ����� ������ �о�´�.
//	fp = fopen("fscanfTest.txt", "r");
//	fscanf(fp, "%d,%s", &nData, &szBuffer);
//	fclose(fp);
//
//	//�о�� ������ ȭ�鿡 ���
//	printf("%d, %s\n", nData, szBuffer);
//	system("notepad.exe fcanfTest.txt");
//}




//filegetc()
//void main()
//{
//	FILE* fp = NULL;
//	char ch;
//
//	//���� ��ο� Test.txt������ �����ϰ� ���ڿ��� ����.
//	fp = fopen("Test.txt", "w");
//	fputs("Test string!", fp);
//	fclose(fp);
//
//	fp = fopen("Test.txt", "r");
//	if (fp == NULL)
//	{
//		return;
//	}
//
//	//���Ͽ��� �ѱ��ھ� �о�� �ٽ� �� ���ھ� ����Ѵ�.
//	while ((ch = fgetc(fp)) != EOF)
//	{
//		putchar(ch);
//
//	}  
//		fclose(fp);
//}








//Filefgets01.c

//void main()
//{
//	FILE* fp = NULL;
//	char szBuffer[512] = { 0 };
//
//	//������ ������ ���� ���� ���ڿ��� �� �� �ݴ´�.
//	fp = fopen("Test.txt", "w");
//	fputs("Test\n", fp);
//	fputs("String\n", fp);
//	fputs("Data\n", fp);
//	fclose(fp);
//
//	fp = fopen("Test.txt", "r");
//	if (fp == NULL)
//	{
//		return;
//	}
//	//���Ͽ��� �� �྿ �о�´�..
//	while (fgets(szBuffer, sizeof(szBuffer), fp))
//	{
//		printf("%s", szBuffer);
//		memset(szBuffer, 0, sizeof(szBuffer));
//	}
//	fclose(fp);
//}




//fflush()
//void main()
//{
//	//ǥ�� �Է���ġ ����(stdin)�� ����Ű�� ������ ���� ���� �� ����
//	FILE *fp = stdin;
//	printf("Input string : ");
//
//	//����ڷκ��� '���ڿ�'�� �Է¹��� �� ù ���ڸ� �о�� ����Ѵ�.
//	printf("getchar() - %c\n", getchar());
//
//	//���ۿ� �����ִ� ������ ������ ���뿡 ���� ������ ����Ѵ�.
//	printf("[%d] %s", fp->_cnt, fp->_base);
//	printf("READ : %d\n", fp->_ptr - fp->_base);
//	//�ٽ� �� ���ڸ� �о�� �� �޶��� ������ Ȯ���Ѵ�.
//	printf("%\n\ngetchar( ) - %c\n", getchar());
//	printf("[%d] %s", fp->_cnt, fp->_base);
//	printf("READ : %d\n", fp->_ptr - fp->_base);
//
//	//���� ����� ���۸� �ʱ�ȭ�� �� ����� Ȯ���Ѵ�.
//	fflush(fp);
//	printf("%\n\nAfter flushing\n[%d] %s", fp->_cnt - fp->_base);
//
//}







typedef struct _USERDATA
{
	char szName[16];
	char szPhone[16];

}USERDATA;

//void main()
//{
//	FILE* fp = NULL;
//	USERDATA UserData = { "Bong-Ki", "123-1234" };
//
//
//	//���̳ʸ� ���� ���� ������ ����(����)�Ѵ�.
//	fp = fopen("Test.dat", "wb");
//	if (fp == NULL)
//		return;
//
//	//����ü�� �ѹ��� ���̳ʸ� ���� ���Ͽ� ����.
//	fwrite(&UserData, sizeof(USERDATA), 1, fp);
//	fclose(fp);
//}

void main()
{
	FILE* fp = NULL;
	USERDATA UserData = { 0 };

	//���̳ʸ� �б� ���� ������ �����Ѵ�.
	//���� ������ ���ٸ� ������ ���µ� �����Ѵ�.
	fp = fopen("Test.dat", "rb");
	if (fp == NULL)
		return;

	//���Ͽ��� ���̳ʸ� ���� ����ü�� �� ���� �а�  ����Ѵ�.
	fread(&UserData, sizeof(UserData), 1, fp);
	puts(UserData.szName);
	puts(UserData.szPhone);
	fclose(fp);
}