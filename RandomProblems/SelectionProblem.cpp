#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

template<typename T>
int partition(vector<T>& nums, int startIndex, int endIndex, int & arryacesscount) {
	T pivot = nums[startIndex];
	int i = startIndex;
	int j = endIndex;

	do {
		do {
			i++;
			++arryacesscount;
		} while (nums[i] < pivot && i < endIndex);

		while (nums[j] > pivot && j > startIndex) {
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


template<typename T>
T qselect(vector <T>& nums, int startIndex, int endIndex, int smallestRank, int & arryacesscount) {
	if (startIndex == endIndex) {
		++arryacesscount;
		return nums[endIndex];
	}
	else {
		int pivotIndex = partition<T>(nums, startIndex, endIndex, arryacesscount);
		int partOneLength = pivotIndex - startIndex + 1;

		if (smallestRank == partOneLength) {
			arryacesscount++;
			return nums[pivotIndex];
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

int RandInt(int i, int j) {
	srand((unsigned)time(0));
	return (rand() % (j - i + 1)) + i;
}

vector<int> RandomInRange(int start, int end) {
	vector<int> nums;

	nums.push_back(0);

	for (int i = 0; i < (end - start + 1); ++i) {
		nums.push_back(start + i);
	}

	int rnd;
	for (int i = 2; i <= (end - start + 1); ++i) {
		rnd = RandInt(1, i);
		swap(nums[i], nums[rnd]);
	}

	return nums;
}


int main() {
	vector<int> testCasesSizes = { 5, 10, 11, 13, 100, 200, 300, 400, 500, 1000, 10000 };

	for (int testNum : testCasesSizes) {
		vector <int> nums = RandomInRange(1, testNum);
		int arryacesscount = 0;
		int chosen = qselect<int>(nums, 1, testNum, (testNum + 1) / 2, arryacesscount);

		cout << "TestSize:\t" << testNum << "\tFetechedAnswer:\t" << chosen << "\tNumber of Operations (array access):\t" << arryacesscount << "\n";
	}

	system("pause");
	return 0;
}