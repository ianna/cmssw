//

#define FETCH_PAYLOAD_CASE( TYPENAME ) \
  if( payloadTypeName == #TYPENAME ){ \
    auto payload = deserialize<TYPENAME>( payloadTypeName, data, streamerInfo ); \
    payloadPtr = payload; \
    match = true; \
  }

#include "CondCore/CondDB/interface/Serialization.h"

#include "CondCore/Utilities/interface/CondDBImport.h"
#include "CondCore/CondDB/interface/Exception.h"
#include "CondFormats.h"

//
#include <sstream>

namespace cond {

  namespace persistency {

    std::pair<std::string, boost::shared_ptr<void> > fetchOne( const std::string &payloadTypeName, const cond::Binary &data, const cond::Binary &streamerInfo, boost::shared_ptr<void> payloadPtr ){

      bool match = false;
      FETCH_PAYLOAD_CASE( std::string ) 
      FETCH_PAYLOAD_CASE( std::vector<unsigned long long> )
      FETCH_PAYLOAD_CASE( AlCaRecoTriggerBits )
      FETCH_PAYLOAD_CASE( AlignmentErrors )
      FETCH_PAYLOAD_CASE( AlignmentErrorsExtended )
      FETCH_PAYLOAD_CASE( AlignmentSurfaceDeformations )
      FETCH_PAYLOAD_CASE( Alignments )
      FETCH_PAYLOAD_CASE( BeamSpotObjects )
      FETCH_PAYLOAD_CASE( CSCBadChambers )
      FETCH_PAYLOAD_CASE( CSCBadStrips )
      FETCH_PAYLOAD_CASE( CSCBadWires )
      FETCH_PAYLOAD_CASE( CSCChamberIndex )
      FETCH_PAYLOAD_CASE( CSCChamberMap )
      FETCH_PAYLOAD_CASE( CSCChamberTimeCorrections )
      FETCH_PAYLOAD_CASE( CSCCrateMap )
      FETCH_PAYLOAD_CASE( CSCDBChipSpeedCorrection )
      FETCH_PAYLOAD_CASE( CSCDBCrosstalk )
      FETCH_PAYLOAD_CASE( CSCDBGains )
      FETCH_PAYLOAD_CASE( CSCDBGasGainCorrection )
      FETCH_PAYLOAD_CASE( CSCDBL1TPParameters )
      FETCH_PAYLOAD_CASE( CSCDBNoiseMatrix )
      FETCH_PAYLOAD_CASE( CSCDBPedestals )
      FETCH_PAYLOAD_CASE( CSCDDUMap )
      FETCH_PAYLOAD_CASE( CSCL1TPParameters )
      FETCH_PAYLOAD_CASE( CSCRecoDigiParameters )
      FETCH_PAYLOAD_CASE( CastorChannelQuality )
      FETCH_PAYLOAD_CASE( CastorElectronicsMap )
      FETCH_PAYLOAD_CASE( CastorGainWidths )
      FETCH_PAYLOAD_CASE( CastorGains )
      FETCH_PAYLOAD_CASE( CastorPedestalWidths )
      FETCH_PAYLOAD_CASE( CastorPedestals )
      FETCH_PAYLOAD_CASE( CastorQIEData )
      FETCH_PAYLOAD_CASE( CastorRecoParams )
      FETCH_PAYLOAD_CASE( CastorSaturationCorrs )
      FETCH_PAYLOAD_CASE( CentralityTable )
      FETCH_PAYLOAD_CASE( DTCCBConfig )
      FETCH_PAYLOAD_CASE( DTDeadFlag )
      FETCH_PAYLOAD_CASE( DTHVStatus )
      FETCH_PAYLOAD_CASE( DTKeyedConfig )
      FETCH_PAYLOAD_CASE( DTLVStatus )
      FETCH_PAYLOAD_CASE( DTMtime )
      FETCH_PAYLOAD_CASE( DTReadOutMapping )
      FETCH_PAYLOAD_CASE( DTRecoConditions )	
      FETCH_PAYLOAD_CASE( DTRecoUncertainties )
      FETCH_PAYLOAD_CASE( DTStatusFlag )
      FETCH_PAYLOAD_CASE( DTT0 )
      FETCH_PAYLOAD_CASE( DTTPGParameters )
      FETCH_PAYLOAD_CASE( DTTtrig )
      FETCH_PAYLOAD_CASE( DropBoxMetadata )
      FETCH_PAYLOAD_CASE( ESChannelStatus )
      FETCH_PAYLOAD_CASE( ESEEIntercalibConstants )
      FETCH_PAYLOAD_CASE( ESFloatCondObjectContainer )
      FETCH_PAYLOAD_CASE( ESGain )
      FETCH_PAYLOAD_CASE( ESMIPToGeVConstant )
      FETCH_PAYLOAD_CASE( ESMissingEnergyCalibration )
      FETCH_PAYLOAD_CASE( ESPedestals )
      FETCH_PAYLOAD_CASE( ESRecHitRatioCuts )
      FETCH_PAYLOAD_CASE( ESThresholds )
      FETCH_PAYLOAD_CASE( ESTimeSampleWeights )
      FETCH_PAYLOAD_CASE( EcalADCToGeVConstant )
      FETCH_PAYLOAD_CASE( EcalChannelStatus )
      FETCH_PAYLOAD_CASE( EcalClusterEnergyCorrectionObjectSpecificParameters )
      FETCH_PAYLOAD_CASE( EcalDAQTowerStatus )
      FETCH_PAYLOAD_CASE( EcalDCSTowerStatus )
      FETCH_PAYLOAD_CASE( EcalDQMChannelStatus )
      FETCH_PAYLOAD_CASE( EcalDQMTowerStatus )
      FETCH_PAYLOAD_CASE( EcalFloatCondObjectContainer )
      FETCH_PAYLOAD_CASE( EcalFunParams )
      FETCH_PAYLOAD_CASE( EcalGainRatios )
      FETCH_PAYLOAD_CASE( EcalLaserAPDPNRatios )
      FETCH_PAYLOAD_CASE( EcalMappingElectronics )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalMappingElement> )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalPedestal> )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalTPGLinearizationConstant> )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalDQMStatusCode> )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalTPGCrystalStatusCode> )
      FETCH_PAYLOAD_CASE( EcalCondTowerObjectContainer<EcalDAQStatusCode> )
      FETCH_PAYLOAD_CASE( EcalCondTowerObjectContainer<EcalChannelStatusCode> )
      FETCH_PAYLOAD_CASE( EcalCondTowerObjectContainer<EcalDQMStatusCode> )
      FETCH_PAYLOAD_CASE( EcalPedestals )
      FETCH_PAYLOAD_CASE( EcalSRSettings )
      FETCH_PAYLOAD_CASE( EcalSampleMask )
      FETCH_PAYLOAD_CASE( EcalTBWeights )
      FETCH_PAYLOAD_CASE( EcalTimeBiasCorrections )
      FETCH_PAYLOAD_CASE( EcalTimeDependentCorrections )
      FETCH_PAYLOAD_CASE( EcalTPGCrystalStatus )
      FETCH_PAYLOAD_CASE( EcalTPGFineGrainEBGroup )
      FETCH_PAYLOAD_CASE( EcalTPGFineGrainEBIdMap )
      FETCH_PAYLOAD_CASE( EcalTPGFineGrainStripEE )
      FETCH_PAYLOAD_CASE( EcalTPGFineGrainTowerEE )
      FETCH_PAYLOAD_CASE( EcalTPGLinearizationConst )
      FETCH_PAYLOAD_CASE( EcalTPGLutGroup )
      FETCH_PAYLOAD_CASE( EcalTPGLutIdMap )
      FETCH_PAYLOAD_CASE( EcalTPGPedestals )
      FETCH_PAYLOAD_CASE( EcalTPGPhysicsConst )
      FETCH_PAYLOAD_CASE( EcalTPGSlidingWindow )
      FETCH_PAYLOAD_CASE( EcalTPGSpike )
      FETCH_PAYLOAD_CASE( EcalTPGStripStatus )
      FETCH_PAYLOAD_CASE( EcalTPGTowerStatus )
      FETCH_PAYLOAD_CASE( EcalTPGWeightGroup )
      FETCH_PAYLOAD_CASE( EcalTPGWeightIdMap )
      FETCH_PAYLOAD_CASE( EcalTimeOffsetConstant )
      FETCH_PAYLOAD_CASE( EcalWeightXtalGroups )
      FETCH_PAYLOAD_CASE( EcalSamplesCorrelation )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalPulseShape> )
      FETCH_PAYLOAD_CASE( EcalPulseShape )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalPulseCovariance> )
      FETCH_PAYLOAD_CASE( EcalPulseCovariance )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalPulseSymmCovariance> )
      FETCH_PAYLOAD_CASE( EcalPulseSymmCovariance )
      FETCH_PAYLOAD_CASE( FileBlob )
      FETCH_PAYLOAD_CASE( GBRForest )
      FETCH_PAYLOAD_CASE( GBRForestD )
      FETCH_PAYLOAD_CASE( HBHENegativeEFilter )
      FETCH_PAYLOAD_CASE( HcalChannelQuality )
      FETCH_PAYLOAD_CASE( HcalCholeskyMatrices )
      FETCH_PAYLOAD_CASE( HcalElectronicsMap )
      FETCH_PAYLOAD_CASE( HcalFlagHFDigiTimeParams )
      FETCH_PAYLOAD_CASE( HcalDcsValues )
      FETCH_PAYLOAD_CASE( HcalGains )
      FETCH_PAYLOAD_CASE( HcalGainWidths )
      FETCH_PAYLOAD_CASE( HcalL1TriggerObjects )
      FETCH_PAYLOAD_CASE( HcalLUTCorrs )
      FETCH_PAYLOAD_CASE( HcalLongRecoParams )
      FETCH_PAYLOAD_CASE( HcalZDCLowGainFractions )
      FETCH_PAYLOAD_CASE( HcalLutMetadata )
      FETCH_PAYLOAD_CASE( HcalMCParams )
      FETCH_PAYLOAD_CASE( HcalPFCorrs )
      FETCH_PAYLOAD_CASE( HcalPedestalWidths )
      FETCH_PAYLOAD_CASE( HcalPedestals )
      FETCH_PAYLOAD_CASE( HcalQIEData )
      FETCH_PAYLOAD_CASE( HcalRecoParams )
      FETCH_PAYLOAD_CASE( HcalRespCorrs )
      FETCH_PAYLOAD_CASE( HcalTimeCorrs )
      FETCH_PAYLOAD_CASE( HcalZSThresholds )
      FETCH_PAYLOAD_CASE( HcalInterpolatedPulseColl )
      FETCH_PAYLOAD_CASE( OOTPileupCorrectionBuffer )
      FETCH_PAYLOAD_CASE( StorableDoubleMap<AbsOOTPileupCorrection> )
      FETCH_PAYLOAD_CASE( JetCorrectorParametersCollection )
      FETCH_PAYLOAD_CASE( JME::JetResolutionObject )
      FETCH_PAYLOAD_CASE( METCorrectorParametersCollection )
      FETCH_PAYLOAD_CASE( L1CaloEcalScale )
      FETCH_PAYLOAD_CASE( L1CaloEtScale )
      FETCH_PAYLOAD_CASE( L1CaloGeometry )
      FETCH_PAYLOAD_CASE( L1CaloHcalScale )
      FETCH_PAYLOAD_CASE( L1GctChannelMask )
      FETCH_PAYLOAD_CASE( L1GctJetFinderParams )
      FETCH_PAYLOAD_CASE( L1GtBoardMaps )
      FETCH_PAYLOAD_CASE( L1GtParameters )
      FETCH_PAYLOAD_CASE( L1GtPrescaleFactors )
      FETCH_PAYLOAD_CASE( L1GtPsbSetup )
      FETCH_PAYLOAD_CASE( L1GtStableParameters )
      FETCH_PAYLOAD_CASE( L1GtTriggerMask )
      FETCH_PAYLOAD_CASE( L1GtTriggerMenu )
      FETCH_PAYLOAD_CASE( L1MuCSCPtLut )
      FETCH_PAYLOAD_CASE( L1MuCSCTFAlignment )
      FETCH_PAYLOAD_CASE( L1MuCSCTFConfiguration )
      FETCH_PAYLOAD_CASE( L1MuDTEtaPatternLut )
      FETCH_PAYLOAD_CASE( L1MuDTExtLut )
      FETCH_PAYLOAD_CASE( L1MuDTPhiLut )
      FETCH_PAYLOAD_CASE( L1MuDTPtaLut )
      FETCH_PAYLOAD_CASE( L1MuDTQualPatternLut )
      FETCH_PAYLOAD_CASE( L1MuDTTFMasks )
      FETCH_PAYLOAD_CASE( L1MuDTTFParameters )
      FETCH_PAYLOAD_CASE( L1MuGMTChannelMask )
      FETCH_PAYLOAD_CASE( L1MuGMTParameters )
      FETCH_PAYLOAD_CASE( L1MuGMTScales )
      FETCH_PAYLOAD_CASE( L1MuTriggerPtScale )
      FETCH_PAYLOAD_CASE( L1MuTriggerScales )
      FETCH_PAYLOAD_CASE( L1RCTChannelMask )
      FETCH_PAYLOAD_CASE( L1RCTNoisyChannelMask )
      FETCH_PAYLOAD_CASE( L1RCTParameters )
      FETCH_PAYLOAD_CASE( L1RPCBxOrConfig )
      FETCH_PAYLOAD_CASE( L1RPCConeDefinition )
      FETCH_PAYLOAD_CASE( L1RPCConfig )
      FETCH_PAYLOAD_CASE( L1RPCHsbConfig ) 
      FETCH_PAYLOAD_CASE( L1RPCHwConfig )
      FETCH_PAYLOAD_CASE( l1t::CaloParams )
      FETCH_PAYLOAD_CASE( l1t::CaloConfig )
      FETCH_PAYLOAD_CASE( L1TriggerKey )
      FETCH_PAYLOAD_CASE( L1TriggerKeyList )
      FETCH_PAYLOAD_CASE( lumi::LumiSectionData )
      FETCH_PAYLOAD_CASE( MixingModuleConfig )
      FETCH_PAYLOAD_CASE( MuScleFitDBobject )
      FETCH_PAYLOAD_CASE( DYTThrObject )
      FETCH_PAYLOAD_CASE( DYTParamObject )
      FETCH_PAYLOAD_CASE( PhysicsTools::Calibration::MVAComputerContainer )
      FETCH_PAYLOAD_CASE( PhysicsTGraphPayload )
      FETCH_PAYLOAD_CASE( PhysicsTFormulaPayload )
      FETCH_PAYLOAD_CASE( PCaloGeometry )
      FETCH_PAYLOAD_CASE( HcalParameters )
      FETCH_PAYLOAD_CASE( PGeometricDet )
      FETCH_PAYLOAD_CASE( PGeometricDetExtra )
      FETCH_PAYLOAD_CASE( PTrackerParameters )
      //FETCH_PAYLOAD_CASE( PerformancePayload )
      FETCH_PAYLOAD_CASE( PerformancePayloadFromTable )
      FETCH_PAYLOAD_CASE( PerformancePayloadFromTFormula )
      FETCH_PAYLOAD_CASE( PerformancePayloadFromBinnedTFormula )
      FETCH_PAYLOAD_CASE( PerformanceWorkingPoint )
      FETCH_PAYLOAD_CASE( PhysicsTools::Calibration::HistogramD3D )
      FETCH_PAYLOAD_CASE( QGLikelihoodCategory                )
      FETCH_PAYLOAD_CASE( QGLikelihoodObject                  )
      FETCH_PAYLOAD_CASE( QGLikelihoodSystematicsObject     )
      FETCH_PAYLOAD_CASE( RPCEMap )
      FETCH_PAYLOAD_CASE( RPCClusterSize )
      FETCH_PAYLOAD_CASE( RPCStripNoises )
      FETCH_PAYLOAD_CASE( RPCObFebmap )
      FETCH_PAYLOAD_CASE( RPCObGas )
      FETCH_PAYLOAD_CASE( RPCObImon )
      FETCH_PAYLOAD_CASE( RPCObGasMix )
      FETCH_PAYLOAD_CASE( RPCObPVSSmap )
      FETCH_PAYLOAD_CASE( RPCObStatus )
      FETCH_PAYLOAD_CASE( RPCObTemp )
      FETCH_PAYLOAD_CASE( RPCObUXC )
      FETCH_PAYLOAD_CASE( RPCObVmon )
      FETCH_PAYLOAD_CASE( RPFlatParams )
      FETCH_PAYLOAD_CASE( RecoIdealGeometry )
      FETCH_PAYLOAD_CASE( RunInfo )
      FETCH_PAYLOAD_CASE( SiPixelCalibConfiguration )
      FETCH_PAYLOAD_CASE( SiPixelCPEGenericErrorParm )
      FETCH_PAYLOAD_CASE( SiPixelFedCablingMap )
      FETCH_PAYLOAD_CASE( SiPixelGainCalibrationForHLT )
      FETCH_PAYLOAD_CASE( SiPixelGainCalibrationOffline )
      FETCH_PAYLOAD_CASE( SiPixelGenErrorDBObject )
      FETCH_PAYLOAD_CASE( SiPixelLorentzAngle )
      FETCH_PAYLOAD_CASE( SiPixelDynamicInefficiency )
      FETCH_PAYLOAD_CASE( SiPixelQuality )
      FETCH_PAYLOAD_CASE( SiPixelTemplateDBObject )
      FETCH_PAYLOAD_CASE( SiPixel2DTemplateDBObject )
      FETCH_PAYLOAD_CASE( SiStripApvGain )
      FETCH_PAYLOAD_CASE( SiStripBackPlaneCorrection )
      FETCH_PAYLOAD_CASE( SiStripBadStrip )
      FETCH_PAYLOAD_CASE( SiStripConfObject )
      FETCH_PAYLOAD_CASE( SiStripDetVOff )
      FETCH_PAYLOAD_CASE( SiStripFedCabling )
      FETCH_PAYLOAD_CASE( SiStripLatency )
      FETCH_PAYLOAD_CASE( SiStripLorentzAngle )
      FETCH_PAYLOAD_CASE( SiStripNoises )
      FETCH_PAYLOAD_CASE( SiStripPedestals )
      FETCH_PAYLOAD_CASE( SiStripThreshold )
      FETCH_PAYLOAD_CASE( TrackProbabilityCalibration )
      FETCH_PAYLOAD_CASE( cond::BaseKeyed )
      FETCH_PAYLOAD_CASE( ESCondObjectContainer<ESChannelStatusCode> )
      FETCH_PAYLOAD_CASE( ESCondObjectContainer<ESPedestal> )
      FETCH_PAYLOAD_CASE( ESCondObjectContainer<float> )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalChannelStatusCode> )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalMGPAGainRatio> )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalTPGPedestal> )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<EcalXtalGroupId> )
      FETCH_PAYLOAD_CASE( EcalCondObjectContainer<float> )
      FETCH_PAYLOAD_CASE( MagFieldConfig )

      //   
      if( payloadTypeName == "PhysicsTools::Calibration::Histogram3D<double,double,double,double>" ){    
	auto payload = deserialize<PhysicsTools::Calibration::Histogram3D<double,double,double,double> >(payloadTypeName, data, streamerInfo );
	payloadPtr = payload;
	match = true;
      }
      if( payloadTypeName == "PhysicsTools::Calibration::Histogram2D<double,double,double>" ){    
	auto payload = deserialize<PhysicsTools::Calibration::Histogram2D<double,double,double> >(payloadTypeName, data, streamerInfo );
	payloadPtr = payload;
	match = true;
      }
      if( payloadTypeName == "std::vector<unsignedlonglong,std::allocator<unsignedlonglong>>" ){
	auto payload = deserialize<std::vector<unsigned long long> >( payloadTypeName, data, streamerInfo );
	payloadPtr = payload;
	match = true;
      }
  
      if( ! match ) throwException( "Payload type \""+payloadTypeName+"\" is unknown.","fetch" );
      return std::make_pair( payloadTypeName, payloadPtr );
    }

    std::pair<std::string,boost::shared_ptr<void> > fetch( const cond::Hash& payloadId, Session& session ){
      boost::shared_ptr<void> payloadPtr;
      cond::Binary data;
      cond::Binary streamerInfo;
      std::string payloadTypeName;
      bool found = session.fetchPayloadData( payloadId, payloadTypeName, data, streamerInfo );
      if( !found ) throwException( "Payload with id "+boost::lexical_cast<std::string>(payloadId)+" has not been found in the database.","fetch" );
      return fetchOne(payloadTypeName, data, streamerInfo, payloadPtr );
    }

 }
}

