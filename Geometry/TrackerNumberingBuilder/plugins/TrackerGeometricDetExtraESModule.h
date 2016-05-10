#ifndef Geometry_TrackerNumberingBuilder_TrackerGeometricDetExtraESModule_H
#define Geometry_TrackerNumberingBuilder_TrackerGeometricDetExtraESModule_H

#include <memory>
#include <vector>
#include "DetectorDescription/Core/interface/DDExpandedView.h"
#include "FWCore/Framework/interface/ESProducer.h"

class GeometricDet;
class GeometricDetExtra;
class IdealGeometryRecord;

namespace edm { class ParameterSet; }

class  TrackerGeometricDetExtraESModule: public edm::ESProducer {

 public:
  TrackerGeometricDetExtraESModule(const edm::ParameterSet & p);
  virtual ~TrackerGeometricDetExtraESModule(); 
  std::shared_ptr<std::vector<GeometricDetExtra> > produce(const IdealGeometryRecord &);

 protected:

 private:
  void putOne(std::vector<GeometricDetExtra> & gde, const GeometricDet* gd, const DDExpandedView& ev, int lev );

  bool fromDDD_;

};


#endif




