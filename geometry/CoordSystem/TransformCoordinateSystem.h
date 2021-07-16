#include "Math/GenVector/Transform3D.h"

/* Legend:
          CCS = CERN Coordinate System
          localSND_CS = SND survey coordinate system (for the alignment and installation of the detector)
          localSND_physCS = SND “Physics” coordinate system (for physics studies)
*/

class CCS_to_localSND_CS : public ROOT::Math::Impl::Transform3D< double >{
   public:
          CCS_to_localSND_CS() : Transform3D(
                    -0.38654450555754,  0.92227075172880, -0.00007568936293, -1648.5120705, 
                    -0.92227075413233, -0.38654450716425, -0.00000730284011,  2598.8710132,
                    -0.00003599250333,  0.00006698321311,  0.99999999710889, -2365.0776284){};    
};
class localSND_CS_to_CCS : public ROOT::Math::Impl::Transform3D< double >{
   public:
          localSND_CS_to_CCS() : Transform3D(
                    -0.38654450555754, -0.92227075413233, -0.00003599250332,  1759.5543209,
                     0.92227075172880, -0.38654450716425,  0.00006698321308,  2525.1122020,
                    -0.00007568936290, -0.00000730284012,  0.99999999710889,  2364.9718259){};
};
class CCS_to_localSND_physCS : public ROOT::Math::Impl::Transform3D< double >{
   public:
          CCS_to_localSND_physCS() : Transform3D(
                     0.38646054170418, -0.92228282252868, -0.00653031195550,  1664.3132966,
                     0.01398585186500, -0.00121946161748,  0.99990144957439, -2386.2683455,
                    -0.92219989462877, -0.38651378782896,  0.01242763713624,  2569.2604796){};
};
class localSND_physCS_to_CCS : public ROOT::Math::Impl::Transform3D< double >{
   public:
          localSND_physCS_to_CCS() : Transform3D(
                     0.38646054170417,  0.01398585186511, -0.92219989462877,  1759.5543210,
                    -0.92228282252868, -0.00121946161773, -0.38651378782896,  2525.1122020,
                    -0.00653031195578,  0.99990144957439,  0.01242763713624,  2364.9718258){};
};
