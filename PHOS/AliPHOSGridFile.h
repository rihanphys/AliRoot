#ifndef ALIPHOSGRIDFILE_H
#define ALIPHOSGRIDFILE_H
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

//_________________________________________________________________________
// Description of logical filename in Grid catalogue
// check here : /afs/cern.ch/user/p/peters/public/README.GRID 
//*--                  
//*-- Author: Yves Schutz (CERN)

// --- ROOT system ---
#include "TObject.h" 
#include "TString.h" 
#include "TGrid.h" 

// --- AliRoot header files ---

class AliPHOSGridFile : public TObject {

 public:
  
  AliPHOSGridFile(TString grid="alien") ; 
  AliPHOSGridFile(AliPHOSGridFile & lfn) : TObject(lfn) {
    lfn.Copy(*this) ; 
  } 
  virtual ~AliPHOSGridFile(void) ; 
  virtual void Copy(AliPHOSGridFile & lfn) ;
  
  void ListEvents() const ; 
  void ListRuns() const ; 
  TString GetRootDir() const { return fRoot ; }
  TString GetLFN() const ; 
  void Help() ; 
  Bool_t IsConnected() const {
    Bool_t rv = kFALSE ; 
    if(fGrid) 
      rv = kTRUE ; 
    return rv ; }
  Bool_t SetYearProd(TString year, TString prod) ; 
  Bool_t SetVers(TString vers) ; 
  Bool_t SetType(TString type) ; 

  Bool_t SetPath(TString year, TString prod, TString vers, TString type) ; 

  Bool_t SetRun(Int_t run) ; 
  Bool_t SetEvt(Int_t evt) ; 

  TString Pwd() const { return fPath ; }

  AliPHOSGridFile & operator = (const AliPHOSGridFile & /*rvalue*/)  {
    // assignement operator requested by coding convention but not needed
    Fatal("operator =", "not implemented") ;
    return *this ; 
  }
  
private:
  
  TGrid * fGrid ; //! connection to alien data catalogue 
  TString fRoot ; //! root directory
  TString fYear ; //! year of the DC 
  TString fProd ; //! production id 
  TString fVers ; //! aliroot tag version
  TString fType ; //! event type
  TString fRun  ; //! run number
  TString fEvt  ; //! event number
  TString fPath ; //! the lfn is fRoot/fYear/fProd/fVers/fType/fRun/fEvt
 

  ClassDef(AliPHOSGridFile,1)  
    
    };

#endif // AliPHOSGRIDFILE_H
 
