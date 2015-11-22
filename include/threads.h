/***************************************************************************
 *   Copyright (C) 2015 by Mike McLean                                     *
 *   libolt@libolt.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *9   GNU General Public License for more details.                         *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,   0                                   *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

 
#ifndef _THREADS_H_
#define _THREADS_H_
 
#include <vector>
#include <boost/thread/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/locks.hpp>

#include "logging.h"
 
//const int globalVariable;

typedef std::vector<long>   workqueue_t;

//   static boost::mutex Writer::_writerMutex;

class threads
{
    public:
        threads();  // constructor

        // Consumes items in work queue
        void consumerThread();
        // Consumes items in work queue
        void producerThread();

        bool getGRunning(); // retrieves the value of gRunning
        void setGRunning(bool set); // sets the value of gRunning

    protected:
    private:
        // Maximum sleep delay
    unsigned kMaxSleepTime_ms;
    // Work queue, a shared resource protected by a mutex
    workqueue_t                 gWorkQueue;
    boost::mutex                gWorkQueueMutex;
    // Flag to tell threads to quit
    bool gRunning;


};





/*
class threads
{
    public:
        static threads *Instance();
        void workerFunc();
        void workerFunc2();
        void inputWorkerFunc();  // handles input processing
	
        void producer();
        void consumer();
       
//        int getGlobalVariable()  // retrieves the value of globalVariable
//        {
//            return (globalVariable);
//        }
//        void setGlobalVariable(int set) // sets the value of globalVariable
//        {
//            globalVariable = set;
//        }


        int getGlobalVariable()  // retrieves the value of globalVariable
        {
            boost::lock_guard<boost::mutex> lock(*globalVariableProtector);
            return (globalVariable);
        }
        void setGlobalVariable(int set) // sets the value of globalVariable
        {
            boost::lock_guard<boost::mutex> lock(*globalVariableProtector);
            globalVariable = set;
        }
        
        boost::mutex *getGlobalVariableProtector()  // returns the value of globalVariableProtector
        {
            return (globalVariableProtector);
        }
        void setGlobalVariableProtector(boost::mutex *set)
        {
            globalVariableProtector = set;
        }
        
        
        class Reader   
        {
            public:
            Reader(int waitTime) { _waitTime = waitTime;}
            void operator() () 
            {

                threads *thread = threads::Instance();
                boost::mutex *globalVariableProtector = thread->getGlobalVariableProtector();

                //boost::lock_guard<boost::mutex> lock(localVariableProtector);
                //boost::lock_guard<boost::mutex> lock(*globalVariableProtector);
                    
                int globalVariable = thread->getGlobalVariable();
                for (int i=0; i < 10; i++) 
                {
                    logMsg("Reader Api: " +convert->toString(globalVariable));
 //       usleep(_waitTime);
                    boost::this_thread::sleep(boost::posix_time::microseconds(_waitTime));
                }
              //  boost::lock_guard<boost::mutex> unlock(*globalVariableProtector);
                    
                //boost::lock_guard<boost::mutex> unlock(localVariableProtector);

                return;
            }
        private:
            int _waitTime;
 //           boost::mutex localVariableProtector;

        };


        class Writer
        {
            public:
                Writer(int variable, int waitTime)
                {
                    _writerVariable = variable;
                    logMsg("Writer Variable: " +convert->toString(_writerVariable));

                    _waitTime = waitTime;
                }
                void operator () () 
                {

                    logMsg("Writer Variable: " +convert->toString(_writerVariable));

                    threads *thread = threads::Instance();
                    int globalVariable = thread->getGlobalVariable();
                    boost::mutex *globalVariableProtector = thread->getGlobalVariableProtector();
                   
                    for (int i=0; i < 10; i++) 
                    {
                        boost::lock_guard<boost::mutex> lock(*globalVariableProtector);

//        usleep(_waitTime);
                        boost::this_thread::sleep(boost::posix_time::microseconds(_waitTime));
                        logMsg("Waittime Variable: " +convert->toString(_waitTime));

                        // Take lock and modify the global variable
                      //  boost::mutex::scoped_lock lock(_writerMutex);
                        globalVariable = _writerVariable;
                        thread->setGlobalVariable(globalVariable);
                        
                        _writerVariable++;
                        // since we have used scoped lock, 
                        // it automatically unlocks on going out of scope
                        boost::lock_guard<boost::mutex> unlock(*globalVariableProtector);

                    }
                        
                    logMsg("Writer Variable: " +convert->toString(_writerVariable));
                    thread->setGlobalVariable(globalVariable);

//                }

//                    thread->setGlobalVariable(globalVariable);
                }   
            private:
                int _writerVariable;
                int _waitTime;
                static boost::mutex _writerMutex;

        };
    
    protected:
        threads();
        threads(const threads&);
        threads& operator= (const threads&); 
    private:
        static threads *pInstance;
         boost::mutex *globalVariableProtector;

        boost::mutex mutex;
        boost::condition_variable condvar;
        typedef boost::unique_lock<boost::mutex> lockType;
        double value;
        int count;
        int globalVariable;

 };
 */
 #endif
 
