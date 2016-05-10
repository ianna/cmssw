#ifndef GEOMETRY_ECALTBHODOSCOPEGEOMETRYLOADERFROMDDD_H
#define GEOMETRY_ECALTBHODOSCOPEGEOMETRYLOADERFROMDDD_H 1

/** \class EcalTBHodoscopeGeometryLoaderFromDDD
 *
 *
 *   
 * \author P. Meridiani - INFN Roma 1
*/

#include <memory>
#include <string>
#include "Geometry/EcalTestBeam/interface/EcalHodoscopeNumberingScheme.h"

class CaloSubdetectorGeometry;
class DDCompactView;
class DDFilter;
class DDFilteredView;

class EcalTBHodoscopeGeometryLoaderFromDDD
{
   public:

      EcalTBHodoscopeGeometryLoaderFromDDD() {} ;

      virtual ~EcalTBHodoscopeGeometryLoaderFromDDD() {} ;

      std::auto_ptr<CaloSubdetectorGeometry> load( const DDCompactView* cpv ) ;

   private:

      void makeGeometry( const DDCompactView*     cpv ,
			 CaloSubdetectorGeometry* ebg  ) ;

      unsigned int getDetIdForDDDNode( const DDFilteredView &fv ) ;

      std::string getDDDString( std::string s, DDFilteredView* fv ) ;

      DDFilter* getDDFilter();

      EcalHodoscopeNumberingScheme _scheme;
};

#endif
