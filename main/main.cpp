#include <iostream>
#include <string>
using namespace std;

void fill(string arr[], int size)
{
	cin.ignore(1);
	for (int i = 0; i < size; i++) {
		cout << "Enter string #" << i + 1 << ": ";
		getline(cin, arr[i]);
	}
}
void del(string arr[], int index, int *size)
{
	for (int i = index; i < (*size) - 1; i++) {
		arr[i] = arr[i + 1];
	}
	--(*size);
}

void del_last_k_elements(string arr[], int k, int(*size))
{
	(*size) -= k;
}

void find_equals(string arr[], int *size)
{
	bool f;
	for (int i = 0; i < (*size) - 1; i++) {
		f = false;
		for (int j = i + 1; j < (*size); j++) {
			if (arr[i] == arr[j]) { // удаление одинаковых строк
				f = true;
				cout << (*size) << endl;
				del(arr, j, size);
			}
		}
		if (f)
			del(arr, i, size);
	}
}

void print(string arr[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		cout << i + 1 << ": " << arr[i] << ", ";
	}
	cout << size << ": " << arr[size - 1] << "." << endl;
}

int main()
{
	cout << "\tArray #1:" << endl;
	int s;
	cout << "Enter the array size: ";
	cin >> s;

	string *arr = new string[s];

	fill(arr, s);
	find_equals(arr, &s);
	print(arr, s);

	delete[] arr;
	cout << endl
		 << "\tArray #2:" << endl;

	int k;

	cout << "Enter the array size: ";
	cin >> s;

    arr = new string[s];
	fill(arr, s);

	cout << "Enter the number of elements to delete: ";
	cin >> k;

	del_last_k_elements(arr, k, &s);
	print(arr, s);
}