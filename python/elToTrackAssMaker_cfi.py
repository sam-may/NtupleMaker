import FWCore.ParameterSet.Config as cms

elToTrackAssMaker = cms.EDFilter("ElToTrackAssMaker",
    # min DR
    minDR = cms.double(0.1),
    haveHits = cms.bool(True),
    electronsInputTag = cms.InputTag("allLayer1Electrons"),
    tracksInputTag    = cms.InputTag("generalTracks")
)

