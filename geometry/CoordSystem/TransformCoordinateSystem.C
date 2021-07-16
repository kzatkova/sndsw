#include "TransformCoordinateSystem.h"

/* Legend:
          CCS = CERN Coordinate System
          localSND_CS = SND survey coordinate system (for the alignment and installation of the detector)
          localSND_physCS = SND “Physics” coordinate system (for physics studies)
*/

void TransformCoordinateSystem(){
  const localSND_CS_to_CCS::Point point(0.,0.,0.); // point is in localSND_CCS
  localSND_CS_to_CCS cs;
  localSND_CS_to_CCS::Point new_point = cs.operator()(point);
  cout<<"Point "<<point<<" transformed to "<<new_point<<endl;
  // Check matrix elements:
  /*double xx,   xy,   xz,   dx, yx,   yy,   yz,   dy, zx,   zy,   zz,   dz;                   
  cs.GetComponents(xx,   xy,   xz,   dx, yx,   yy,   yz,   dy, zx,   zy,   zz, dz);
  cout<<"xx "<<xx<<" xy "<<xy<<" dz "<<dz<<endl;*/
}
