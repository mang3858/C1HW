/*
주어진 단어가 palindrome인지를 판별하는 프로그램을 작성하라.
palindrome은 madam나 abccba처럼 앞에서부터 읽으나 뒤에서부터 읽으나 동일한 단어를 의미한다
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define MAX_STRING 81 
#define BOOL int 
#define TRUE 1 
#define FALSE 0 

// Palindrome 검사
BOOL isPalindrome(char str[]);
int main(void)

{
	char str[MAX_STRING];

	printf("* Palindrome 체크\n\n");
	printf("문자열 입력(문자수 %d 이하): ", MAX_STRING);
	scanf("%s", str);

	if (isPalindrome(str)) // Palindrome 검사
		printf("\"%s\" is a Palindrome\n\n", str); // “를 출력하려면 \”를 써야함
	else
		printf("\"%s\" isn't a Palindrome\n\n", str);
	
	return 0;
}
BOOL isPalindrome(char s[])
{
	//문자열 s를(사실은 s는 포인터이지만, 이는 2학기때 배운다)
	//체크해서 palindrome이면 TRUE값을 palindrome아니면 FALSE값을 return한다
	int i, len;
	char rs[MAX_STRING];

	for (i = 0; s[i] != '\0'; i++);
	len = i;

	for (i = 0; s[i] != '\0'; i++)
		rs[i] = s[len - i - 1];
	rs[i] = '\0';

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == rs[i])
			return TRUE;
		else
			return FALSE;
	}

	/*
	for (j = 0; j < len / 2; j++)
		if (s[j] != s[i - j - 1])
			return FALSE;
	return TRUE;
	*/
		
}