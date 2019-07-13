#include "Book.h"
#include <iostream>
Book::Book(const std::string title, const std::string author, std::string keywords):
    _title(title),_author(author),_keywords(keywords)
{
}
std::string Book::getTitle(){
    return _title;
}
std::string Book::getAuthor(){
    return _author;
}
std::string Book::getKeywords(){
    return _keywords;
}
void Book::getAllInfo(){
    std::cout<<"Book found!\nTitle: "<<_title<<"\nAuthor: "<<_author<<
        "\nKeywords: "<<_keywords<<std::endl;
}