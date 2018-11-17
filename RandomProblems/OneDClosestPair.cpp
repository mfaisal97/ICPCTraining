#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

pair<int, int> BruteForce(vector<int>& nums) {	//T(n) = 2 + 2n^2 - 2n = O(n^2)

	int indexOne = 0;
	int indexTwo = 1;
	int smallest_diff = abs(nums[indexOne] - nums[indexTwo]);		//T = 2
	int new_diff;

	for (int i = 0; i < nums.size(); ++i) {							//T(n) = (2n-2)(for i = 0 to n-1) = (2n - 2)(n-1-0+1) = 2n^2 - 2n
		for (int j = 0; j < nums.size(); ++j) {						//T(n) = 2 (for i = 0 to n - 1 and i != j) = 2 ((n-1 - 0 + 1) - (1)) = 2n - 2
			if (i != j) {
				new_diff = abs(nums[indexOne] - nums[indexTwo]);	//T = 2
				if (new_diff < smallest_diff) {
					indexOne = i;
					indexTwo = j;
					smallest_diff = new_diff;
				}
			}
		}
	}

	return pair<int, int>(indexOne, indexTwo);
}

pair<int, int> PresortAndScan(vector<int>& nums) { 	//T(n) = O(n logn)

	sort_heap(nums.begin(), nums.end());			//Standard heapify algorithm : T(n) = O(n logn)

	int indexOne = 0;
	int indexTwo = 1;
	int smallestDistance = nums[1] - nums[0];		//T = 2

	int newDistance;
	for (int i = 1; i < nums.size() - 1; ++i) {		//T(n) = 2 (for i = 1 to n-2) = 2(n-2-1+1) = 2(n-2) = 2n-4
		newDistance = nums[i + 1] - nums[i];		//T = 2
		if (newDistance < smallestDistance) {
			smallestDistance = newDistance;
			indexOne = i;
			indexTwo = i + 1;
		}
	}

	return pair<int, int>(indexOne, indexTwo);
}

template<typename T>
int partition(vector<T>& nums, int startIndex, int endIndex, int & arryacesscount) {
	T pivot = nums[startIndex];
	int i = startIndex;
	int j = endIndex;

	do {
		do {
			i++;
			++arryacesscount;
		} while (i < endIndex && nums[i] < pivot);

		while (j > startIndex && nums[j] > pivot) {
			j--;
			++arryacesscount;
		}

		if (i < j) {
			arryacesscount = arryacesscount + 2;
			swap(nums[i], nums[j]);
		}

	} while (i < j);

	nums[startIndex] = nums[j];
	nums[j] = pivot;
	arryacesscount = arryacesscount + 3;

	return j;
}


// has O(n) according to the Qselect algorithm analysis with the assignment
template<typename T>
pair <T, int> qselect(vector <T>& nums, int startIndex, int endIndex, int smallestRank, int & arryacesscount) {
	if (startIndex == endIndex) {
		++arryacesscount;
		return pair <T, int>(nums[endIndex], endIndex);
	}
	else {
		int pivotIndex = partition<T>(nums, startIndex, endIndex, arryacesscount);
		int partOneLength = pivotIndex - startIndex + 1;

		if (smallestRank == partOneLength) {
			arryacesscount++;
			return pair <T, int>(nums[pivotIndex], pivotIndex);
		}
		else if (smallestRank < partOneLength)
		{
			return qselect(nums, startIndex, pivotIndex - 1, smallestRank, arryacesscount);
		}
		else
		{
			return qselect(nums, pivotIndex + 1, endIndex, smallestRank - partOneLength, arryacesscount);
		}
	}
}

//T(n) = O(n logn)
template<typename T>
pair<T, T> ClosestPairQSelect(vector<T>& nums, int startIndex, int endIndex, int& arrayAccessCount) {
	if (endIndex - startIndex + 1 < 2) {
		return pair<T, T>(-1, -1);
	}
	else if (endIndex - startIndex + 1 == 2) {			//T = 2
		arrayAccessCount = arrayAccessCount + 2;
		return pair <T, T>(nums[startIndex], nums[endIndex]);
	}
	else
	{				//O(n log n)
		pair<T, int> median = qselect<T>(nums, startIndex, endIndex, (endIndex - startIndex + 1) / 2, arrayAccessCount);	//O(n)

		if (endIndex - median.second < 2) {
			pair<T, T> P1;
			pair<T, T> P3;
			if (median.second - startIndex < 2) {
				P1 = ClosestPairQSelect(nums, startIndex, median.second, arrayAccessCount);
				P3 = ClosestPairQSelect(nums, median.second, endIndex, arrayAccessCount);
			}
			else {
				P1 = ClosestPairQSelect(nums, startIndex, median.second - 1, arrayAccessCount);
				P3 = ClosestPairQSelect(nums, median.second - 1, endIndex, arrayAccessCount);
			}

			if ((P1.second - P1.first) < (P3.second - P3.first)) {
				return P1;
			}
			else
			{
				return P3;
			}
		}


		if (median.second - startIndex < 2) {

			pair<T, T> P2 = ClosestPairQSelect(nums, median.second + 1, endIndex, arrayAccessCount);
			pair<T, T> P3 = ClosestPairQSelect(nums, startIndex, median.second + 1, arrayAccessCount);

			if ((P2.second - P2.first) < (P3.second - P3.first)) {
				return P2;
			}
			else
			{
				return P3;
			}
		}

		pair<T, T> P1 = ClosestPairQSelect(nums, startIndex, median.second - 1, arrayAccessCount);
		pair<T, T> P2 = ClosestPairQSelect(nums, median.second + 1, endIndex, arrayAccessCount);
		pair<T, T> P3 = ClosestPairQSelect(nums, median.second - 1, median.second + 1, arrayAccessCount);

		if ((P1.second - P1.first) < (P2.second - P1.first)) {
			if ((P1.second - P1.first) < (P3.second - P3.first)) {
				return P1;
			}
			else
			{
				return P3;
			}
		}
		else
		{
			if ((P2.second - P2.first) < (P3.second - P3.first)) {
				return P2;
			}
			else
			{
				return P3;
			}
		}
	}
}


int main() {
	vector<int> testSizes = { 10, 50, 100, 150, 200, 300, 400, 1000, 10000 };
	srand((unsigned)time(0));

	for (int testSize : testSizes) {
		vector<float> nums;

		for (int i = 0; i < testSize; ++i) {
			nums.push_back(1.0 * rand() / rand() * 100);
		}
		int c = 0;

		pair <float, float> p = ClosestPairQSelect<float>(nums, 1, nums.size() - 1, c);
		cout << "TestCase Size:\t" << testSize << "\t>>>>>>\t" << p.first << "\t\t" << p.second << "\n";
		nums.clear();
	}

	system("pause");
	return 0;
}