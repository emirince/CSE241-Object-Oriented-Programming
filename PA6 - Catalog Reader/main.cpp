#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "catalog.h"
#include "exception.h"
#include "Music.h"
#include "Movie.h"
#include "Book.h"
#include "template.h"

using namespace PA6;

//It returns true if the string is a whitespace. It works to chech if the string is empty
bool isWhitespace(const std::string& str) {    
    return std::all_of(str.begin(), str.end(), [](char c) {
        return std::isspace(static_cast<unsigned char>(c));
    });
}

int main(){

    std::ifstream dataFile("data.txt");
    std::ifstream commandFile("command.txt");
    
    std::string line; //files line is saved to this string
    std::string type; //it saves the catalog types 

    std::string command; //it saves which type of command. sort or search
    std::string toFound; //It saves what should be search through the file
    std::string field;  //It saves which field should be seached. Title, director etc.
    std::string notUsedString; //It saves the "in" string in the : Search "Joe" in "artists"

    std::string wholeFile;  //The whole string which will be printed into output.txt into this string.
    std::string duplicateFile;  //Duplicate entry errors is saved into this string. After that it is saved in the wholeFile string
    std::string missingFile;    //Missing field errors is saved into this string. After that it is saved in the wholeFile string
    std::string commandWrongFile;  ////Wrong command errors is saved into this string. After that it is saved in the wholeFile string
    std::string catalogReadFile;  //catalog read info is saved into this string. After that it is saved in the wholeFile string  

    int checkDoubleQuotes = 0;  //I use this int variable to count how many double quotes are there in a line. By dividing it to 2, i can count how many field a line has. I use this to check if any field is missing

    int uniqueEntry = 0;    //I use this to count how many unique entries a catalog have

    if (dataFile.is_open())
    {
        dataFile >> type;       //It saves the type of catalog

        std::getline(dataFile,line);

        if (type == "music")
        {
            Catalog<Music> catalog;    //It creates the Template Class Object

            catalogReadFile = "Catalog Read: " + type + "\n";

            wholeFile += catalogReadFile;

            while (std::getline(dataFile, line)) {

                std::stringstream ss(line);
                std::string title, artist, year, genre;     //necessary music variable

                std::getline(ss, title, '"');   //By this following lines, i can get save whats between the double quotes
                std::getline(ss, title, '"');

                std::getline(ss, artist, '"');
                std::getline(ss, artist, '"');

                std::getline(ss, year, '"');
                std::getline(ss, year, '"');

                std::getline(ss, genre, '"');
                std::getline(ss, genre, '"');

                try{
                    checkDoubleQuotes = 0;      //It resets the check double quotes at the every start of loop
                    for(auto it = line.begin() ; it != line.end() ; it++){
                        if(*it == '"')
                            checkDoubleQuotes++;        //Increments for every double quotes in a line
                    }

                    if (checkDoubleQuotes != 8)     //Since line has 4 variables, it should have 8 double quotes. If it doesn't have, there is missing field error
                        throw MissingField();
                }
                catch(const MissingField& e)
                {   
                    missingFile = "Exception: " + e.errorMessage() +  "\n";

                    //By this if blocks, it is detected which field is missing 
                    if(!isWhitespace(title))        
                        missingFile += "\"" + title + "\" "; 
                    
                    if(!isWhitespace(artist))
                        missingFile += "\"" + artist + "\" ";
                    
                    if(!isWhitespace(year))
                        missingFile += "\"" + year + "\" ";
                    
                    if(!isWhitespace(genre))
                        missingFile += "\"" + genre + "\" ";
                    
                    wholeFile += missingFile + "\n";
                    continue;
                }

                Music music(title, artist, year, genre);    //The music object is created

                try{
                    for (auto it = catalog.getObjects().begin() ; it != catalog.getObjects().end() ; it++)
                    {
                        if (music.getTitle() == it->getTitle())      //By this line, we compare every element of the catalog list to check if the the objects it is just created is already on the list. If it's in the list, the error is thrown     
                            throw DuplicateEntry();   
                    }
                }
                catch(const DuplicateEntry& e){
                    duplicateFile = "Exception: " + e.errorMessage() + "\n" + "\"" + music.getTitle() + "\" \"" + music.getArtist() +  "\" \"" + music.getYear() +  "\" \"" + music.getGenre() + "\"" + "\n";
                    wholeFile += duplicateFile;
                    continue;
                }

                catalog.addObject(music);   //If there is no missing field error, or duplicate error, the object is added to the catalog

                uniqueEntry++;    //Increment unique entry variable to keep track of it
            }

            std::string uniqueEntryString;

            uniqueEntryString = std::to_string(uniqueEntry) + " unique entries\n";      //Converting unique entry variable to string to put it in the wholeFile string to put it in to output.txt

            wholeFile += uniqueEntryString;

            if (commandFile.is_open()) {

                std::string line;
                while (std::getline(commandFile, line)) {
                    std::stringstream ss(line);
                    std::string command, toFound, field, notUsedString;
                    
                    try{
                        ss >> command;  
                        if (command != "search" && command != "sort" )      //If the command isn't search or sort, Wrong command exception is thrown
                            throw CommandWrong();
                    }

                    catch(const CommandWrong& e){
                        std::getline(ss >> std::ws, toFound, '"');  //It's captured whats between the double quotes to save into toFound string
                        std::getline(ss >> std::ws, toFound, '"');

                        ss >> notUsedString;
                        
                        std::getline(ss >> std::ws, field, '"');    //It's captured whats between the double quotes to save into field string
                        std::getline(ss >> std::ws, field, '"');
                        
                        //Exception error is saved into the file
                        commandWrongFile = "Exception: " + e.errorMessage() + "\n" + command + " \"" + toFound + "\" " + notUsedString + " \"" + field + "\"" + "\n";

                        wholeFile += commandWrongFile;
                        continue;
                    }

                    if (command == "search") {

                        std::getline(ss >> std::ws, toFound, '"');  //It's captured whats between the double quotes to save into toFound string
                        std::getline(ss >> std::ws, toFound, '"');
                        
                        ss >> notUsedString;
                        
                        std::getline(ss >> std::ws, field, '"');    //It's captured whats between the double quotes to save into field string
                        std::getline(ss >> std::ws, field, '"');

                        searchCommand<Music>(toFound, field, catalog.getObjects(), wholeFile);   //All necessary arguments is sent to seachCommand function
                    }
                   
                    else if (command == "sort") {
                    
                        std::getline(ss >> std::ws, field, '"');    //It's captured whats between the double quotes to save into field string
                        std::getline(ss >> std::ws, field, '"');
                    
                        sortCommand<Music>(field, catalog.getObjects(), wholeFile);     //All necessary arguments is sent to seachCommand function
                    }
                }

            }     
        }
        
        else if (type == "book")
        {
            Catalog<Book> catalog;      //It creates the Template Class Object

            catalogReadFile = "Catalog Read: " + type + "\n";

            wholeFile += catalogReadFile;

            while (std::getline(dataFile, line)) {

                std::stringstream ss(line);
                std::string title, authors, year, tags;     //necessary book arguments

                std::getline(ss, title, '"');       //By this following lines, i can get save whats between the double quotes
                std::getline(ss, title, '"');

                std::getline(ss, authors, '"');
                std::getline(ss, authors, '"');

                std::getline(ss, year, '"');
                std::getline(ss, year, '"');

                std::getline(ss, tags, '"');
                std::getline(ss, tags, '"');

                try{
                    checkDoubleQuotes = 0;      //It resets the check double quotes at the every start of loop
                    for(auto it = line.begin() ; it != line.end() ; it++){
                        if(*it == '"')
                            checkDoubleQuotes++;    //Increments for every double quotes in a line
                    }

                    if (checkDoubleQuotes != 8)     //Since line has 4 variables, it should have 8 double quotes. If it doesn't have, there is missing field error
                        throw MissingField();
                }
                catch(const MissingField& e)
                {   
                    missingFile = "Exception: " + e.errorMessage() +  "\n";

                    //By this if blocks, it is detected which field is missing 
                    if(!isWhitespace(title))
                        missingFile += "\"" + title + "\" "; 

                    if(!isWhitespace(authors))
                        missingFile += "\"" + authors + "\" ";
                    
                    if(!isWhitespace(year))
                        missingFile += "\"" + year + "\" ";
                    
                    if(!isWhitespace(tags))
                        missingFile += "\"" + tags + "\" ";
                    
                    wholeFile += missingFile + "\n";
                    continue;
                }   

                Book book(title, authors, year, tags);      //The book object is created

                try{
                    for (auto it = catalog.getObjects().begin() ; it != catalog.getObjects().end() ; it++)
                    {
                        if (book.getTitle() == it->getTitle())          //By this line, we compare every element of the catalog list to check if the the objects it is just created is already on the list. If it's in the list, the error is thrown 
                            throw DuplicateEntry();
                    }
                }
                catch(const DuplicateEntry& e){
                    duplicateFile = "Exception: " + e.errorMessage() + "\n" + "\"" + book.getTitle() + "\" \"" + book.getAuthors() +  "\" \"" + book.getYear() +  "\" \"" + book.getTags() + "\"" + "\n";
                    wholeFile += duplicateFile;
                    continue;
                }

                catalog.addObject(book);         //If there is no missing field error, or duplicate error, the object is added to the catalog
                
                uniqueEntry++;      //Increment unique entry variable to keep track of it
            }

            std::string uniqueEntryString;

            uniqueEntryString = std::to_string(uniqueEntry) + " unique entries\n";       //Converting unique entry variable to string to put it in the wholeFile string to put it in to output.txt

            wholeFile += uniqueEntryString;

            if (commandFile.is_open()) {

                std::string line;
                while (std::getline(commandFile, line)) {
                    std::stringstream ss(line);
                    std::string command, toFound, field, notUsedString;
                    
                    try{
                        ss >> command; 
                        if (command != "search" && command != "sort" )      //If the command isn't search or sort, Wrong command exception is thrown
                            throw CommandWrong();
                    }
                    catch(const CommandWrong& e){
                        std::getline(ss >> std::ws, toFound, '"');      //It's captured whats between the double quotes to save into toFound string
                        std::getline(ss >> std::ws, toFound, '"');

                        ss >> notUsedString;
                        
                        std::getline(ss >> std::ws, field, '"');    //It's captured whats between the double quotes to save into field string
                        std::getline(ss >> std::ws, field, '"');
                        
                        //Exception error is saved into the file
                        commandWrongFile = "Exception: " + e.errorMessage() + "\n" + command + " \"" + toFound + "\" " + notUsedString + " \"" + field + "\"" + "\n";

                        wholeFile += commandWrongFile;
                        continue;
                    }

                    if (command == "search") {

                        std::getline(ss >> std::ws, toFound, '"');      //It's captured whats between the double quotes to save into toFound string
                        std::getline(ss >> std::ws, toFound, '"');
                        
                        ss >> notUsedString;
                        
                        std::getline(ss >> std::ws, field, '"');         //It's captured whats between the double quotes to save into field string
                        std::getline(ss >> std::ws, field, '"');
                                        
                        searchCommand<Book>(toFound, field,catalog.getObjects(), wholeFile);        //All necessary arguments is sent to seachCommand function
                    }
                    
                    else if (command == "sort") {
                        
                        std::getline(ss >> std::ws, field, '"');        //It's captured whats between the double quotes to save into field string
                        std::getline(ss >> std::ws, field, '"');        

                        sortCommand<Book>(field, catalog.getObjects(), wholeFile);       //All necessary arguments is sent to seachCommand function
                    }
                }
            }
        }
        
        else if (type == "movie")
        {
            Catalog<Movie> catalog;     //It creates the Template Class Object

            catalogReadFile = "Catalog Read: " + type + "\n";

            wholeFile += catalogReadFile;

            while (std::getline(dataFile, line)) {

                std::stringstream ss(line);
                std::string title, director, year, genre, starring;     //necessary movie arguments

                std::getline(ss, title, '"');       //By this following lines, i can get save whats between the double quotes
                std::getline(ss, title, '"');

                std::getline(ss, director, '"');
                std::getline(ss, director, '"');

                std::getline(ss, year, '"');
                std::getline(ss, year, '"');

                std::getline(ss, genre, '"');
                std::getline(ss, genre, '"');

                std::getline(ss, starring, '"');
                std::getline(ss, starring, '"');

                try{    
                    checkDoubleQuotes = 0;      //It resets the check double quotes at the every start of loop
                    for(auto it = line.begin() ; it != line.end() ; it++){
                        if(*it == '"'){
                            checkDoubleQuotes++;        //Increments for every double quotes in a line
                        }
                    }

                    if (checkDoubleQuotes != 10)      //Since line has 5 variables, it should have 10 double quotes. If it doesn't have, there is missing field error
                        throw MissingField();
                }
                catch(const MissingField& e)
                {   
                    missingFile = "Exception: " + e.errorMessage() +  "\n";

                    //By this if blocks, it is detected which field is missing
                    if(!isWhitespace(title))
                        missingFile += "\"" + title + "\" "; 

                    if(!isWhitespace(director))
                        missingFile += "\"" + director + "\" ";

                    if(!isWhitespace(year))
                        missingFile += "\"" + year + "\" ";
        
                    if(!isWhitespace(genre))
                        missingFile += "\"" + genre + "\" ";

                    if(!isWhitespace(starring))
                        missingFile += "\"" + starring + "\" ";
                    
                    wholeFile += missingFile + "\n";
                    continue;
                }

                Movie movie(title, director, year, genre, starring);        //The movie object is created

                try{
                    for (auto it = catalog.getObjects().begin() ; it != catalog.getObjects().end() ; it++)
                    {
                        if (movie.getTitle() == it->getTitle())         //By this line, we compare every element of the catalog list to check if the the objects it is just created is already on the list. If it's in the list, the error is thrown 
                            throw DuplicateEntry();
                    }
                }
                catch(const DuplicateEntry& e){
                    duplicateFile = "Exception: " + e.errorMessage() + "\n" + "\"" + movie.getTitle() + "\" \"" + movie.getDirector() +  "\" \"" + movie.getYear() +  "\" \"" + movie.getGenre() + "\" \"" + movie.getStarring() + "\"" + "\n";
                    wholeFile += duplicateFile;
                    continue;
                }

                catalog.addObject(movie);       //If there is no missing field error, or duplicate error, the object is added to the catalog

                uniqueEntry++;      //Increment unique entry variable to keep track of it
            }

            std::string uniqueEntryString;

            uniqueEntryString = std::to_string(uniqueEntry) + " unique entries\n";          //Converting unique entry variable to string to put it in the wholeFile string to put it in to output.txt

            wholeFile += uniqueEntryString;

            if (commandFile.is_open()) {

                std::string line;
                while (std::getline(commandFile, line)) {
                    std::stringstream ss(line);
                    std::string command, toFound, field, notUsedString;
                    
                    try{
                        ss >> command; 
                        if (command != "search" && command != "sort" ){         //If the command isn't search or sort, Wrong command exception is thrown
                            throw CommandWrong();
                        }
                    }
                    catch(const CommandWrong& e){
                        std::getline(ss >> std::ws, toFound, '"');          //It's captured whats between the double quotes to save into toFound string
                        std::getline(ss >> std::ws, toFound, '"');

                        ss >> notUsedString;
                        
                        std::getline(ss >> std::ws, field, '"');        //It's captured whats between the double quotes to save into field string
                        std::getline(ss >> std::ws, field, '"');
                        
                        //Exception error is saved into the file 
                        commandWrongFile = "Exception: " + e.errorMessage() + "\n" + command + " \"" + toFound + "\" " + notUsedString + " \"" + field + "\"" + "\n";

                        wholeFile += commandWrongFile;

                        continue;
                    }

                    if (command == "search") {

                        std::getline(ss >> std::ws, toFound, '"');      //It's captured whats between the double quotes to save into toFound string
                        std::getline(ss >> std::ws, toFound, '"');
                        
                        ss >> notUsedString;
                        
                        std::getline(ss >> std::ws, field, '"');        //It's captured whats between the double quotes to save into field string
                        std::getline(ss >> std::ws, field, '"');

                        searchCommand<Movie>(toFound, field, catalog.getObjects(), wholeFile);       //All necessary arguments is sent to seachCommand function
                    }
                    
                    else if (command == "sort") {

                        std::getline(ss >> std::ws, field, '"');        //It's captured whats between the double quotes to save into field string
                        std::getline(ss >> std::ws, field, '"');        

                        sortCommand<Movie>(field, catalog.getObjects(), wholeFile);      //All necessary arguments is sent to seachCommand function
                    }
                }
            }
        }
        else
            std::cout << "Invalid type" << std::endl;
    }
    else
        std::cout << "Unable to open the data.txt" << std::endl;

    std::ofstream outputFile("output.txt");

    outputFile << wholeFile;        //the wholeString file is print into output.txt file

    outputFile.close();

    commandFile.close();
}