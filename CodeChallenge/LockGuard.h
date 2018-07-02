#pragma once
#include <mutex> 
#include <iostream>
#include <thread>
#include <string>

//Header file to implement "lock_guard"

std::mutex mut;

//prototype

void sharedThread(std::string msg, int id) {
	mut.lock(); //lock first
	std::cout << msg << ":" << id << std::endl;
	mut.unlock(); //unlock
}


void threadFunction1() {
	//std::cout << "Thread: 1 ";
	for (int i = -10; i < 0; i++) {
		sharedThread("thread function " , i);
	}
}





