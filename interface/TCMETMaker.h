// -*- C++ -*-
//
// Package:    NtupleMaker
// Class:      TCMETMaker
// 
/**\class TCMETMaker.cc CMS2/NtupleMaker/src/TCMETMaker.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Puneeth Kalavase
//         Created:  Fri Jun  6 11:07:38 CDT 2008
// $Id: TCMETMaker.h,v 1.1 2008/12/17 10:29:20 fgolf Exp $
//
//
#ifndef NTUPLEMAKER_TCMETMAKER_H
#define NTUPLEMAKER_TCMETMAKER_H

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

//
// class decleration
//

class TCMETMaker : public edm::EDProducer {
public:
     explicit TCMETMaker (const edm::ParameterSet&);
      ~TCMETMaker();

private:
     virtual void beginJob(const edm::EventSetup&) ;
     virtual void produce(edm::Event&, const edm::EventSetup&);
     virtual void endJob() ;

      // ----------member data ---------------------------
  
};


#endif