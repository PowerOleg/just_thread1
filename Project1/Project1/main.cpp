#include <iostream>
#include <thread>
#include <chrono>

void client_work(int& total_count)
{
	total_count++;
}

void operator_work()
{

}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	unsigned int cores_quantity = std::thread::hardware_concurrency();
	std::cout << "Количество аппаратных ядер - " << cores_quantity << std::endl;
	int clients_max_quantity = 1;
	int count = 0;
	std::thread t1(client_work, std::ref(count));
	if (t1.joinable())
	{
		t1.join();
	}
	
	std::cout << count << std::endl;

	/*auto start = std::chrono::steady_clock::now();
	do_something();
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";*/
	return 0;
}