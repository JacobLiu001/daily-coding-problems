// This is not good practice but I can't be bothered.
#include "includes/universal.h"
using namespace std;

vector<thread> threads;

template<typename F>
void executeAfter(F f, int n) {
    threads.emplace_back([](F f1, int n1){
        this_thread::sleep_for(chrono::milliseconds(n1));
        f1();
    }, f, n);
}


void hello() {
    cout << "Hello, world!" << endl;
}

int main() {
    executeAfter(hello, 5000);
    executeAfter(hello, 4000);

    for (auto& t: threads) {
        t.join();
    }
    return 0;
}