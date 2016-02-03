#include <memory>
#include <set>

#include "SiPSMacroDigitizerAlgorithm.h"

#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/SiPixelDigi/interface/PixelDigi.h"
#include "SimDataFormats/TrackerDigiSimLink/interface/PixelDigiSimLink.h"
#include "DataFormats/Common/interface/DetSet.h"
#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/SiPixelDigi/interface/PixelDigi.h"
#include "DataFormats/SiPixelDigi/interface/PixelDigiCollection.h"
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/GeometryVector/interface/LocalVector.h"
#include "Geometry/CommonDetUnit/interface/GeomDetUnit.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetUnit.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"

#include "Geometry/CommonTopologies/interface/PixelTopology.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetType.h"

#include "DataFormats/TrackerCommon/interface/TrackerTopology.h"
// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "MagneticField/Engine/interface/MagneticField.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "SimGeneral/MixingModule/interface/PileUpEventPrincipal.h"

//Random Number
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Utilities/interface/RandomNumberGenerator.h"
#include "FWCore/Utilities/interface/StreamID.h"
#include "FWCore/Utilities/interface/Exception.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "SimGeneral/MixingModule/interface/DigiAccumulatorMixMod.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/Provenance/interface/EventID.h"

namespace edm {
  class ConsumesCollector;
  namespace stream {
    class EDProducerBase;
  }
  class Event;
  class EventSetup;
  class ParameterSet;
  template<typename T> class Handle;
  class StreamID;
}

class MagneticField;
class PileUpEventPrincipal;
class PixelGeomDetUnit;
class PSimHit;
class SiPSMacroDigitizerAlgorithm;
class TrackerGeometry;

namespace CLHEP {
  class HepRandomEngine;
}

namespace cms {
  class SiPSMacroDigitizer : public DigiAccumulatorMixMod {
  public:

    explicit SiPSMacroDigitizer(const edm::ParameterSet& conf, edm::stream::EDProducerBase& mixMod, edm::ConsumesCollector& iC);

    virtual ~SiPSMacroDigitizer();

    virtual void initializeEvent(edm::Event const& e, edm::EventSetup const& c) override;
    virtual void accumulate(edm::Event const& e, edm::EventSetup const& c) override;
    virtual void accumulate(PileUpEventPrincipal const& e, edm::EventSetup const& c, edm::StreamID const&) override;
    virtual void finalizeEvent(edm::Event& e, edm::EventSetup const& c) override;

    virtual void beginJob() {}

    virtual void StorePileupInformation( std::vector<int> &numInteractionList,
					 std::vector<int> &bunchCrossingList,
					 std::vector<float> &TrueInteractionList, 
					 std::vector<edm::EventID> &eventInfoList, int bunchSpacing){
      PileupInfo_ = new PileupMixingContent(numInteractionList, bunchCrossingList, TrueInteractionList, eventInfoList, bunchSpacing);
    }

    virtual PileupMixingContent* getEventPileupInfo() { return PileupInfo_; }

  private:
    void accumulatePixelHits(edm::Handle<std::vector<PSimHit> >,
			     size_t globalSimHitIndex,
			     const unsigned int tofBin,
			     CLHEP::HepRandomEngine*,
			     edm::EventSetup const& c);
    CLHEP::HepRandomEngine* randomEngine(edm::StreamID const& streamID);

    bool firstInitializeEvent_;
    bool firstFinalizeEvent_;
    std::unique_ptr<SiPSMacroDigitizerAlgorithm>  _pixeldigialgo;
    /** @brief Offset to add to the index of each sim hit to account for which crossing it's in.
*
* I need to know what each sim hit index will be when the hits from all crossing frames are merged into
* one collection (assuming the MixingModule is configured to create the crossing frame for all sim hits).
* To do this I'll record how many hits were in each crossing, and then add that on to the index for a given
* hit in a given crossing. This assumes that the crossings are processed in the same order here as they are
* put into the crossing frame, which I'm pretty sure is true.<br/>
* The key is the name of the sim hit collection. */
    std::map<std::string,size_t> crossingSimHitIndexOffset_;

    typedef std::vector<std::string> vstring;
    const std::string hitsProducer;
    const vstring trackerContainers;
    const std::string geometryType;
    edm::ESHandle<TrackerGeometry> pDD;
    /////edm::ESHandle<MagneticField> pSetup;
    std::map<unsigned int, PixelGeomDetUnit const *> detectorUnits;
    std::vector<CLHEP::HepRandomEngine*> randomEngines_;

    PileupMixingContent* PileupInfo_;
    
    const bool pilotBlades; // Default = false
    const int NumberOfEndcapDisks; // Default = 2
  };
}

namespace CLHEP {
  class HepRandomEngine;
}

namespace cms
{
  SiPSMacroDigitizer::SiPSMacroDigitizer(const edm::ParameterSet& iConfig, edm::stream::EDProducerBase& mixMod, edm::ConsumesCollector& iC):
    firstInitializeEvent_(true),
    firstFinalizeEvent_(true),
    _pixeldigialgo(),
    hitsProducer(iConfig.getParameter<std::string>("hitsProducer")),
    trackerContainers(iConfig.getParameter<std::vector<std::string> >("RoutList")),
    geometryType(iConfig.getParameter<std::string>("PixGeometryType")),
    pilotBlades(iConfig.exists("enablePilotBlades")?iConfig.getParameter<bool>("enablePilotBlades"):false),
    NumberOfEndcapDisks(iConfig.exists("NumPixelEndcap")?iConfig.getParameter<int>("NumPixelEndcap"):2)
  {
    edm::LogInfo ("PixelDigitizer ") <<"Enter the Pixel Digitizer";
    
    const std::string alias ("simSiPixelDigis"); 
    
    mixMod.produces<edm::DetSetVector<PixelDigi> >().setBranchAlias(alias);
    mixMod.produces<edm::DetSetVector<PixelDigiSimLink> >().setBranchAlias(alias + "siPixelDigiSimLink");
    for(auto const& trackerContainer : trackerContainers) {
      edm::InputTag tag(hitsProducer, trackerContainer);
      iC.consumes<std::vector<PSimHit> >(edm::InputTag(hitsProducer, trackerContainer));
    }
    edm::Service<edm::RandomNumberGenerator> rng;
    if ( ! rng.isAvailable()) {
      throw cms::Exception("Configuration")
        << "SiPSMacroDigitizer requires the RandomNumberGeneratorService\n"
        "which is not present in the configuration file.  You must add the service\n"
        "in the configuration file or remove the modules that require it.";
    }

    _pixeldigialgo.reset(new SiPSMacroDigitizerAlgorithm(iConfig));
  }
  
  SiPSMacroDigitizer::~SiPSMacroDigitizer(){  
    edm::LogInfo ("PixelDigitizer ") <<"Destruct the Pixel Digitizer";
  }

  void
  SiPSMacroDigitizer::accumulatePixelHits(edm::Handle<std::vector<PSimHit> > hSimHits,
					size_t globalSimHitIndex,
					const unsigned int tofBin,
					CLHEP::HepRandomEngine* engine,
					edm::EventSetup const& iSetup) {
    if(hSimHits.isValid()) {
       std::set<unsigned int> detIds;
       std::vector<PSimHit> const& simHits = *hSimHits.product();
       edm::ESHandle<TrackerTopology> tTopoHand;
       iSetup.get<TrackerTopologyRcd>().get(tTopoHand);
       const TrackerTopology *tTopo=tTopoHand.product();
       for(std::vector<PSimHit>::const_iterator it = simHits.begin(), itEnd = simHits.end(); it != itEnd; ++it, ++globalSimHitIndex) {
         unsigned int detId = (*it).detUnitId();
         if(detIds.insert(detId).second) {
           // The insert succeeded, so this detector element has not yet been processed.
	   assert(detectorUnits[detId]);
	   if(detectorUnits[detId] && detectorUnits[detId]->type().isTrackerPixel()) { // this test could be avoided and changed into a check of pixdet!=0
	     std::map<unsigned int, PixelGeomDetUnit const *>::iterator itDet = detectorUnits.find(detId);	     
	     if (itDet == detectorUnits.end()) continue;
             auto pixdet = itDet->second;
	     assert(pixdet !=0);
             //access to magnetic field in global coordinates
             GlobalVector bfield; // = pSetup->inTesla(pixdet->surface().position());
             // LogDebug ("PixelDigitizer ") << "B-field(T) at " << pixdet->surface().position() << "(cm): " 
             //                              << pSetup->inTesla(pixdet->surface().position());
             _pixeldigialgo->accumulateSimHits(it, itEnd, globalSimHitIndex, tofBin, pixdet, bfield, tTopo, engine);
           }
         }
       }
    }
  }
  
  void
  SiPSMacroDigitizer::initializeEvent(edm::Event const& e, edm::EventSetup const& iSetup) {
    if(firstInitializeEvent_){
      _pixeldigialgo->init(iSetup);
      firstInitializeEvent_ = false;
    }

    // Make sure that the first crossing processed starts indexing the sim hits from zero.
    // This variable is used so that the sim hits from all crossing frames have sequential
    // indices used to create the digi-sim link (if configured to do so) rather than starting
    // from zero for each crossing.
    crossingSimHitIndexOffset_.clear();

    _pixeldigialgo->initializeEvent();
    /////    iSetup.get<TrackerDigiGeometryRecord>().get(geometryType, pDD);
    iSetup.get<TrackerDigiGeometryRecord>().get(pDD);
    //// No MagneticField iSetup.get<IdealMagneticFieldRecord>().get(pSetup);
    edm::ESHandle<TrackerTopology> tTopoHand;
    iSetup.get<TrackerTopologyRcd>().get(tTopoHand);
    const TrackerTopology *tTopo=tTopoHand.product();

    // FIX THIS! We only need to clear and (re)fill this map when the geometry type IOV changes.  Use ESWatcher to determine this.
    if(true) { // Replace with ESWatcher 
      detectorUnits.clear();
      for(TrackingGeometry::DetUnitContainer::const_iterator iu = pDD->detUnits().begin(); iu != pDD->detUnits().end(); ++iu) {
        unsigned int detId = (*iu)->geographicalId().rawId();
	if((*iu)->type().isTrackerPixel()) {
          auto pixdet = dynamic_cast<const PixelGeomDetUnit*>((*iu));
          assert(pixdet != 0);
	  if ((*iu)->subDetector()==GeomDetEnumerators::SubDetector::PixelEndcap) { // true ONLY for the phase 0 pixel deetctor
	    unsigned int disk = tTopo->layer(detId); // using the generic layer method
	    //if using pilot blades, then allowing it for current detector only
	    if ((disk == 3)&&((!pilotBlades)&&(NumberOfEndcapDisks == 2))) continue;
	  }
          detectorUnits.insert(std::make_pair(detId, pixdet));
        }
      }
    }
  }

  void
  SiPSMacroDigitizer::accumulate(edm::Event const& iEvent, edm::EventSetup const& iSetup) {
    // Step A: Get Inputs
    for(vstring::const_iterator i = trackerContainers.begin(), iEnd = trackerContainers.end(); i != iEnd; ++i) {
      edm::Handle<std::vector<PSimHit> > simHits;
      edm::InputTag tag(hitsProducer, *i);

      iEvent.getByLabel(tag, simHits);
      unsigned int tofBin = PixelDigiSimLink::LowTof;
      if ((*i).find(std::string("HighTof")) != std::string::npos) tofBin = PixelDigiSimLink::HighTof;
      accumulatePixelHits(simHits, crossingSimHitIndexOffset_[tag.encode()], tofBin, randomEngine(iEvent.streamID()), iSetup);
      // Now that the hits have been processed, I'll add the amount of hits in this crossing on to
      // the global counter. Next time accumulateStripHits() is called it will count the sim hits
      // as though they were on the end of this collection.
      // Note that this is only used for creating digi-sim links (if configured to do so).
//       std::cout << "index offset, current hit count = " << crossingSimHitIndexOffset_[tag.encode()] << ", " << simHits->size() << std::endl;
      if( simHits.isValid() ) crossingSimHitIndexOffset_[tag.encode()]+=simHits->size();
    }
  }

  void
  SiPSMacroDigitizer::accumulate(PileUpEventPrincipal const& iEvent, edm::EventSetup const& iSetup, edm::StreamID const& streamID) {
    // Step A: Get Inputs
    for(vstring::const_iterator i = trackerContainers.begin(), iEnd = trackerContainers.end(); i != iEnd; ++i) {
      edm::Handle<std::vector<PSimHit> > simHits;
      edm::InputTag tag(hitsProducer, *i);

      iEvent.getByLabel(tag, simHits);
      unsigned int tofBin = PixelDigiSimLink::LowTof;
      if ((*i).find(std::string("HighTof")) != std::string::npos) tofBin = PixelDigiSimLink::HighTof;
      accumulatePixelHits(simHits, crossingSimHitIndexOffset_[tag.encode()], tofBin, randomEngine(streamID), iSetup);
      // Now that the hits have been processed, I'll add the amount of hits in this crossing on to
      // the global counter. Next time accumulateStripHits() is called it will count the sim hits
      // as though they were on the end of this collection.
      // Note that this is only used for creating digi-sim links (if configured to do so).
//       std::cout << "index offset, current hit count = " << crossingSimHitIndexOffset_[tag.encode()] << ", " << simHits->size() << std::endl;
      if( simHits.isValid() ) crossingSimHitIndexOffset_[tag.encode()]+=simHits->size();
    }
  }

  // ------------ method called to produce the data  ------------
  void
  SiPSMacroDigitizer::finalizeEvent(edm::Event& iEvent, const edm::EventSetup& iSetup) {

    edm::Service<edm::RandomNumberGenerator> rng;
    CLHEP::HepRandomEngine* engine = &rng->getEngine(iEvent.streamID());

    edm::ESHandle<TrackerTopology> tTopoHand;
    iSetup.get<TrackerTopologyRcd>().get(tTopoHand);
    const TrackerTopology *tTopo=tTopoHand.product();

    std::vector<edm::DetSet<PixelDigi> > theDigiVector;
    std::vector<edm::DetSet<PixelDigiSimLink> > theDigiLinkVector;
 
    PileupInfo_ = getEventPileupInfo();
    if (firstFinalizeEvent_) {
      const unsigned int bunchspace = PileupInfo_->getMix_bunchSpacing();
      _pixeldigialgo->init_DynIneffDB(iSetup, bunchspace);
      firstFinalizeEvent_ = false;
    }
    _pixeldigialgo->calculateInstlumiFactor(PileupInfo_);   

    for(TrackingGeometry::DetUnitContainer::const_iterator iu = pDD->detUnits().begin(); iu != pDD->detUnits().end(); iu ++){
      
      if((*iu)->type().isTrackerPixel()) {

	//

        edm::DetSet<PixelDigi> collector((*iu)->geographicalId().rawId());
        edm::DetSet<PixelDigiSimLink> linkcollector((*iu)->geographicalId().rawId());
        
        
        _pixeldigialgo->digitize(dynamic_cast<const PixelGeomDetUnit*>((*iu)),
                                 collector.data,
                                 linkcollector.data,
				 tTopo,
                                 engine);
        if(collector.data.size() > 0) {
          theDigiVector.push_back(std::move(collector));
        }
        if(linkcollector.data.size() > 0) {
          theDigiLinkVector.push_back(std::move(linkcollector));
        }
      }
    }
    
    // Step C: create collection with the cache vector of DetSet 
    std::auto_ptr<edm::DetSetVector<PixelDigi> > 
      output(new edm::DetSetVector<PixelDigi>(theDigiVector) );
    std::auto_ptr<edm::DetSetVector<PixelDigiSimLink> > 
      outputlink(new edm::DetSetVector<PixelDigiSimLink>(theDigiLinkVector) );

    // Step D: write output to file 
    iEvent.put(output);
    iEvent.put(outputlink);
  }

  CLHEP::HepRandomEngine* SiPSMacroDigitizer::randomEngine(edm::StreamID const& streamID) {
    unsigned int index = streamID.value();
    if(index >= randomEngines_.size()) {
      randomEngines_.resize(index + 1, nullptr);
    }
    CLHEP::HepRandomEngine* ptr = randomEngines_[index];
    if(!ptr) {
      edm::Service<edm::RandomNumberGenerator> rng;
      ptr = &rng->getEngine(streamID);
      randomEngines_[index] = ptr;
    }
    return ptr;
  }

}

#include "FWCore/Framework/interface/MakerMacros.h"
#include "SimGeneral/MixingModule/interface/DigiAccumulatorMixModFactory.h"

using cms::SiPSMacroDigitizer;
DEFINE_DIGI_ACCUMULATOR(SiPSMacroDigitizer);
