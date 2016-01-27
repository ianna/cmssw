import FWCore.ParameterSet.Config as cms

# CRack geometry
XMLIdealGeometryESSource = cms.ESSource("XMLIdealGeometryESSource",
  geomXMLFiles = cms.vstring(
    'Geometry/CMSCommonData/data/materials.xml',
    'Geometry/TrackerCommonData/data/trackermaterial.xml',
    'Geometry/TrackerCommonData/data/PhaseII/trackerParameters.xml',
    'Geometry/CMSCommonData/data/rotations.xml',
    'Geometry/TrackerCommonData/data/MaPSA/cms.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsa.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsamodpar.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsamodule2.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsamaterial.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod_SS4H.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod2h.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod2c.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod_SS4L.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod2l.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod_DSH_L2.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod1h.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod0c.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsamodule0.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod_SS6L.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod4l.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod4c.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsamodule4.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod_SS6H.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod4h.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod_DSL_L2.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarod1l.xml',
    'Geometry/TrackerCommonData/data/MaPSA/mapsarodpar.xml',
    'Geometry/TrackerCommonData/data/MaPSA/tracker.xml',
    'Geometry/TrackerCommonData/data/MaPSA/trackerStructureTopology.xml',
    'Geometry/TrackerCommonData/data/MaPSA/trackersens_2DS_5SS6_5SS4.xml',
    'Geometry/TrackerCommonData/data/MaPSA/trackerRecoMaterial_2DS_5SS6_5SS4.xml',
    'Geometry/TrackerCommonData/data/MaPSA/trackerProdCuts_2DS_5SS6_5SS4.xml'
  ),
  rootNodeName = cms.string('cms:OCMS')
)

