#ifndef DTGEOMETRYBUILDERFROMCONDDB_H
#define DTGEOMETRYBUILDERFROMCONDDB_H

/** \class DTGeometryBuilderFromCondDB
 *
 * Description:
 *  
 *  detailed description
 *
 * \author : Stefano Lacaprara - INFN LNL <stefano.lacaprara@pd.infn.it>
 *
 * Modification:
 *
 */

/* Base Class Headers */

/* Collaborating Class Declarations */
class RecoIdealGeometry;
class DTGeometry;
class DTChamber;
class DTSuperLayer;
class DTLayer;
class DetId;
#include "DataFormats/GeometrySurface/interface/Plane.h"

/* C++ Headers */
#include <memory>
#include <vector>

/* ====================================================================== */

/* Class DTGeometryBuilderFromCondDB Interface */

class DTGeometryBuilderFromCondDB{

  public:

/* Constructor */ 
    DTGeometryBuilderFromCondDB() ;

/* Destructor */ 
    virtual ~DTGeometryBuilderFromCondDB() ;

/* Operations */ 
    void build( const std::shared_ptr<DTGeometry>& theGeometry,
		const RecoIdealGeometry& rig);

  private:
    std::shared_ptr< const DTChamber > buildChamber(const DetId& id,
						    const RecoIdealGeometry& rig,
						    size_t idt) const ;

    std::shared_ptr< const DTSuperLayer > buildSuperLayer( std::shared_ptr< conat DTChamber > chamber,
							   const DetId& id,
							   const RecoIdealGeometry& rig,
							   size_t idt) const ;

    std::shared_ptr< const DTLayer > buildLayer( std::shared_ptr< const DTSuperLayer > sl,
						 const DetId& id,
						 const RecoIdealGeometry& rig,
						 size_t idt) const ;

    typedef ReferenceCountingPointer<Plane> RCPPlane;

    RCPPlane plane(const std::vector<double>::const_iterator tranStart,
                   const std::vector<double>::const_iterator rotStart,
                   Bounds * bounds) const ;
};
#endif // DTGEOMETRYBUILDERFROMCONDDB_H

