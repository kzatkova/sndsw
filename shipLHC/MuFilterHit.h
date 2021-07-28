#ifndef MUFILTERHIT_H
#define MUFILTERHIT_H 1


#include "ShipHit.h"
#include "MuFilterPoint.h"
#include "TObject.h"
#include "TVector3.h"

class MuFilterHit : public ShipHit
{
  public:

    /** Default constructor **/
    MuFilterHit();

    /** Constructor with arguments
     *@param detID    Detector ID
     *@param digi      digitized/measured TDC 
     *@param flag      True/False, false if there is another hit with smaller tdc 
     **/
    MuFilterHit(Int_t detID, Float_t tdc);
    // MuFilterHit(MuFilterPoint* p, Double_t t0 = 0.0);
    MuFilterHit(MuFilterPoint* p);

    void BarEndPoints(MuFilterPoint* p, TVector3 vtop, TVector3 vbot);  
/** Destructor **/
    virtual ~MuFilterHit();

    /** Output to screen **/
    virtual void Print() const;
    Float_t GetTDC() const {return fdigi;}
    void setInvalid() {flag = false;}
    bool isValid() const {return flag;}

  private:
    /** Copy constructor **/
    MuFilterHit(const MuFilterHit& point);
    MuFilterHit operator=(const MuFilterHit& point);

    Float_t flag;   ///< flag

    ClassDef(MuFilterHit,1);
    

};

#endif
