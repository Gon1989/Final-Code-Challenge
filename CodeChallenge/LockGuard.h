#pragma once
#include <mutex> 
#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <condition_variable>

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
std::condition_variable cv;
std::string data;

/*
class Counter {

public:
	Counter(int id, int numIterations) : mID(id), mNumIterations(numIterations) {

	}

	void operator()() const {
		for (int i = 0; i < mNumIterations; i++) {
			lock_guard<mutex> lock(mut); //implement lock_guard to protect data at each iteration
			cout << "Counter " << mID << " = ";
			cout << i << endl;
		}
	}

private:
	int mID;
	int mNumIterations;
	mutex mut;

};

*/





