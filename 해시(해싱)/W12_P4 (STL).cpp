#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	map<string, string> list2;  // 출석 상태를 저장하는 리스트

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

			list2.insert(make_pair(value, "absent"));  // 0 : NOITEM, 1 : 출석, 2 : 결석
		}
		else if (a == "delete")
		{
			string key;
			cin >> key;
			string key2 = hash1[key];
			if (list2[key2] == "present") // 출석 상태인 경우
			{
				// cout << "delete 호출" << endl;
				present--;
			}
			hash1.erase(key);
			hash2.erase(key2);
			list2.erase(key2);

			//auto key2 = hash1.find(key);
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
				if (list2[key] == "absent") // 결석 상태인 경우
				{
					// cout << "present 호출" << endl;
					list2[key] = "present"; // 출석 상태로 변경
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
				if (list2[key] == "present") // 출석 상태인 경우
				{
					// cout << "absent 호출" << endl;
					list2[key] = "absent";
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