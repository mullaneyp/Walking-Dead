/*************************************************
 ** Author: Patrick Mullaney
 ** Description: Main driver program for text
 ** based Walking Dead dungeon crawler game.
 ** Date: 11/28/16
 ************************************************/

#include <iostream>
#include "grid.hpp"
#include "menu.hpp"
#include "space.hpp"
#include "walker.hpp"
#include "negansmen.hpp"
#include "hilltop.hpp"
#include "fighter.hpp"
#include "Rick.hpp"
#include "Michonne.hpp"
#include "Savior.hpp"
#include "Negan.hpp"
#include <queue>
#include "queue.hpp"
#include "stack.hpp"
#include "Item.hpp"
#include "Tank.hpp"
#include "prison.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {

    int moves, food, guns, health;
    
    Grid board;
    cout << "Walking Dead: Save The Kingdom" << endl;
    cout << "Save King Ezekiel and The Kingdom from Negan" << endl;
    cout << "Map legend: \nA Armory\nH Hilltop\nK The Kingdom" << endl;
    cout << "# Grass\n. Road\n^ hill\nS Savior\nW Walker" << endl;
    cout << "\nNote to TA: " << endl;
    cout << "To win game: must make it to Kingdom before food runs out and fight boss Negan" << endl;
    
    // Initialize board spaces.
    board.setBoard();
    // Player pointer.
    Fighter* pl;
    // Select player.
    pl = selection();
    // Set player on board.
    board.setPlayer(9,5, pl);
   // board.setPlayer(0,8,pl); *** used to get to/test bost battle quicker.
    char loc;
    bool key;
    loc = pl->getLoc()->getChar();
    Item** satchel;
    int foodSupply;
    foodSupply = 25;
    
    /* Player traverses board until either the Kingdom's food supply runs out,
    // player dies, or player reaches the kingdom. */
    while((foodSupply > 0) && (pl->getStrength()> 0) && (loc != 'K'))
    {
            satchel = pl->getSatchel();
            board.print();
        
          //  guns = board.getPlayer()->getGuns();
            guns = satchel[0]->getQuantity();
            key = pl->getKey();
            //food = board.getPlayer()->getFood();
            food = satchel[1]->getQuantity();
            health = board.getPlayer()->getStrength();
            if(key)
            {
                cout << "Key: " << key;
            }
            else if(!key)
            {
                cout << "Guns: " << guns;
            }
            cout << " Food: " << food << " Health: " << health << endl;
            if(food < 0)
            {
                cout << "Out of food " << pl->getType() << " starving. -1 strength." << endl;
                pl->setStrength((pl->getStrength())-1);
            }
            cout << "Location: " << pl->getLoc()->getName() << endl;
            cout << "Kingdom food supply: " << foodSupply << endl;
        
            loc = pl->getLoc()->getChar();
            if(loc!='K')
            {
                cout << "Please make a move: " << endl;
                moves = move();
                board.makeMove(moves);
            }
            foodSupply--;
    }
    cout << "location before battle: " << pl->getLoc()->getName() << endl;
    pl->getLoc()->setPlayer(NULL);
    // If player has died, output error message.
    if(pl->getStrength() <= 0)
    {
        cout << pl->getType() << " died." << endl;
        pl->free();
    }
    // If Kingdom food supply has run out.
    if(foodSupply <= 0)
    {
        cout << "The Kingdom has starved...Negan won...you have failed." << endl;
        pl->free();
    }
    // If player alive and food supply greater than 0, boss fight commences.
    if((pl->getStrength() > 0) && (foodSupply > 0))
    {
        cout << "Fight negan!" << endl;
        Fighter *f1, *f2, *f3, *c1;
        satchel = pl->getSatchel();
     
        guns = satchel[0]->getQuantity();
        cout << "Team size: " << (guns/5) << endl;
        Queue team;
        Stack loser;
        
        // If player has gotten the tank, only the tank fights.
        if(pl->getTank())
        {
            cout << pl->getType() << " has Tank!" << endl;
            f1 = new Tank();
            team.push(f1);
        }
        else if(!pl->getTank()) //Else player fights.
        {
            f1 = board.getPlayer();
            team.push(f1);
            if(pl->getLoc()->getChar() == 'K')
            {
                if(pl->getLoc()->getZeke()) // If player gave all food to Ezekiel, he fights with you.
                {
                    team.push(new Ezekiel());
                }
            }
            // If guns are greater than 10, allow player to select a second character to join the fight.
            if((guns/5) > 2)
            {
                f2 = selectTeam(f1);
                cout << f2->getType() << " selected" << endl;
                team.push(f2);
            }
            if((guns/5) > 3)
            {
                f3 = selectTeam(f1);
                team.push(f3);
            }
        }
        // Initialize boss Negan.
        c1 = new Negan();
        cout << "Team: ";
        team.display();
        int roll1, roll2, round, order;
        round = 0;
        while(!(team.empty()) && (c1->getStrength() > 0))
        {
            cout << f1->getType() << " strength: " << f1->getStrength() << endl;
            cout << c1->getType() << " strength: " << c1->getStrength() << endl;
            
            while((f1->getStrength() > 0) && (c1->getStrength()> 0))
            {
                f1 = team.pop();
                order = round%2;
        
                // Heal fighters.
                f1->heal();
                c1->heal();
        
                cout << f1->getType() << " strength: " << f1->getStrength() << endl;
                cout << c1->getType() << " strength: " << c1->getStrength() << endl;
            
                if(order == 1)            // Player 1 attacks first.
                {
                    roll1 = f1->attack();
                    //    cout << "P1 " << f1->getName() << " attack: " << roll1 << endl;
                    // Player 2 defends.
                    c1->defend(roll1);
                
                    // If player 2 dies, notify user.  If alive, attack player 1.
                    if(c1->getStrength() <= 0)
                    {
                        cout << c1->getType() << " died! " << endl;
                        loser.push(c1);
                    }
                    else if(c1->getStrength() > 0)
                    {
                        roll2 =  c1->attack();
                        f1->defend(roll2);
                        if(f1->getStrength() <= 0)
                        {
                            cout  << f1->getType() << " died! " << endl;
                            loser.push(f1);
                            f1 = team.pop();
                        }
                       // else
                         //   team.push(f1);
                    }
                }
                else if(order == 0)            // Negan attacks first.
                {
                    roll1 = c1->attack();
                    // Player 1 defends.
                    f1->defend(roll1);
                
                    // If player 1 dies, notify user.  If alive, attack player 2.
                    if(f1->getStrength() <= 0)
                    {
                        cout << f1->getType() << " died! " << endl;
                        loser.push(f1);
                        f1 = team.pop();
                    }
                    else if(f1->getStrength() > 0)
                    {
                        roll2 = f1->attack();
                    //          cout << "P1 " << f1->getName() << " attack: " << roll2 << endl;
                        c1->defend(roll2);
                      //  team.push(f1);
                        if(c1->getStrength() <= 0)
                        {
                            cout  << c1->getType() << " died! " << endl;
                            loser.push(c1);
                        }
                    }
                }
            if(f1->getStrength()> 0)
            {
                team.push(f1);
            }
            }
        }
        // Display winner
        if(c1->getStrength() > 0)
        {
            cout << "Negan has won, you have failed."  << endl;
        }
        else
        {
            cout << "You have won!" << endl;
            // Display alive characters
            cout << "Those who survived: " << endl;
          //  cout << f1->getType() << endl;
            if(!team.empty())
            {
                team.display();
            }
        }
        // Display defeated characters
        cout << "Those who have fallen: " << endl;
        loser.display();
    }
    cout << "Game over." << endl;
    return 0;
}
