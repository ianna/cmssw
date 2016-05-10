#ifndef Geometry_TrackerGeometryBuilder_TrackerDigiGeometryESModule_H
#define Geometry_TrackerGeometryBuilder_TrackerDigiGeometryESModule_H

#include <memory>
#include <string>
#include "FWCore/Framework/interface/ESProducer.h"

class TrackerDigiGeometryRecord;
class TrackerGeometry;

namespace edm { class ConfigurationDescriptions; }
namespace edm { class ParameterSet; }

namespace edm {
  class ConfigurationDescriptions;
}

class  TrackerDigiGeometryESModule: public edm::ESProducer{
 public:
  TrackerDigiGeometryESModule(const edm::ParameterSet & p);
  virtual ~TrackerDigiGeometryESModule(); 
  std::shared_ptr<TrackerGeometry> produce(const TrackerDigiGeometryRecord &);

  static void fillDescriptions(edm::ConfigurationDescriptions & descriptions);
  
 private:
  /// Called when geometry description changes
  std::shared_ptr<TrackerGeometry> _tracker;
  const std::string alignmentsLabel_;
  const std::string myLabel_;
  bool applyAlignment_; // Switch to apply alignment corrections
  bool fromDDD_;
};


#endif




