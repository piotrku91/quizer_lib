#pragma once

template <typename T> class stacky {
private:
	struct node {
		T data;
		node *next;
	};

	node *head;

public:
	stacky() : head(nullptr){};
	stacky(const std::initializer_list<T>& x){
	  for (auto& item : x)
	  {
	    push(item);
	  };
	  
	  
	};

	void push(const T &newdata) {
		node *tmpnode = new node();
		tmpnode->data = newdata;
		tmpnode->next = head;
		head = tmpnode;
	};

	void pop() {
		if (!isEmpty()) {
			node *tmpnode = head;
			head = head->next;
			delete tmpnode;
		};
	};

	bool isEmpty() {
		return (head == nullptr);
	};

	void clear() {
		while(!isEmpty())
		{
			pop();
		}
	};

	T top() {
		return head->data;
	};
};
