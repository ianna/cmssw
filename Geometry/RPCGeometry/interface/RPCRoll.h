#ifndef Geometry_RPCSimAlgo_RPCRoll_H
#define Geometry_RPCSimAlgo_RPCRoll_H

#include "DataFormats/GeometrySurface/interface/LocalError.h"
#include "DataFormats/GeometrySurface/interface/Plane.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"

class GeomDetType;
class RPCChamber;
class RPCRollSpecs;
class StripTopology;
class Topology;

class RPCRoll : public GeomDetUnit{

 public:
  
  RPCRoll(RPCDetId id, BoundPlane::BoundPlanePointer bp, RPCRollSpecs* rrs);
  ~RPCRoll();
  const RPCRollSpecs* specs() const;
  RPCDetId id() const;
  const Topology& topology() const;
  const StripTopology& specificTopology() const;
  const GeomDetType& type() const; 
 
  /// Return the chamber this roll belongs to 
  const RPCChamber* chamber() const;
  
  int nstrips() const;

  LocalPoint  centreOfStrip(int strip) const;
  LocalPoint  centreOfStrip(float strip) const;
  LocalError  localError(float strip) const;

  float strip(const LocalPoint& lp) const;
  float pitch() const;
  float localPitch(const LocalPoint& lp) const; 
  bool isBarrel() const; 
  bool isForward() const;
  
 private:
  void setChamber(const RPCChamber* ch);

 private:
  RPCDetId _id;
  RPCRollSpecs* _rrs;
  const RPCChamber* theCh; // NOT owned
};

#endif
