#ifndef LIBRARY_H
#define LIBRARY_H
#include<string>
#include"Book.h"
#include<vector>

class Library{
private:
    std::vector<Book> _Books;

public:
 
    void addBook(Book newBook);
    void searchTitle(std::string title);
    void searchKeyword(std::string keyword);
};
#endif