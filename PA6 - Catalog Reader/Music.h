#ifndef MUSIC_H
#define MUSIC_H
#include <string>
#include "exception.h"

namespace PA6{

class Music: public Catalog<Music>{ 
public: 
    Music(const std::string& title, const std::string& artist, const std::string& year, const std::string& genre)   //constructor
        : title(title), artist(artist), year(year), genre(genre), type("music") {}

    ~Music(){}  //destructor

    //getters
    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    std::string getYear() const { return year; }
    std::string getGenre() const { return genre; }
    std::string getDirector() const { throw CommandWrong(); }
    std::string getStarring() const { throw CommandWrong(); }
    std::string getTags() const { throw CommandWrong(); }
    std::string getAuthors() const { throw CommandWrong(); }
    std::string getType() const { return type; }

    //setters
    void setTitle(const std::string _title){ title = _title; } 
    void setArtist(const std::string _artist){ artist = _artist; }
    void setYear(const std::string _year){ year = _year; }
    void setGenre(const std::string _genre){ genre = _genre; }
    
private:
    std::string type;
    std::string title;
    std::string artist;
    std::string year;
    std::string genre;
};
}
#endif