#ifndef LIST_H
#define LIST_H

struct node{
    int data;
    node* next;
};


class List{
private:
    node *_root;

public:
    List(int data);
    ~List();
    void add(int data);
    void erase(int data);
    void print();

    
};


#endif