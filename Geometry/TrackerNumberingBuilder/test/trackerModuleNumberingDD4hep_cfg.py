import FWCore.ParameterSet.Config as cms
from Configuration.Eras.Era_Run3_dd4hep_cff import Run3_dd4hep
 
process = cms.Process('NumberingTest',Run3_dd4hep)

process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load('Configuration.Geometry.GeometryDD4hepExtended2021Reco_cff')

if 'MessageLogger' in process.__dict__:
    process.MessageLogger.categories.append('TrackerGeometryBuilder')
    
process.source = cms.Source("EmptySource")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

process.prod = cms.EDAnalyzer("ModuleNumbering")

process.Timing = cms.Service("Timing")
process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck")

process.p1 = cms.Path(process.prod)


