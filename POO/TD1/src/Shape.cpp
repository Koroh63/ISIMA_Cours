#include "Shape.hpp"
#include <iostream>

using namespace std;

Shape::Shape(){
    px = py = .0;
}

Shape::Shape(int i,int j){
    px = i;
    py = j;

}

void Shape::afficher(){
    std::cout << "Shape" << std::endl;
}