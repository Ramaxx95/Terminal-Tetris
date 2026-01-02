/*
  License: GPLv2
  Copyright (C) 2023 Martin Di Paola
  Taken from: https://github.com/eldipa/hands-on-threads
*/

#ifndef THREAD_H
#define THREAD_H

#include <exception>
#include <iostream>
#include <thread>
#include <vector>

// Implementacion de thread extraido de hands on thread
// Es una clase abstracta -> hay que definir 'run' y '~Thread' para
// toda clase que querramos que corra en un hilo diferente
class Thread {
private:
    std::thread thread;
    void main();

public:
    Thread();

    void start();

    void join();

    virtual void run() = 0;

    virtual ~Thread() {}

    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;

    Thread(Thread&& other) = delete;
    Thread& operator=(Thread&& other) = delete;
};

#endif  // THREAD_H
