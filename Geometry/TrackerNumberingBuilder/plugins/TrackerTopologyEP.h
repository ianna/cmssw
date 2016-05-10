#ifndef GEOMETRY_TRACKERNUMBERINGBUILDER_TRACKERTOPOLOGYEP_H
#define GEOMETRY_TRACKERNUMBERINGBUILDER_TRACKERTOPOLOGYEP_H 1

#include <memory>
#include "DataFormats/TrackerCommon/interface/TrackerTopology.h"
#include "FWCore/Framework/interface/ESProducer.h"

class PTrackerParameters;
class TrackerTopologyRcd;

namespace edm { class ConfigurationDescriptions; }
namespace edm { class ParameterSet; }

class TrackerTopologyEP : public edm::ESProducer
{
public:
  TrackerTopologyEP( const edm::ParameterSet & );
  ~TrackerTopologyEP( void );

  typedef std::shared_ptr<TrackerTopology> ReturnType;

  static void fillDescriptions( edm::ConfigurationDescriptions & descriptions );
    
  ReturnType produce( const TrackerTopologyRcd & );

private:
  void fillParameters( const PTrackerParameters& );
    
  TrackerTopology::PixelBarrelValues pxbVals_;
  TrackerTopology::PixelEndcapValues pxfVals_;
  TrackerTopology::TECValues tecVals_;
  TrackerTopology::TIBValues tibVals_;
  TrackerTopology::TIDValues tidVals_;
  TrackerTopology::TOBValues tobVals_;
};

#endif
