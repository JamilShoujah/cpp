// Lesson 13: threads
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono> // used to simulate delay
#include <vector>

using namespace std;

// Concurrency VS Parallelism:

    // Concurrency:
        // Definition: Handling multiple tasks at the same time, but not necessarily simultaneously.
        // How: Tasks take turns using the CPU — often seen in systems with a single core.
            // ex: Imagine one tailor who has multiple pieces of clothing to sew. They work on one shirt for a bit, 
            // then pause and work on pants, then switch to a jacket — doing a bit of each in turn.

            // => They're juggling tasks, not finishing them all at once — that's concurrency.

    //  Parallelism
        // Definition: Performing multiple tasks at the exact same time.
        // How: Tasks are run on multiple cores or processors simultaneously.
            // ex:  imagine three tailors, each with their own sewing machine, working on different 
            // clothes at the same time.
            
            // => Tasks are getting done simultaneously — that's parallelism.

// Why Parallelism & Concurrency?
    // Improve performance 
    // Critical for modern apps 
    // Enables responsive UIs and real-time systems
    // Allows for effcient use of system resources


// Threads and Processes
// these are operating system level material but its crucial to understand them

    // What Is a Process?
        // A process is an independent program in execution.
        // Each process has:
            // Its own memory space
            // Its own resources (like file handles, registers)
            // At least one thread (called the main thread)

        // Opening Chrome, Word, or any app launches a process.

    // What Is a Thread?
        // A thread is the smallest unit of execution within a process.
        // Threads share the same memory and resources of the process they belong to.
        // A process can have multiple threads running concurrently.

    // In a browser (process), one thread might handle the UI, another might load a webpage,
    // and another plays video — all part of the same program.

// Example of threads and processes:
    // Process = The Entire Restaurant
        // The restaurant as a whole is a process. It has its own space, kitchen, staff, and tools — 
        // completely independent from other restaurants.

    // Threads = Staff Members in That Restaurant
        // Inside the restaurant, you have multiple staff (threads):
            // One takes orders (UI)
            // One cooks food (background task)
            // One washes dishes (maintenance)
            // One serves customers (output)

    // All of them work simultaneously within the same restaurant, sharing the same kitchen, menus, and space 
    //  — just like threads in a process sharing memory and resources.

// Dealing with threads in cpp
    // Since C++11, the Standard Library offers direct support for multithreading using the <thread> header.

    // Creating Threads Using std::thread
    // You create a thread by instantiating a std::thread object and passing it a callable (e.g., a function, lambda, or functor).

    // We call t.join(); in C++ to make sure the main thread waits for the worker thread to finish before it continues (or exits). 

    // ex:

    void printMessage() {
        cout << "Hello from worker thread!\n";
    }

    void ExampleOne() {
        // Creates a new thread of execution that runs the printMessage() function
        thread t(printMessage);

        // Blocks the current (main) thread until t finishes execution.
        // This ensures that the main thread waits for the worker thread to complete
        t.join();

        // Note:
        // In this example, ExampleOne mimics what would typically happen in main().
        // Both the main thread and the new thread (t) run concurrently.
        // Without calling join(), ExampleOne could finish and exit before
        // the printMessage thread completes, causing:
        // - unfinished output,
        // - missing messages, or
        // - crashes if shared resources are destroyed prematurely.

        cout << "Back in main thread.\n";
    }

    // IRL Example:

        // Imagine you're cooking dinner (main thread), and you ask your sibling to chop vegetables (a new thread). 
        // Two scenarios can happen:

        // scenario 1:
            // You tell your sibling to chop the veggies.
            // Then you immediately start cooking without waiting. But the veggies aren’t chopped yet 
            //— or worse, you serve the food before they’re even ready.

            // This is like not calling join() — the thread is still running, but the main task finishes or exits. 
            // That leads to incomplete or incorrect results (just like a half-made dinner).

        // Scenario 2:
            // You tell your sibling to chop the veggies
            // then you wait until they’re done before using the veggies in the dish.

            // This is like calling t.join() — you wait for the thread to finish before proceeding. The dinner turns out well.

    // Recap on .join()
    // join() blocks the calling thread (usually main) until the thread finishes execution.
        // It’s synchronous.
        // Prevents premature termination of threads.
        // Must be called once per thread, otherwise leads to an exception or crash.

    // Detach()
        // Makes the thread run independently (in the background). The system cleans it up automatically once it finishes.
        // in other words, When you call t.detach() on a thread, you're telling the program: 
            // "Let this thread run on its own. I don’t care when or how it finishes — just don’t wait for it."
        // ex:

        #include <chrono> // just to make the thread sleep to simulate working for a long time

        void backgroundTask() {
            this_thread::sleep_for(std::chrono::seconds(2));
            // std::this_thread is a namespace in C++ that provides utilities specifically for the currently running thread
            // — the one that's executing the current code. It’s part of the <thread> header.
            cout << "Finished background task.\n";
        }

        void ExampleTwo() {
            thread t(backgroundTask);
            t.detach(); // Don't wait — let it run on its own
            cout << "Main thread ends immediately.\n";
        }

        // output:
        // Main thread ends immediately.

        // And nothing else — because the detached thread is still sleeping for 2 seconds, but the program likely exits before it finishes.

        // To See the Background Output:
        // after ExampleTwo() is called to keep the process alive:
        // checkout Example 3 below..


        void ExampleThree(){
            thread t(backgroundTask);
            t.detach();  // runs independently

            cout << "Main thread ends, but we sleep so detached can finish...\n";
            this_thread::sleep_for(std::chrono::seconds(3));
        }


// Synchronization with mutex
    // Why Synchronization Is Needed
        // When multiple threads are accessing and modifying the same data (shared resource) at the same time, there's a risk of:
            // Race conditions: where the outcome depends on unpredictable timing
            // Data corruption: threads overwrite or read inconsistent values

        // This happens because CPU threads can interrupt each other at any moment.
        // this is where mutex comes into play


    // std::mutex
        // A mutex ensures that only one thread at a time can access the critical section of code that manipulates shared data.
        // Think of it like a lock on a bathroom door — only one person (thread) can enter at a time.

        // ex:
            mutex mtx;

            void criticalSection() {
                mtx.lock();   // Lock access

                // Access shared resource here

                mtx.unlock(); // Unlock when done
            }
            // But this has problems if you forget to unlock()


    // std::lock_guard<std::mutex> — The Safer Option
        // This is a C++ wrapper that automatically locks the mutex when it’s created and unlocks it when it goes out of scope.

        // Why it’s better:
            // No need to manually unlock
            // Prevents deadlocks due to forgotten unlock() calls
            // Follows RAII (Resource Acquisition Is Initialization)

        // ex:
            mutex mtx2;

            void safeCriticalSection() {
                std::lock_guard<std::mutex> lock(mtx2);
                // Safe access to shared data
                // lock is automatically released when function ends or an exception is thrown
            }


// Multithreading programs: concurrency issues

    // Race Condition:
        // A race condition happens when two or more threads access shared data at the same time, 
        // and the final result depends on the timing of their execution.

        // IRL example:
            // Imagine you and your sibling both have access to the same bank account, which currently has $100.
            // You both go to different ATMs at the same time, and each of you tries to withdraw $100.

            // Both ATMs check the balance — they see $100.
            // Both ATMs think there's enough money.
            // Both proceed to withdraw $100.
            // The account ends up at - $100. (you both get $100 when only one should have)

        // Why this is a race condition:
            // Both ATMs (threads) read the shared balance at the same time, and both decide it’s okay to withdraw,
            // but they’re not aware of each other’s actions. Because they race to update the balance, you get a wrong final result.

            
        // code example:
        // Shared bank account balance (global variable)
        int balance = 100;

        // Simulates a withdrawal by a user from the shared account
        void withdraw(const string& name, int amount) {
            // Check if the balance is enough to withdraw the requested amount
            if (balance >= amount) {
                cout << name << " sees balance: $" << balance << "\n";

                // Simulate a small delay (e.g., processing time at an ATM)
                this_thread::sleep_for(chrono::milliseconds(100));

                // After the delay, subtract the withdrawal amount from the balance
                balance -= amount;

                cout << name << " successfully withdrew $" << amount << ". Remaining balance: $" << balance << "\n";
            } else {
                // If there's not enough money in the account
                cout << name << " tried to withdraw $" << amount << " but not enough balance.\n";
            }
        }

        void ExampleFour() {
            // Start two threads, each trying to withdraw $100 from the same account
            thread user1(withdraw, "User1", 100);
            thread user2(withdraw, "User2", 100);

            // Wait for both threads to finish before exiting the main function
            user1.join();
            user2.join();

            // Show the final balance (may be negative due to race condition!)
            cout << "Final balance: $" << balance << "\n";
        }

        // Possible output (incorrect):
            // User1 sees balance: $100
            // User2 sees balance: $100
            // User1 successfully withdrew $100. Remaining balance: $0
            // User2 successfully withdrew $100. Remaining balance: $-100
            // Final balance: $-100


        // Consequences:
            // Unpredictable results
            // Hard-to-find bugs (non-deterministic behavior)
            // Data corruption

// -----------------------------------------------------------------------------------------------------------------------------------------

    // Deadlocks:
        // A deadlock occurs when two or more threads are each waiting on a resource held by the other, and none can proceed.

        // IRL Example: Two Friends, Two Forks
            // Two friends, Alice and Bob, are about to eat dinner.
            // There are two forks on the table. 

            //To eat, each person needs both forks. 

            // Alice picks up one fork first and Bob picks up the other fork first.
            // Then both wait for the other fork to be free.

            // What happens:
                // Alice picks up the left fork.
                // At the same time, Bob picks up the right fork.

            // Now:
                // Alice waits for the right fork (held by Bob).
                // Bob waits for the left fork (held by Alice).

            // Both are stuck, waiting for a resource that will never be released because they’re waiting on each other

        // code example:

            // Simulating two shared resources
            mutex resourceA;
            mutex resourceB;

            // Thread function that locks resource A first, then B
            void task1() {
                cout << "Task1: Trying to lock Resource A...\n";
                resourceA.lock();
                cout << "Task1: Locked Resource A.\n";

                this_thread::sleep_for(chrono::milliseconds(100)); // simulate work

                cout << "Task1: Trying to lock Resource B...\n";
                resourceB.lock(); // deadlock happens here if task2 already has B
                cout << "Task1: Locked Resource B.\n";

                cout << "Task1: Doing work with both resources.\n";

                resourceB.unlock();
                resourceA.unlock();
            }

            // Thread function that locks resource B first, then A
            void task2() {
                cout << "Task2: Trying to lock Resource B...\n";
                resourceB.lock();
                cout << "Task2: Locked Resource B.\n";

                this_thread::sleep_for(chrono::milliseconds(100)); // simulate work

                cout << "Task2: Trying to lock Resource A...\n";
                resourceA.lock(); // deadlock happens here if task1 already has A
                cout << "Task2: Locked Resource A.\n";

                cout << "Task2: Doing work with both resources.\n";

                resourceA.unlock();
                resourceB.unlock();
            }

            void ExampleFive() {
                thread t1(task1);
                thread t2(task2);

                t1.join();
                t2.join();

                cout << "Main thread done.\n";
            }

        // Output:
            // depends on where the program gets stuck but usually nothing
            // the program will not result in an output because neither thread can get the second lock they’re waiting for.

        // Consequences:
            // Program freezes permanently
            // No error thrown — hard to detect without analysis tools
// -----------------------------------------------------------------------------------------------------------------------------------------

    // Livelocks:
        // A livelock is like deadlock, but instead of freezing, threads keep changing their state in response to each other 
        // — yet make no actual progress.
        
        //  IRL Example:
            // Two people trying to pass each other in a hallway:
            // Both step left → still blocked
            // Both step right → still blocked
            // They keep dancing without moving forward

            // In code terms:
            // Two threads repeatedly trying to acquire the same resource but politely backing off when the other one does too — endlessly.

        // code example:

            // Shared state variables (flags) for communication between threads
            bool task1Ready = false;  // Flag to indicate whether Worker 1 is ready
            bool task2Ready = false;  // Flag to indicate whether Worker 2 is ready
            mutex flagMutex;          // Mutex to protect access to the shared flags

            // Function representing Worker 1's behavior
            void politeWorker1() {
                while (true) {
                    {
                        // Lock the mutex before reading shared state
                        lock_guard<mutex> lock(flagMutex);
                        
                        // If Worker 2 is not ready, Worker 1 will wait
                        if (!task2Ready) {
                            cout << "Worker 1: Waiting for Worker 2 to be ready...\n";

                            // Simulate waiting (sleep) before retrying
                            this_thread::sleep_for(chrono::milliseconds(100));
                            continue; // Retry loop
                        }
                    }

                    // At this point, Worker 2 is ready — but Worker 1 tries to be polite and backs off
                    cout << "Worker 1: Noticed Worker 2 is ready, backing off politely.\n";

                    {
                        // Lock mutex and set its own ready flag to false — "backing off"
                        lock_guard<mutex> lock(flagMutex);
                        task1Ready = false;
                    }

                    // Pause before retrying
                    this_thread::sleep_for(chrono::milliseconds(100));

                    {
                        // Lock mutex again and mark itself as ready to try again
                        lock_guard<mutex> lock(flagMutex);
                        task1Ready = true;
                    }
                }
            }

            // Function representing Worker 2's behavior (same logic but mirrored)
            void politeWorker2() {
                while (true) {
                    {
                        lock_guard<mutex> lock(flagMutex);
                        if (!task1Ready) {
                            cout << "Worker 2: Waiting for Worker 1 to be ready...\n";
                            this_thread::sleep_for(chrono::milliseconds(100));
                            continue;
                        }
                    }

                    cout << "Worker 2: Noticed Worker 1 is ready, backing off politely.\n";

                    {
                        lock_guard<mutex> lock(flagMutex);
                        task2Ready = false;
                    }

                    this_thread::sleep_for(chrono::milliseconds(100));

                    {
                        lock_guard<mutex> lock(flagMutex);
                        task2Ready = true;
                    }
                }
            }

            void ExampleSix() {
                {
                    // Initialize both workers as "ready"
                    lock_guard<mutex> lock(flagMutex);
                    task1Ready = true;
                    task2Ready = true;
                }

                // Start both threads, representing the two polite workers
                thread t1(politeWorker1);
                thread t2(politeWorker2);

                // Let the program run for 5 seconds so we can observe the livelock
                this_thread::sleep_for(chrono::seconds(5));

                cout << "Main: Ending program (livelock should be observable).\n";

                // Detach threads so they continue independently (no join)
                t1.detach();
                t2.detach();
            }

        // What’s happening here?
            // Both workers are being "polite" and backing off when they see the other is ready.
            // They keep changing their states and retrying, but never actually move forward or finish a task.
            // It simulates real-life scenarios where too much cooperation causes nothing to get done.

        // Consequences:
            // CPU usage remains high (unlike deadlock)
            // No work is accomplished

// -----------------------------------------------------------------------------------------------------------------------------------------

    // Starvation
        // Starvation happens when a thread never gets access to the resources it needs because other threads are always favored.

        // IRL Example:
            // In a busy office, there's one shared printer.
            // Managers have access to a "priority print" button that jumps their document to the front of the print queue.
            // Interns submit documents that wait in line normally.
            // Throughout the day, managers keep submitting new high-priority documents. As a result, the intern’s document stays stuck 
            // in the queue and never prints.

            // Starvation happens because the intern’s job is always bypassed by higher-priority jobs.

        // code example:
        mutex counterMutex;
        int sharedCounter = 0; // Shared resource (a simple counter)
        bool running = true;   // Flag to control thread lifetime

        // High-priority worker: accesses the counter quickly and frequently
        void highPriorityWorker(int id) {
            while (running) {
                if (counterMutex.try_lock()) { // Try locking without waiting
                    ++sharedCounter;
                    cout << "[High " << id << "] Incremented counter to: " << sharedCounter << endl;
                    counterMutex.unlock();
                }
                this_thread::sleep_for(chrono::milliseconds(10)); // Short delay = more chances to run
            }
        }

        // Low-priority worker: tries to update counter but gets blocked
        void lowPriorityWorker() {
            while (running) {
                // Simulate trying to acquire the lock, but gets delayed
                if (counterMutex.try_lock()) {
                    ++sharedCounter;
                    cout << ">>> [LOW] Finally incremented counter to: " << sharedCounter << " <<<\n";
                    counterMutex.unlock();
                    this_thread::sleep_for(chrono::milliseconds(500)); // Works slowly
                } else {
                    // Print message when it can't access the shared resource
                    cout << "[LOW] Waiting for lock...\n";
                }

                this_thread::sleep_for(chrono::milliseconds(100));
            }
        }

        void ExampleSeven() {
            vector<thread> threads;

            // Start 5 high-priority threads
            for (int i = 1; i <= 5; ++i) {
                threads.emplace_back(highPriorityWorker, i);
            }

            // Start 1 low-priority thread
            thread lowThread(lowPriorityWorker);

            // Run for 5 seconds
            this_thread::sleep_for(chrono::seconds(5));
            running = false;

            // Join all threads
            for (auto& t : threads) {
                if (t.joinable()) t.join();
            }

            if (lowThread.joinable()) lowThread.join();

            cout << "Final counter value: " << sharedCounter << endl;

        }

        // output:
            // The high-priority threads dominate the lock.
            // The low-priority thread rarely (or maybe never) gets to increment the counter.

            // You’ll see messages like: [LOW] Waiting for lock...
            // repeated many times, indicating starvation.

        // Consequences:
            // Unfair scheduling
            // Some operations might never complete


// Avoiding concurrency issues:

    // Avoiding Race Conditions
        // - Use mutexes or locks to protect shared resources:
            // ex:
                std::mutex m;
                int sharedCounter = 0;

                void safeIncrement() {
                    std::lock_guard<std::mutex> guard(m); // Automatically locks and unlocks
                    ++sharedCounter;
                }

        // - Use atomic variables for simple operations:
            // ex:
                std::atomic<int> sharedCounter{0};

                void safeAtomicIncrement() {
                    ++sharedCounter;
                }

        // - Prefer immutable or thread-local data where possible.

    
    // Avoiding Deadlocks
        // - Always lock multiple mutexes in a fixed global order:
            // ex:
                std::mutex m1, m2;

                void threadA() {
                    std::lock(m1, m2); // Locks both safely in a deadlock-free way
                    std::lock_guard<std::mutex> lock1(m1, std::adopt_lock);
                    std::lock_guard<std::mutex> lock2(m2, std::adopt_lock);
                    // Do work
                }
        // - Avoid holding locks for too long — keep critical sections small.
        // - Use std::lock() or scoped lock (std::scoped_lock) for locking multiple mutexes.
        // - Avoid circular wait — don’t design systems where threads must acquire resources in loops.

    //  Avoiding Livelocks
        // - Introduce random backoff/retry delays
        // - Design logic to guarantee progress — ensure some thread eventually succeeds.
        // - Avoid overreacting to the state of other threads.


    // Avoiding Starvation
        // - Use fair locks, e.g., with condition variables, or semaphores that queue access:
                // Semaphores are low-level synchronization primitives used in concurrent programming to control access to shared resources. 
                // Think of a semaphore as a counter that manages how many threads can access a particular resource or section of code at 
                // the same time. more on that when we get to the operating systems course
        // ex:
            std::condition_variable cv;
            std::mutex m;
            bool ready = false;

            void worker() {
                std::unique_lock<std::mutex> lock(m);
                cv.wait(lock, [] { return ready; }); // waits fairly
                // Do work
            }

        // - Avoid priority inversion — if using thread priorities, ensure low-priority threads are not blocked indefinitely.
        // - Use scheduling strategies or thread pools that fairly distribute load.

// General Best Practices for Concurrency
    // Keep shared state to a minimum. Favor message-passing (e.g., queues) over shared memory when possible.
    // Use thread-safe data structures like std::queue with mutex or concurrent_queue (if available).
    // Prefer higher-level concurrency abstractions like:
    // std::async (for simple futures),
    // Thread pools,
    // std::promise/std::future for communication.
    // Test with thread sanitizers (-fsanitize=thread in GCC/Clang) to detect data races.
