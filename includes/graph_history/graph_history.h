#ifndef GRAPH_HISTORY_H 
#define GRAPH_HISTORY_H 

#include<iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "../../includes/queue/MyQueue.h"
#include "../../includes/graph_info/graph_info.h"
#include "../../includes/vector_class/vector_class.h"
#include "../../includes/text_box/text_box.h"

using namespace std; 

//class that is in charge of keeping track of graphHistory 
class Graph_History{
    public: 
        //constructors 
        Graph_History(); 
        Graph_History(graph_info* graphInfoVal); 

        void addEquation(string equ);  //adds an equation to this class's vector of equations
        int returnClickedIndex(double x, double y); //returns the index of the clicked graph in history
        string returnClickedEqu(int index); //returns a string representing the clicked equation
        void saveEqus(); //saves equ to a text file --> called before window closes 
        void transferEqus(); //called when first opening the window --> transfers any existing equs back to 
        void addBox(); //box refers to the equs in history (on the sidebar) --> this method adds a new equ to the sidebar 
        void updateBoxes(); //checks if equs have exceeded the max amount and if so, decrease accordingly 
        void draw(sf::RenderWindow& tempWindow); //draws the equations on to sidebar 
        Vector<string> getHistory(); //returns a vector of strings of all past equs 

    private: 
        void initBoxes(); //this method initializes the maximum amount of "boxes" for the graph equations on the sidebar 
        //either will be blank or it will display graphs from old history 
        sf::RectangleShape box1, box2, box3, box4; 
        const int maxBoxes = 4; 
        Vector<string> pastEquations; //a vector that stores past equs
        Vector<Text_Box> boxes; //a vector of text boxes (rectangle shapes with text objs in front of them)
        graph_info* graphInfo; 
}; 


#endif 