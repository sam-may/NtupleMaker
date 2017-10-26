# NtupleMaker
This is a fork from cms-tas/NtupleMaker that includes a modified main_pset.py which allows for easily making CMS4 with or without pf candidates.

### Installing
1. `curl https://raw.githubusercontent.com/cmstas/NtupleMaker/master/install.sh > install.sh`.
2. `source install.sh` will check out the CMSSW release and NtupleMaker repository, and build everything.

### Running
1. `cd $CMSSW_BASE/src/CMS3/NtupleMaker/test/`.
2. To make a CMS4 ntuple with pfcands: `cmsRun main_pset.py pfcands=True`
3. To make a CMS4 ntuple without pfcands: `cmsRun main_pset.py pfcands=False`

### Notes
1. You might want to modify some of the lines in the last block of code in main_pset.py:
```
process.GlobalTag.globaltag = "92X_dataRun2_Prompt_v8"
if opts.pfcands:
  process.out.fileName = cms.untracked.string('ntuple_YesPfCands.root')
else:
  process.out.fileName = cms.untracked.string('ntuple_NoPfCands.root')
process.source.fileNames = cms.untracked.vstring("/store/data/Run2017C/SingleMuon/MINIAOD/PromptReco-v3/000/300/742/00000/DA895311-577E-E711-84E0-02163E01A1DD.root")
# process.eventMaker.CMS3tag = cms.string('V08-00-18')
# process.eventMaker.datasetName = cms.string('/DoubleEG/Run2016C-03Feb2017-v1/MINIAOD')
# process.maxEvents.input = cms.untracked.int32(1000)
```
  * To run a small test with only a few events, change `process.maxEvents.input = cms.untracked.int32(-1)` from `-1` to desired number of events.
  * To run on a different file, select a name from: `http://uaf-10.t2.ucsd.edu/~namin/makers/disMaker/?query=%2FMET%2FRun2017B-PromptReco-v1%2FMINIAOD&type=files&short=short` and replace the string in `process.source.fileNames` 
