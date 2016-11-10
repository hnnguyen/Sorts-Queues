#include "arrayIntQueue.cpp"
#include <iostream>
using namespace std;

//Sample output:
 
int main() {
    queue q(3);

    q.push(6);
    cout << "After pushing 6 to the queue..." << endl;
    q.print();

    q.push(3);
    cout << "After pushing 3 to the queue..." << endl;
    q.print();
    
    q.push(8);
    cout << "After pushing 8 to the queue..." << endl;
    q.print();

    q.pop();
    cout << "After popping from the queue..." << endl;
    q.print();

    q.push(2);
    cout << "After pushing 2 to the queue..." << endl;
    q.print();
    
    q.pop();
    cout << "After popping from the queue..." << endl;
    q.print();
   
    q.push(9);
    cout << "After pushing 9 to the queue..." << endl;
    q.print();

    q.pop();
    cout << "After popping from the queue..." << endl;
    q.print();
    
    q.pop();
    cout << "After popping from the queue..." << endl;
    q.print();
   
    q.pop();
    cout << "After popping from the queue..." << endl;
    q.print();

    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Push 1, 2, 3 in this order to the queue ...";
    cout << endl << "The size of the queue is " << q.size() << "." << endl;
   
    cout << "Pop the elements out from the queue, starting from front..." << endl;

    while ( !q.empty() ) {
          cout << q.front() << " ";
          q.pop();
    }
    cout << endl;

    return 0;

}

