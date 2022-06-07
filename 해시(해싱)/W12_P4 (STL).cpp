#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	map<string, string> list;  // 출석 상태를 저장하는 리스트
	// => 이름을 key 값으로, 출석여부 상태를 value 로 가진다. 즉, 학번이 아닌 이름으로 출석여부를 판단

	map<string, string> hash1;
	map<string, string> hash2;
	int present = 0; // 현재 출석 상태수

	int t;
	cin >> t;
	while (t--)
	{
		string a;
		cin >> a;
		if (a == "add")
		{
			string key, value;
			cin >> key >> value;
			hash1.insert(make_pair(key, value));
			hash2.insert(make_pair(value, key));

			list.insert(make_pair(value, "absent"));  // 이름으로 출석여부를 저장하기 위해 value 로 저장할것! 
		}
		else if (a == "delete")
		{
			string key;
			cin >> key;
			string key2 = hash1[key];  // 해시테이블1의 주어진 key 값의 value 로부터 해시테이블2 의 key 값을 얻어옴 
			if (list[key2] == "present") // 출석 상태인 경우
			{
				present--;
			}
			hash1.erase(key);
			hash2.erase(key2);
			list.erase(key2);  // 출석상태 리스트에서도 삭제
		}
		else if (a == "name")
		{
			string key;
			cin >> key;
			cout << hash1[key] << endl;
		}
		else if (a == "present")
		{
			string key;
			cin >> key;
			if (hash2.count(key) == 1)  // count(key) : 주어진 key의 요소 개수를 리턴.  => 0 또는 1을 리턴
			{
				cout << hash2[key] << endl;
				if (list[key] == "absent") // 결석 상태인 경우
				{
					list[key] = "present"; // 출석 상태로 변경
					present++;
				}
			}
			else
			{
				cout << "Invalid" << endl;
			}
		}
		else if (a == "absent")
		{
			string key;
			cin >> key;
			if (hash2.count(key) == 1)
			{
				cout << hash2[key] << endl;
				if (list[key] == "present") // 출석 상태인 경우
				{
					list[key] = "absent";  // 결석 상태로 변경
					present--;
				}
			}
			else
			{
				cout << "Invalid" << endl;
			}
		}
	}
	cout << present << endl;
}
