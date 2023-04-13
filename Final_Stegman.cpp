/*
Name: Chandler Stegman
Date: 4/20/20
Activity: Poker
*/


#include <bits/stdc++.h>

using namespace std;

class Poker{
public:
   int bet;
   int chips;
   int total_hands;
   int total_wins;
   int total_loss;
  
   Poker(){
       chips=100;
       total_hands = 0;
       total_wins = 0;
       total_loss = 0;
       bet=0;
   }

   string randomCard(){
          srand(time(NULL));
       
       int number = rand() % 9 + 2; 
       
       stringstream its;
       its<<number;
       
       string suit[4]={"C","S","H","D"};
       int suit_index= rand() % 4;
       string card = its.str()+suit[suit_index];
       return card;
   }

    vector<string> hand(){
       total_hands++;
       vector<string> cards;
        for(int i=0;i<4;i++){
           while(1){
                string card=randomCard();
                if(find(cards.begin(),cards.end(),card) == cards.end()){
                  cards.push_back(card);
                   break;
               }
           }          
       }
      
       for(int i=0;i<cards.size();i++){
           cout<<cards[i]<<" ";
       }
       cout<<endl;
      
       return cards;
   }

   void checkHand(vector<string> hand){
 
       vector<int> number;
       vector<char> suit;
       for(int i=0;i<4;i++){
           string number_string=hand[i].substr(0,hand[i].length()-1);
           number.push_back(atoi(number_string.c_str()));
           
           suit.push_back(hand[i][hand[i].length()-1]);
       }
       
	   sort(number.begin(), number.end());
       
       if(number[0]==number[1] && number[1]==number[2] && number[2]==number[3]){
           cout<<"Congrats: Four of a kind! +1,000 Chips"<<endl;
           total_wins++;
           chips+=1000;
       }
       else if(number[0]==number[1]-1 && number[1]==number[2]-1 && number[2]==number[3]-1){
           
           if(suit[0]==suit[1] && suit[1]==suit[2] && suit[2]==suit[3]){
               cout<<"Congrats: Straight Flush nice!  +500 Chips"<<endl;
               total_wins++;
               chips+=500;
           }
           else{
               cout<<"Congrats:Flush +250 Chips"<<endl;
               total_wins++;
               chips+=250;
           }
       }
       else if((number[0]==number[1] && number[1]==number[2]) ||
           (number[1]==number[2] && number[2]==number[3])){
           cout<<"Congrats: Three of a kind +150 Chips"<<endl;
           total_wins++;
           chips+=150;
       }
       else if(number[0]==number[1] && number[2]==number[3]){
           cout<<"Congrats: Two Pair +100 Chips"<<endl;
           total_wins++;
           chips+=100;
       }
       else if((number[0]==number[1]) || (number[1]==number[2]) || (number[2]==number[3])){
           cout<<"Congrats: Two of a kind! +1 Chip"<<endl;
           total_wins++;
           chips+=1;
       }
       else{
           cout<<"Sorry: You got nothing and have lost $"<<bet<<endl;
         
           total_loss++;
           chips-=bet;
       }
   }
};

int main(){
   
   cout<<"Welcome to single player Poker game"<<endl;
   cout<<"Your Start Ammount is: $100"<<endl<<endl;
   cout<<"=================================================="<<endl;
   
   Poker poker;
 
   string y;
   while(1){
       
       cout<<"Play a hand [y / n]? ";
       cin>>y;
       if(y=="y" || y=="n"){
           break;
       }
     
       cout<<"Invalid input, should be y or n"<<endl;
   }
   while(y=="y"){
       cout<<endl<<"Place your bet [1, "<<poker.chips<<"]: ";
     
       cin>>poker.bet;
       
       if(poker.bet>poker.chips){
           cout<<poker.bet<<" Invalid  you only have "<<poker.chips<<endl;
           continue;
       }
       
       cout<<"... Shuffling Deck ..."<<endl;
       cout<<"... Good luck ..."<<endl;
     
       vector<string> hand=poker.hand();
       
       poker.checkHand(hand);
       cout<<endl;
      
       if(poker.chips<=0){
           cout<<"You broke the bank"<<endl;
       }
       
       while(1){
           cout<<"Play a hand [y / n]? ";
           cin>>y;
           if(y=="y" || y=="n"){
               break;
           }
           cout<<"Invalid input, should be y or n"<<endl;
       }
   }
   
   cout<<endl<<"=================================================="<<endl;
   cout<<"Thanks for playing ..."<<endl;
   cout<<"You played a total of "<<poker.total_hands<<" hands"<<endl;
   cout<<"You have won "<<poker.total_wins<<endl;
   cout<<"And lost "<<poker.total_loss<<endl;
   cout<<"But in the end you won $"<<poker.chips-100;
}
