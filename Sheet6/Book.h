#ifndef BOOK_H
#define BOOK_H
#include <string>


class Book {
private:
    std::string _title;
    std::string _author;
    std::string _keywords;
public: 
    // Generates an object Book with 3 strings
    Book(const std::string title, const std::string author, std::string keywords);
    std::string getTitle();
    std::string getAuthor();
    std::string getKeywords();
    void getAllInfo();
};

#endif