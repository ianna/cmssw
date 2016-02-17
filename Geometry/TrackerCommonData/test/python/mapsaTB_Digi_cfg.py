import FWCore.ParameterSet.Config as cms

process = cms.Process("PRODMIXNEW")
process.load('Configuration.StandardSequences.MagneticField_0T_cff')
process.load('SimGeneral.HepPDTESSource.pdt_cfi')

process.load('Geometry.TrackerCommonData.mapsaGeometryXML_cfi')
process.load('Geometry.TrackerNumberingBuilder.trackerNumberingGeometry_cfi')
process.load('Geometry.TrackerNumberingBuilder.trackerTopology_cfi')
process.load('Geometry.TrackerGeometryBuilder.trackerParameters_cfi')
process.load('Geometry.TrackerGeometryBuilder.trackerGeometry_cfi')
process.trackerGeometry.applyAlignment = cms.bool(False)

# Tracker
process.load("RecoTracker.GeometryESProducer.TrackerRecoGeometryESProducer_cfi")

# Alignment
process.load("Geometry.TrackerGeometryBuilder.idealForDigiTrackerGeometry_cff")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:step1.root')
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

process.mix = cms.EDProducer("MixingModule",
    LabelPlayback = cms.string(''),
    bunchspace = cms.int32(450),
    digitizers = cms.PSet(
        pixel = cms.PSet(
            AdcFullScale = cms.int32(255),
            AdcFullScaleStack = cms.int32(255),
            AddNoise = cms.bool(True),
            AddNoisyPixels = cms.bool(True),
            AddPixelInefficiency = cms.bool(False),
            AddThresholdSmearing = cms.bool(True),
            Alpha2Order = cms.bool(True),
            BPix_SignalResponse_p0 = cms.double(0.0035),
            BPix_SignalResponse_p1 = cms.double(1.23),
            BPix_SignalResponse_p2 = cms.double(97.4),
            BPix_SignalResponse_p3 = cms.double(126.5),
            ChargeVCALSmearing = cms.bool(True),
            DeadModules = cms.VPSet(),
            ## Set Dead modules here, for example:
            ##     cms.PSet(
            ##         Dead_detID = cms.int32(302055940),
            ##         Module = cms.string('tbmB')
            ##         ), 
            ##     cms.PSet(
            ##         Dead_detID = cms.int32(302059800),
            ##         Module = cms.string('whole')
            ##     )
            ##   ),
            DeadModules_DB = cms.bool(False),
            DoPixelAging = cms.bool(False),
            ElectronPerAdc = cms.double(135.0),
            ElectronsPerVcal = cms.double(65.5),
            ElectronsPerVcal_Offset = cms.double(-414.0),
            FPix_SignalResponse_p0 = cms.double(0.0043),
            FPix_SignalResponse_p1 = cms.double(1.31),
            FPix_SignalResponse_p2 = cms.double(93.6),
            FPix_SignalResponse_p3 = cms.double(134.6),
            FirstStackLayer = cms.int32(5),
            GainSmearing = cms.double(0.0),
            LorentzAngle_DB = cms.bool(False),
            MissCalibrate = cms.bool(True),
            NoiseInElectrons = cms.double(175.0),
            NumPixelBarrel = cms.int32(3),
            NumPixelEndcap = cms.int32(2),
            OffsetSmearing = cms.double(0.0),
            PixGeometryType = cms.string('idealForDigi'),
            ReadoutNoiseInElec = cms.double(350.0),
            RoutList = cms.vstring('TrackerHitsPixelBarrelLowTof', 
                                   'TrackerHitsPixelBarrelHighTof', 
                                   'TrackerHitsPixelEndcapLowTof', 
                                   'TrackerHitsPixelEndcapHighTof'),
            TanLorentzAnglePerTesla_BPix = cms.double(0.106),
            TanLorentzAnglePerTesla_FPix = cms.double(0.106),
            ThresholdInElectrons_BPix = cms.double(3500.0),
            ThresholdInElectrons_BPix_L1 = cms.double(3500.0),
            ThresholdInElectrons_FPix = cms.double(3000.0),
            ThresholdSmearing_BPix = cms.double(245.0),
            ThresholdSmearing_BPix_L1 = cms.double(245.0),
            ThresholdSmearing_FPix = cms.double(210.0),
            TofLowerCut = cms.double(-12.5),
            TofUpperCut = cms.double(12.5),
            accumulatorType = cms.string('SiPSMacroDigitizer'),
            deltaProductionCut = cms.double(0.03),
            hitsProducer = cms.string('g4SimHits'),
            killModules = cms.bool(True),
            makeDigiSimLinks = cms.untracked.bool(True),
            useDB = cms.bool(False)
        )
    ),
    maxBunch = cms.int32(3),
    minBunch = cms.int32(-5),
    mixObjects = cms.PSet(),
    mixProdStep1 = cms.bool(False),
    mixProdStep2 = cms.bool(False),
    playback = cms.untracked.bool(False),
    useCurrentProcessOnly = cms.bool(False)
)

process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('file:step2.root'),
    outputCommands = cms.untracked.vstring('drop *_*_*_*',
                                           'keep *_*_TrackerHitsPixel*_PRODSIMNEW',
                                           'keep SimTracks_*_*_PRODSIMNEW',
                                           'keep *_*_*_PRODMIXNEW')
)

process.p = cms.Path(process.mix)

process.outpath = cms.EndPath(process.out)

process.MessageLogger = cms.Service("MessageLogger",
    categories = cms.untracked.vstring('MixingModule'),
    cout = cms.untracked.PSet(
        DEBUG = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        ),
        MixingModule = cms.untracked.PSet(
            limit = cms.untracked.int32(1000000)
        ),
        threshold = cms.untracked.string('DEBUG')
    ),
    debugModules = cms.untracked.vstring('mix'),
    destinations = cms.untracked.vstring('cout')
)

process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
                                                   mix = cms.PSet(
        initialSeed = cms.untracked.uint32(98765432),
        engineName = cms.untracked.string('TRandom3')
        ))

process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
    ignoreTotal = cms.untracked.int32(1),
    oncePerEventMode = cms.untracked.bool(True)
)
