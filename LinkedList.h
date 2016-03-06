class LinkedList{
	private:
		struct Node{
			int data;
			Node * next;
		};
		int numberOfNodes;
		Node *root;
		Node createNode();
	public:
		LinkedList();
		void addNode(int);
		void insertNode(int,int);
		void deleteNode(int);
		int getData(int);
		int getNumberOfNodes();
		void printList();
		void deleteDuplicateNodes();
};
