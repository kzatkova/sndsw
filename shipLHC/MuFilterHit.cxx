#include "MuFilterHit.h"
#include "MuFilter.h"
#include "MuFilterPoint.h"
#include "TVector3.h"
#include "FairRun.h"
#include "FairRunSim.h"
#include "TMath.h"
#include "TRandom1.h"
#include "TRandom3.h"
#include "TGeoManager.h"
#include "TGeoShape.h"
#include "TGeoTube.h"

#include <iostream>
#include <math.h>
using std::cout;
using std::endl;
using std::pow;
using std::floor;
using std::to_string;
#include <string> 

Double_t attenuationlength = 1.00; // Change this 
Double_t speedOfLight = TMath::C() *100./1000000000.0 ; // from m/sec to cm/ns
// -----   Default constructor   -------------------------------------------
MuFilterHit::MuFilterHit()
  : ShipHit()
{
 flag = true;
}
// -----   Standard constructor   ------------------------------------------
MuFilterHit::MuFilterHit(Int_t detID, Float_t tdc)
  : ShipHit(detID,tdc)
{
 flag = true;
}
// -----   constructor from MuFilterPoint   ------------------------------------------
MuFilterHit::MuFilterHit(MuFilterPoint* p)

  : ShipHit()
{
     TVector3 start = TVector3();
     TVector3 stop  = TVector3();
     fDetectorID = p->GetDetectorID();
     // cout << fDetectorID << endl;
     // MuFilter* module = dynamic_cast<MuFilter*> (FairRunSim::Instance()->GetListOfModules()->FindObject("MuFilter") );
     // FairRunSim* fairrunsiminstance = FairRunSim::Instance();

     // cout << fairrunsiminstance->GetListOfModules() << endl;
     // //Double_t v_drift       = module->StrawVdrift();
     // //Double_t sigma_spatial = module->StrawSigmaSpatial(); 
     

     //module->BarEndPoints(p, start, stop);
     // //Double_t t_drift = fabs( gRandom->Gaus( p->dist2Wire(), sigma_spatial ) )/v_drift;
     // //fdigi = t0 + p->GetTime() + t_drift + ( stop[0]-p->GetX() )/ speedOfLight; // What is t_drift
     
     flag = true;

     
}

void MuFilterHit::BarEndPoints(MuFilterPoint* p, TVector3 vtop, TVector3 vbot) 
{

  int subsystem = floor(fDetectorID/1e+4);
  int plane = floor(fDetectorID/1e+3) - 10*subsystem;
  int bar_number = fDetectorID - subsystem*1e+4 - plane*1e+3;

  cout << "subsystem: "<<subsystem<<endl;
  cout << "plane: "<<plane<<endl;
  cout << "bar_number: "<<bar_number<<endl;

  TString path = "FAIRGeom/cave_1/";
  switch(subsystem) {    
  
  case 1: 
      path.Append("volVeto_1/");
      cout << path<<endl;
      //int digit_2 = floor(fDetectorID/1e+3) - 10;
      if (plane == 0) {
        path.Append("volVetoPlane_0_0/volVetoBar_10");
        //int bar_number = fDetectorID- digit_1*1e+4 - digit_2*1e+3;
        cout << "bar_number: "<<bar_number << endl;
        if ( bar_number == 0 ) { 
          path.Append("000");
          }
        else if (bar_number <9) {path.Append("00"); path.Append(to_string(bar_number));}
        else if (bar_number >9) {path.Append("0"); path.Append(to_string(bar_number));}
        }
      else if (plane == 1) {
        path.Append("volVetoPlane_1_1/volVetoBar_11");
        //int bar_number = fDetectorID - digit_1*1e+4 - digit_2*1e+3;
        cout << "bar_number: "<< bar_number << endl;
                  if ( bar_number == 0 ) { 
          path.Append("000");
          }
        else if (bar_number <9) {path.Append("00"); path.Append(to_string(bar_number));}
        else if (bar_number >9) {path.Append("0"); path.Append(to_string(bar_number));}
        }
      cout << path<< endl;
      break;
    
    case 2: 
      path.Append("volMuFilter_1/");
      cout << path<<endl;
      if (plane == 0) {
        path.Append("volMuUpstreamDet_0_2/volMuUpstreamBar_20");
        cout << "bar_number: "<<bar_number << endl;
        if ( bar_number == 0 ) { 
          path.Append("000");
          }
        else if (bar_number <9) {path.Append("00"); path.Append(to_string(bar_number));}
        else if (bar_number >9) {path.Append("0"); path.Append(to_string(bar_number));}
        }
      else if (plane == 1) {
        path.Append("volVetoPlane_1_3/volVetoBar_21");
        //int bar_number = fDetectorID - digit_1*1e+4 - digit_2*1e+3;
        cout << "bar_number: "<< bar_number << endl;
                  if ( bar_number == 0 ) { 
          path.Append("000");
          }
        else if (bar_number <9) {path.Append("00"); path.Append(to_string(bar_number));}
        else if (bar_number >9) {path.Append("0"); path.Append(to_string(bar_number));}
        }
      else if (plane == 2) {
        path.Append("volVetoPlane_2_4/volVetoBar_22");
        //int bar_number = fDetectorID - digit_1*1e+4 - digit_2*1e+3;
        cout << "bar_number: "<< bar_number << endl;
                  if ( bar_number == 0 ) { 
          path.Append("000");
          }
        else if (bar_number <9) {path.Append("00"); path.Append(to_string(bar_number));}
        else if (bar_number >9) {path.Append("0"); path.Append(to_string(bar_number));}
        }
      else if (plane == 3) {
        path.Append("volVetoPlane_3_5/volVetoBar_23");
        //int bar_number = fDetectorID - digit_1*1e+4 - digit_2*1e+3;
        cout << "bar_number: "<< bar_number << endl;
                  if ( bar_number == 0 ) { 
          path.Append("000");
          }
        else if (bar_number <9) {path.Append("00"); path.Append(to_string(bar_number));}
        else if (bar_number >9) {path.Append("0"); path.Append(to_string(bar_number));}
        }
      else if (plane == 4) {
        path.Append("volVetoPlane_4_6/volVetoBar_24");
        //int bar_number = fDetectorID - digit_1*1e+4 - digit_2*1e+3;
        cout << "bar_number: "<< bar_number << endl;
                  if ( bar_number == 0 ) { 
          path.Append("000");
          }
        else if (bar_number <9) {path.Append("00"); path.Append(to_string(bar_number));}
        else if (bar_number >9) {path.Append("0"); path.Append(to_string(bar_number));}
        }                                     
      break;

    case 3: 
      path.Append("volMuFilter_1/");
      cout << path<<endl;  
      if (plane == 0) {
        path.Append("volMuDownstreamDet_0_5/volMuDownstreamBar_");
        //int bar_number = fDetectorID - digit_1*1e+4 - digit_2*1e+3;
        cout << "bar_number: "<<bar_number << endl;
        if ( bar_number < 60 ) { 
          if (bar_number < 10) {path.Append("hor_00"); path.Append(to_string(bar_number));}
          else if (bar_number >9 and bar_number<60) {path.Append("hor_0"); path.Append(to_string(bar_number));}
          }
        else {
          if (bar_number < 100) {path.Append("ver_0"); path.Append(to_string(bar_number));}
          else { path.Append("ver_"+to_string(bar_number));}
        }
        }
      cout << path << endl;
      break;
      if (plane == 1) {
        path.Append("volMuDownstreamDet_1_6/volMuDownstreamBar_");
        //int bar_number = fDetectorID - digit_1*1e+4 - digit_2*1e+3;
        cout << "bar_number: "<<bar_number << endl;
        if ( bar_number < 60 ) { 
          if (bar_number < 10) {path.Append("hor_00"); path.Append(to_string(bar_number));}
          else if (bar_number >9 and bar_number<60) {path.Append("hor_0"); path.Append(to_string(bar_number));}
          }
        else {
          if (bar_number < 100) {path.Append("ver_0"); path.Append(to_string(bar_number));}
          else { path.Append("ver_"+to_string(bar_number));}
        }
        }
      cout << path << endl;
      break;
      if (plane == 2) {
        path.Append("volMuDownstreamDet_2_7/volMuDownstreamBar_");
        //int bar_number = fDetectorID - digit_1*1e+4 - digit_2*1e+3;
        cout << "bar_number: "<<bar_number << endl;
        if ( bar_number < 60 ) { 
          if (bar_number < 10) {path.Append("hor_00"); path.Append(to_string(bar_number));}
          else if (bar_number >9 and bar_number<60) {path.Append("hor_0"); path.Append(to_string(bar_number));}
          }
        else {
          if (bar_number < 100) {path.Append("ver_0"); path.Append(to_string(bar_number));}
          else { path.Append("ver_"+to_string(bar_number));}
        }
        }
      cout << path << endl;
      break;
  }

    TGeoNavigator* nav = gGeoManager->GetCurrentNavigator();
    nav->cd(path);
    TGeoNode* W = nav->GetCurrentNode();
    TGeoBBox* S = dynamic_cast<TGeoBBox*>(W->GetVolume()->GetShape());

    if (subsystem == 3 and bar_number >59){

      Double_t top[3] = {0,S->GetDY(), 0}; // Why z? Surely the straws go in x or y?
      Double_t bot[3] = {0,-S->GetDY(),0};
      Double_t Gtop[3],Gbot[3];
      nav->LocalToMaster(top, Gtop);   nav->LocalToMaster(bot, Gbot);
      vtop.SetXYZ(Gtop[0],Gtop[1],Gtop[2]);
      vbot.SetXYZ(Gbot[0],Gbot[1],Gbot[2]);
      // Find distances from MCPoint centre to top of bar 
      Double_t distance_to_top_of_bar =  pow(pow(p->GetX() - vtop.X(), 2) + pow(p->GetY() - vtop.Y(), 2) + pow(p->GetZ() - vtop.Z(), 2)   , 0.5);

    }
    else {
      Double_t posXend[3] = {S->GetDX(),0,0};
      Double_t negXend[3] = {-S->GetDZ(),0,0};
      Double_t GposXend[3],GnegXend[3];
      nav->LocalToMaster(posXend, GposXend);   nav->LocalToMaster(negXend, GnegXend);
      vtop.SetXYZ(GposXend[0],GposXend[1],GposXend[2]);
      vbot.SetXYZ(GnegXend[0],GnegXend[1],GnegXend[2]);
      // Find distances from MCPoint centre to top of bar 

      Double_t distance_to_posXend =  pow(pow(p->GetX() - vtop.X(), 2) + pow(p->GetY() - vtop.Y(), 2) + pow(p->GetZ() - vtop.Z(), 2), 0.5);      
      Double_t distance_to_negXend =  pow(pow(p->GetX() - vbot.X(), 2) + pow(p->GetY() - vbot.Y(), 2) + pow(p->GetZ() - vbot.Z(), 2), 0.5);     
            

    }


}

// void MuFilterHit::EnergyValues(MuFilterPoint* p) 
// {

// }

// Double_t MuFilterHit::EnergyAttenuation(MuFilterPoint* p)
// {
//   Double_t Eloss = p->GetEloss();
//   Double_t res_energy = Eloss - pow(e, -1*attenuationlength)
  
// }


// -------------------------------------------------------------------------

// -----   Destructor   ----------------------------------------------------
MuFilterHit::~MuFilterHit() { }
// -------------------------------------------------------------------------

// -----   Public method Print   -------------------------------------------
void MuFilterHit::Print() const
{
  cout << "-I- MuFilterHit: MuFilter hit " << " in detector " << fDetectorID << endl;
  cout << "  TDC " << fdigi << " ns" << endl;
}
// -------------------------------------------------------------------------

ClassImp(MuFilterHit)

