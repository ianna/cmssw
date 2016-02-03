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
from RecoTracker.GeometryESProducer.TrackerRecoGeometryESProducer_cfi import *

# Alignment
from Geometry.TrackerGeometryBuilder.idealForDigiTrackerGeometry_cff import *

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:step1.root')
)
process.SiPixelSimBlock = cms.PSet(
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
    DeadModules = cms.VPSet(cms.PSet(
        Dead_detID = cms.int32(302055940),
        Module = cms.string('tbmB')
    ), 
        cms.PSet(
            Dead_detID = cms.int32(302059800),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302121992),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302123296),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302125060),
            Module = cms.string('tbmA')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302125076),
            Module = cms.string('tbmA')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302126364),
            Module = cms.string('tbmB')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302126596),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302127136),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302188552),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302188824),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302194200),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302195232),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302197252),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302197784),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352453892),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352453896),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352453900),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352453904),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454916),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454920),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454924),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454928),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455940),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455944),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455948),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455952),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454148),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454152),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454156),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455172),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455176),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455180),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352456196),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352456200),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352456204),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(343999748),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(343999752),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(343999756),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(343999760),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344014340),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344014344),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344014348),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344019460),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344019464),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344019468),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344077572),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344077576),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344077580),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344077584),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078596),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078600),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078604),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078608),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344079620),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344079624),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344079628),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344079632),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078852),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078856),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078860),
            Module = cms.string('whole')
        )),
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
    deltaProductionCut = cms.double(0.03),
    killModules = cms.bool(True),
    useDB = cms.bool(False)
)

process.apd_sim_parameters = cms.PSet(
    apdAddToBarrel = cms.bool(False),
    apdDigiTag = cms.string('APD'),
    apdDoPEStats = cms.bool(True),
    apdNonlParms = cms.vdouble(1.48, -3.75, 1.81, 1.26, 2.0, 
        45, 1.0),
    apdSeparateDigi = cms.bool(True),
    apdShapeTau = cms.double(40.5),
    apdShapeTstart = cms.double(74.5),
    apdSimToPEHigh = cms.double(88200000.0),
    apdSimToPELow = cms.double(2450000.0),
    apdTimeOffWidth = cms.double(0.8),
    apdTimeOffset = cms.double(-13.5)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(2)
)

process.pixelDigitizer = cms.PSet(
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
    DeadModules = cms.VPSet(cms.PSet(
        Dead_detID = cms.int32(302055940),
        Module = cms.string('tbmB')
    ), 
        cms.PSet(
            Dead_detID = cms.int32(302059800),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302121992),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302123296),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302125060),
            Module = cms.string('tbmA')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302125076),
            Module = cms.string('tbmA')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302126364),
            Module = cms.string('tbmB')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302126596),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302127136),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302188552),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302188824),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302194200),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302195232),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302197252),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(302197784),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352453892),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352453896),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352453900),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352453904),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454916),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454920),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454924),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454928),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455940),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455944),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455948),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455952),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454148),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454152),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352454156),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455172),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455176),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352455180),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352456196),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352456200),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(352456204),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(343999748),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(343999752),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(343999756),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(343999760),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344014340),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344014344),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344014348),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344019460),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344019464),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344019468),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344077572),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344077576),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344077580),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344077584),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078596),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078600),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078604),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078608),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344079620),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344079624),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344079628),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344079632),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078852),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078856),
            Module = cms.string('whole')
        ), 
        cms.PSet(
            Dead_detID = cms.int32(344078860),
            Module = cms.string('whole')
        )),
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

process.recoTrackAccumulator = cms.PSet(
    accumulatorType = cms.string('RecoTrackAccumulator'),
    makeDigiSimLinks = cms.untracked.bool(False),
    outputLabel = cms.string('generalTracks'),
    pileUpTracks = cms.InputTag("generalTracksBeforeMixing"),
    signalTracks = cms.InputTag("generalTracksBeforeMixing")
)

process.theDigitizers = cms.PSet(
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
        DeadModules = cms.VPSet(cms.PSet(
            Dead_detID = cms.int32(302055940),
            Module = cms.string('tbmB')
        ), 
            cms.PSet(
                Dead_detID = cms.int32(302059800),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302121992),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302123296),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302125060),
                Module = cms.string('tbmA')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302125076),
                Module = cms.string('tbmA')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302126364),
                Module = cms.string('tbmB')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302126596),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302127136),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302188552),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302188824),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302194200),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302195232),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302197252),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302197784),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352453892),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352453896),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352453900),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352453904),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454916),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454920),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454924),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454928),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455940),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455944),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455948),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455952),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454148),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454152),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454156),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455172),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455176),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455180),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352456196),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352456200),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352456204),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(343999748),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(343999752),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(343999756),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(343999760),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344014340),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344014344),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344014348),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344019460),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344019464),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344019468),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344077572),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344077576),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344077580),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344077584),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078596),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078600),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078604),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078608),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344079620),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344079624),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344079628),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344079632),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078852),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078856),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078860),
                Module = cms.string('whole')
            )),
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
    ),
    puVtx = cms.PSet(
        accumulatorType = cms.string('PileupVertexAccumulator'),
        hitsProducer = cms.string('generator'),
        makeDigiSimLinks = cms.untracked.bool(False),
        vtxFallbackTag = cms.InputTag("generator"),
        vtxTag = cms.InputTag("generatorSmeared")
    )
)

process.theDigitizersValid = cms.PSet(
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
        DeadModules = cms.VPSet(cms.PSet(
            Dead_detID = cms.int32(302055940),
            Module = cms.string('tbmB')
        ), 
            cms.PSet(
                Dead_detID = cms.int32(302059800),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302121992),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302123296),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302125060),
                Module = cms.string('tbmA')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302125076),
                Module = cms.string('tbmA')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302126364),
                Module = cms.string('tbmB')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302126596),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302127136),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302188552),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302188824),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302194200),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302195232),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302197252),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(302197784),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352453892),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352453896),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352453900),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352453904),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454916),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454920),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454924),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454928),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455940),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455944),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455948),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455952),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454148),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454152),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352454156),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455172),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455176),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352455180),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352456196),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352456200),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(352456204),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(343999748),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(343999752),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(343999756),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(343999760),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344014340),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344014344),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344014348),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344019460),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344019464),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344019468),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344077572),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344077576),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344077580),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344077584),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078596),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078600),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078604),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078608),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344079620),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344079624),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344079628),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344079632),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078852),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078856),
                Module = cms.string('whole')
            ), 
            cms.PSet(
                Dead_detID = cms.int32(344078860),
                Module = cms.string('whole')
            )),
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
)

process.theMixObjects = cms.PSet(
    mixCH = cms.PSet(
        crossingFrames = cms.untracked.vstring(),
        input = cms.VInputTag(cms.InputTag("g4SimHits","CastorFI"), cms.InputTag("g4SimHits","EcalHitsEB"), cms.InputTag("g4SimHits","EcalHitsEE"), cms.InputTag("g4SimHits","EcalHitsES"), cms.InputTag("g4SimHits","HcalHits"), 
            cms.InputTag("g4SimHits","ZDCHITS")),
        subdets = cms.vstring('CastorFI', 
            'EcalHitsEB', 
            'EcalHitsEE', 
            'EcalHitsES', 
            'HcalHits', 
            'ZDCHITS'),
        type = cms.string('PCaloHit')
    ),
    mixHepMC = cms.PSet(
        input = cms.VInputTag(cms.InputTag("generatorSmeared"), cms.InputTag("generator")),
        makeCrossingFrame = cms.untracked.bool(False),
        type = cms.string('HepMCProduct')
    ),
    mixSH = cms.PSet(
        crossingFrames = cms.untracked.vstring('MuonCSCHits', 
            'MuonDTHits', 
            'MuonRPCHits'),
        input = cms.VInputTag(cms.InputTag("g4SimHits","MuonCSCHits"), cms.InputTag("g4SimHits","MuonDTHits"), cms.InputTag("g4SimHits","MuonRPCHits"), cms.InputTag("g4SimHits","TrackerHitsPixelBarrelHighTof"), cms.InputTag("g4SimHits","TrackerHitsPixelBarrelLowTof"), 
            cms.InputTag("g4SimHits","TrackerHitsPixelEndcapHighTof"), cms.InputTag("g4SimHits","TrackerHitsPixelEndcapLowTof"), cms.InputTag("g4SimHits","TrackerHitsTECHighTof"), cms.InputTag("g4SimHits","TrackerHitsTECLowTof"), cms.InputTag("g4SimHits","TrackerHitsTIBHighTof"), 
            cms.InputTag("g4SimHits","TrackerHitsTIBLowTof"), cms.InputTag("g4SimHits","TrackerHitsTIDHighTof"), cms.InputTag("g4SimHits","TrackerHitsTIDLowTof"), cms.InputTag("g4SimHits","TrackerHitsTOBHighTof"), cms.InputTag("g4SimHits","TrackerHitsTOBLowTof")),
        subdets = cms.vstring('MuonCSCHits', 
            'MuonDTHits', 
            'MuonRPCHits', 
            'TrackerHitsPixelBarrelHighTof', 
            'TrackerHitsPixelBarrelLowTof', 
            'TrackerHitsPixelEndcapHighTof', 
            'TrackerHitsPixelEndcapLowTof', 
            'TrackerHitsTECHighTof', 
            'TrackerHitsTECLowTof', 
            'TrackerHitsTIBHighTof', 
            'TrackerHitsTIBLowTof', 
            'TrackerHitsTIDHighTof', 
            'TrackerHitsTIDLowTof', 
            'TrackerHitsTOBHighTof', 
            'TrackerHitsTOBLowTof'),
        type = cms.string('PSimHit')
    ),
    mixTracks = cms.PSet(
        input = cms.VInputTag(cms.InputTag("g4SimHits")),
        makeCrossingFrame = cms.untracked.bool(False),
        type = cms.string('SimTrack')
    ),
    mixVertices = cms.PSet(
        input = cms.VInputTag(cms.InputTag("g4SimHits")),
        makeCrossingFrame = cms.untracked.bool(False),
        type = cms.string('SimVertex')
    )
)

process.trackingParticles = cms.PSet(
    HepMCProductLabel = cms.InputTag("generatorSmeared"),
    accumulatorType = cms.string('TrackingTruthAccumulator'),
    allowDifferentSimHitProcesses = cms.bool(False),
    alwaysAddAncestors = cms.bool(True),
    createInitialVertexCollection = cms.bool(False),
    createMergedBremsstrahlung = cms.bool(True),
    createUnmergedCollection = cms.bool(True),
    genParticleCollection = cms.InputTag("genParticles"),
    ignoreTracksOutsideVolume = cms.bool(False),
    maximumPreviousBunchCrossing = cms.uint32(9999),
    maximumSubsequentBunchCrossing = cms.uint32(9999),
    removeDeadModules = cms.bool(False),
    select = cms.PSet(
        chargedOnlyTP = cms.bool(True),
        intimeOnlyTP = cms.bool(False),
        lipTP = cms.double(1000),
        maxRapidityTP = cms.double(5.0),
        minHitTP = cms.int32(0),
        minRapidityTP = cms.double(-5.0),
        pdgIdTP = cms.vint32(),
        ptMinTP = cms.double(0.1),
        signalOnlyTP = cms.bool(False),
        stableOnlyTP = cms.bool(False),
        tipTP = cms.double(1000)
    ),
    simHitCollections = cms.PSet(
        muon = cms.VInputTag(cms.InputTag("g4SimHits","MuonDTHits"), cms.InputTag("g4SimHits","MuonCSCHits"), cms.InputTag("g4SimHits","MuonRPCHits")),
        pixel = cms.VInputTag(cms.InputTag("g4SimHits","TrackerHitsPixelBarrelLowTof"), cms.InputTag("g4SimHits","TrackerHitsPixelBarrelHighTof"), cms.InputTag("g4SimHits","TrackerHitsPixelEndcapLowTof"), cms.InputTag("g4SimHits","TrackerHitsPixelEndcapHighTof")),
        tracker = cms.VInputTag(cms.InputTag("g4SimHits","TrackerHitsTIBLowTof"), cms.InputTag("g4SimHits","TrackerHitsTIBHighTof"), cms.InputTag("g4SimHits","TrackerHitsTIDLowTof"), cms.InputTag("g4SimHits","TrackerHitsTIDHighTof"), cms.InputTag("g4SimHits","TrackerHitsTOBLowTof"), 
            cms.InputTag("g4SimHits","TrackerHitsTOBHighTof"), cms.InputTag("g4SimHits","TrackerHitsTECLowTof"), cms.InputTag("g4SimHits","TrackerHitsTECHighTof"))
    ),
    simTrackCollection = cms.InputTag("g4SimHits"),
    simVertexCollection = cms.InputTag("g4SimHits"),
    vertexDistanceCut = cms.double(0.003),
    volumeRadius = cms.double(120.0),
    volumeZ = cms.double(300.0)
)

process.trackingParticlesSelection = cms.PSet(
    chargedOnlyTP = cms.bool(True),
    intimeOnlyTP = cms.bool(False),
    lipTP = cms.double(1000),
    maxRapidityTP = cms.double(5.0),
    minHitTP = cms.int32(0),
    minRapidityTP = cms.double(-5.0),
    pdgIdTP = cms.vint32(),
    ptMinTP = cms.double(0.1),
    signalOnlyTP = cms.bool(False),
    stableOnlyTP = cms.bool(False),
    tipTP = cms.double(1000)
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
            DeadModules = cms.VPSet(cms.PSet(
                Dead_detID = cms.int32(302055940),
                Module = cms.string('tbmB')
            ), 
                cms.PSet(
                    Dead_detID = cms.int32(302059800),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302121992),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302123296),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302125060),
                    Module = cms.string('tbmA')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302125076),
                    Module = cms.string('tbmA')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302126364),
                    Module = cms.string('tbmB')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302126596),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302127136),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302188552),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302188824),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302194200),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302195232),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302197252),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(302197784),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352453892),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352453896),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352453900),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352453904),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352454916),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352454920),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352454924),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352454928),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352455940),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352455944),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352455948),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352455952),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352454148),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352454152),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352454156),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352455172),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352455176),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352455180),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352456196),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352456200),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(352456204),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(343999748),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(343999752),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(343999756),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(343999760),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344014340),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344014344),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344014348),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344019460),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344019464),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344019468),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344077572),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344077576),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344077580),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344077584),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344078596),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344078600),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344078604),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344078608),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344079620),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344079624),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344079628),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344079632),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344078852),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344078856),
                    Module = cms.string('whole')
                ), 
                cms.PSet(
                    Dead_detID = cms.int32(344078860),
                    Module = cms.string('whole')
                )),
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
    mixObjects = cms.PSet(
        mixCH = cms.PSet(
            crossingFrames = cms.untracked.vstring(),
            input = cms.VInputTag(cms.InputTag("g4SimHits","CastorFI"), cms.InputTag("g4SimHits","EcalHitsEB"), cms.InputTag("g4SimHits","EcalHitsEE"), cms.InputTag("g4SimHits","EcalHitsES"), cms.InputTag("g4SimHits","HcalHits"), 
                cms.InputTag("g4SimHits","ZDCHITS")),
            subdets = cms.vstring('CastorFI', 
                'EcalHitsEB', 
                'EcalHitsEE', 
                'EcalHitsES', 
                'HcalHits', 
                'ZDCHITS'),
            type = cms.string('PCaloHit')
        ),
        mixHepMC = cms.PSet(
            input = cms.VInputTag(cms.InputTag("generatorSmeared"), cms.InputTag("generator")),
            makeCrossingFrame = cms.untracked.bool(False),
            type = cms.string('HepMCProduct')
        ),
        mixSH = cms.PSet(
            crossingFrames = cms.untracked.vstring('MuonCSCHits', 
                'MuonDTHits', 
                'MuonRPCHits'),
            input = cms.VInputTag(cms.InputTag("g4SimHits","MuonCSCHits"), cms.InputTag("g4SimHits","MuonDTHits"), cms.InputTag("g4SimHits","MuonRPCHits"), cms.InputTag("g4SimHits","TrackerHitsPixelBarrelHighTof"), cms.InputTag("g4SimHits","TrackerHitsPixelBarrelLowTof"), 
                cms.InputTag("g4SimHits","TrackerHitsPixelEndcapHighTof"), cms.InputTag("g4SimHits","TrackerHitsPixelEndcapLowTof"), cms.InputTag("g4SimHits","TrackerHitsTECHighTof"), cms.InputTag("g4SimHits","TrackerHitsTECLowTof"), cms.InputTag("g4SimHits","TrackerHitsTIBHighTof"), 
                cms.InputTag("g4SimHits","TrackerHitsTIBLowTof"), cms.InputTag("g4SimHits","TrackerHitsTIDHighTof"), cms.InputTag("g4SimHits","TrackerHitsTIDLowTof"), cms.InputTag("g4SimHits","TrackerHitsTOBHighTof"), cms.InputTag("g4SimHits","TrackerHitsTOBLowTof")),
            subdets = cms.vstring('MuonCSCHits', 
                'MuonDTHits', 
                'MuonRPCHits', 
                'TrackerHitsPixelBarrelHighTof', 
                'TrackerHitsPixelBarrelLowTof', 
                'TrackerHitsPixelEndcapHighTof', 
                'TrackerHitsPixelEndcapLowTof', 
                'TrackerHitsTECHighTof', 
                'TrackerHitsTECLowTof', 
                'TrackerHitsTIBHighTof', 
                'TrackerHitsTIBLowTof', 
                'TrackerHitsTIDHighTof', 
                'TrackerHitsTIDLowTof', 
                'TrackerHitsTOBHighTof', 
                'TrackerHitsTOBLowTof'),
            type = cms.string('PSimHit')
        ),
        mixTracks = cms.PSet(
            input = cms.VInputTag(cms.InputTag("g4SimHits")),
            makeCrossingFrame = cms.untracked.bool(False),
            type = cms.string('SimTrack')
        ),
        mixVertices = cms.PSet(
            input = cms.VInputTag(cms.InputTag("g4SimHits")),
            makeCrossingFrame = cms.untracked.bool(False),
            type = cms.string('SimVertex')
        )
    ),
    mixProdStep1 = cms.bool(False),
    mixProdStep2 = cms.bool(False),
    playback = cms.untracked.bool(False),
    useCurrentProcessOnly = cms.bool(False)
)


process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('file:step2.root'),
    outputCommands = cms.untracked.vstring('drop *_*_*_*', 
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

