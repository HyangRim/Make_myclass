#include <iostream>

struct node {
	struct node* next;
	int value;
};

node* head = NULL;
node* tail = NULL;

void make_newnode(int value) {
	node* newnode = new node;
	newnode->value = value;
	newnode->next = NULL;
	
	if (head == NULL) {
		head = tail = newnode;
	}
	else {
		tail->next = newnode;
		tail = newnode;
	}
}

void add_front(int value) {
	node* newnode = new node;
	newnode->value = value;
	newnode->next = NULL;
	if (head == NULL) {
		head = tail = newnode;
	}
	else {
		newnode->next = head;
		head = newnode;
	}
}

void view_allnode() {
	node* cur = head;
	std::cout << "Start All node view\n";
	while (cur != NULL) {
		std::cout << cur->value << "\n";
		cur = cur->next;
	}

	std::cout << "End All node View\n";
}

void delete_from_value(int num) {
	if (head == NULL)return;
	if (head->value == num) {
		node* cur = head;
		free(cur);
		head = head->next;
		return;
	}

	node* cur = head;
	node* curr = head->next;

	while (curr != NULL) {
		if (curr->value == num) {
			cur->next = curr->next;
			free(curr);
			return;
		}
		cur = curr;
		curr = cur->next;
	}
}

void delete_front() {
	if (head == NULL)return;
	node* cur = head;
	node* curr = head->next;

	free(cur);
	head = curr;
}

void delete_back() {
	if (head == NULL)return;
	if (head->next == NULL) {
		node* cur = head;
		free(cur);
		head = NULL;
		tail = NULL;
		return;
	}
	node* cur = head;
	node* curr = head->next;

	while (curr != NULL) {
		if (curr->next == NULL) {
			free(curr);
			tail = cur;
			tail->next = NULL;
			return;
		}
		cur = cur->next;
		curr = curr->next;
	}
}

int main() {
	while (1) {
		int oper, value;
		std::cout << "Insert Operation :";
		std::cin >> oper;
		if (oper == 0) {		//Add back
			std::cin >> value;
			make_newnode(value);
		}
		else if (oper == 1) {	//cout Allnode
			view_allnode();
		}
		else if (oper == 2) {	// delete from value
			std::cin >> value;
			delete_from_value(value);
		}
		else if (oper == 3) {	//delete front
			delete_front();
		}
		else if (oper == 4) {	//delete back
			delete_back();
		}
		else if (oper == 5) {	//add front
			std::cin >> value;
			add_front(value);
		}
		
	}
	return 0;
}