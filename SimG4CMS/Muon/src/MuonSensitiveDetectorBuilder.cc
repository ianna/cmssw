// -*- C++ -*-
//
// Package:     SimG4CMS/Muon
// Class  :     MuonSensitiveDetectorBuilder
//
// Implementation:
//     [Notes on implementation]
//
// Original Author:  Christopher Jones
//         Created:  Fri, 04 Jun 2021 18:18:17 GMT
//

// system include files

// user include files
#include "SimG4Core/SensitiveDetector/interface/SensitiveDetectorMakerBase.h"
#include "SimG4Core/Notification/interface/SimActivityRegistryEnroller.h"
#include "SimG4Core/SensitiveDetector/interface/SensitiveDetectorPluginFactory.h"

#include "Geometry/MuonNumbering/interface/MuonGeometryConstants.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"

#include "SimG4CMS/Muon/interface/MuonSensitiveDetector.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

class MuonSensitiveDetectorBuilder : public SensitiveDetectorMakerBase {
  SensitiveDetector* make(const std::string& iname,
                          const edm::EventSetup& es,
                          const SensitiveDetectorCatalog& clg,
                          const edm::ParameterSet& p,
                          const SimTrackManager* man,
                          SimActivityRegistry& reg) const override {
    edm::ESHandle<MuonOffsetMap> mom;
    es.get<IdealGeometryRecord>().get(mom);
    const MuonOffsetMap* offmap = (mom.isValid()) ? mom.product() : nullptr;
    edm::LogVerbatim("MuonSim") << "Finds the offset map at " << offmap;
    edm::ESHandle<MuonGeometryConstants> mdc;
    es.get<IdealGeometryRecord>().get(mdc);

    edm::ParameterSet m_MuonSD = p.getParameter<edm::ParameterSet>("MuonSD");
    auto ePersistentCutGeV =
        m_MuonSD.getParameter<double>("EnergyThresholdForPersistency") / CLHEP::GeV;  //Default 1. GeV
    auto allMuonsPersistent = m_MuonSD.getParameter<bool>("AllMuonsPersistent");
    auto printHits = m_MuonSD.getParameter<bool>("PrintHits");
    bool dd4hep = p.getParameter<bool>("g4GeometryDD4hepSource");
    //

    MuonSensitiveDetector* sd = new MuonSensitiveDetector(
        iname, offmap, *mdc, clg, ePersistentCutGeV, allMuonsPersistent, printHits, dd4hep, man);
    SimActivityRegistryEnroller::enroll(reg, sd);
    return sd;
  }
};

DEFINE_SENSITIVEDETECTORBUILDER(MuonSensitiveDetectorBuilder, MuonSensitiveDetector);
