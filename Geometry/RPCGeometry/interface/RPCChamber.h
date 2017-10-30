#ifndef RPCGeometry_RPCChamber_h
#define RPCGeometry_RPCChamber_h

/** \class RPCChamber
 *
 *  Model of a RPC chamber.
 *   
 *  A chamber is a GeomDet.
 *  The chamber is composed by 2 or 3 Roll (GeomDetUnit).
 *
 *  \author R. Trentadue
 */

#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"

class RPCRoll;

class RPCChamber : public GeomDet {
public:
  /// Constructor
  RPCChamber(RPCDetId id, const ReferenceCountingPointer<BoundPlane>& plane);
  /// Destructor
  ~RPCChamber() override;

  /// Return the RPCChamberId of this chamber
  RPCDetId id() const;

  // Which subdetector
  SubDetector subDetector() const override {return GeomDetEnumerators::RPCBarrel;}

  /// equal if the id is the same
  bool operator==(const RPCChamber& ch) const;

  /// Add Roll to the chamber which takes ownership
  void add( std::shared_ptr< const RPCRoll > rl);

  /// Return the rolls in the chamber
  std::vector< std::shared_ptr< const GeomDet >> components() const override;

  /// Return the sub-component (roll) with a given id in this chamber
  const std::shared_ptr< const GeomDet > component(DetId id) const override;

  /// Return the Roll corresponding to the given id 
  const std::shared_ptr< const RPCRoll > roll(RPCDetId id) const;

  const std::shared_ptr< const RPCRoll > roll(int isl) const;
  
  /// Return the Rolls
  const std::vector< std::shared_ptr< const RPCRoll >>& rolls() const;

  /// Retunr numbers of rolls
  int nrolls() const;

private:

  RPCDetId theId;

  // The chamber owns its Rolls
  std::vector< std::shared_ptr< const RPCRoll >> theRolls;

};
#endif
