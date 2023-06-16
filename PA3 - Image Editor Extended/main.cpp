#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class ImageEditor{

private:
    int width, height, max_color;  //Thıs variable stores datas from ppm file
    vector<vector<vector<int>>> pixels; 

public:
    void printMainMenu();

    void printOpenImageMenu();

    void printSaveImageMenu();

    void printScripts();

    void printGrayscaleMenu();

    void runProgram();

    void runOpenImageMenu();

    void runSaveImageMenu();

    void runScripts();

    void runGrayscaleMenu();

    void openImage(string filename);
    
    void saveImage(string filename);

    void turnGrayScale(float c_r, float c_g, float c_b);
};

void ImageEditor::openImage(string filename){
        ifstream file(filename);
        string type;
        file >> type >> width >> height >> max_color;
        pixels.resize(height, vector<vector<int>>(width, vector<int>(3)));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                file >> pixels[i][j][0] >> pixels[i][j][1] >> pixels[i][j][2];
            }
        }
        file.close();
}

void ImageEditor::saveImage(string filename){
        ofstream file(filename);
        file << "P3\n" << width << " " << height << "\n" << max_color << "\n";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                file << pixels[i][j][0] << " " << pixels[i][j][1] << " " << pixels[i][j][2] << " ";
            }
            file << "\n";
        }
        file.close();
}

void ImageEditor::turnGrayScale(float c_r, float c_g, float c_b){
    for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int gray = c_r * pixels[i][j][0] + c_g * pixels[i][j][1] + c_b * pixels[i][j][2];
                if (gray > 255) gray = 255;  
                pixels[i][j][0] = gray;
                pixels[i][j][1] = gray;
                pixels[i][j][2] = gray;
            }
    }
}

void ImageEditor::runOpenImageMenu(){
    
    int menuChoice;
    string filename;

    do
    {
        printOpenImageMenu();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 0:
            break;

        case 1:
            cin >> filename;
            openImage(filename);
            break;
        
        default:
            cout << "Invalid Entry" << endl;
            break;
        }

    } while (menuChoice!=0);
    
}

void ImageEditor::runSaveImageMenu(){

    int menuChoice;
    string filename;

    do
    {
        printSaveImageMenu();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 0:
            break;
        case 1:
            cin >> filename;
            saveImage(filename);
            break;
        default:
            cout << "Invalid Entry" << endl;
            break;
        }
    } while (menuChoice!=0);
}

void ImageEditor::runScripts(){
    
    int menuChoice;

    do
    {
        printScripts();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 0:
            break;
        case 1:
            runGrayscaleMenu();
            break;
        default:
            cout << "Invalid Entry" << endl;
            break;
        }
    } while (menuChoice!=0);
    
}

void ImageEditor::runGrayscaleMenu(){

    int menuChoice;

    do
    {
        printGrayscaleMenu();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 0:
            break;
        
        case 1: 
            float c_r, c_g, c_b;
            cin >> c_r >> c_g >> c_b;

            while (c_r<0 || c_g<0 || c_b<0 || c_r>=1 || c_g>=1 || c_b>=1)
            {
                cout << "Invalid input. Please try again" << endl;
                cin >> c_r >> c_g >> c_b;
            }
            
            turnGrayScale(c_r,c_g,c_b);

            break;

        default:
            cout << "Invalid Entry" << endl;
            break;
        }

    } while (menuChoice!=0);
    
}

void ImageEditor::printMainMenu(){
    cout << "MAIN MENU" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Open An Image(D)" << endl;
    cout << "2 - Save Image Data(D)" << endl;
    cout << "3 - Scripts(D)" << endl;
}

void ImageEditor::printOpenImageMenu(){
    cout << "OPEN AN IMAGE MENU" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Enter The Name Of The Image File" << endl;
}

void ImageEditor::printSaveImageMenu(){
    cout << "SAVE IMAGE DATA MENU" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Enter A File Name" << endl;
}

void ImageEditor::printScripts(){
    cout << "SCRIPTS MENU" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Convert To Grayscale(D)" << endl;
}

void ImageEditor::printGrayscaleMenu(){
    cout << "CONVERT TO GRAYSCALE MENU" << endl;
    cout << "0 - Exit" << endl;
    cout << "1 - Enter Coefficients For RED GREEN And BLUE Channels." << endl;
}

void ImageEditor::runProgram(){

    int menuChoice;

    do
    {
        printMainMenu();

        cin >> menuChoice;

        switch (menuChoice)
        { 
        case 0:
            cout << "Exiting Program" << endl;
            break;
        
        case 1:
            runOpenImageMenu();
            break;

        case 2:
            runSaveImageMenu();
            break;
        
        case 3:
            runScripts();
        
        default:
            cout << "Invalid Entry" << endl;
            break;
        }
    } while (menuChoice!=0);
    
}

int main(){

    ImageEditor test;

    test.runProgram();

    return 0;
}