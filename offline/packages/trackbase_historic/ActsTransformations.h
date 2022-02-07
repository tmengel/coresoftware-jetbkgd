#ifndef TRACKRECO_ACTSTRANSFORMATIONS_H
#define TRACKRECO_ACTSTRANSFORMATIONS_H

#include <trackbase/TrkrDefs.h>
#include <trackbase/ActsSurfaceMaps.h>
#include <trackbase/ActsTrackingGeometry.h>

/// Acts includes to create all necessary definitions
#include <Acts/Utilities/BinnedArray.hpp>
#include <Acts/Definitions/Algebra.hpp>
#include <Acts/Utilities/Logger.hpp>

#include <Acts/EventData/MultiTrajectory.hpp>

#include <ActsExamples/EventData/Track.hpp>

#include "SvtxTrack.h"

/// std (and the like) includes
#include <cmath>
#include <iostream>
#include <memory>
#include <utility>

class TrkrCluster;

using Trajectory = Acts::MultiTrajectory;


/**
 * This is a helper class for rotating track covariance matrices to and from
 * the basis that Acts expects. The covariance matrix is nominally given in the
 * global basis (x,y,z,px,py,pz). Acts expects the covariance matrix in a local
 * basis with respect to the given reference point that is provided as an
 * option to the KalmanFitter. 
 */
class ActsTransformations
{
 public:
 ActsTransformations() = default;
    
  /// Rotates an SvtxTrack covariance matrix from (x,y,z,px,py,pz) global
  /// cartesian coordinates to (d0, z0, phi, theta, q/p, time) coordinates for
  /// Acts. The track fitter performs the fitting with respect to the nominal
  /// origin of sPHENIX, so we rotate accordingly
  Acts::BoundSymMatrix rotateSvtxTrackCovToActs(const SvtxTrack *track,
						Acts::GeometryContext geoCtxt) const;
  
  /// Same as above, but rotate from Acts basis to global (x,y,z,px,py,pz)
  Acts::BoundSymMatrix rotateActsCovToSvtxTrack(
                       const ActsExamples::TrackParameters params,
		       Acts::GeometryContext geoCtxt) const;

  void setVerbosity(int verbosity) {m_verbosity = verbosity;}

  void printMatrix(const std::string &message, Acts::BoundSymMatrix matrix) const;

  /// Calculate the DCA for a given Acts fitted track parameters and 
  /// vertex
  void calculateDCA(const ActsExamples::TrackParameters param,
		    Acts::Vector3 vertex,
		    Acts::BoundSymMatrix cov,
		    Acts::GeometryContext geoCtxt,
		    float &dca3Dxy,
		    float &dca3Dz,
		    float &dca3DxyCov,
		    float &dca3DzCov) const;

  void fillSvtxTrackState(const Trajectory& traj, 
			  const size_t &trackTip,
			  SvtxTrack *svtxTrack,
			  Acts::GeometryContext geoContext) const;
  
  Eigen::Matrix<float,3,1> getGlobalPositionF(TrkrCluster* cluster,
					      ActsSurfaceMaps* surfMaps,
					      ActsTrackingGeometry *tGeometry) const;

  Acts::Vector3 getGlobalPosition(TrkrCluster* cluster,
				   ActsSurfaceMaps* surfMaps,
				   ActsTrackingGeometry *tGeometry) const;

  Surface getSurface(TrkrCluster* cluster,
		     ActsSurfaceMaps* surfMaps) const;
  
  Surface getSiliconSurface(TrkrDefs::hitsetkey hitsetkey,
			    ActsSurfaceMaps *maps) const;

  Surface getTpcSurface(TrkrDefs::hitsetkey hitsetkey,
    TrkrDefs::subsurfkey surfkey,
    ActsSurfaceMaps *maps) const;

  Surface getMMSurface(TrkrDefs::hitsetkey hitsetkey,
    ActsSurfaceMaps *maps) const;

  private:
  int m_verbosity = 0;
  

};


#endif
