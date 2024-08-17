#include <iostream>
#include <thread>
#include <chrono>

void client_worker(int& count, int count_max)
{
	while (true)
	{
		if (count < count_max)
		{
			std::cout << ++count << " ";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
}

void operator_worker(int& count)
{
	while (count > 0)
	{
		std::cout << --count << " ";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
}

int main(int argc, char** argv)
{
	unsigned int cores_quantity = std::thread::hardware_concurrency();
	std::cout << "Quantity of processor cores - " << cores_quantity << std::endl;
	int count_max = 10;
	int count = 0;
	std::thread t1(client_worker, std::ref(count), count_max);
	std::thread t2(operator_worker, std::ref(count));
	if (t1.joinable())
	{
		t1.join();
	}
	if (t2.joinable())
	{
		t2.join();
	}
	std::cout << "The end" << std::endl;
	return 0;
}