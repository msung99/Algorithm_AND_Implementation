#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000001];
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

// arr의 인덱스 (st ~ mid) 와 인덱스 (mid ~ en-1) 에 이미 정렬되어 있을때,
// arr의 st ~ (en-1) 을 정렬하는 함수이다.
// => 즉, 2개의 정렬된 두 리스트 배열을 합치는 것을 구현하는 함수
void merge(int st, int en) {
	int mid = (st + en) / 2;
	int lidx = st; // arr[st:mid] 에서 값을 보기위해 사용하는 인덱스
	int ridx = mid; // arr[mid:en] 에서 값을 보기위해 사용하는 인덱스

	// 정렬된 두 배열 리스트의 원소를 하나씩 차곡차곡 값을 비교하며 새로운 리스트로써 병합시킴
	for (int i = st; i < en; i++) 
	{
		if (ridx == en) {  // 2번쨰 리스트의 원소를 끝까지 다 써버린 경우
			tmp[i] = arr[lidx];
			lidx++;
		}
		else if (lidx == mid) { // 1번쨰 리스트의 원소를 끝까지 다 써버린 경우
			tmp[i] = arr[ridx];
			ridx++;
		}
		else if (arr[lidx] <= arr[ridx]) { // 2번쨰 리스트의 원소값이 더 큰 경우
			tmp[i] = arr[lidx];
			lidx++;
		}
		else {  // 1번쨰 리스트의 원소값이 더 큰 경우
			tmp[i] = arr[ridx];
			ridx++;
		}
	}

	for (int i = st; i < en; i++) {
		arr[i] = tmp[i]; // tmp 에 임시저장해둔 값을 arr 로 다시 옮김
	}
}

// 배열 arr의 인덱스 st ~ (en-1) 을 정렬하는 함수
void merge_sort(int st, int en) {
	if (st + 1 == en) // base condition : 배열의 크기가 1일때
		return;
	
	int mid = (st + en) / 2;  
	merge_sort(st, mid); // 주어진 리스트 배열 arr 을 2개로 쪼개고 각각 정렬한다.
	merge_sort(mid, en);
	merge(st, en);  // 2개로 나눈 두 리스트를 정렬시키면서 병합한다.
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	merge_sort(0, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
}