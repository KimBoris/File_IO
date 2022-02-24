#define _CRT_SECURE_NO_WARNINGS;
#include <stdio.h>
#include <stdlib.h>	
#include <string.h>



//파일 입출력
/*  

File이란 ? 
1. 가장 흔한 보편적인 파일 (1)- mp3, avi, txt ... >> 데이터 파일
						 (2)- exe, dll파일 >> 실행파일

2. USERMODE에서 커널모드로 진입할 수 있는 인터페이스

<FILE의 특징>
- 파일마다 고유의 I/O버퍼가 있다. 

<FILE SYSTEM>
- 데이터 파일, 실행 파일들을 관리하는 체계를 뜻한다.
 
 ex) FAT, NTFS
 FAT = File Allocation Table  >> USB같은것들

NTFS = 윈도우 

<HDD>
- 자기 원판 = 금속성을 되어있어 HARD DISK DIVER이다 .

<테잎방식>
 - 플로피디스크
 - 원판 처럼 생겨 트랙과섹터로 나눠진다.
 - 한트랙은 원판을 둘러싸고있는 한줄의 원이며
 - 섹터는 원판내부를 자른구역을 나눈것이다.
 - 보통 섹터는 512BYTE이다

 TEST.AVI 파일을 저장할 때에
 시작지점을 기준으로 이어서 데이터 저장이 되지만 만약 사용해야하는 데이터 자리에 이미 다른 데이터가 
 저장되어있다면 그 데이터를 뛰어넘어서 저장된다. 
 FAT = 데이터가 시작된 지점을 나타낸 테이블 
 TEST.AVI의 크기가 32BIT이면 FAT32
				  16BIT이면 FAT16이다. 


				  <운영체제 설치할 때>
				  1. FILE SYSTEM 을 무엇으로 할 지 결정
				  2. NFTS -> C,D드라이브 나눈후
				  3. 포맷 -> 텅빈 디스크에 트랙과 섹터로 나눠주어 관리할수 있도록 하는것

				  
*이 책에서는 데이터, 실행, TEXT > FILE SYSTEM이 관리 ( 커널에 존재한다 ) 등 다루는 방법을 교육한다.

다루는 방법 > 1. 개방, 2. 폐쇄, 3. I/O




<파일 구조>

FILE = 논리구조가 '선형 구조'이다 떄문에 STREAMING이 된다.

TMI... STREAMING 이야기가 나오면 머리속에 BUFFER를 생각하고 BUFFER가 나오면 QUEUE구조를 생각해야한다
- 보통 QUEUE구조로 되어있다.
즉, FILE STREAM > BUFFER > QUEUE구조

FILE이라고 하는것은 DISK(보조 기억장치)를 사용하는 방법 중 하나
> DISK를 쓰기 위해서 FILE을 사용한다.

<DISK>
- 공간 크기 : 넓다
- 속도 : 느리다

<RAM>
- 공간 크기 : 작다
- 속도 : 빠르다.


* 테잎 구조로 되어있는 디스크를 한줄로 쭉 이어주면 선형 구조가 된다.
(기본적으로 DISK, 램, 메모리등은 선형구조를 가진다.)


<FILE I/O지점>

FILE의 I/지점이 있다.
1. ㅁㅁㅁㅁㅁㅁㅁ
      ㅅ
	  ㅣ  (시작지점)    이러한 디스크에 시작지점이 있다

2. 시작지점으로부터 개방(생성)한다.
3. 개방(생성) 당시의 공간의 크기 = 0
4. 크기가 0이면 공간이 있다는 것인가?
ㅁㅁㅁㅁㅁㅁ >> 이 전체가 공간임

크기가 0인 공간에 WRITE를 하게 되면 디스크 전체 공간에서 
사용한 공간만큼 빼준다.

ㅁㅁ7ㅁㅁㅁ
	ㅅ
	ㅣ (시작지점)
5. FILE에 위와같이 WRITE가 일어나면
I/O지점이 한칸 밀린다. 
6. 사용된 메모리에 이어서 WRITE되고 크기는 자동으로 커지게 되있다.


* 변수, 메모리 동적 = RAM
* FILE             = DISK  
를 사용하는 방법이다

*또한, 원래 '폴더'가 아닌 '디렉토리'였는데 윈도우 95에서 바꿔버림















//int main(void)
//{
//	//파일 입출력
//	//FileOpen.c
//
//	//파일 제어에 필요한 FILE구조체에 대한 포인터 변수 선언 및 정의
//	FILE* fp = NULL;
//	//test.txt파일을 쓰기 모드로 개방.
//	//단, 같은 이름의 파일이 이미 존재하면 삭제(크기를 0으로 수정하고) 새파일 생성
//	//없다면 새로 생성
//
//	//fp = fopen( "Test.txt", "w"); // "w" = 쓰기모드 기존의 파일을 지우고 새로 작성
//	//if (fp == NULL)
//	//{
//	//	puts("Error : Falied to open file!");
//	//	return;
//	//}
//	////TODO : File I/O
//
//	////개방한 파일을 닫는다.
//	//fclose(fp);
//
//
//
//
//	///아래 식은 _fcloseall()함수를 선언한 상태
//
//	int nClosed = 0;
//	fopen_s(&fp,"Test1.txt", "w");
//	fopen_s(&fp,"Test2.txt", "w");
//	fopen_s(&fp,"Test3.txt", "w");
//
//	//지금까지 개방한 파일들을 모두 닫는다.
//	//FILE*는 필요없다
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

int main(void)
{
	//'w' -> 무조건 생성. 이미 존재하면 삭제하고 생성.
	//FILE* fp = fopen_s(&fp, "Test.txt", "w");

	FILE* fp = fopen_s(&fp, "CON", "w");  //중간 매개변수에 CON을 적는다면
										 //파일이 열리지않고 콘솔에 작성한 문자가 출력된다. 
										//CON = 콘솔이라는 추상적인 단어
										//PRN = 프린터로 찍는것
										//COM1 = 시리얼 포트로 데이터나간다. 
	//이런것이 디바이스 파일이다.

										

	fprintf_s(fp,  "HelloFile I/O");
	fclose(fp);
	system("Text.txt");




	return 0;
}