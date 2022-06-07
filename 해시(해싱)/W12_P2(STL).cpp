#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(void)
{
	map<string, string> list; // 회원가입 상태를 저장하는 리스트
	map<string, string> hash;

	int t;
	cin >> t;
	while(t--)
	{
		string a;
		cin >> a;
		if (a == "signup")
		{
			string key, value;
			cin >> key >> value;
			if (hash.count(key) == 1) // 이미 회원가입된 경우
			{
				cout << "Invalid" << endl;
			}
			else
			{
				hash.insert(make_pair(key, value));
				list.insert(make_pair(key, "logout"));  // "로그아웃" 상태로 저장함!!!!!!!!!!!!!!
				cout << "Submit" << endl;
			}
		}
		else if (a == "login")
		{
			string key, value;
			cin >> key >> value;

			if (hash.count(key) == 0) // 존재하지 않는 아이디인 경우
			{
				cout << "Invalid" << endl;
			}
			else if (hash[key] != value) // 비밀번호가 일치하지 않는 경우
			{
				cout << "Invalid" << endl;
			}
			else if (list[key] == "login" && hash[key] == value)  // 아디 비번 모두 일치하지만 이미 로그인 상테인 경우
			{
				cout << "Quit" << endl;
			}
			else if (list[key] == "logout" && hash[key] == value) // 이다 비번 모두 일치하고 로그아웃 상태인 경우
			{
				list[key] = "login"; // 로그인 상태로 바꿈
				cout << "Submit" << endl;
			}
		}
		else if (a == "logout")
		{
			string key;
			cin >> key;
			list[key] = "logout"; // 로그아웃 상태로 바꿈
			cout << "Submit" << endl;
		}
	}
}