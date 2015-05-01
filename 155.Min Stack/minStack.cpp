#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class MinStack {
public:
    void push(int x) {
        if(size == max_size) {
            int *new_space = new int[max_size * 2];
            copy(stack_space, stack_space + size, new_space);
            max_size *= 2;
            delete [] stack_space;
            stack_space = new_space;
        }
        stack_space[size++] = x;
        int min = x;
        if(!min_val.empty() && min > min_val.back()) min = min_val.back();
        min_val.push_back(min);
    }

    void pop() {
        assert(!empty());
        min_val.pop_back();
        --size;
    }

    int top() {
        assert(!empty());
        return stack_space[size - 1]; 
    }

    int getMin() {
        assert(!empty());
        return min_val.back();
    }
    
    bool empty() {
        return size == 0;
    }
private:
    const int init_size = 10;
    int *stack_space = new int[init_size];
    int size = 0;
    int max_size = init_size;;
    vector<int> min_val;
};

int main() {
    MinStack stk;
    for(int i = 0; i < 20; ++i) {
        stk.push(20 - i);
        cout << stk.getMin() << endl;
    }

    while(!stk.empty()) {
        stk.pop();
    }
    return 0;
}
