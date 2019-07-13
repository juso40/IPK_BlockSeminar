#include "List.h"
#include <iostream>

List::List(int data)
{
    _root = new node;
    _root->data=data;
    _root->next=nullptr;
}
List::~List()
{
    if (_root==nullptr){
    }else{
        node *temp;
        temp=_root;
        while (temp!=nullptr){
            _root=temp;
            temp=temp->next;
            delete _root;
        }
    }
}

void List::add(int data){

    node *tail = _root;//starts at the first entry
    node *temp = new node;//to add the new node
    temp->data = data;//sets the new notes data
    temp->next = nullptr;//the newest node will be added to the back therefore it has to point to 0
    //goes to the last node and stops
    while (tail->next!=nullptr){
        tail=tail->next;
    }
    tail->next=temp;//connects the last node to the new node
   
}

void List::erase(int data){
    //still need to figure out how to delete first and last node :(
    std::cout<<"Going to erase all: "<< data <<std::endl;
    node *temp_current = nullptr;
    node *temp_previous = nullptr;

    if (_root->next ==nullptr){
        delete _root;
    }else{
        temp_current=_root;

        while (temp_current!=nullptr){
            if (temp_current->data==data){
                temp_current=temp_current->next;
                delete temp_previous->next;
                temp_previous->next=temp_current;
            }
            temp_previous=temp_current;
            temp_current=temp_current->next;
        }
    }
}

void List::print(){
    node *temp;
     if (_root==nullptr){
        std::cout<<"No data to print!"<<std::endl;
    }else{
        temp=_root;
        while (temp!=nullptr){
            std::cout<<temp->data<<std::endl;
            temp=temp->next;
        }
    }
}