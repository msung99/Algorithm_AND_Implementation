#include <iotstream>
#include <string>
using namespace std;

class vector {
private:
	int* arr;
	int n;
	int capacity;
public:
	vector(int capacity);
	int size();
	bool empty();
	int at(int idx);
	void set(int idx, int data);
	void insert(int idx, int data);
	void erase(int idx);
	void reverse(int size);
};

vector::vector(int capacity)
{
	this->capacity = capacity;
	n = 0;
	arr = new int[capacity];
}

int vector::size() // O(1)
{
	return n;
}

bool vector::empty() // O(1)
{
	if (n == 0)
		return true;
	else
		return false;
}

int vector::at(int idx)  // O(1)
{
	if (idx < 0 || idx >= n)
		return -1;

	return arr[idx];
}

void vector::set(int idx, int data) // O(1)
{
	if (idx < 0 || idx >= n)
		return;
	arr[idx] = data;
	n++;
}

// insert 연산 : O(1) => 원래는 O(n) 이지만, 더블링 기법으로 구현했으므로 Amotized Analysis에 따라서 O(1) 이다.
void vector::insert(int idx, int data) 
{
	if (idx < 0 || idx >= n)
		return;
	if (n == capacity) // 배열이 꽉차서 더블링 strategy 를 하는경우
		reverse(2 * capacity);  // 더블링 strategy => O(1)

	for (int i = n - 1; i >= idx; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[idx] = data;
	n++;
}

void vector::reverse(int size)  // 더블링 strategy => O(1) (Amotized Analysis에 따라서 O(n)처럼 보여도 실제로는 O(1)이다)
{
	if (size <= capacity)
		return;
	int* newArr = new int[size]; // 배로운 배열에 데이터 값들 할당
	for (int i = 0; i < n; i++)
	{
		newArr[i] = arr[i];
	}

	if (arr != NULL) // 기존 배열 삭제
		delete[] arr;

	arr = newArr; // 기존 배열에 대한 포인터가 이제 새로운 배열을 가리키게 함
	capacity = size;
}

void vector::erase(int idx) // erase 연산 : O(n) (=> 환형배열로 구현했다면 맨앞,맨뒤 원소를 erase하는 연산에 한해서만 O(1)이 걸렸을것이다.)
{
	if (idx < 0 || idx >= n)
		return;
	for (int i = idx + 1; i <= n - 1; i++)
	{
		arr[i - 1] = arr[i];
	}
	n--;
}





















