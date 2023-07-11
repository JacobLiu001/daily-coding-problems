// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

vector<thread> threads;

void _task(function<void()> f, int n) {
    this_thread::sleep_for(chrono::milliseconds(n));
    f();
}

template<typename F>
void executeAfter(F f, int n) {
    threads.emplace_back(thread(_task, f, n));
}

void hello() {
    cout << "Hello, world!" << endl;
}

int main() {
    executeAfter(hello, 5000);
    executeAfter(hello, 1000);

    for (auto& t: threads) {
        t.join();
    }
    return 0;
}