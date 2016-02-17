import FWCore.ParameterSet.Config as cms

process = cms.Process("PRODSIMNEW")

process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Geometry.TrackerCommonData.mapsaGeometryXML_cfi')
process.load('Geometry.TrackerNumberingBuilder.trackerNumberingGeometry_cfi')
process.load('Geometry.TrackerNumberingBuilder.trackerTopology_cfi')
process.load('Geometry.TrackerGeometryBuilder.trackerParameters_cfi')

process.MessageLogger.destinations = cms.untracked.vstring("MaPSATestBeam.txt")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)
process.load('SimGeneral.HepPDTESSource.pdt_cfi')
process.load('IOMC.EventVertexGenerators.VtxSmearedFlat_cfi')
process.load('GeneratorInterface.Core.generatorSmeared_cfi')

process.source = cms.Source("EmptySource")

process.generator = cms.EDProducer("FlatRandomPtGunProducer",
    PGunParameters = cms.PSet(
        PartID = cms.vint32(13),
        MinEta = cms.double(-0.1),
        MaxEta = cms.double(0.1),
        MinPhi = cms.double(-3.14159265359),
        MaxPhi = cms.double(3.14159265359),
        MinPt  = cms.double(9.99),
        MaxPt  = cms.double(10.01)
    ),
    AddAntiParticle = cms.bool(False),
    Verbosity       = cms.untracked.int32(0),
    firstRun        = cms.untracked.uint32(1)
)

process.EnableFloatingPointExceptions = cms.Service("EnableFloatingPointExceptions")

process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
    generator = cms.PSet(
         initialSeed = cms.untracked.uint32(123456789),
         engineName = cms.untracked.string('HepJamesRandom')
    ),
    VtxSmeared = cms.PSet(
        engineName = cms.untracked.string('HepJamesRandom'),
        initialSeed = cms.untracked.uint32(98765432)
    ),
    g4SimHits = cms.PSet(
         initialSeed = cms.untracked.uint32(11),
         engineName = cms.untracked.string('HepJamesRandom')
    )
)

process.load("SimG4Core.Application.g4SimHits_cfi")

process.g4SimHits.Physics.type            = 'SimG4Core/Physics/DummyPhysics'
process.g4SimHits.UseMagneticField        = False
process.g4SimHits.Physics.DummyEMPhysics  = True
process.g4SimHits.Physics.DefaultCutValue = 10. 
process.g4SimHits.Watchers = cms.VPSet(cms.PSet(
	Name           = cms.untracked.string('OTPhase2Barrel'),
	type           = cms.string('PrintMaterialBudgetInfo')))

# Output definition

process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('file:step1.root'),
    outputCommands = cms.untracked.vstring('drop *_*_*_*', 
                                           'keep *_*_TrackerHitsPixel*_PRODSIMNEW',
                                           'keep SimTracks_*_*_PRODSIMNEW')
)

process.RAWSIMoutput_step = cms.EndPath(process.RAWSIMoutput)

process.p1 = cms.Path(process.generator*process.VtxSmeared*process.generatorSmeared*process.g4SimHits)
