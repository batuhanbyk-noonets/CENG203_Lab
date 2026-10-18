#include "Labs.h"
#include "../Stack/Stack.h"
#include "../Stack/ArrayStack.h"
#include "../Queue/Queue.h"
#include "../Queue/CircularQueue.h"
#include <iostream>
#include <string>
using namespace std;

// ---------- Q4: reverse a string with a stack ----------
string reverseWithStack(const string& s)
{
    string result;
    Stack st;
    for (char c : s)
        st.push(c);
    int v;
    while (st.pop(v))
        result += (char)v;
    return result;
}

// Q4 d) bonus
bool isPalindrome(const string& s)
{
    return s == reverseWithStack(s);
}

// ---------- Q6: balanced brackets ----------
bool isBalanced(const string& s)
{
    Stack st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            int open;
            if (!st.pop(open))
                return false;           // kapatan var, acan yok
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{'))
                return false;           // tur uyusmuyor
        }
    }
    return st.isEmpty();                // kapanmamis parantez kalmamali
}

// ---------- Q8: a queue made of two stacks ----------
class TwoStackQueue
{
private:
    Stack inbox;                    // enqueue pushes here
    Stack outbox;                   // dequeue pops from here

public:
    void enqueue(int value)
    {
        inbox.push(value);
    }

    bool dequeue(int& value)
    {
        if (outbox.isEmpty()) {
            int v;
            while (inbox.pop(v))
                outbox.push(v);
        }
        return outbox.pop(value);
    }

    bool isEmpty() const
    {
        return inbox.isEmpty() && outbox.isEmpty();
    }
};

// ---------- Q9: undo / redo with two stacks ----------
class Editor
{
private:
    string text;
    Stack undoStack;                // characters typed, newest on top
    Stack redoStack;                // characters undone, newest on top

public:
    void type(char c)
    {
        text += c;
        undoStack.push(c);
        redoStack.clear();          // yeni yazma redo gecmisini siler
    }

    bool undo()
    {
        int c;
        if (!undoStack.pop(c))
            return false;
        text.pop_back();
        redoStack.push(c);
        return true;
    }

    bool redo()
    {
        int c;
        if (!redoStack.pop(c))
            return false;
        text += (char)c;
        undoStack.push(c);
        return true;
    }

    string getText() const
    {
        return text;
    }
};

void runWeek04()
{
    cout << "--- Week 4: Stacks and Queues ---" << endl;
    cout << boolalpha;              // print true/false instead of 1/0
    int v;

    // ---------- Q2: linked-list stack ----------
    Stack s;
    s.push(2);  s.push(7);  s.push(5);  s.push(8);
    cout << "[Q2] ";  s.display();
    s.pop(v);
    cout << "[Q2] pop -> " << v << endl;
    s.push(4);
    cout << "[Q2] ";  s.display();
    s.peek(v);
    cout << "[Q2] peek -> " << v << "  size = " << s.size() << endl;
    while (s.pop(v))
        cout << "[Q2] pop -> " << v << endl;
    cout << "[Q2] pop on empty = " << s.pop(v) << endl;

    // ---------- Q3: array stack ----------
    ArrayStack as;
    for (int i = 1; i <= 6; i++)
        cout << "[Q3] push(" << i * 10 << ") = " << as.push(i * 10) << endl;
    cout << "[Q3] ";  as.display();
    cout << "[Q3] isFull = " << as.isFull() << "  size = " << as.size()
         << endl;
    as.pop(v);
    cout << "[Q3] pop -> " << v << "  push(60) = " << as.push(60) << endl;
    cout << "[Q3] ";  as.display();

    // ---------- Q4: reverse a string ----------
    cout << "[Q4] " << reverseWithStack("CENG203") << endl;
    cout << "[Q4] " << reverseWithStack("stack") << endl;

    // ---------- Q5: linked-list queue ----------
    Queue q;
    q.enqueue(2);  q.enqueue(7);  q.enqueue(5);  q.enqueue(8);
    cout << "[Q5] ";  q.display();
    q.dequeue(v);
    cout << "[Q5] dequeue -> " << v << endl;
    q.enqueue(4);
    cout << "[Q5] ";  q.display();
    q.peek(v);
    cout << "[Q5] peek -> " << v << "  size = " << q.size() << endl;
    while (q.dequeue(v))
        cout << "[Q5] dequeue -> " << v << endl;
    cout << "[Q5] dequeue on empty = " << q.dequeue(v) << endl;
    q.enqueue(9);                   // works again after the queue was empty
    cout << "[Q5] ";  q.display();

    // ---------- Q6: balanced brackets ----------
    string tests[] = { "([]{})", "{[()()]}", "([)]", "((", ")(", "" };
    for (const string& t : tests)
        cout << "[Q6] \"" << t << "\" -> " << isBalanced(t) << endl;

    // ---------- Q7: circular queue ----------
    CircularQueue cq;
    for (int i = 1; i <= 6; i++)
        cout << "[Q7] enqueue(" << i << ") = " << cq.enqueue(i) << endl;
    cout << "[Q7] ";  cq.display();
    cq.dequeue(v);  cout << "[Q7] dequeue -> " << v << endl;
    cq.dequeue(v);  cout << "[Q7] dequeue -> " << v << endl;
    cout << "[Q7] enqueue(6) = " << cq.enqueue(6)
         << "  enqueue(7) = " << cq.enqueue(7) << endl;
    cout << "[Q7] ";  cq.display();

    // ---------- Q8: queue made of two stacks ----------
    TwoStackQueue tq;
    tq.enqueue(1);  tq.enqueue(2);  tq.enqueue(3);
    tq.dequeue(v);  cout << "[Q8] dequeue -> " << v << endl;
    tq.enqueue(4);
    while (tq.dequeue(v))
        cout << "[Q8] dequeue -> " << v << endl;
    cout << "[Q8] isEmpty = " << tq.isEmpty() << endl;

    // ---------- Q9: undo / redo ----------
    Editor ed;
    ed.type('a');  ed.type('b');  ed.type('c');
    cout << "[Q9] typed abc     -> \"" << ed.getText() << "\"" << endl;
    ed.undo();  ed.undo();
    cout << "[Q9] undo, undo    -> \"" << ed.getText() << "\"" << endl;
    ed.redo();
    cout << "[Q9] redo          -> \"" << ed.getText() << "\"" << endl;
    ed.type('x');
    cout << "[Q9] type x        -> \"" << ed.getText() << "\"" << endl;
    cout << "[Q9] redo after type = " << ed.redo() << endl;
}
