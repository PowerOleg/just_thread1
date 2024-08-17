#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>
#include <numeric>

void summ_vectors(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int> &result, long from, long size)
{
	for (size_t i = from; i < size; i++)
	{
		result[i] = v1[i] + v2[i];
	}
}

double thread_1(const std::vector<int>& v1000, long size)
{
	std::vector<int> result(size);

	auto start = std::chrono::steady_clock::now();
	std::thread t1(summ_vectors, v1000, v1000, std::ref(result), 0, size);
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

double threads_2(const std::vector<int>& v1000, long size)
{
	std::vector<int> result(size);

	auto start = std::chrono::steady_clock::now();
	long half = size / 2;
	std::thread t1(summ_vectors, v1000, v1000, std::ref(result), 0, half);
	std::thread t2(summ_vectors, v1000, v1000, std::ref(result), half, size);
	if (t1.joinable())
	{
		t1.join();
	}
	if (t2.joinable())
	{
		t2.join();
	}
	auto end = std::chrono::steady_clock::now();
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

	long size1000 = 1000L;
	long size10000 = 10000L;
	long size100000 = 100000L;
	long size1000000 = 1000000L;
	std::vector<int> v1000(size1000);
	std::iota(std::begin(v1000), std::end(v1000), 0);
	std::vector<int> v10000(size10000);
	std::iota(std::begin(v10000), std::end(v10000), 0);
	std::vector<int> v100000(size100000);
	std::iota(std::begin(v100000), std::end(v100000), 0);
	std::vector<int> v1000000(size1000000);
	std::iota(std::begin(v1000000), std::end(v1000000), 0);

	//quantity of threads = 1
	double result_time1000 = thread_1(v1000, size1000);
	double result_time10000 = thread_1(v10000, size10000);
	double result_time100000 = thread_1(v100000, size100000);
	double result_time1000000 = thread_1(v1000000, size1000000);
	std::cout << "1 thread "  << result_time1000 << "s" << "\t" << result_time10000 << "s" << "\t" << result_time100000 << "s" << "\t" << result_time1000000 << "s" << std::endl;

	//quantity of threads = 2
	double result_time1000_2 = threads_2(v1000, size1000);
	double result_time10000_2 = threads_2(v10000, size10000);
	double result_time100000_2 = threads_2(v100000, size100000);
	double result_time1000000_2 = threads_2(v1000000, size1000000);
	std::cout << "2 threads " << result_time1000_2 << "s" << "\t" << result_time10000_2 << "s" << "\t" << result_time100000_2 << "s" << "\t" << result_time1000000_2 << "s" << std::endl;
	
	//quantity of threads = 4
	/*double result_time1000_4 = threads_4(v1000, size1000);
	double result_time10000_4 = threads_4(v10000, size10000);
	double result_time100000_4 = threads_4(v100000, size100000);
	double result_time1000000_4 = threads_4(v1000000, size1000000);
	std::cout << "4 threads " << result_time1000_4 << "s" << "\t" << result_time10000_4 << "s" << "\t" << result_time100000_4 << "s" << "\t" << result_time1000000_4 << "s" << std::endl;
	*/
	//quantity of threads = 8

	//quantity of threads = 16

	//std::thread t2(operator_worker, std::ref(count));
	

	std::cout << "The end" << std::endl;
	return 0;
}