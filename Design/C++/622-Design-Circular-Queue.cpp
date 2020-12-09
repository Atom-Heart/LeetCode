/*
*解释一下为什么要创建一个k + 1大小的buffer，因为tail指向的是可插入空间。如果buffer大小为3，判断为空的条件是head==tail,那么插入1，2，3之后，tail指向下标0
*那么这个时候就不知道怎么去判断满了。所以需要最后一个空间当个标志位，如果tail指向那个最后一个空间了，那么就说明满了
*/
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        buf.resize(k + 1);
        head = tail = 0;
        n = k + 1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        buf[tail] = value;
        tail = (tail + 1) % n;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        head = (head + 1) % n;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return buf[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        /*这个操作最重要,万一tail是0怎么办？*/
        return buf[(tail + n - 1) % n];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(tail == head) return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if((tail + 1) % n == head) return true;
        return false;
    }
    vector<int> buf;
    int head;
    int tail;
    int n;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */