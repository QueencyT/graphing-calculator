#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include "../../includes/graph_info/graph_info.h"
#include "../../includes/Graph/graph.h"
#include "../../includes/vector_class/vector_class.h"
#include "../../includes/point/point.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/token/token.h"
#include "../../includes/Plot/plot.h"
#include "../../includes/animate.h/animate.h"
#include "../../includes/system/system.h"
#include "../../includes/user_input/user_input.h"

#include "../../includes/coordinate_translator/coordinate_translator.h"

using namespace std;

//shuntingyard or rpn already tested in previous assignment

//Plot functions
bool test_getPoints(bool debug){
  cout<<"==================== TEST PLOTTING =====================\n";
  if(debug){
    sf::Vector2f dimensions(600,600); 
    sf::Vector2f domain(-3,3); 
    graph_info* graphInfo = new graph_info("x", dimensions, domain); 
    Plot plot(graphInfo); 
    Vector<Point> points = plot.getPoints(); 
    //Point  answerKey[] = {Point(-3,-3) Point(-2,-2), Point(-1,)}

    for(int i = 0; i < points.size(); i++){
      if(points.at(i).x != points.at(i).y){
        cout<<"failed: equ was y = x , but y was not equal x\n"; 
        return false; 
      }
      cout<<"point: "<<points.at(i)<<endl; 
    }
  }
  return true; 
}

bool test_translator(bool debug){
  cout<<"========================= TEST TRANSLATOR ======================\n";
  if(debug){
    cout<<"======================= CASE - (-3,3) =====================\n"; 
    sf::Vector2f dimensions(1800,1200); 
    sf::Vector2f domain(-4,4); 
    graph_info* graphInfo = new graph_info("x^2", dimensions, domain); 
    Coordinate_Translator translator(graphInfo); 

    Point testPoint(-3,3);
    Point answerPoint(157.5,127.5); 
    Point translatePoint = translator.translate(testPoint); 
    cout<<"translated point: "<<translatePoint<<endl; 
    cout<<"original point: "<<testPoint<<endl;

    if(translatePoint.x != answerPoint.x || answerPoint.y != translatePoint.y){
      cout<<"failed test case 1\n"; 
      return false; 
    }
  }

  if(debug){
    cout<<"======================= CASE - (2,0) =====================\n"; 
    sf::Vector2f dimensions(1800,1200); 
    sf::Vector2f domain(-3,3); 
    graph_info* graphInfo = new graph_info("x^2", dimensions, domain); 
    Coordinate_Translator translator(graphInfo); 

    Point testPoint(2,0);
    Point answerPoint(1050,600); 
    Point translatePoint = translator.translate(testPoint); 
    cout<<"translated point: "<<translatePoint<<endl; 
    cout<<"original point: "<<testPoint<<endl;

    if(translatePoint.x != answerPoint.x || answerPoint.y != translatePoint.y){
      cout<<"failed test case 1\n"; 
      return false; 
    }
  }

  if(false){
    cout<<"================== LAST CASE =================\n"; 
    //just a basic runner 
    //Graph creation
    sf::Vector2f dimensions(1800,1200); 
    sf::Vector2f domain(-3,3); 
    int numPoints = 2; 
    graph_info* graphInfo = new graph_info("x^2", dimensions, domain); 

    Coordinate_Translator translator(graphInfo); 
    Plot plotter(graphInfo); 
    Vector<Point> points = plotter.getPoints(); 
    for(int i = 0; i < points.size(); i++){
      Point testPoint = points.at(i); 
      cout<<"testPoint: "<<testPoint<<endl; 
      Point translatedPoint = translator.translate(testPoint); 
      cout<<"translated point: "<<translatedPoint<<endl; 
    }
  }
  return true; 
}


//testing window creation and whether graph is being updated properly --> pan/zoom/etc
bool test_window_creation(bool debug){
  if(debug){
    sf::Vector2f dimensions(1800,1200); 
    sf::Vector2f domain(-5,5); 
    graph_info* graphInfo = new graph_info("x", dimensions, domain); 
    animate anim(graphInfo); 
    anim.run(); 
    //running so far --> window is created correctly 
  }
  return true; 
}


TEST(TEST_PLOT, testGetPoints){
  EXPECT_EQ(1, test_getPoints(false)); 
}

TEST(TEST_TRANSLATOR, testTranslator){
  EXPECT_EQ(1, test_translator(false)); 
}

TEST(TEST_ANIMATE, testWindowCreation){
  EXPECT_EQ(1, test_window_creation(true)); 
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

