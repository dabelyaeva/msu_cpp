
#include <iostream>
#include <chrono>

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using microseconds = std::chrono::microseconds;
public:
	Timer()
		: start_(clock_t::now())
	{
	}

	~Timer()
	{
		const auto finish = clock_t::now();
		const auto us =
			std::chrono::duration_cast<microseconds>
			(finish - start_).count();
		std::cout << us << " us" << std::endl;
	}

private:
	const clock_t::time_point start_;
};

int main() {
	const size_t ARRAY_SIZE = 50;
	int** myArr = new int*[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		myArr[i] = new int[ARRAY_SIZE];
	}
	for (int i = 0; i < ARRAY_SIZE; ++i)
		for (int j = 0; j < ARRAY_SIZE; ++j)
			myArr[i][j] = i + j;

	Timer T;
	int sumRow = 0;
	for (int i = 0; i < ARRAY_SIZE; ++i)
		for (int j = 0; j < ARRAY_SIZE; ++j)
			sumRow += myArr[i][j];			//[j][i] for Column

	for (int i = 0; i < ARRAY_SIZE; ++i)
		delete[]myArr[i];
	delete[]myArr;

	std::cout << sumRow << std::endl;

	return 0;
}