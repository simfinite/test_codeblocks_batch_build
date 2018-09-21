#include <iostream>
#include <thread>
#include <sstream>
#include <signal.h>

using namespace std;

//!\todo Process cannot be killed when run as compiler from Codeblocks..

int quit = 0;
void signal_handler(int sig)
{
    cout << "Quitting..." << endl;
    signal(sig, signal_handler);
    quit = 1;
}

int main(int argc, char *argv[])
{
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGBREAK, signal_handler);
    signal(SIGABRT, signal_handler);
    
    cout << "Trust me, I'm a compiler!" << endl;
    
//    int n_warnings = 10;
//    int work_us = 0;
//    int sleep_us = 1000000;
    int n_warnings = 5;
    int work_us = 1000000;
    int sleep_us = 100;
    int timeout_s = 10;

    const string warning("D:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:9:11:   required from 'void produce_compiler_warnings() [with int i = 8]'\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:18:35:   required from 'void bar() [with int i = 9]'\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:9:11:   required from 'void produce_compiler_warnings() [with int i = 9]'\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:18:35:   required from 'void bar() [with int i = 10]'\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:9:11:   required from 'void produce_compiler_warnings() [with int i = 10]'\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/fsm.hpp:206:39:   required from here\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:10:10: warning: unused variable 'baz' [-Wunused-variable]\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h: In instantiation of 'void produce_compiler_warnings() [with int i = 1]':\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:18:35:   required from 'void bar() [with int i = 2]'\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:9:11:   required from 'void produce_compiler_warnings() [with int i = 2]'\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:18:35:   required from 'void bar() [with int i = 3]'\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:9:11:   required from 'void produce_compiler_warnings() [with int i = 3]'\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:18:35:   required from 'void bar() [with int i = 4]'\nD:/SomeFolder/ThatLeads/ToMy/TestProject/AndDoesNotExist/InReality/produce_compiler_warnings.h:9:11:   [ skipping 8 instantiation contexts, use -ftemplate-backtrace-limit=0 to disable ]");

    /*
    if (argc > 1)
    {
        istringstream ss(argv[1]);
        ss >> n_warnings;
    }
    if (argc > 2)
    {
        istringstream ss(argv[3]);
        ss >> work_us;
    }
    if (argc > 3)
    {
        istringstream ss(argv[3]);
        ss >> sleep_us;
    }
    */
    
    cout << "Will produce " << n_warnings << " fake warnings each loop. " << endl;
    cout << "Will work for " << work_us << " microseconds each loop. " << endl;
    cout << "Will be sleeping for " << sleep_us << " microseconds each loop. " << endl;
    
    auto app_start = chrono::system_clock::now();
    while(!quit)
    {
        // Busy loop for work_us microseconds
        auto work_loop_start = chrono::system_clock::now();
        while(true)
        {
            auto now = chrono::system_clock::now();
            auto interval = chrono::duration_cast<chrono::microseconds>(now - work_loop_start);
            if ( interval.count() > work_us)
            {
                break;
            }   
        }
        // Output n_warnings warnings
        for (int i=0;i<n_warnings;++i)
        {
            cout << warning << endl;
        }
        // Sleep for sleep_us microseconds
        this_thread::sleep_for(chrono::microseconds(sleep_us));
        
        auto now = chrono::system_clock::now();
        auto time_running = chrono::duration_cast<chrono::seconds>(now - app_start);
        if (time_running.count() > timeout_s)
        {
            break;
        }
    }

    return 0;
}
