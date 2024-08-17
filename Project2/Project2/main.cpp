#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> summ_vectors(const std::vector<int>& v1, const std::vector<int>& v2, long size)
{
	std::vector<int> result(size);
	for (size_t i = 0; i < size; i++)
	{
		result[i] = v1[i] + v2[i];
	}
	return result;
}

double thread1(const std::vector<int>& v1000)
{
	auto start = std::chrono::steady_clock::now();
	std::thread t1(summ_vectors, v1000, v1000, 1000L);
	if (t1.joinable())
	{
		t1.join();
	}
	auto end = std::chrono::steady_clock::now();
	//std::chrono::duration<double> elapsed_time = end - start;
	std::chrono::duration<long, std::nano> time = end - start;
	
	double d_time = static_cast<double>(time.count()) / 1000000000;
	return d_time;
}


int main(int argc, char** argv)
{
	//setlocale(LC_ALL, "ru");
	unsigned int cores_quantity = std::thread::hardware_concurrency();
	std::cout << "Quantity of processor cores - " << cores_quantity << std::endl << std::endl;
	std::cout << "\t" << "1000" << "\t" << "\t" << "10000" << "\t" << "\t" << "100000" << "\t" << "\t" << "1000000" << "\t" << std::endl;


	std::vector<int> v1000(1000);
	std::iota(std::begin(v1000), std::end(v1000), 0);
	std::vector<int> v10000(10000);
	std::iota(std::begin(v10000), std::end(v10000), 0);
	std::vector<int> v100000(100000);
	std::iota(std::begin(v100000), std::end(v100000), 0);
	std::vector<int> v1000000(1000000);
	std::iota(std::begin(v1000000), std::end(v1000000), 0);

	//quantity of threads = 1
	double result_time1 = thread1(v1000);
	std::cout << "1 thread "  << result_time1 << "s" << "\t" << 0.9999 << std::endl;


	//quantity of threads = 2

	//quantity of threads = 4

	//quantity of threads = 8

	//quantity of threads = 16

	//std::thread t2(operator_worker, std::ref(count));
	

	std::cout << "The end" << std::endl;
	return 0;
}