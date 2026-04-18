#include <iostream>
#include <string>
#include <vector>

struct Vertex{
  float x, y, z;
  Vertex(float x, float y, float z) : x(x), y(y), z(z) {}
  Vertex (const Vertex& vertex) 
    : x(vertex.x), y(vertex.y), z(vertex.z) {
    std::cout << "Copied!" << std::endl;
  }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& v) {
    stream << "Vertex(" << v.x << ", " << v.y << ", " << v.z << ")";
    return stream;
}

int main(){
  std::vector<Vertex*> vertices;
  vertices.reserve(10);
  vertices.push_back(new Vertex{1.0f, 2.0f, 3.0f});
  vertices.push_back(new Vertex{4.0f, 5.0f, 6.0f});
  vertices.emplace_back(7.0f, 8.0f, 9.0f);

  for (int i = 0; i < vertices.size(); ++i) {
    std::cout << *vertices[i] << std::endl;
  }

  for (Vertex* v : vertices) {
    std::cout << *v << std::endl;
  }

  std::cin.get();
  return 0;
}
