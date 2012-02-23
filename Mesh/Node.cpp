#include "Node.h"

#include <iomanip>
//------------------------------------------------------ 
//   Topology definition of geometrical element.
//    WW. 10.01.2005
//------------------------------------------------------ 
namespace Mesh_Group
{ 
  
using namespace std;

//1.  Node declaration
 //    WW. 06.2005
Node:: Node(const int Index, const double x, 
            const double y, const double z):Grain(Index)
{
   Coordinate = new double[3];
   Coordinate[0] = x;
   Coordinate[1] =y;
   Coordinate[2] =z;
   boundayC = 'I';
  
}
//    WW. 06.2005
void Node::operator = (const Node& n)
{
   boundayC = n.boundayC; 
   index = n.index;
   mark = n.mark;
   Coordinate[0] = n.Coordinate[0]; 
   Coordinate[1] = n.Coordinate[1]; 
   Coordinate[2] = n.Coordinate[2]; 
}
//    WW. 06.2005
bool Node::operator == (const Node& n)
{
   if(index == n.index)
      return true;
   else 
	  return false;
}
//    WW. 06.2005
// Output
void Node::Write(ostream& osm) const
{
    osm.setf(ios::scientific, ios::floatfield);
    setw(14);
    osm.precision(14);
    osm<<index<<deli
       <<Coordinate[0]<<deli
       <<Coordinate[1]<<deli
       <<Coordinate[2]<<endl;
}
//    WW. 06.2005
// Set
void Node::SetCoordinates(const double* argCoord)
{
    Coordinate[0] = argCoord[0];
  	Coordinate[1] = argCoord[1];
  	Coordinate[2] = argCoord[2];
}

}
