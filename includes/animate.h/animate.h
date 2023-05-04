#ifndef ANIMATE_H
#define ANIMATE_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../includes/graph_info/graph_info.h"
#include "../../includes/graph_history/graph_history.h"
#include "../../includes/vector_class/vector_class.h"
#include "../../includes/system/system.h"
#include "../../includes/sidebar/sidebar.h"
#include "../../includes/text_box/text_box.h"
#include "../../includes/user_input/user_input.h"
#include "../../includes/utilities/utilities.h"


using namespace std; 
class animate{
public:
    animate(graph_info* graphInfoVal); //runner class --> displays the window and all graphics, senses updates, etc 
    ~animate(); //destructor to destroy the dynamic graph info and graphHistory 
    void run(); //updates, renders, and processes the graph
    void processEvents(); //proccesses events --> knows whether user pressed a key, or clicked their mouse and etc 
    void update(); //updates graph --> zoom, pan, etc 
    void render(); //in charge of displaying, clearing, and drawing graph
    void Draw(); //calls all draw methods 
private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;
    sf::Image image;
    bool mouseIn; 
    bool textBoxClicked = false; 
    bool equChanged = false; 
    bool clear = false; 
    int graphHistoryClicked; 
    string someStr; 
    string newEqu; 
    string prevEqu; 
    int command = 100; 
    graph_info* graphInfo;
    Graph_History* graphHistory; 
    User_Input userInput;
    System system; 
    Sidebar sidebar; 
    Text_Box textBox;
    Utility utilities; 
};

#endif // GAME_H