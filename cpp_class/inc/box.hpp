#ifndef BOX_H
#define BOX_H
class BoxA
{
      // declare member variables
    private:
      double length;   // length
      double breadth;  // breadth
      double height;   // height
    public:  
      // declare member functions
      double get(void);
      void set( double len, double bre, double hei );
      BoxA();
};

class BoxB
{
    public:
      // declare member variables
      double length;   // length
      double breadth;  // breadth
      double height;   // height
      // declare member functions
      double get(void);
      void set( double len, double bre, double hei );
      BoxB();
};
#endif