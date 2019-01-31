
#include <iostream>
#include "numbers.dat"

const int MAX_NUMBERS = 100000;

void findPrime(bool *prime) {
	for (int i = 0; i < MAX_NUMBERS; ++i)
		prime[i] = true;
	prime[1] = false;
	for (int i = 2; i*i < MAX_NUMBERS; ++i)
		if (prime[i])
			for (int j = i*i; j < MAX_NUMBERS; j += i)
				prime[j] = false;
}

int binarySearch(int res, int first, int second) {
	if (first == second)
		return first;
	int mid = (first + second) / 2;
	
	if (Data[mid] == res)
		return mid;
	if (Data[mid] < res)
		return binarySearch(res, mid + 1, second);
	else
		return binarySearch(res, first, mid - 1);
}		

int UpSecondBound(int indSecond, int second) {
	while (Data[indSecond + 1] == second)
		indSecond++;
	return indSecond;
}		//find the latest second number

int main() {
	int first, second;
	std::cin >> first >> second;

	bool *prime = new bool[MAX_NUMBERS];
	findPrime(prime);						//array of prime numbers

	int indFirst = binarySearch(first, 0, Size - 1);
	int indSecond = binarySearch(second, 0, Size - 1);
	if ((Data[indFirst] != first) || (Data[indSecond] != second))
		std::cout << 0;		//check the bounds
	else {
		int count = 0;
		int indSecondUp = UpSecondBound(indSecond, second);
		for (int i = indFirst; i <= indSecond; ++i)
			if (prime[Data[i]])
				count++;
		std::cout << count;
	}

	delete[] prime;
	return 0;
}