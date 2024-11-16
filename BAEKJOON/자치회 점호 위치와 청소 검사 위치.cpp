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
void RollCall(vector<Resident>& residents); // ��ȣ ��ġ
void CleaningInspection(vector<Resident>& residents); // û�� �˻�

int main() {
	srand(static_cast<unsigned int>(time(0)));

	vector<Resident> residents = getResidents();

	RollCall(residents);
}

vector<Resident> getResidents()
{
	vector<Resident> residents = {
		{2, false, "�ڹ�ȣ"}, {2, false, "�����"}, {2, true, "������"},
		{3, false, "���ٿ�"}, {3, false, "������"}, {3, true, "����ȣ"},
		{4, false, "������"}, {4, false, "��ȣ��"}, {4, true, "������"}, {4, true, "�ھƸ�"}
	};

	return residents;
}

void RollCall(vector<Resident>& residents) {
	vector<int> indices;
	map<pair<int, bool>, int> posCount; // �� ��ġ�� ������ �ο� ��

	// 4�� ������ �ֹ� �����ϰ� �ε��� ���� �ʱ�ȭ
	for (int i = 0; i < residents.size(); ++i) {
		if (!(residents[i].floor == 4 && residents[i].isRight)) {
			indices.push_back(i);
		}
		else {
			// 4�� ������ �ֹ��� ����
			residents[i].rollCallPos = { 4, true };
		}
	}

	random_shuffle(indices.begin(), indices.end());

	posCount.clear(); // �� �ָ��� ������ �ο� �� �ʱ�ȭ

	vector<Resident*> weekResidents;

	// �� ���� �ּ� �� �� ����
	for (int floor = 2; floor <= 4; ++floor) {
		if (floor == 4) continue; // 4�� ������ ����

		bool isRight = rand() % 2;
		int idx;

		do {
			idx = indices.back();
			indices.pop_back();
		} while (residents[idx].floor == 4 && residents[idx].isRight); // 4�� ���� ����

		residents[idx].rollCallPos = { floor, isRight };
		posCount[{floor, isRight}]++;
		weekResidents.push_back(&residents[idx]);
	}

	// ������ �ֹε� ����
	for (int i = 0; i < indices.size(); ++i) {
		int idx = indices[i];
		int floor;
		bool isRight;

		do {
			floor = rand() % 3 + 2; // 2~4�� ���� ����
			isRight = rand() % 2;   // ����/���� ���� ����
		} while ((floor == 4 && isRight) || posCount[{floor, isRight}] >= 2); // 4�� ���� ����, �� ��ġ�� �ִ� 2�� ����

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