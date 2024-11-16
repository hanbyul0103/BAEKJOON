#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct RollCallPos {
	int floor;
	bool isRight;
};

struct CleaningInspectionPos {
	int floor;
	bool isRight;
};

struct Resident {
	int floor;
	bool isRight;
	string name;
	RollCallPos rollCallPos;
	CleaningInspectionPos cleaningInspectionPos;
};

vector<Resident> getResidents();
void RollCall(vector<Resident>& residents); // 점호 위치
void CleaningInspection(vector<Resident>& residents); // 청소 검사

int main() {
	srand(static_cast<unsigned int>(time(0)));

	vector<Resident> residents = getResidents();

	RollCall(residents);
}

vector<Resident> getResidents()
{
	vector<Resident> residents = {
		{2, false, "박민호"}, {2, false, "김대현"}, {2, true, "엄제유"},
		{3, false, "유근영"}, {3, false, "정세현"}, {3, true, "최찬호"},
		{4, false, "이정빈"}, {4, false, "승호성"}, {4, true, "김윤지"}, {4, true, "박아름"}
	};

	return residents;
}

void RollCall(vector<Resident>& residents) {
	vector<int> indices;
	map<pair<int, bool>, int> posCount; // 각 위치에 배정된 인원 수

	// 4층 오른쪽 주민 제외하고 인덱스 벡터 초기화
	for (int i = 0; i < residents.size(); ++i) {
		if (!(residents[i].floor == 4 && residents[i].isRight)) {
			indices.push_back(i);
		}
		else {
			// 4층 오른쪽 주민은 고정
			residents[i].rollCallPos = { 4, true };
		}
	}

	random_shuffle(indices.begin(), indices.end());

	posCount.clear(); // 각 주마다 배정된 인원 수 초기화

	vector<Resident*> weekResidents;

	// 각 층에 최소 한 명씩 배정
	for (int floor = 2; floor <= 4; ++floor) {
		if (floor == 4) continue; // 4층 우측은 고정

		bool isRight = rand() % 2;
		int idx;

		do {
			idx = indices.back();
			indices.pop_back();
		} while (residents[idx].floor == 4 && residents[idx].isRight); // 4층 우측 제외

		residents[idx].rollCallPos = { floor, isRight };
		posCount[{floor, isRight}]++;
		weekResidents.push_back(&residents[idx]);
	}

	// 나머지 주민들 배정
	for (int i = 0; i < indices.size(); ++i) {
		int idx = indices[i];
		int floor;
		bool isRight;

		do {
			floor = rand() % 3 + 2; // 2~4층 랜덤 선택
			isRight = rand() % 2;   // 좌측/우측 랜덤 선택
		} while ((floor == 4 && isRight) || posCount[{floor, isRight}] >= 2); // 4층 우측 제외, 각 위치에 최대 2명 배정

		residents[idx].rollCallPos = { floor, isRight };
		posCount[{floor, isRight}]++;
		weekResidents.push_back(&residents[idx]);
	}

	for (int i = 0; i < weekResidents.size(); ++i) {
		cout << weekResidents[i]->name << " -> " << weekResidents[i]->rollCallPos.floor << (weekResidents[i]->rollCallPos.isRight ? "R" : "L") << endl;
	}
	cout << endl;
}


void CleaningInspection(vector<Resident>& residents)
{

}