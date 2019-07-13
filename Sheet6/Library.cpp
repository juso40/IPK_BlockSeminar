#include "Library.h"

void Library::addBook(Book newBook){
    _Books.push_back(newBook);
}

void Library::searchTitle(std::string title){
    for (auto& v: _Books){
        if (v.getTitle() == title){
            v.getAllInfo();
        }
    }

}

void Library::searchKeyword(std::string keyword){
    for (auto& v: _Books){
        if (v.getKeywords().find(keyword)!=std::string::npos){
            v.getAllInfo();
        }
    }
}