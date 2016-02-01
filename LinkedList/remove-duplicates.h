// Write code to remove duplicates from an unsorted linked list

class LinkedList {
private:
	struct Node{
		int data;
		Node* next;
	};
	Node* head;
  	bool isDuplicate();
public:
	void add();
  	void removeDuplicates();
  	//remove duplicates
}
