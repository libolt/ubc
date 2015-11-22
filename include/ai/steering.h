/***************************************************************************
 *   Copyright (C) 1999 - 2015 by Mike McLean   *
 *   libolt@libolt.net   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _STEERING_H_
#define _STEERING_H_

#include "OpenSteer/AbstractVehicle.h"
#include "OpenSteer/Annotation.h"

#include "OpenSteer/SteerLibrary.h"
#include "OpenSteer/Color.h"
#include "OpenSteer/PlugIn.h"
#include "OpenSteer/UnusedParameter.h"
#include "OpenSteer/Utilities.h"

#include "Ogre.h"

typedef OpenSteer::LocalSpaceMixin<OpenSteer::AbstractVehicle> steering_1;
typedef OpenSteer::SteerLibraryMixin<steering_1> steering_2;

class steering : public steering_2
{
public:

    // a box object for the field and the goals.
    class AABBox{
    public:
        AABBox(OpenSteer::Vec3 &min, OpenSteer::Vec3& max): m_min(min), m_max(max){}
        AABBox(OpenSteer::Vec3 min, OpenSteer::Vec3 max): m_min(min), m_max(max){}

		OpenSteer::Vec3 getMin()
		{
			return (m_min);
		}
		void setMin(OpenSteer::Vec3 min)
		{
			m_min = min;
		}

		OpenSteer::Vec3 getMax()
		{
			return (m_max);
		}
		void setMax(OpenSteer::Vec3 max)
		{
			m_max = max;
		}

        bool	InsideX(const OpenSteer::Vec3 p){if(p.x < m_min.x || p.x > m_max.x)	return false;return true;}
        bool	InsideZ(const OpenSteer::Vec3 p){if(p.z < m_min.z || p.z > m_max.z)	return false;return true;}
/*        void	draw(){
            Vec3 b,c;
            b = Vec3(m_min.x, 0, m_max.z);
            c = Vec3(m_max.x, 0, m_min.z);
            Color color(1.0f,1.0f,0.0f);
            drawLineAlpha(m_min, b, color, 1.0f);
            drawLineAlpha(b, m_max, color, 1.0f);
            drawLineAlpha(m_max, c, color, 1.0f);
            drawLineAlpha(c,m_min, color, 1.0f);
        }*/

    private:
        OpenSteer::Vec3 m_min;
        OpenSteer::Vec3 m_max;
    };
	// constructor
	steering();

	// destructor
	~steering();

	// sets up steering state
	void setup(void);

	// reset vehicle state
	void reset(void)
	{
		// reset LocalSpace state
		resetLocalSpace();

		// reset SteerLibraryMixin state
		// (XXX this seems really fragile, needs to be redesigned XXX)
		steering_2::reset();

		setMass(1);          // mass (defaults to 1 so acceleration=force)
		setSpeed (0);         // speed along Forward direction.

		setRadius (0.5f);     // size of bounding sphere

		setMaxForce (0.1f);   // steering force is clipped to this magnitude
		setMaxSpeed (1.0f);   // velocity is clipped to this magnitude

		// reset bookkeeping to do running averages of these quanities
		resetSmoothedPosition ();
		resetSmoothedCurvature ();
		resetSmoothedAcceleration ();
	}

	// get/set mass
	float mass (void) const {return _mass;}
	float setMass (float m) {return _mass = m;}

	// get velocity of vehicle
	OpenSteer::Vec3 velocity (void) const {return forward() * _speed;}

	// get/set speed of vehicle  (may be faster than taking mag of velocity)
	float speed (void) const {return _speed;}
	float setSpeed (float s) {return _speed = s;}

	// size of bounding sphere, for obstacle avoidance, etc.
	float radius (void) const {return _radius;}
	float setRadius (float m) {return _radius = m;}

	// get/set maxForce
	float maxForce (void) const {return _maxForce;}
	float setMaxForce (float mf) {return _maxForce = mf;}

	// get/set maxSpeed
	float maxSpeed (void) const {return _maxSpeed;}
	float setMaxSpeed (float ms) {return _maxSpeed = ms;}


	// apply a given steering force to our momentum,
	// adjusting our orientation to maintain velocity-alignment.
	void applySteeringForce (const OpenSteer::Vec3& force, const float deltaTime);

	// the default version: keep FORWARD parallel to velocity, change
	// UP as little as possible.
    void regenerateLocalSpace (const OpenSteer::Vec3& newVelocity,
									   const float elapsedTime);

	// alternate version: keep FORWARD parallel to velocity, adjust UP
	// according to a no-basis-in-reality "banking" behavior, something
	// like what birds and airplanes do.  (XXX experimental cwr 6-5-03)
	void regenerateLocalSpaceForBanking (const OpenSteer::Vec3& newVelocity,
										 const float elapsedTime);

	// adjust the steering force passed to applySteeringForce.
	// allows a specific vehicle class to redefine this adjustment.
	// default is to disallow backward-facing steering at low speed.
	// xxx experimental 8-20-02
    OpenSteer::Vec3 adjustRawSteeringForce (const OpenSteer::Vec3& force,
										 const float deltaTime);

	// apply a given braking force (for a given dt) to our momentum.
	// xxx experimental 9-6-02
	void applyBrakingForce (const float rate, const float deltaTime);

	// predict position of this vehicle at some time in the future
	// (assumes velocity remains constant)
	OpenSteer::Vec3 predictFuturePosition (const float predictionTime) const;

	// get instantaneous curvature (since last update)
	float curvature (void) {return _curvature;}

	// get/reset smoothedCurvature, smoothedAcceleration and smoothedPosition
	float smoothedCurvature (void) {return _smoothedCurvature;}
	float resetSmoothedCurvature (float value = 0)
	{
		_lastForward = OpenSteer::Vec3::zero;
		_lastPosition = OpenSteer::Vec3::zero;
		return _smoothedCurvature = _curvature = value;
	}
	OpenSteer::Vec3 smoothedAcceleration (void) {return _smoothedAcceleration;}
	OpenSteer::Vec3 resetSmoothedAcceleration (const OpenSteer::Vec3& value = OpenSteer::Vec3::zero)
	{
		return _smoothedAcceleration = value;
	}
	OpenSteer::Vec3 smoothedPosition (void) {return _smoothedPosition;}
	OpenSteer::Vec3 resetSmoothedPosition (const OpenSteer::Vec3& value = OpenSteer::Vec3::zero)
	{
		return _smoothedPosition = value;
	}

	// give each vehicle a unique number
	int serialNumber;
	static int serialNumberCounter;

	// draw lines from vehicle's position showing its velocity and acceleration
	void annotationVelocityAcceleration (float maxLengthA, float maxLengthV);
	void annotationVelocityAcceleration (float maxLength)
		{annotationVelocityAcceleration (maxLength, maxLength);}
	void annotationVelocityAcceleration (void)
		{annotationVelocityAcceleration (3, 3);}

	// set a random "2D" heading: set local Up to global Y, then effectively
	// rotate about it by a random angle (pick random forward, derive side).
	void randomizeHeadingOnXZPlane (void)
	{
		setUp (OpenSteer::Vec3::up);
		setForward (OpenSteer::RandomUnitVectorOnXZPlane ());
		setSide (localRotateForwardToSide (forward()));
	}

private:

	float _mass;       // mass (defaults to unity so acceleration=force)

	float _radius;     // size of bounding sphere, for obstacle avoidance, etc.

	float _speed;      // speed along Forward direction.  Because local space
					   // is velocity-aligned, velocity = Forward * Speed

	float _maxForce;   // the maximum steering force this vehicle can apply
					   // (steering force is clipped to this magnitude)

	float _maxSpeed;   // the maximum speed this vehicle is allowed to move
					   // (velocity is clipped to this magnitude)

	float _curvature;
	OpenSteer::Vec3 _lastForward;
	OpenSteer::Vec3 _lastPosition;
	OpenSteer::Vec3 _smoothedPosition;
	float _smoothedCurvature;
	OpenSteer::Vec3 _smoothedAcceleration;

	// measure path curvature (1/turning-radius), maintain smoothed version
	void measurePathCurvature (const float elapsedTime);
};

#endif

