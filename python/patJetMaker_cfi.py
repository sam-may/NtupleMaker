import FWCore.ParameterSet.Config as cms

patJetMaker = cms.EDFilter("PATJetMaker",
    # qt jet collection
    patJetsInputTag = cms.InputTag("allLayer1Jets")
)


