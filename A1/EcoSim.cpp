/*
  Name: Wenlin Li
  Assignment: A1 An Ecological Simulation
  Some basic C++ programming in the context of the ecological simulation.
*/

#include <iostream>
#include <cmath>
using namespace std;

// declare some methods
void runSimulation(int iterations, double rabbits, double foxes);
void updatePopulations(double g, double p, double c, double m, double K,
double& numRabbits, double& numFoxes);
void plotCharacter(int number, char character);
void plotPopulations(double rabbits, double foxes, double factor);
void incrementCounter(int* pointer);

// Tge main function that that asks the user for initial rabbit and fox populations, 
// stored as doubles to smooth the simulation, then calls runSimulation with a value of 500 iterations 
// and the initial rabbit and fox populations.
int main(){

        double RabbitsNum, FoxesNum;
        cout << "Enter the number of the rabbits: ";
        if(!(cin >> RabbitsNum) and RabbitsNum < 0){
            cout << "Invalid Input" << endl;
            return 0;
        }


        cout << "Enter the number of the foxes: ";
        if(!(cin >> FoxesNum) and FoxesNum < 0){
            cout << "Invalid Input" << endl;
            return 0;
        }

        runSimulation(500, RabbitsNum, FoxesNum);
}

// The void runSimulation function that has parameters for iterations, number of rabbits, and number of foxes in that order. 
// Rabbits and foxes should be double type for the simulation math.
void runSimulation(int iterations, double rabbits, double foxes){
    for(int i = 0; i < iterations and (rabbits > 1 and foxes > 1); incrementCounter(&i)){
        // These value come from the instructions
        plotPopulations(rabbits, foxes, 0.1);
        std::cout << std::endl;
        updatePopulations(0.2,0.0022,0.6,0.2,1000.0,rabbits,foxes);    
    }
}

// A void function with the population update that takes in the model parameters and 
// the number of rabbits and number of foxes with a pass-by-reference style.
void updatePopulations(double g, double p, double c, double m, double K, double& numRabbits, double& numFoxes){
    // delta rabbits = g*rabbits*(1-(rabbits/K)) - p*rabbits*foxes
    double deltaR = g * numRabbits * (1 - (numRabbits / K)) - p * numRabbits * numFoxes;
    // delta foxes = c*p*rabbits*foxes-m*foxes
    double deltaF = c * p * numRabbits *numFoxes - m * numFoxes;

    numRabbits = numRabbits + deltaR;
    numFoxes = numFoxes + deltaF;
}

// The void charting function plotPopulations that has parameters for the number of rabbits, the number of foxes, 
// and a fractional scale factor in that order.
void plotPopulations(double rabbits, double foxes, double factor){

    int rabbitsPosition = floor(rabbits * factor);
    int foxesPosition = floor(foxes * factor);

    if(rabbitsPosition == foxesPosition){
        plotCharacter(rabbitsPosition, '*');
        
    }
    else if (rabbitsPosition > foxesPosition){
        plotCharacter(foxesPosition, 'F');
        plotCharacter(rabbitsPosition - foxesPosition - 1 , 'r');
       
    }
    else{
        plotCharacter(rabbitsPosition,'r');
        plotCharacter(foxesPosition - rabbitsPosition - 1, 'F');
 
    }

}

// A void helper function plotCharacter that takes in an int number 
// and a character and sends to std::cout number spaces followed by the character. 
void plotCharacter(int number, char character){
    string line = "";
    for(int i = 0; i < number; i++){
        line +=" ";  
    }
    line += character;
    cout << line;
}

// A helper function incrementCounter that returns void and has a pointer to an integer parameter. 
void incrementCounter(int* pointer){
    // pass by deference
    *pointer += 1;
}
