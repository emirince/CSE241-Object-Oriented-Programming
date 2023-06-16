#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "exception.h"
#include "Catalog.h"

namespace PA6{

class Book: public Catalog<Book>{
public:
    Book(const std::string& title, const std::string& authors, const std::string& year, const std::string& tags)    //constructor
        : title(title), authors(authors), year(year), tags(tags), type("book") {}

    ~Book(){}   //destructor

    //getters
    std::string getTitle() const { return title; }
    std::string getAuthors() const { return authors; }
    std::string getYear() const { return year; }
    std::string getTags() const { return tags; }
    std::string getArtist() const { throw CommandWrong(); }
    std::string getGenre() const { throw CommandWrong(); }
    std::string getDirector() const { throw CommandWrong(); }
    std::string getStarring() const { throw CommandWrong(); }
    std::string getType() const { return type; }

    //setters
    void setTitle(const std::string _title){ title = _title; } 
    void setAuthors(const std::string _authors){ authors = _authors; }
    void setYear(const std::string _year){ year = _year; }
    void setGenre(const std::string _tags){ tags = _tags; }

private:
    std::string title;
    std::string authors;
    std::string year;
    std::string tags;
    std::string type;
};
}
#endif