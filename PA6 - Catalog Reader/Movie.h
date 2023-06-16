#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "exception.h" 

namespace PA6{

class Movie: public Catalog<Movie>{
public:
    Movie(const std::string& title, const std::string& director, const std::string& year, const std::string& genre, const std::string& starring)    //constructor
        : title(title), director(director), year(year), genre(genre), starring(starring), type("movie") {}

    ~Movie(){}  //destructor

    //getters
    std::string getTitle() const { return title; } 
    std::string getDirector() const { return director; }
    std::string getYear() const { return year; }
    std::string getGenre() const { return genre; }
    std::string getStarring() const { return starring; }
    std::string getArtist() const { throw CommandWrong(); }
    std::string getTags() const { throw CommandWrong(); }
    std::string getAuthors() const { throw CommandWrong(); }
    std::string getType() const { return type; }

    //setters
    void setTitle(const std::string _title){ title = _title; } 
    void setDirector(const std::string _director){ director = _director; }
    void setYear(const std::string _year){ year = _year; }
    void setGenre(const std::string _genre){ genre = _genre; }
    void setStarring(const std::string _starring){ starring = _starring; }

private:
    std::string title;
    std::string director;
    std::string year;
    std::string genre;
    std::string starring;
    std::string type;
};

}
#endif
