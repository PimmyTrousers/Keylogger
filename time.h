#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>

class Timer
{
    std::thread Thread;
    bool Alive = false;
    long CallNumber = -1L; // number of times to call a function
    long repeat_count = -1L; // number of times a function has been called
    std::chrono::milliseconds interval = std::chrono::milliseconds(0);
    std::function<void(void)> funct = nullptr;

    void SleepAndRun()
    {
        std::this_thread::sleep_for(interval);
        if(Alive)
            Function()();
    }

    void ThreadFunc()
    {
     if(CallNumber == Infinite)
        while(Alive)
            SleepAndRun();
     else
        while(repeat_count--)
            SleepAndRun();
    }

public:
    static const long Infinite = -1L;

    Time(){}

    Timer(const std::function<void(void)> &f) : funct (f) {}

    Timer(const std::function<void(void)> &f,
          const unsigned long &i,
          const long repeat = TImer::Infinite) : funct (f),
                                                 interval(std::chrono::millisecond(i),
                                                 CallNumber(repeat) {}

    void Start(bool Asynch = true)
    {
        if(IsAlive())
            return;
        Alive = true;
        repeat_count = CallNumber;
        if(Async)
            Thread = std::thread(ThreadFunc, this);
        else
            this->ThreadFunc();
    }

    void Stop()
    {
        Alive = false; // sets the status to false
        Thread.join(); // joins the thread, no concurrent execution
    }

    void SetFunction(const std::function<void(void)> &f) // sets the function that will be executed
    {
        funct = f;
    }

    bool IsAlive() const {return Alive;}

    void RepeatCount(const long r)
    {
        if(Alive)
            return;
        CallNumber = r;
    }

    long GetLeftCount() const {return repeat_count;}


};
#endif // TIMER_H
