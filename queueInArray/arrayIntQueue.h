//arrayIntQueue.h 
//found on ELC
//February 26, 2015

class queue {
    public:
        queue();
        queue(int capacity);
        ~queue();

        void push(int value);
        void pop();
        int front();
        int back();
        int size();
        bool empty();
        void print(); //print out the elements in the queue, from the front to the end

     private:
        int *arr; 
        int capacity;
        int f; //index of the current front element
        int r; //index of the current end element
        int n; //number of elements in the queue
        //we can detect the queue is full by (r+1)%capacity == f.
        //But to find out whether a queue is empty or not is not straightforward.
        //(r == f) may not means that a queue is empty.
        //Of course, everytime when the queue becomes empty, we can set f = r = -1
        //by resetting the values for f and r, but that is not intuitive.
        //Use a variable to record the number of elements in the queue
        //would make the code easier to understand.
}; //; cannot be omitted.
