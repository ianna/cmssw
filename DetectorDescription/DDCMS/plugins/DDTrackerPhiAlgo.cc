#include "DD4hep/DetFactoryHelper.h"
#include "DetectorDescription/DDCMS/interface/DDCMSPlugins.h"

using namespace std;
using namespace dd4hep;
using namespace dd4hep::cms;

static long algorithm(Detector& /* description */,
                      ParsingContext& ctxt,
                      xml_h e,
                      SensitiveDetector& /* sens */)
{
  Namespace      ns(ctxt, e, true);
  AlgoArguments  args(ctxt, e);
  Volume         mother      = ns.volume(args.parentName());
  Volume         child       = ns.volume(args.childName());
  int            startcn     = args.find("StartCopyNo") ? args.value<int>("StartCopyNo") : 1;
  int            incrcn      = args.find("IncrCopyNo")  ? args.value<int>("IncrCopyNo")  : 1;
  vector<double> phi         = args.value<vector<double> >("Phi");         // Phi values
  vector<double> zpos        = args.value<vector<double> >("ZPos");        // Z positions
  int            numcopies   = args.find("NumCopies") ? args.value<int>("NumCopies") : int(phi.size());
  double         radius      = args.value<double>("Radius");
  double         tilt        = args.value<double>("Tilt");

  if ( numcopies != int(phi.size()) )  {
    LogDebug("TrackerGeom") << "error: Parameter "
        << "NumCopies does not agree with the size "
        << "of the Phi vector. It was adjusted to "
        << "be the size of the Phi vector and may "
        << "lead to crashes or errors.";
  }
  LogDebug("TrackerGeom") << "debug: Parameters for position"
                          << "ing:: " << " Radius " << radius << " Tilt " 
                          << tilt/CLHEP::deg << " Copies " << phi.size() 
                          << " at";
  for (int i=0; i<(int)(phi.size()); i++)
    LogDebug("TrackerGeom") << "\t[" << i << "] phi = " << phi[i]/CLHEP::deg 
        << " z = " << zpos[i];
  LogDebug("TrackerGeom") <<  "debug: Parent " << mother.name()
      <<"\tChild " << child.name() << " NameSpace " << ns.name;

  double theta  = 90.*CLHEP::deg;
  int ci = startcn;
  for (int i  = 0; i < numcopies; ++i) {
    double phix   = phi[i] + tilt;
    double phiy   = phix + 90.*CLHEP::deg;
    double xpos   = radius*cos(phi[i]);
    double ypos   = radius*sin(phi[i]);
    Rotation3D rot = make_rotation3D(theta, phix, theta, phiy, 0., 0.);
    Position   tran(xpos, ypos, zpos[i]);
    /* PlacedVolume pv = */ mother.placeVolume(child,ci,Transform3D(rot,tran));
    LogDebug("TrackerGeom") << "test: " << child.name() << " number "
        << ci << " positioned in " << mother.name() << " at "
        << tran  << " with " << rot;
    ci = ci+incrcn;
  }
  return 1;
}

// first argument is the type from the xml file
DECLARE_DDCMS_DETELEMENT(DDCMS_track_DDTrackerPhiAlgo,algorithm)

