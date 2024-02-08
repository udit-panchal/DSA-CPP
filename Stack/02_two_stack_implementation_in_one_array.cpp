#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    int top1;
    int top2;
    int size;
    int *arr;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // for first stack
    void push1(int data)
    {
        if ((top2 - top1 > 1) && (top1 < size - 1))
        {
            top1++;
            arr[top1] = data;
        }
        else
        {
            cout << "Stack-1 Overflow for : " << data << endl;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            cout << "Stack-1 Underflow" << endl;
            return -1;
        }
    }

    int peek1()
    {
        if (top1 >= 0)
            return arr[top1];
        else
        {
            cout << "Stack-1 is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty1()
    {
        return (top1 == -1) ? true : false;
    }

    // for second stack

    void push2(int data)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = data;
        }
        else
            cout << "Stack-2 Overflow for : " << data << endl;
    }

    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            cout << "Stack-2 Underflow" << endl;
            return -1;
        }
    }

    int peek2()
    {
        if (top2 < size)
        {
            return arr[top2];
        }
        else
        {
            cout << "Stack-2 is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty2()
    {
        return (top2 == size) ? true : false;
    }

    void print()
    {
        cout << "Array : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(10);

    st.push1(100);
    st.push1(200);
    st.push1(300);
    st.push1(400);
    st.push1(500);

    st.push2(110);
    st.push2(210);
    st.push2(310);
    st.push2(410);
    st.push2(510);

    // check for overflow condition
    st.push1(999);

    // poping elements
    st.pop1();
    st.pop2();
    st.pop1();
    st.pop2();
    st.pop1();
    st.pop2();
    st.pop1();
    st.pop2();

    st.pop1();

    cout << "Top of stack 1 is : " << st.peek1() << endl;
    cout << "Top of stack 2 is : " << st.peek2() << endl;
    st.print();

    return 0;
}