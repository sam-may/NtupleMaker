# NtupleMaker
This is a fork from cms-tas/NtupleMaker that includes a modified main_pset.py which allows for easily making CMS4 with or without pf candidates.

### Installing
1. `curl https://raw.githubusercontent.com/sam-may/NtupleMaker/master/install.sh > install.sh`.
2. `source install.sh` will check out the CMSSW release and NtupleMaker repository, and build everything.

### Running
1. `cd CMSSW_9_2_8` (you'll already be there if it's the first time installing).
2. `source /code/osgcode/cmssoft/cmsset_default.sh > /dev/null 2>&1`
3. `export SCRAM_ARCH=slc6_amd64_gcc530`
4. `cmsenv`
5. `cd src/CMS3/NtupleMaker/test/`
6. To make a CMS4 ntuple with pfcands: `cmsRun main_pset.py pfcands=True &> cmsdumpYesCands.outerr`
7. To make a CMS4 ntuple without pfcands: `cmsRun main_pset.py pfcands=False &> cmsdumpNoCands.outerr`

### Notes
1. You might want to modify some of the lines in the last block of code in main_pset.py:
```
process.GlobalTag.globaltag = "92X_dataRun2_Prompt_v8"
if opts.pfcands:
  process.out.fileName = cms.untracked.string('ntuple_YesPfCands.root')
else:
  process.out.fileName = cms.untracked.string('ntuple_NoPfCands.root')
process.source.fileNames = cms.untracked.vstring("file:/hadoop/cms/phedex/store/data/Run2017C/DoubleMuon/MINIAOD/PromptReco-v3/000/300/742/00000/2AC36403-8E7E-E711-A599-02163E01366D.root")
# process.eventMaker.CMS3tag = cms.string('V08-00-18')
# process.eventMaker.datasetName = cms.string('/DoubleEG/Run2016C-03Feb2017-v1/MINIAOD')
process.maxEvents.input = cms.untracked.int32(1000)
```
  * To run a small test with only a few events, change `process.maxEvents.input = cms.untracked.int32(-1)` from `-1` to desired number of events.
  * To run on a different file, select a name from: `http://uaf-10.t2.ucsd.edu/~namin/makers/disMaker/?query=%2FDoubleMuon%2FRun2017C-PromptReco-v3%2FMINIAOD&type=files&short=short` and replace the end of the string (leave `file:/hadoop/cms/phedex/` the same) in `process.source.fileNames` 
