#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/chrono.hpp>

// using mutex from the boost library
boost::mutex mutex;
void wait(int seconds)
{
	boost::this_thread::sleep_for(boost::chrono::seconds{ seconds });
}

void workerFunc()
{
	// mutex to lock the resource from being used by another thread
	mutex.lock();

	boost::posix_time::seconds workTime(3);
	wait(3);
	
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Worker: running" << std::endl;

	//Pretend to do something useful...
	boost::this_thread::sleep(workTime);

	std::cout << "Worker: finished" << std::endl;

	std::cout << "------------------------------------" << std::endl;

	// mutex to unlock the resource and allow it to be used again
	mutex.unlock();

}


int main(int argc, char* argv[])
{
	std::cout << "main: startup" << std::endl;

	std::cout << "main: waiting for threads" << std::endl;

	// 10 threads are made that run the worker function
	boost::thread t1{ workerFunc };
	boost::thread t2{ workerFunc };
	boost::thread t3{ workerFunc };
	boost::thread t4{ workerFunc };
	boost::thread t5{ workerFunc };
	boost::thread t6{ workerFunc };
	boost::thread t7{ workerFunc };
	boost::thread t8{ workerFunc };
	boost::thread t9{ workerFunc };
	boost::thread t10{ workerFunc };


	// 10 threads are joined
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();

	std::cout << "main: done" << std::endl;

	system("pause");
	return 0;
}
