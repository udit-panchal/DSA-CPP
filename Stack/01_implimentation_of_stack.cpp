#include <iostream>
using namespace std;

class Stack
{
    // properties
public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // operations

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
            cout << "Stack OverFlow" << endl;
    }

    void pop()
    {
        if (top >= -1)
        {
            cout << "Element poped" << endl;
            top--;
        }
        else
            cout << "Stack is Underflow" << endl;
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        return (top == -1) ? true : false;
    }
};

int main()
{
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout << "Top of the stack : " << st.peek() << endl;

    st.pop();

    cout << "Top of the stack : " << st.peek() << endl;
}