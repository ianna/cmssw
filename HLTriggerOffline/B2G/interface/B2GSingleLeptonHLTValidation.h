// -*- C++ -*-
//
// Package:    HLTriggerOffline/B2G
// Class:      B2GSingleLeptonHLTValidation
//
/**\class B2GSingleLeptonHLTValidation B2GSingleLeptonHLTValidation.h
 HLTriggerOffline/B2G/interface/B2GSingleLeptonHLTValidation.h

 Description: compute efficiencies of trigger paths on offline reco selection
 with respect to pt and eta

 Implementation:
     harvesting
*/
//
// Original Author:  Elvire Bouvier
//         Created:  Thu, 16 Jan 2014 16:27:35 GMT
//
//
#ifndef B2GSINGLELEPTONHLTVALIDATION
#define B2GSINGLELEPTONHLTVALIDATION

// system include files
#include <memory>

// user include files
#include "DQMServices/Core/interface/DQMEDAnalyzer.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"

#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"

//
// class declaration
//

class B2GSingleLeptonHLTValidation : public DQMEDAnalyzer {
public:
  explicit B2GSingleLeptonHLTValidation(const edm::ParameterSet &);
  ~B2GSingleLeptonHLTValidation() override;

  static void fillDescriptions(edm::ConfigurationDescriptions &descriptions);

private:
  void analyze(const edm::Event &, const edm::EventSetup &) override;
  void bookHistograms(DQMStore::IBooker &, edm::Run const &,
                      edm::EventSetup const &) override;
  /// deduce monitorPath from label, the label is expected
  /// to be of type 'selectionPath:monitorPath'
  std::string monitorPath(const std::string &label) const {
    return label.substr(label.find(':') + 1);
  };
  /// set configurable labels for trigger monitoring histograms
  void triggerBinLabels(const std::vector<std::string> &labels);

  // ----------member data ---------------------------
  // DQM
  std::string sDir_;
  MonitorElement *hNumLeptonPt;
  MonitorElement *hDenLeptonPt;
  MonitorElement *hNumLeptonEta;
  MonitorElement *hDenLeptonEta;
  MonitorElement *hNumJetPt;
  MonitorElement *hDenJetPt;
  MonitorElement *hNumJetEta;
  MonitorElement *hDenJetEta;
  MonitorElement *hNumTriggerMon;
  MonitorElement *hDenTriggerMon;
  // Electrons
  edm::Ptr<reco::GsfElectron> elec_;
  std::string sElectrons_;
  edm::EDGetTokenT<edm::View<reco::GsfElectron>> tokElectrons_;
  double ptElectrons_;
  double etaElectrons_;
  double isoElectrons_;
  unsigned int minElectrons_;
  // Muons
  edm::Ptr<reco::Muon> mu_;
  std::string sMuons_;
  edm::EDGetTokenT<edm::View<reco::Muon>> tokMuons_;
  double ptMuons_;
  double etaMuons_;
  double isoMuons_;
  unsigned int minMuons_;
  // Jets
  edm::Ptr<reco::Jet> jet_;
  std::string sJets_;
  edm::EDGetTokenT<edm::View<reco::Jet>> tokJets_;
  double ptJets_;
  double ptJets0_;
  double ptJets1_;
  double etaJets_;
  unsigned int minJets_;
  // Trigger
  std::string sTrigger_;
  edm::EDGetTokenT<edm::TriggerResults> tokTrigger_;
  std::vector<std::string> vsPaths_;
  // Flags
  bool isAll_ = false;
  bool isSel_ = false;
};

inline void B2GSingleLeptonHLTValidation::triggerBinLabels(
    const std::vector<std::string> &labels) {
  for (unsigned int idx = 0; idx < labels.size(); ++idx) {
    hNumTriggerMon->setBinLabel(idx + 1, "[" + monitorPath(labels[idx]) + "]",
                                1);
    hDenTriggerMon->setBinLabel(idx + 1, "[" + monitorPath(labels[idx]) + "]",
                                1);
  }
}

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
B2GSingleLeptonHLTValidation::B2GSingleLeptonHLTValidation(
    const edm::ParameterSet &iConfig)
    : sDir_(iConfig.getUntrackedParameter<std::string>(
          "sDir", "HLTValidation/B2G/Efficiencies/")),
      sElectrons_(iConfig.getUntrackedParameter<std::string>("sElectrons",
                                                             "gsfElectrons")),
      ptElectrons_(iConfig.getUntrackedParameter<double>("ptElectrons", 0.)),
      etaElectrons_(iConfig.getUntrackedParameter<double>("etaElectrons", 0.)),
      isoElectrons_(iConfig.getUntrackedParameter<double>("isoElectrons", 0.)),
      minElectrons_(
          iConfig.getUntrackedParameter<unsigned int>("minElectrons", 0)),
      sMuons_(iConfig.getUntrackedParameter<std::string>("sMuons", "muons")),
      ptMuons_(iConfig.getUntrackedParameter<double>("ptMuons", 0.)),
      etaMuons_(iConfig.getUntrackedParameter<double>("etaMuons", 0.)),
      isoMuons_(iConfig.getUntrackedParameter<double>("isoMuons", 0.)),
      minMuons_(iConfig.getUntrackedParameter<unsigned int>("minMuons", 0)),
      sJets_(iConfig.getUntrackedParameter<std::string>("sJets", "ak5PFJets")),
      ptJets_(iConfig.getUntrackedParameter<double>("ptJets", 0.)),
      ptJets0_(iConfig.getUntrackedParameter<double>("ptJets0", 0.)),
      ptJets1_(iConfig.getUntrackedParameter<double>("ptJets1", 0.)),
      etaJets_(iConfig.getUntrackedParameter<double>("etaJets", 0.)),
      minJets_(iConfig.getUntrackedParameter<unsigned int>("minJets", 0)),
      sTrigger_(iConfig.getUntrackedParameter<std::string>("sTrigger",
                                                           "TriggerResults")),
      vsPaths_(
          iConfig.getUntrackedParameter<std::vector<std::string>>("vsPaths"))

{
  // Electrons
  tokElectrons_ =
      consumes<edm::View<reco::GsfElectron>>(edm::InputTag(sElectrons_));
  // Muons
  tokMuons_ = consumes<edm::View<reco::Muon>>(edm::InputTag(sMuons_));
  // Jets
  tokJets_ = consumes<edm::View<reco::Jet>>(edm::InputTag(sJets_));
  // Trigger
  tokTrigger_ =
      consumes<edm::TriggerResults>(edm::InputTag(sTrigger_, "", "HLT"));
}

B2GSingleLeptonHLTValidation::~B2GSingleLeptonHLTValidation() {

  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
}
#endif

// define this as a plug-in
DEFINE_FWK_MODULE(B2GSingleLeptonHLTValidation);
