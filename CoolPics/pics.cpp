/**
 * pics.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Kanishk Kandoi, Abby Moomaw
 * Kanishkk, amoomaw
 *
 * A projects in which we read  a description of shapes,
 * draws those shapes, and saves the result to a file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints an opening message.
 */
void printOpener();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a closing message.
 */
void printCloser();

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a menu.
 */
void printMenu();

/**
 * Requires: ins is in good state.
 * Modifies: cin, ins.
 * Effects:  Closes ins if it is open. Keeps reading filename from the user
 *           (and appends .txt) until the file is successfully opened.
 *           Returns the name of the file that was opened.
 */
string openFile(ifstream& ins);

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns str with all of its alphabetical characters lowercased.
 */
string tolower(string str);

/**
 * Requires: Nothing.
 * Modifies: cin, drawer.
 * Effects:
 *     Opens a file
 *     Start with a blank canvas (drawer)
 *     Start reading from file.  For each line....
 *        Read the 1st character to determine shape
 *        Read the shape:  L reads a line, C reads a circle, T read a triangle
 *            R reads a rectangle.
 *            For any other character, clears drawer and prints
 *            "Error in input file: " << [character already read]
 *            << [all chars remaining on the line] << endl;
 *        Draw shape on canvas
 *     Close file
 *     Print "[Loaded <filename>]", where <filename> is replaced with
 *                                  the name of the file.
 */
void loadFile(Graphics& drawer);

/**
 * Requires: Nothing.
 * Modifies: cin, cout, drawer.
 * Effects:
 *     Read filename from user
 *     concatenate filename with .bmp
 *     Write image to file.
 *     Print "[Wrote filename]"
 */
void writeFile(const Graphics& drawer);

void coolPics()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();
    
    return;
}

/* Writes the name of the file and adds extension .bmp */

void writeFile(const Graphics& drawer)
{
    string fileName;
    cin >> fileName;
    string newFileName = fileName + ".bmp";
    drawer.writeFile(newFileName);
    cout << endl << endl << "[Wrote " << fileName << ".bmp]" << endl;
}

/* Loads shape data from a file into the Graphics object for drawing */

void loadFile(Graphics& drawer) {
    ifstream inputFile;
    string filename = openFile(inputFile);

    if (!filename.empty()) {
        char shapeType;
        string line;
        drawer.clear();

        while (getline(inputFile, line)) {
            istringstream lineStream(line);

            if (lineStream >> shapeType) {
                if (shapeType == 'R') {
                    Rectangle rectangle;
                    rectangle.read(lineStream);
                    rectangle.draw(drawer);
                } else if (shapeType == 'C') {
                    Circle circle;
                    circle.read(lineStream);
                    circle.draw(drawer);
                } else if (shapeType == 'L') {
                    Line line;
                    line.read(lineStream);
                    line.draw(drawer);
                } else if (shapeType == 'T') {
                    Triangle triangle;
                    triangle.read(lineStream);
                    triangle.draw(drawer);
                } else {
                    drawer.clear();
                    cout << "Error in input file: " << shapeType << lineStream.str() << endl;
                }
            }
        }

        inputFile.close();
        cout << "[Loaded " << filename << "]" << endl;
    }
}

/* Converts characters in string to lowercase */

string tolower(string str)
{
    for (size_t i = 0; i < str.length(); ++i) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

// Don't change the implementations below!

void printMenu()
{
    cout << "Command:            Description:" << endl
         << "--------            ------------" << endl
         << "load filename       Loads data from a txt file" << endl
         << "write filename      Creates a bmp image from data" << endl
         << "quit                Quits the program" << endl << endl;
}


void printOpener()
{
    cout << "=================================================" << endl
         << "               Welcome to CoolPics" << endl
         << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
         << "            Thanks for using CoolPics!" << endl
         << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;

    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }

    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);

    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";
        ins.open(fileName);
    }

    return fileName;
}
