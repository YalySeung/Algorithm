// Programmers_Bruteforce_PrimeNumber.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <math.h>

using namespace std;

int inputLength;
unordered_set<int> targetNumbers;

bool isPrimeNumber(int number) {
	bool ret = true;
	if (number < 2) ret = false;

	for (size_t i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0) {
			ret = false;
			break;
		}
	}
	return ret;
}

void makeSet(string numberStr) {
	sort(numberStr.begin(), numberStr.end());
	do
	{
		if (numberStr.length() == 0) return;
		targetNumbers.insert(stoi(numberStr));
	} while (next_permutation(numberStr.begin(), numberStr.end()));
}

void makeNumber(string numbers, int checkIndex) {
	if (checkIndex >= numbers.length())
	{
		makeSet(numbers);
		return;
	}

	makeNumber(numbers, checkIndex + 1);
	makeNumber(numbers.erase(checkIndex, 1), checkIndex);
}

int solution(string numbers) {
	int answer = 0;
	inputLength = numbers.size();
	makeNumber(numbers, 0);

	for (unordered_set<int>::iterator it = targetNumbers.begin(); it != targetNumbers.end(); it++)
	{
		if (isPrimeNumber(*it)) answer++;
	}
	return answer;
}

int main()
{
	//cout << solution("17") << endl;
	cout << solution("002") << endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
