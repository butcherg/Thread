#ifndef __THREAD_H_INCLUDED__
#define __THREAD_H_INCLUDED__

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif


//Extremely simple thread class. Uses either Windows Threads (win32)
//or pthreads (unix).
class Thread
{
    public:
        Thread();
        int CreateNewThread(void * arg);

    protected:
        static void * EntryPoint(void* pthis);
        void * Arg() const {return Arg_;}
        void Arg(void* a){Arg_ = a;}

    public:
        virtual void Setup() {};
        virtual void Run(void*) {};

    private:
        void * Arg_;
#ifdef WIN32
        HANDLE thread; //Thread handle
        DWORD lpId;
#else
        pthread_t thread;
#endif
};

#endif  // THREAD_H_INCLUDED
