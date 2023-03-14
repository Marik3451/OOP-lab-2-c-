#include <iostream>
#include<algorithm>
#include<vector>
#include <numeric>
using namespace std;

int hideMinI(vector<int> arr)
{
	auto min_index = min_element(arr.begin(), arr.end(),
		[](int a, int b)
		{
			return abs(a) < abs(b);
		}
	) - arr.begin();
	return min_index;
}

int sumElemAfterFirstNegElem(vector<int> arr)
{
	auto result = accumulate(
		find_if(begin(arr), end(arr),
			[](auto const& value)
			{
				return value < 0;
			}
		), end(arr), 0, [](auto const& boo, auto const& value)
			{
				return boo + abs(value);
			});
	return result;
}

void removeElem(vector<int> arr, int a1, int b1, int n)
{
	arr.erase(remove_if(arr.begin(), arr.end(), [a1, b1](int x) { return (x >= a1 && x <= b1); }), arr.end());
	while (arr.size() < n)
		arr.push_back(0);
	int m = 0;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main()
{
	int n;
	int a1, b1;
	cout << "Enter size of array: " << endl;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
	cout << "Index of min element: " << hideMinI(arr) << endl;
	cout << "Sum of elements after first negative element1: " << sumElemAfterFirstNegElem(arr) - 1 << endl;
	cout << "Enter a and b: ";
	cin >> a1 >> b1;
	removeElem(arr, a1, b1, n);
	return 0;
}


