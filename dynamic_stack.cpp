#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray {
    int *data;
    int nextIndex;
    int capacity;

    public:

    // constructor
    StackUsingArray() {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    // return the number of elements present in my stack
    int size() {
        return nextIndex;
    }

    bool isEmpty() {

        /*
        if(nextIndex == 0) {
            return true;
        }
        else {
            return false;
        }
        */

       //the above comment statement can also be written as
       return nextIndex == 0;
    }

    //insert element
    void push(int element) {

        if(nextIndex == capacity) {
            int *newData = new int [2 * capacity];
            for (int i=0; i<capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
            // cout << "Stack full " << endl;
            // return;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // delete element
    int pop() {
        if(isEmpty()) {
            cout<<"Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top() {
        if(isEmpty()) {
            cout<<"Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

int main() {
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << s.isEmpty() << endl;
}
