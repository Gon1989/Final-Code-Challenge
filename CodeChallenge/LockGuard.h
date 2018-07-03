#pragma once
#include <mutex> 
#include <iostream>
#include <thread>
#include <string>
#include <chrono>


/*	-----INSTRUCTIONS-----

2) Reimplement c++11 lock_guard(NOT use std::lock_guard).Use namespace
to allow you to call your class impl "lock_guard" and not conflict with

std::lock_guard

LockGuard.h          // header file only impl

3) Implement c++11 threading example

2 - 3 threads running

4) Use c++11 std::condition_var in solution from #3 to synchronize threads

-- Psuedo Code --

main:

1) start: thread 1, thread 2, thread 3
2) all threads block on condition_signal
3) main signals condition_signal
4) join all threads to prevent exit main // gimmee

thread 1:

break from condition_signal due to step 3

sleep(random(1, 5))

signal thread 2

wait on condition_signal

example output :

main: starting all threads

	thread1 : starting, waiting.

	thread2 : starting, waiting.

	thread3 : starting, waiting.

	main : starting thread 1.

	thread1 : signal received, doing work ....

	thread1 : done with work, signal next thread

	thread2 : signal received, doing work ....

	thread2 : done with work, signal next thread

	on and on and on until you CTRL - C the program

	5) Use your implementation of c++11 lock_guard(NOT std::lock_guard)

	to protect a common resource in your threading example from #3 and #4
*/


//Header file to implement "lock_guard"

std::mutex mut;

//prototype
void func();


void func() {
	mut.lock(); //lock it

	std::cout << "Starting Thread, " << std::this_thread::get_id() << std::endl; //enter the thread 
	std::this_thread::sleep_for(std::chrono::seconds(rand() % 10)); //timer 1 second 
	std::cout << "Waiting Thread " << std::this_thread::get_id() << std::endl;
	
	mut.unlock(); //unlock the mutex
}









/*void sharedThread(std::string msg, int id) {
	mut.lock(); //lock first
	std::cout << msg << ":" << id << std::endl;
	mut.unlock(); //unlock
}


void threadFunction1() {
	//std::cout << "Thread: 1 ";
	for (int i = 5; i > 0; i--) {
		sharedThread("Thread function " , i);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}*/





