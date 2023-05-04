#ifndef TOKEN_H 
#define TOKEN_H 

#include "../../includes/queue/MyQueue.h"

class Token{
    public:
        //Constructors 
        Token(); 
        Token(int typeVal, string tokVal); 

        int getType(); //returns the type of token it is (integer, operator, etc)
        void setType(int typeVal); //sets the type of the token
        string getToken(); //gets the string value of the token 

        friend bool operator ==(const Token& left, const Token& right){
            return ((left.type == right.type) && (left._token == right._token)); 
        }

        friend ostream& operator <<(ostream& outs, const Token& printMe){
            outs<<printMe._token; 
            return outs; 
        } 
    private: 
        int type; //type 1 --> int, type2 --> function, type3--> operator 
        string _token; 
}; 

#endif 