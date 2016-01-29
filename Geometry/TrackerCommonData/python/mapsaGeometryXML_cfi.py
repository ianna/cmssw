import FWCore.ParameterSet.Config as cms

# CRack geometry
XMLIdealGeometryESSource = cms.ESSource("XMLIdealGeometryESSource",
  geomXMLFiles = cms.vstring(
    'Geometry/CMSCommonData/data/materials.xml',
    'Geometry/TrackerCommonData/data/PhaseII/trackerParameters.xml',
    'Geometry/CMSCommonData/data/rotations.xml',
    'Geometry/TrackerCommonData/data/MaPSA/cms.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsa.xml',
    'Geometry/TrackerCommonData/data/MaPSA/tracker.xml',
    'Geometry/TrackerCommonData/data/MaPSA/trackerStructureTopology.xml',
    'Geometry/TrackerCommonData/data/MaPSA/trackersens.xml',
    'Geometry/TrackerCommonData/data/MaPSA/trackerRecoMaterial.xml',
    'Geometry/TrackerCommonData/data/MaPSA/trackerProdCuts.xml'
  ),
  rootNodeName = cms.string('tracker:Tracker')
)

