#include "Thread.h"

Thread::Thread() {}

int Thread::CreateNewThread(void * arg)
{
    int code = 0;
    Arg(arg); // store user data
#ifdef WIN32
    thread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)EntryPoint,(LPVOID) this,0,(LPDWORD) &lpId);
    if(thread == NULL) code = 1;
#else
    code = pthread_create( &thread, NULL, Thread::EntryPoint, this);
#endif
    return code;
}

void * Thread::EntryPoint(void * pthis)
{
    Thread * pt = (Thread*)pthis;
    pt->Run( pt->Arg() );
    return NULL;
}
