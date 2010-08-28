Thread: C++ Class Wrapper for Windows/pthreads

Glenn Butcher
8/27/2010

Usage:

__________________________________________

#include "Thread.h"
#include <iostream>

using namespace std;

class MyThread: public Thread
{

    public:
	MyThread()
	{
		Thread::CreateNewThread(this);
	}

	void Run(void*)
	{
		while (1) cout << "I'm a thread!\n";
	}

};


int main()
{

	MyThread *t = new MyThread();  
	while (1)  cout << "I'm not a thread!\n";
}

____________________________________________


There may be a better way to do this, but it works for me. I
use it in a MessageTransceiver class, which inherits Thread 
and implements a Run() method.  Tested with MinGW on Vista 
(yeah, I know...) and Debian Lenny.  Note that it only implements 
thread initialization and kickoff; made no attempt to wrap 
thread synchronization or other facilities.

Compiling with CodeBlocks/MinGW:
I tested it with a standard console application, no mods to the 
project.

Compiling with g++ on Debian:
You need to include -pthread in the command line.
