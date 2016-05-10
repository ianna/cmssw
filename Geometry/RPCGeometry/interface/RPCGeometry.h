#ifndef RPCGeometry_RPCGeometry_h
#define RPCGeometry_RPCGeometry_h

/** \class RPCGeometry
 *
 *  The model of the geometry of RPC.
 *
 *  \author M. Maggi - INFN Bari
 */

#include <vector>
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/CommonDetUnit/interface/TrackingGeometry.h"

class RPCChamber;
class RPCRoll;

class RPCGeometry : public TrackingGeometry {

 public:
  /// Default constructor
  RPCGeometry();

  /// Destructor
  virtual ~RPCGeometry();

  // Return a vector of all det types
  virtual const DetTypeContainer&  detTypes() const override;

  // Return a vector of all GeomDetUnit
  virtual const DetUnitContainer& detUnits() const override;

  // Return a vector of all GeomDet
  virtual const DetContainer& dets() const override;
  
  // Return a vector of all GeomDetUnit DetIds
  virtual const DetIdContainer& detUnitIds() const override;

  // Return a vector of all GeomDet DetIds
  virtual const DetIdContainer& detIds() const override;

  // Return the pointer to the GeomDetUnit corresponding to a given DetId
  virtual const GeomDetUnit* idToDetUnit(DetId) const override;

  // Return the pointer to the GeomDet corresponding to a given DetId
  virtual const GeomDet* idToDet(DetId) const override;


  //---- Extension of the interface

  /// Return a vector of all RPC chambers
  const std::vector<const RPCChamber*>& chambers() const;

  /// Return a vector of all RPC rolls
  const std::vector<const RPCRoll*>& rolls() const;

  // Return a RPCChamber given its id
  const RPCChamber* chamber(RPCDetId id) const;

  /// Return a roll given its id
  const RPCRoll* roll(RPCDetId id) const;

  /// Add a RPC roll to the Geometry
  void add(RPCRoll* roll);

  /// Add a RPC roll to the Geometry
  void add(RPCChamber* ch);

 private:
  DetUnitContainer theRolls;
  DetContainer theDets;
  DetTypeContainer theRollTypes;
  DetIdContainer theRollIds;
  DetIdContainer theDetIds;
  
  // Map for efficient lookup by DetId 
  mapIdToDet theMap;

  std::vector<const RPCRoll*> allRolls; // Are not owned by this class; are owned by their chamber.
  std::vector<const RPCChamber*> allChambers; // Are owned by this class.

};

#endif
