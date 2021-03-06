// -*- C++ -*-
//
// Package:    NtupleMaker
// Class:      PFMETMaker
// 
/**\class PFMETMaker.cc CMS3/NtupleMaker/src/PFMETMaker.cc

   Description: <one line class summary>

   Implementation:
   <Notes on implementation>
*/
//
// Original Author:  Puneeth Kalavase
//         Created:  Fri Jun  6 11:07:38 CDT 2008
// $Id: PFMETMaker.h,v 1.5 2012/05/09 22:51:52 fgolf Exp $
//
//
#ifndef NTUPLEMAKER_PFMETMAKER_H
#define NTUPLEMAKER_PFMETMAKER_H

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/PatCandidates/interface/MET.h"

//
// class decleration
//

class PFMETMaker : public edm::stream::EDProducer<> {
public:
    explicit PFMETMaker (const edm::ParameterSet&);
    ~PFMETMaker();

private:
    virtual void beginJob() ;
    virtual void produce(edm::Event&, const edm::EventSetup&);
    virtual void endJob() ;

    // ----------member data ---------------------------
    edm::EDGetTokenT<edm::View<pat::MET> > pfMetToken;
	std::string aliasprefix_;
    edm::InputTag pfMetCorInputTag;

  bool isData_;
  bool onlySaveTwoVector_;
  bool doUncertainties_;
};


#endif
