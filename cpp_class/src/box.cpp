#include <iostream>
#include "box.hpp"

using namespace std;

double BoxA::get(void){
  return length * breadth * height;
}

double BoxB::get(void){
  return length * breadth * height;
}

void BoxA::set( double len, double bre, double hei){
  length = len;
  breadth = bre;
  height = hei;
}

void BoxB::set( double len, double bre, double hei){
  length = len;
  breadth = bre;
  height = hei;
}

BoxB::BoxB(){
  length = 0;
  breadth = 0;
  height = 0;
  cout << "BoxB is used" <<endl;
}

BoxA::BoxA(){
  length = 0;
  breadth = 0;
  height = 0;
  cout << "BoxA is used" <<endl;
}