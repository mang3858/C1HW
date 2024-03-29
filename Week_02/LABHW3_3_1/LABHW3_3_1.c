//함수화: 뼈대 코드를 완성하라
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10 
#include <stdio.h> 

char askReservation();
void printSeats(int s[], int size);
void processReservation(int s[], int size, int seatNumber);

int main(void) // 변경하지 마라
{
	int seatChoice;
	int seats[SIZE] = { 0 };

	printf("******좌석 예약 시스템******\n");

	while (askReservation() == 'y')
	{
		printSeats(seats, SIZE);

		printf("몇번째 좌석? ");
		scanf("%d", &seatChoice);

		processReservation(seats, SIZE, seatChoice);

		while (getchar() != '\n'); // 버퍼 비움
	}
}
char askReservation()
{
	char choice;
	printf("\n좌석을 예약하시겠습니까?(y/n) ");
	scanf("%c", &choice);
	return choice;
}
void processReservation(int s[], int size, int seatNumber)
{
	if (s[seatNumber - 1] == 0) {  
		s[seatNumber - 1] = 1;
		printf("예약되었습니다.\n");
	}
	else
		printf("이미 예약된 자리입니다\n");
}
void printSeats(int s[], int size)
{
	int i;
	printf("----------------------\n");
	printf(" 1 2 3 4 5 6 7 8 9 10\n");
	printf("----------------------\n");
	for (i = 0; i < SIZE; i++)
		printf("%2d", s[i]);
	printf("\n");
}

/*완성본 
#define SIZE 10 
#include <stdio.h> 
int main(void)
{
	int seatChoice;
	char choice; // 계속 여부 
	int seats[SIZE] = { 0 };
	int i;
	
	printf("******좌석 예약 시스템******\n");
	
	printf("\n좌석을 예약하시겠습니까?(y/n) ");
	scanf("%c", &choice);
	while (choice == 'y')
	{
		// 좌석표 출력 
		printf("----------------------\n");
		printf(" 1 2 3 4 5 6 7 8 9 10\n");
		printf("----------------------\n");
		for (i = 0; i < SIZE; i++)
			printf("%2d", seats[i]);
		printf("\n");
		
		printf("몇번째 좌석? ");
		scanf("%d", &seatChoice);
		
		if (seats[seatChoice - 1] == 0) { //예약 가능이면 
			seats[seatChoice - 1] = 1;
			printf("예약되었습니다.\n");
		
		// 예약내용 반영한 좌석표 출력 
			printf("----------------------\n");
			printf(" 1 2 3 4 5 6 7 8 9 10\n");
			printf("----------------------\n");
			for (i = 0; i < SIZE; i++)
				printf("%2d", seats[i]);
			printf("\n");
		}
		else // 이미 예약되었으면 
			printf("이미 예약된 자리입니다.\n");
		
		while (getchar() != '\n'); //getchar()는 하나 문자입력
		
		printf("\n좌석을 예약하시겠습니까?(y/n) ");
		scanf("%c", &choice);
	}
}
*/