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

double thread_1(const std::vector<int>& v, long size)
{
	std::vector<int> result(size);

	auto start = std::chrono::steady_clock::now();
	std::thread t1(summ_vectors, v, v, std::ref(result), 0, size);
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

double threads_2(const std::vector<int>& v, long size)
{
	std::vector<int> result(size);

	auto start = std::chrono::steady_clock::now();
	long half = size / 2;
	std::thread t1(summ_vectors, v, v, std::ref(result), 0, half);
	std::thread t2(summ_vectors, v, v, std::ref(result), half, size);
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

double threads_4(const std::vector<int>& v, long size)
{
	std::vector<int> result(size);

	auto start = std::chrono::steady_clock::now();
	long half = size / 2;
	long quarter = size / 4;
	long half_and_quarter = half + quarter;

	std::thread t1(summ_vectors, v, v, std::ref(result), 0, quarter);
	std::thread t2(summ_vectors, v, v, std::ref(result), quarter, half);
	std::thread t3(summ_vectors, v, v, std::ref(result), half, half_and_quarter);
	std::thread t4(summ_vectors, v, v, std::ref(result), half_and_quarter, size);
	if (t1.joinable())
	{
		t1.join();
	}
	if (t2.joinable())
	{
		t2.join();
	}
	if (t3.joinable())
	{
		t3.join();
	}
	if (t4.joinable())
	{
		t4.join();
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<long, std::nano> time = end - start;

	double d_time = static_cast<double>(time.count()) / 1000000000;
	return d_time;
}

double threads_8(const std::vector<int>& v, long size)
{
	std::vector<int> result(size);

	auto start = std::chrono::steady_clock::now();

	long first_half = size / 2;
	long second_half = size - first_half;

	long first_quarter_of_first_half = first_half / 2;
	long first_eighth_of_first_quarter_of_first_half = first_quarter_of_first_half / 2;
	//long second_eighth_of_first_quarter_of_first_half = first_quarter_of_first_half - first_eighth_of_first_quarter_of_first_half;


	long second_quarter_of_first_half = first_half - first_quarter_of_first_half;
	long first_eighth_of_second_quarter_of_first_half = second_quarter_of_first_half / 2;
	//long second_eighth_of_second_quarter_of_first_half = second_quarter_of_first_half - first_eighth_of_second_quarter_of_first_half;


	long first_quarter_of_second_half = second_half / 2;
	long first_eighth_of_first_quarter_of_second_half = first_quarter_of_second_half / 2;
	//long second_eighth_of_first_quarter_of_second_half = first_quarter_of_second_half - first_eighth_of_first_quarter_of_second_half;


	long second_quarter_of_second_half = second_half - first_quarter_of_second_half;
	long first_eighth_of_second_quarter_of_second_half = second_quarter_of_second_half / 2;
	//long second_eighth_of_second_quarter_of_second_half = second_quarter_of_second_half - first_eighth_of_second_quarter_of_second_half;

	long end_of_part1 = first_eighth_of_first_quarter_of_first_half;
	long end_of_part2 = first_quarter_of_first_half;
	long end_of_part3 = first_quarter_of_first_half + first_eighth_of_second_quarter_of_first_half;
	long end_of_part4 = first_half;

	long end_of_part5 = first_half + first_eighth_of_first_quarter_of_second_half;
	long end_of_part6 = first_half + first_quarter_of_second_half;
	long end_of_part7 = first_half + first_quarter_of_second_half + first_eighth_of_second_quarter_of_second_half;
	//long end_of_part8 = size;

	std::thread t1(summ_vectors, v, v, std::ref(result), 0, end_of_part1);
	std::thread t2(summ_vectors, v, v, std::ref(result), end_of_part1, end_of_part2);
	std::thread t3(summ_vectors, v, v, std::ref(result), end_of_part2, end_of_part3);
	std::thread t4(summ_vectors, v, v, std::ref(result), end_of_part3, end_of_part4);
	std::thread t5(summ_vectors, v, v, std::ref(result), end_of_part4, end_of_part5);
	std::thread t6(summ_vectors, v, v, std::ref(result), end_of_part5, end_of_part6);
	std::thread t7(summ_vectors, v, v, std::ref(result), end_of_part6, end_of_part7);
	std::thread t8(summ_vectors, v, v, std::ref(result), end_of_part7, size);
	if (t1.joinable())
	{
		t1.join();
	}
	if (t2.joinable())
	{
		t2.join();
	}
	if (t3.joinable())
	{
		t3.join();
	}
	if (t4.joinable())
	{
		t4.join();
	}
	if (t5.joinable())
	{
		t5.join();
	}
	if (t6.joinable())
	{
		t6.join();
	}
	if (t7.joinable())
	{
		t7.join();
	}
	if (t8.joinable())
	{
		t8.join();
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
	double result_time1000_4 = threads_4(v1000, size1000);
	double result_time10000_4 = threads_4(v10000, size10000);
	double result_time100000_4 = threads_4(v100000, size100000);
	double result_time1000000_4 = threads_4(v1000000, size1000000);
	std::cout << "4 threads " << result_time1000_4 << "s" << "\t" << result_time10000_4 << "s" << "\t" << result_time100000_4 << "s" << "\t" << result_time1000000_4 << "s" << std::endl;
	
	//quantity of threads = 8
	double result_time1000_8 = threads_8(v1000, size1000);
	double result_time10000_8 = threads_8(v10000, size10000);
	double result_time100000_8 = threads_8(v100000, size100000);
	double result_time1000000_8 = threads_8(v1000000, size1000000);
	std::cout << "8 threads " << result_time1000_8 << "s" << "\t" << result_time10000_8 << "s" << "\t" << result_time100000_8 << "s" << "\t" << result_time1000000_8 << "s" << std::endl;

	//quantity of threads = 16
	/*double result_time1000_16 = threads_16(v1000, size1000);
	double result_time10000_16 = threads_16(v10000, size10000);
	double result_time100000_16 = threads_16(v100000, size100000);
	double result_time1000000_16 = threads_16(v1000000, size1000000);
	std::cout << "16 threads " << result_time1000_16 << "s" << "\t" << result_time10000_16 << "s" << "\t" << result_time100000_16 << "s" << "\t" << result_time1000000_16 << "s" << std::endl;
	*/

	std::cout << "The end" << std::endl;
	return 0;
}