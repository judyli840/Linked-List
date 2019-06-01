// intlist.cpp
// Implements class IntList
//Judy Li, 1/28/19

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
	if(source.first == 0)
		first = 0;	
	Node *n = source.first;
	first = new Node;
	first->info = source.first -> info;
	Node *f = first;
    
    while(n->next){
        f->next = new Node;
        f = f->next;
        n = n->next;
        f->info = n->info;
    }
    f->next =0;	

}

// destructor deletes all nodes
IntList::~IntList() {
	Node *p = first;
	while(p){	
		Node *n = p->next;
		delete p;
		p = n;
    }
}


// return sum of values in list
int IntList::sum() const {
	int total = 0;
	Node *n = first;
	while (n){
		total += n->info;
		n = n->next;
	}
    return total; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
	Node *n = first;
	while (n){
		if(n->info == value)
			return true;
		n = n->next;
	}
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
	if(first == nullptr)
		return 0;
	Node *n = first;
	int largest = n->info;
	n = n->next;
	while (n){
		if (largest <= n->info)
			largest = n->info;
		n = n->next;
	}
	
    return largest; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
	if(first == nullptr)
		return 0.0;
	Node *n = first;
	double sum = 0;
	while (n){
		sum += n->info;
		n = n->next;
	}
    return sum/count(); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
	if(first == 0){
		first = new Node;
		first->info = value;
		first->next = NULL;
	}else{
	Node *n = new Node;
	n->info = value;
	n->next = first;
	first = n;
	}

}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(first == source.first){
        return *this;
    }
	
    if(source.first == 0){
	    first = nullptr;
	    return *this;
    }
    if (first){
	    Node *n = first;
	    while (n){
		    Node *temp = n->next;
		    delete n;
		    n=temp;
	    }
    }

  /*  IntList temp(source);
    first = temp.first;*/

	
   first = new Node;
    Node *t = first;
    Node *s = source.first;
    first->info = s->info;
    Node *prev = first;
    s = s->next;
    while (s){
      t = new Node;
      t->info = s->info;
      prev->next = t;
      prev = t;
      s = s->next;	  
    }

    t->next = 0;
   
    return *this;	
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
