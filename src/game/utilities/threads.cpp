/***************************************************************************
 *   Copyright (C) 2015 by Mike McLean   *
 *   libolt@libolt.net   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Generalhhh Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "utilities/conversion.h"
#include "utilities/threads.h"
#include "engine/gameengine.h" 
#include <cstdlib>


threads::threads()
{
    kMaxSleepTime_ms = 500;
    gRunning = false;
}

// Consumes items in work queue
void threads::consumerThread()
{
/*    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert ;
    
    while (gRunning)
    {
        if (gWorkQueueMutex.try_lock())
        {
            if (gWorkQueue.size())
            {
                long val = gWorkQueue.back();
                gWorkQueue.pop_back();

            //    printf("vvv %ld\n", val);

                logMsg("display = " +convert->toString(val));
            }

            // Hold the mutex for a little while
            std::posix_time::milliseconds delayTime(50);
            std::this_thread::sleep(delayTime);

            gWorkQueueMutex.unlock();
        }
        else
        {
        //    printf("v==\n");
            logMsg("no lock");
        }

        // Slow things down a little
        std::posix_time::milliseconds delayTime(rand() % kMaxSleepTime_ms);
        std::this_thread::sleep(delayTime);
    }*/
}

// Produces work items for queue
void threads::producerThread()
{
/*    //conversion *convert = conversion::Instance();
    conversionSharedPtr convert ;
    
    long val = 0;
    while (gRunning)
    {
        if (gWorkQueueMutex.try_lock())
        {
        //    long val = rand();
            val +=1;
            gWorkQueue.push_back(val);

            //printf("^^^ %ld\n", val);
            logMsg("add " +convert->toString(val));

            //    logMsg("vvv " +convert->toString(val));
            //}

            // Hold the mutex for a little while
            std::posix_time::milliseconds delayTime(50);
            std::this_thread::sleep(delayTime);

            gWorkQueueMutex.unlock();
        }
        else
        {
        //    printf("v==\n");
            logMsg("v==");
        }

        // Slow things down a little
        std::posix_time::milliseconds delayTime(rand() % kMaxSleepTime_ms);
        std::this_thread::sleep(delayTime);
    }*/
}

bool threads::getGRunning() // retrieves the value of gRunning
{
    return (gRunning);
}

void threads::setGRunning(bool set) // sets the value of gRunning
{
    gRunning = set;
}
/*
threads* threads::pInstance = 0;
threads* threads::Instance()
{
    if (pInstance == 0)  // is it the first call?
    {
        pInstance = new threads; // create sole instance
    }
    return pInstance; // address of sole instance
}

std::mutex threads::Writer::_writerMutex;
//-------------------------------------------------------------------------------------
threads::threads()
{
    value = 0;
    count = 0;
    globalVariable = 0;
    globalVariableProtector = new std::mutex;
}
 
void threads::workerFunc()
{
    std::posix_time::seconds workTime(3);

    logMsg("Worker: running");

    // Pretend to do something useful...
    std::this_thread::sleep(workTime);

    logMsg("Worker: finished");
//	exit(0);
}

void threads::workerFunc2()
{
    std::posix_time::seconds workTime(3);

    logMsg("Worker2: running");

    // Pretend to do something useful...
    std::this_thread::sleep(workTime);

    logMsg("Worker2: finished");
//	exit(0);
}

void threads::inputWorkerFunc()  // handles input processing
{
    gameEngine *gameE = gameEngine::Instance();
    
    logMsg("inputWorker!");
    gameE->processInput();
}

void threads::producer()
{
    while (true)
    {
        {
            // value and counter must both be updated atomically
            // using a mutex lock
            lockType lock(mutex);
            value = std::rand();
            ++count;

            // Notify the consumer that a new value is ready.
            condvar.notify_one();
        }

        // Simulate exaggerated 2ms delay
        std::this_thread::sleep(std::posix_time::milliseconds(200));
    }
}

void threads::consumer()
{
    // Local copies of 'count' and 'valjue' variables. We want to do the
    // work using local copies so that they don't get clobbered by
    // the producer when it updates.
    int currentCount = 0;
    double currentValue = 0;

    while (true)
    {
        {
            // Acquire the mutex before accessing 'count' and 'value' variables.
            lockType lock(mutex); // mutex is locked while in this scope
            while (count == currentCount)
            {
                // Wait for producer to signal that there is a new value.
                // While we are waiting, std releases the mutex so that
                // other threads may acquire it.
                condvar.wait(lock);
            }

            // `lock` is automatically re-acquired when we come out ofvuuyvvb hn
            // condvar.wait(lock). So it's safe to access the 'value'
            // variable at this point.
            currentValue = value; // Grab a copy of the latest value
                                  // while we hold the lock.
        }

        // Now that we are out of the mutex lock scope, we work with our
        // local copy of `value`. The producer can keep on clobbering the
        // 'value' variable all it wants, but it won't affect us here
        // because we are now using `currentVanglue`.
        std::cout << "value = " << currentValue << "\n";

        // Simulate exaggerated 5ms delay
        std::this_thread::sleep(std::posix_time::milliseconds(500));
    }
}
*/
