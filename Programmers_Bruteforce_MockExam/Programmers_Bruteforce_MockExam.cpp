// Programmers_Bruteforce_MockExam.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> inputAnswers;

struct compare {
	bool operator()(pair<int, int> pre, pair<int, int> post) {
		return pre.second < post.second;
	}
};

int countCorrect(vector<int> pattern) {
	int count = 0;
	for (int i = 0; i < inputAnswers.size(); i++)
	{
		if (inputAnswers.at(i) == pattern.at(i % pattern.size())) count++;
	}
	return count;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	inputAnswers = answers;
	int maxValue = 0;

	pq.push(make_pair(1, countCorrect({ 1,2,3,4,5 })));
	pq.push(make_pair(2, countCorrect({ 2,1,2,3,2,4,2,5 })));
	pq.push(make_pair(3, countCorrect({ 3,3,1,1,2,2,4,4,5,5 })));

	maxValue = pq.top().second;
	answer.push_back(pq.top().first);
	pq.pop();

	while (!pq.empty())
	{
		if (pq.top().second < maxValue) break;
		answer.push_back(pq.top().first);
		pq.pop();
	}

	sort(answer.begin(), answer.end());

	return answer;
}

int main()
{
	vector<int> answer = solution({ 1,3,2,4,2 });
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer.at(i) << endl;
	}
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
