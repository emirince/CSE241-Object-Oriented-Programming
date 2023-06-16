#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <string>
#include <vector>
//forward decleration

namespace PA6{

template<class T>       
class Catalog;

//teplate title comparer
template<class T>
bool compareTitle(const T& left,const T& right){
    return left.getTitle() < right.getTitle();
}

//teplate artist comparer
template<class T>
bool compareArtist(const T& left, const T& right){
    return left.getArtist() < right.getArtist();
}

//teplate year comparer
template<class T>
bool compareYear(const T& left, const T& right){
    return left.getYear() < right.getYear();
}

//teplate genre comparer
template<class T>
bool compareGenre(const T& left, const T& right){
    return left.getGenre() < right.getGenre();
}

//teplate director comparer
template<class T>
bool compareDirector(const T& left, const T& right){
    return left.getDirector() < right.getDirector();
}

//teplate starring comparer
template<class T>
bool compareStarring(const T& left, const T& right){
    return left.getStarring() < right.getStarring();
}

//teplate author comparer
template<class T>
bool compareAuthors(const T& left, const T& right){
    return left.getAuthors() < right.getAuthors();
}

//teplate tags comparer
template<class T>
bool compareTags(const T& left, const T& right){
    return left.getTags() < right.getTags();
}

//template sort function
template<class T>
bool sortCommand(const std::string command, std::vector<T> listToSort, std::string &wholeFile){

    std::string sortFile = "";

    try{

    if (command == "title")
    {
        std::sort(listToSort.begin(), listToSort.end(),compareTitle<T>);    //It sorts according to titles
    }
    
    else if (command == "director")
    {
        std::sort(listToSort.begin(), listToSort.end(),compareDirector<T>);     //It sorts according to directors
    }
    
    else if (command == "year")
    {
        std::sort(listToSort.begin(), listToSort.end(),compareYear<T>);     //It sorts according to years
    }
    
    else if (command == "genre")
    {
        std::sort(listToSort.begin(), listToSort.end(),compareGenre<T>);    //It sorts according to genres
    }
    
    else if (command == "starring")
    {
        std::sort(listToSort.begin(), listToSort.end(),compareStarring<T>);     //It sorts according to starrings
    }

    else if (command == "artist")
    {
        std::sort(listToSort.begin(), listToSort.end(),compareArtist<T>);       ////It sorts according to artists
    }

    else if (command == "authors")
    {
        std::sort(listToSort.begin(), listToSort.end(),compareAuthors<T>);      //It sorts according to authors
    }

    else if (command == "tags")
    {
        std::sort(listToSort.begin(), listToSort.end(),compareTags<T>);     //It sorts according to tags
    }

    else
    {
        throw CommandWrong();     //If the type is not one of the above, It throws an wrong command exception
    }

    }

    catch(const CommandWrong& e){
        wholeFile = wholeFile + " Exception: " + e.errorMessage() + "\n" + "sort \"" + command + "\"" + "\n";
    }

    wholeFile = wholeFile + "sort " + "\"" + command + "\"" + "\n";

    if(listToSort.at(0).getType()=="movie")      //If the catalog type is movie, it uses this block to print into file
    {
        for (auto it = listToSort.begin() ; it != listToSort.end() ; it++) 
        {
            sortFile +=  "\"" + it->getTitle() + "\" \"" + it->getDirector() + "\" \"" + it->getYear() + "\" \"" + it->getGenre() + "\" \"" + it->getStarring() + "\"\n";
        }   
    }

    else if (listToSort.at(0).getType()=="book")    //If the catalog type is book, it uses this block to print into file
    {   
        for (auto it = listToSort.begin() ; it != listToSort.end() ; it++) 
        {
            sortFile +=  "\"" + it->getTitle() + "\" \"" + it->getAuthors() + "\" \"" + it->getYear() + "\" \"" + it->getTags() + "\"\n";
        }
    }

    else if (listToSort.at(0).getType()=="music")       //If the catalog type is music, it uses this block to print into file
    {
        for (auto it = listToSort.begin() ; it != listToSort.end() ; it++) 
        {
            sortFile +=  "\"" + it->getTitle() + "\" \"" + it->getArtist() + "\" \"" + it->getYear() + "\" \"" + it->getGenre() + "\"\n";
        }     
    }

    wholeFile += sortFile;

    return true;
}


//template seach function
template<class T>
bool searchCommand(const std::string toFound, const std::string field, const std::vector<T> listToSearch, std::string &wholeFile) {
    
    std::string searchFile;
        
    bool found = false;     //To keep track if its found
    int index = 0;      //If the object is found, the index is updated according to objects index
    std::string CommandWrongFile; 

    for (auto it = listToSearch.begin(); it != listToSearch.end(); ++it) {      //It search through whole list
        std::string stringToCheck;

        try{                
            if (field == "title")           //It returns what the field is equal to
                stringToCheck = it->getTitle();
            else if (field == "artists")
                stringToCheck = it->getArtist();
            else if (field == "year")
                stringToCheck = it->getYear();
            else if (field == "genre")
                stringToCheck = it->getGenre();
            else if (field == "director")
                stringToCheck = it->getDirector();
            else if (field == "starring")
                stringToCheck = it->getStarring();
            else if (field == "authors")
                stringToCheck = it->getAuthors();
            else if (field == "tags")
                stringToCheck = it->getTags();
            else
                throw CommandWrong();    
        }catch(const CommandWrong& e){
            CommandWrongFile = "Exception: " + e.errorMessage() + "\n" + "search" + " \"" + toFound + "\" " + "in " + "\"" + field + "\"" + "\n";
            wholeFile += CommandWrongFile;
            return false;
        }        

        if (stringToCheck.find(toFound) != std::string::npos) {     //If stringToCheck contains toFound check boolean variable turns to true 
            found = true;
        }

        else{
            index++;        //If it doesn't contain, the index increments
        }

        if (found)      //If found is true, then this part works
        {
            wholeFile = wholeFile + "search " + "\"" + toFound + "\" in \"" + field + "\"" + "\n"; 

            if (listToSearch.at(0).getType() == "book")
            {
                searchFile = "\"" + listToSearch[index].getTitle() + "\" \"" + listToSearch[index].getAuthors() + "\" \"" + listToSearch[index].getYear() + "\" \"" + listToSearch[index].getTags() + "\"\n";   
                wholeFile += searchFile;
                return true;
            }

            else if (listToSearch.at(0).getType() == "movie")
            {
                searchFile = "\"" + listToSearch[index].getTitle() + "\" \"" + listToSearch[index].getDirector() + "\" \"" + listToSearch[index].getYear() + "\" \"" + listToSearch[index].getGenre() + "\" \"" + listToSearch[index].getStarring() + "\"\n";
                wholeFile += searchFile; 
                return true;
            }

            else if (listToSearch.at(0).getType() == "music")
            {   
                searchFile = "\"" + listToSearch[index].getTitle() + "\" \"" + listToSearch[index].getArtist() + "\" \"" + listToSearch[index].getYear() + "\" \"" + listToSearch[index].getGenre() + "\"\n";    
                wholeFile += searchFile;
                return true;
            }            
        }
    }
    return true;
}
}
#endif