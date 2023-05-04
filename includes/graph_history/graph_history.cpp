#include "../../includes/graph_history/graph_history.h" 

Graph_History::Graph_History(){

}

Graph_History::Graph_History(graph_info* graphInfoVal){
    graphInfo = graphInfoVal; 
    pastEquations.push_back(graphInfo->_equation); 
    initBoxes(); 
    transferEqus(); 
} 

void Graph_History::addEquation(string equ){
    pastEquations.insert(0,equ); //insert in front 
}

void Graph_History::initBoxes(){
    for(int i = 0; i < maxBoxes; i++){
        addBox(); 
    }
}

void Graph_History::updateBoxes(){
    if(pastEquations.size() > maxBoxes){
        pastEquations.pop_back(); 
    }
}

int Graph_History::returnClickedIndex(double x, double y){
    for(int i = 0; i < boxes.size(); i++){
        if(boxes.at(i).onClicked(x, y)){
            return i; 
        }
    }
    return -1; 
}

string Graph_History::returnClickedEqu(int index){
    return pastEquations.at(index); 
}

void Graph_History::saveEqus(){
    ofstream historyFile; 
    historyFile.open("history.txt"); 

    if(historyFile.fail()){
        cout<<"failed to open file!\n"; 
        assert(false); 
    }

    for(int i = 0; i < pastEquations.size(); i++){
        historyFile<<pastEquations.at(i)<<endl;  
    }
}

void Graph_History::transferEqus(){
    ifstream historyFile; 
    string equ; 
    historyFile.open("history.txt"); 

    if(historyFile.fail()){
        cout<<"failed to open file - INPUT\n"; 
        assert(false); 
    }

    while(getline(historyFile, equ)){
        pastEquations.push_back(equ); 
    }
}

void Graph_History::addBox(){ //will make it have a text later //maybe just init with my text boxes class 
    Text_Box textBox; 
    double width = graphInfo->_window_dimensions.x - graphInfo->_graph_dimensions.x - 40; //40 for padding
    textBox.setColor(sf::Color::Blue); 
    textBox.setSize(sf::Vector2f(width,graphInfo->_window_dimensions.y * 0.08)); 

    double padding = graphInfo->_graph_dimensions.y * 0.1; 
    
    
    if(boxes.empty()){ 
        double padding = graphInfo->_graph_dimensions.y * 0.5; 
        textBox.setPosition(graphInfo->_graph_dimensions.x + graphInfo->_graph_dimensions.x * 0.015, graphInfo->_graph_dimensions.y * 0.05 + padding);
    }
    else{
        double newY = boxes.back().getPosition().y + padding; 
        double newX = boxes.back().getPosition().x; //no need for padding
        textBox.setPosition(newX, newY); 
    }
    boxes.push_back(textBox);
}

Vector<string> Graph_History::getHistory(){
    return pastEquations; 
}

void Graph_History::draw(sf::RenderWindow& tempWindow){ 
    string equ;
    for(int i = 0; i < boxes.size() && i < maxBoxes && i < pastEquations.size(); i++){
        equ = pastEquations.at(i); 
        boxes.at(i).draw(tempWindow, equ); 
    } 
}