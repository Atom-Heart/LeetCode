class MyCircularDeque {
public:
	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k) {
		n = k + 1;
		buf = vector<int>(n);
		head = 0;
		tail = 0;
	}

	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (!isFull()) {
			head = (head - 1 + n) % n;
			buf[head] = value;
			return true;
		}
		return false;
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (!isFull()) {
			buf[tail] = value;
			tail = (tail + 1) % n;
			return true;
		}
		return false;
	}

	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (!isEmpty()) {
			head = (head + 1) % n;
			return true;
		}
		return false;
	}

	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (!isEmpty()) {
			tail = (tail - 1 + n) % n;
			return true;
		}
		return false;
	}

	/** Get the front item from the deque. */
	int getFront() {
		if (!isEmpty()) {
			return buf[head];
		}
		return -1;
	}

	/** Get the last item from the deque. */
	int getRear() {
		if (!isEmpty()) {
			return buf[(tail - 1 + n) % n];
		}
		return -1;
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return head == tail;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		int sz = n;
		return ((tail + 1) % sz) == head;
	}
	vector<int> buf;
	int head, tail;
	int n;
};