#ifndef BOXPOINT_H
#define BOXPOINT_H 1


#include "FairMCPoint.h"

#include "TObject.h"
#include "TVector3.h"

class EmulsionDetPoint : public FairMCPoint
{

  public:

    /** Default constructor **/
    EmulsionDetPoint();


    /** Constructor with arguments
     *@param trackID  Index of MCTrack
     *@param detID    Detector ID
     *@param pos      Ccoordinates at entrance to active volume [cm]
     *@param mom      Momentum of track at entrance [GeV]
     *@param tof      Time since event start [ns]
     *@param length   Track length since creation [cm]
     *@param eLoss    Energy deposit [GeV]
     **/

    
    EmulsionDetPoint(Int_t trackID, Int_t detID, TVector3 pos, TVector3 mom,
		Double_t tof, Double_t length, Double_t eLoss, Int_t pdgCode);

    /** Destructor **/
    virtual ~EmulsionDetPoint();

    /** Output to screen **/
    virtual void Print(const Option_t* opt) const;
    

    Int_t PdgCode() const {return fPdgCode;}

  private:


    Int_t fPdgCode;
    
    /** Copy constructor **/
    
    EmulsionDetPoint(const EmulsionDetPoint& point);
    EmulsionDetPoint operator=(const EmulsionDetPoint& point);

    ClassDef(EmulsionDetPoint,1)

};

#endif
