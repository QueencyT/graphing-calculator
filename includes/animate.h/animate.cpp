#include "../../includes/animate.h/animate.h"

animate::animate(graph_info* graphInfoVal){
    graphInfo = graphInfoVal; 
    graphHistory = new Graph_History(graphInfo); 
    userInput = User_Input(graphInfo, graphHistory); 
    system = System(graphInfo); 
    sidebar = Sidebar(graphInfo); 
    textBox = Text_Box(graphInfo, ""); 
    utilities = Utility(graphInfo); 
    someStr = graphInfo->_equation; 

    int screen_width = graphInfo->_window_dimensions.x; 
    int screen_height = graphInfo->_window_dimensions.y; 

    window.create(sf::VideoMode(screen_width, screen_height), "Graphing calculator"); 
    image.loadFromFile("cat.jpg"); 
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr()); 
    window.setFramerateLimit(60); 
    mouseIn = true; 
    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);
}

animate::~animate(){
    delete graphInfo; 
    graphInfo = nullptr; 
}

void animate::Draw(){
    if(clear){
        system.clear(window); 
    }
    else{
        system.draw(window); 
    }

    sidebar.draw(window); 
    textBox.draw(window, someStr);
    utilities.draw(window); 
    graphHistory->draw(window); 
        

    if (mouseIn){
        window.draw(mousePoint);
    }

    //sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    //window.draw(myTextLabel); //COMMENTED OUT FOR NOW B/C NO TEXT
    //. . . . . . . . . . . . . . . . . . .
}


void animate::update(){

   equChanged = (prevEqu != newEqu); 

   if(equChanged){
        userInput.setUserInput(newEqu); 
        graphHistory->updateBoxes();
        prevEqu = newEqu; 
   }

    system.update(command); 
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5, sf::Mouse::getPosition(window).y-5);
        //mouse location text for sidebar:
        //sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
    }

}
void animate::render(){
       window.clear();
       Draw();
       window.display();
}



void animate::processEvents()
{
   sf::Event event;
   float mouseX, mouseY;
   float pressStartX, pressStartY; 
   int last; 
   char letter; 
   //string someStr;
   while (window.pollEvent(event))//or waitEvent
       {
       // check the type of the event...
           switch (event.type)
           {
           // window closed
           case sf::Event::Closed:
                graphHistory->saveEqus(); 
               window.close();
               break;

           // key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code){
                case sf::Keyboard::Up:
                    cout<<"UP ARROW PRESSED\n";
                    command = CMD_ZOOM_IN; 
                    break; 
                case sf::Keyboard::Down:
                    cout<<"DOWN ARROW PRESSED\n"; 
                    command = CMD_ZOOM_OUT; 
                    break; 
                case sf::Keyboard::Left:
                    //sidebar[SB_KEY_PRESSED] = "LEFT ARROW"; //COMMENTED OUT FOR NOW 
                    cout<<"LEFT KEY PRESSED\n"; 
                   command = CMD_PAN_LEFT;
                   break;
               case sf::Keyboard::Right:
                   //sidebar[SB_KEY_PRESSED] = "RIGHT ARROW";
                   cout<<"RIGHT KEY PRESSED\n"; 
                   command = CMD_PAN_RIGHT; 
                   break;
                case sf::Keyboard::BackSpace: 
                    cout<<"BACKSPACE PRESSED\n"; 
                    if(someStr.length() != 0){
                    last = someStr.length() - 1; 
                    someStr.erase(last); 
                    }
                    break; 
                case sf::Keyboard::Enter:
                    cout<<"ENTER PRESSED\n";
                    newEqu = someStr; 
                    clear = false; 
                    command = CMD_REDRAW; 
                    break; 
               case sf::Keyboard::Escape:
                   //sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                   window.close();
                break;
               }
               break;

            case sf::Event::TextEntered:
            letter = event.text.unicode;

               if(textBoxClicked){
                    if(letter != 8) { //not equal to the ascii value of backspace
                        someStr += letter; 
                    }
                  cout<<someStr<<endl; 
                }


                break; 
           case sf::Event::MouseEntered:
               mouseIn = true;
               break;

           case sf::Event::MouseLeft:
               mouseIn = false;
               break;

           case sf::Event::MouseMoved:
                //Do something with it if you need to...
               break;
            case sf::Event::MouseButtonPressed:
                pressStartX = sf::Mouse::getPosition(window).x; 
                pressStartY = sf::Mouse::getPosition(window).y; 

                textBoxClicked = textBox.onClicked(pressStartX, pressStartY);
                graphHistoryClicked = graphHistory->returnClickedIndex(pressStartX, pressStartY); 

                if(utilities.getClear().onClicked(pressStartX, pressStartY)){//to decide if to clear 
                    someStr = ""; 
                    newEqu = someStr; 
                    clear = true; 
                }

                if(graphHistoryClicked != -1){//to decide if we are accessing old graphs (graph history)
                    someStr = graphHistory->returnClickedEqu(graphHistoryClicked); 
                    newEqu = someStr; 
                    command = CMD_REDRAW; 
                }

                break; 
           case sf::Event::MouseButtonReleased:
                   if (event.mouseButton.button == sf::Mouse::Right)
                   {
                       //sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                               //mouse_pos_string(window);

                   }
                   else{
                       //sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                               //mouse_pos_string(window);
                   }
                   break;

               default:
                   break;
           }
       }
}

void animate::run()
{
   while (window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}


string mouse_pos_string(sf::RenderWindow& window);