#ifndef GEOMETRY_FORWARDGEOMETRY_IDEALCASTORTRAPEZOID_H
#define GEOMETRY_FORWARDGEOMETRY_IDEALCASTORTRAPEZOID_H

#include "DataFormats/CaloGeometry/interface/CaloCellGeometry.h"

  /** \class IdealCastorTrapezoid
    
  Trapezoid class used for CASTOR volumes.  
  
  Required parameters for an ideal trapezoid:
  
  - dxl, dxh, dh, dz, z-face tilt-angle, dR
    dxl is the HALFlength of the side at smaller y
    dxh is the HALFlength of the side at larger y
    dxl and dxh are both either positive or negative;
        positive means a "right-handed" trapezoid cross section
        negative means a "left-handed" trapezoid cross section
    dh is the HALFheight of the actual side, not its projection
    dz is the HALFlength in z of each long side
    an is the angle of tilt in the z direction 
    dR is the length of the line in the xy plane from the origin
        to the perpendicular intersection with the extended edge
        at the lower-y side of the trapezoid

  - locaton x, y and z of faceCenter
  
  Total: 6+3 parameters 
  
  $Revision: 1.12 $
  \author P. Katsas - UoA
  */

class IdealCastorTrapezoid final : public CaloCellGeometry 
{
 public:

  typedef CaloCellGeometry::CCGFloat CCGFloat ;
  typedef CaloCellGeometry::Pt3D     Pt3D     ;
  typedef CaloCellGeometry::Pt3DVec  Pt3DVec  ;
  typedef CaloCellGeometry::Tr3D     Tr3D     ;

  IdealCastorTrapezoid() ;

  IdealCastorTrapezoid( const IdealCastorTrapezoid& idct ) ;
      
  IdealCastorTrapezoid& operator=( const IdealCastorTrapezoid& idct ) ;
      
  IdealCastorTrapezoid( const GlobalPoint&   faceCenter,
			CornersMgr*          mgr       ,
			const CCGFloat*      parm        ) ;
	 
  virtual ~IdealCastorTrapezoid() ;
	 
  CCGFloat dxl() const ; 
  CCGFloat dxh() const ; 
  CCGFloat dx()  const ; 
  CCGFloat dh()  const ;
  CCGFloat dy()  const ; 
  CCGFloat dz()  const ;
  CCGFloat dhz() const ; 
  CCGFloat dzb() const ; 
  CCGFloat dzs() const ;
  CCGFloat an()  const ;
  CCGFloat dR()  const ;

  virtual void vocalCorners( Pt3DVec&        vec ,
			     const CCGFloat* pv  ,
			     Pt3D&           ref  ) const override;

  static void localCorners( Pt3DVec&        vec ,
			    const CCGFloat* pv  , 
			    Pt3D&           ref   ) ;
 private:
  virtual void initCorners(CornersVec& ) override;
};

std::ostream& operator<<( std::ostream& s , const IdealCastorTrapezoid& cell ) ;

#endif
