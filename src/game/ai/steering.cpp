/***************************************************************************
 *   Copyright (C) 1999 - 2018 by Mike McLean                              *
 *   libolt@libolt.net                                                     *
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

#include "Ogre.h"
#include "ai/steering.h"
#include <algorithm>

// Static Declarations

// int steering::serialNumberCounter = 0;
// float steering::_maxForce;

steering::steering ()  // constructor
{
    _mass = 0.0f;
    _radius = 0.0f;
    _speed = 0.0f;
    _maxForce = 0.0f;
    _maxSpeed = 0.0f;
    _curvature = 0.0f;
    _smoothedCurvature = 0.0f;
    
    // set inital state
    reset ();

    // maintain unique serial numbers
    serialNumber = serialNumberCounter++;
}

steering::~steering ()  // destructor
{
}

float steering::mass () const // retrieves the value of _mass 
{
    return (_mass);
}
float steering::setMass (float m)  // sets the value of _mass 
{
    return (_mass = m);
}

OpenSteer::Vec3 steering::velocity () const  // retrieves the value of steering velocity
{
    return (forward() * _speed);
}

// get/set speed of vehicle  (may be faster than taking mag of velocity)
float steering::speed () const  // retrieves the value of _speed
{
    return (_speed);
}
float steering::setSpeed (float s)  // sets the value of _speed
{
    return (_speed = s);
}

float steering::radius () const  // retrieves the value of _radius
{
    return _radius;
}
float steering::setRadius (float m)  // sets the value of radius
{
    return (_radius = m);
}

float steering::maxForce () const  // retrieves the value of _maxForce
{
    return (_maxForce);
}
float steering::setMaxForce (float mf)  // sets the value of _maxForce 
{
    return (_maxForce = mf);
}
float steering::setMaxForces (float mf)  // sets the value of _maxForce 
{
    return (_maxForces = mf);
}

float steering::maxSpeed () const  // retrieves the value of _maxSpeed
{
    return (_maxSpeed);
}
float steering::setMaxSpeed (const float ms)  // sets the value of _maxSpeed
{
    return (_maxSpeed = ms);
}
    
// get instantaneous curvature (since last update)
float steering::curvature ()
{
    return (_curvature);
}

float steering::smoothedCurvature ()  // retrieves the value of _smoothedCurvature
{
    return (_smoothedCurvature);
}
float steering::resetSmoothedCurvature (float value/* = 0*/) // resets values of _smoothedCurvature
{
    _lastForward = OpenSteer::Vec3::zero;
    _lastPosition = OpenSteer::Vec3::zero;
    return _smoothedCurvature = _curvature = value;
}

OpenSteer::Vec3 steering::smoothedAcceleration ()  // retrieves the value of _smoothedAcceleration
{
    return (_smoothedAcceleration);
}
OpenSteer::Vec3 steering::resetSmoothedAcceleration (const OpenSteer::Vec3& value /*= OpenSteer::Vec3::zero*/)  // resets the value of _smoothedAcceleration
{
    return (_smoothedAcceleration = value);
}

OpenSteer::Vec3 steering::smoothedPosition ()  // retrieves the value of _smoothedPosition
{
    return (_smoothedPosition);
}
OpenSteer::Vec3 steering::resetSmoothedPosition (const OpenSteer::Vec3& value /*= OpenSteer::Vec3::zero*/)  // resets the value of _smoothedPosition
{
    return _smoothedPosition = value;
}

void steering::randomizeHeadingOnXZPlane ()
{
    setUp (OpenSteer::Vec3::up);
    setForward (OpenSteer::RandomUnitVectorOnXZPlane ());
    setSide (localRotateForwardToSide (forward()));
}
    
void steering::reset()
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

// ----------------------------------------------------------------------------
// adjust the steering force passed to applySteeringForce.
//
// allows a specific vehicle class to redefine this adjustment.
// default is to disallow backward-facing steering at low speed.
//
// xxx should the default be this ad-hocery, or no adjustment?
// xxx experimental 8-20-02
//
// parameter names commented out to prevent compiler warning from "-W"


OpenSteer::Vec3 steering::adjustRawSteeringForce (const OpenSteer::Vec3& force, const float /* deltaTime */)
{
    const float maxAdjustedSpeed = 0.2f * maxSpeed ();

    if ((speed () > maxAdjustedSpeed) || (force ==OpenSteer::Vec3::zero))
    {
        return force;
    }
    else
    {
        const float range = speed() / maxAdjustedSpeed;
        // const float cosine = interpolate (pow (range, 6), 1.0f, -1.0f);
        // const float cosine = interpolate (pow (range, 10), 1.0f, -1.0f);
        // const float cosine = interpolate (pow (range, 20), 1.0f, -1.0f);
        // const float cosine = interpolate (pow (range, 100), 1.0f, -1.0f);
        // const float cosine = interpolate (pow (range, 50), 1.0f, -1.0f);
        const float cosine = OpenSteer::interpolate (pow (range, 20), 1.0f, -1.0f);
        return limitMaxDeviationAngle (force, cosine, forward());
    }
}


// ----------------------------------------------------------------------------
// xxx experimental 9-6-02
//
// apply a given braking force (for a given dt) to our momentum.
//
// (this is intended as a companion to applySteeringForce, but I'm not sure how
// well integrated it is.  It was motivated by the fact that "braking" (as in
// "capture the flag" endgame) by using "forward * speed * -rate" as a steering
// force was causing problems in adjustRawSteeringForce.  In fact it made it
// get NAN, but even if it had worked it would have defeated the braking.
//
// maybe the guts of applySteeringForce should be split off into a subroutine
// used by both applySteeringForce and applyBrakingForce?


void steering::applyBrakingForce (const float rate, const float deltaTime)
{
    const float rawBraking = speed () * rate;
    const float clipBraking = ((rawBraking < maxForce ()) ?
                               rawBraking :
                               maxForce ());

    setSpeed (speed () - (clipBraking * deltaTime));
}


// ----------------------------------------------------------------------------
// apply a given steering force to our momentum,
// adjusting our orientation to maintain velocity-alignment.


void steering::applySteeringForce (const OpenSteer::Vec3& force, const float elapsedTime)
{
    const OpenSteer::Vec3 adjustedForce = adjustRawSteeringForce (force, elapsedTime);

    // enforce limit on magnitude of steering force
    const OpenSteer::Vec3 clippedForce = adjustedForce.truncateLength (maxForce ());

    // compute acceleration and velocity
   OpenSteer::Vec3 newAcceleration = (clippedForce / mass());
   OpenSteer::Vec3 newVelocity = velocity();

    // damp out abrupt changes and oscillations in steering acceleration
    // (rate is proportional to time step, then clipped into useful range)
    if (elapsedTime > 0)
    {
        const float smoothRate = OpenSteer::clip (9 * elapsedTime, 0.15f, 0.4f);
        blendIntoAccumulator (smoothRate, newAcceleration, _smoothedAcceleration);
    }

    // Euler integrate (per frame) acceleration into velocity
    newVelocity += _smoothedAcceleration * elapsedTime;

    // enforce speed limit
    newVelocity = newVelocity.truncateLength (maxSpeed ());

    // update Speed
    setSpeed (newVelocity.length());

    // Euler integrate (per frame) velocity into position
    setPosition (position() + (newVelocity * elapsedTime));

    // regenerate local space (by default: align vehicle's forward axis with
    // new velocity, but this behavior may be overridden by derived classes.)
    regenerateLocalSpace (newVelocity, elapsedTime);

    // maintain path curvature information
    measurePathCurvature (elapsedTime);

    // running average of recent positions
    blendIntoAccumulator (elapsedTime * 0.06f, position (), _smoothedPosition);
}


// ----------------------------------------------------------------------------
// the default version: keep FORWARD parallel to velocity, change UP as
// little as possible.
//
// parameter names commented out to prevent compiler warning from "-W"


void steering::regenerateLocalSpace (const OpenSteer::Vec3& newVelocity, const float /* elapsedTime */)
{
    // adjust orthonormal basis vectors to be aligned with new velocity
    if (speed() > 0) regenerateOrthonormalBasisUF (newVelocity / speed());
}


// ----------------------------------------------------------------------------
// alternate version: keep FORWARD parallel to velocity, adjust UP according
// to a no-basis-in-reality "banking" behavior, something like what birds and
// airplanes do

// XXX experimental cwr 6-5-03


void steering::regenerateLocalSpaceForBanking (const OpenSteer::Vec3& newVelocity, const float elapsedTime)
{
    // the length of this global-upward-pointing vector controls the vehicle's
    // tendency to right itself as it is rolled over from turning acceleration
    const OpenSteer::Vec3 globalUp (0, 0.2f, 0);

    // acceleration points toward the center of local path curvature, the
    // length determines how much the vehicle will roll while turning
    const OpenSteer::Vec3 accelUp = _smoothedAcceleration * 0.05f;

    // combined banking, sum of UP due to turning and global UP
    const OpenSteer::Vec3 bankUp = accelUp + globalUp;

    // blend bankUp into vehicle's UP basis vector
    const float smoothRate = elapsedTime * 3;
   OpenSteer::Vec3 tempUp = up();
    blendIntoAccumulator (smoothRate, bankUp, tempUp);
    setUp (tempUp.normalize());

//  annotationLine (position(), position() + (globalUp * 4), gWhite);  // XXX
//  annotationLine (position(), position() + (bankUp   * 4), gOrange); // XXX
//  annotationLine (position(), position() + (accelUp  * 4), gRed);    // XXX
//  annotationLine (position(), position() + (up ()    * 1), gYellow); // XXX

    // adjust orthonormal basis vectors to be aligned with new velocity
    if (speed() > 0) regenerateOrthonormalBasisUF (newVelocity / speed());
}


// ----------------------------------------------------------------------------
// measure path curvature (1/turning-radius), maintain smoothed version


void steering::measurePathCurvature (const float elapsedTime)
{
    if (elapsedTime > 0)
    {
        const OpenSteer::Vec3 dP = _lastPosition - position ();
        const OpenSteer::Vec3 dF = (_lastForward - forward ()) / dP.length ();
        const OpenSteer::Vec3 lateral = dF.perpendicularComponent (forward ());
        const float sign = (lateral.dot (side ()) < 0) ? 1.0f : -1.0f;
        _curvature = lateral.length() * sign;
        OpenSteer::blendIntoAccumulator (elapsedTime * 4.0f, _curvature, _smoothedCurvature);
        _lastForward = forward ();
        _lastPosition = position ();
    }
}


// ----------------------------------------------------------------------------
// draw lines from vehicle's position showing its velocity and acceleration


void steering::annotationVelocityAcceleration (float maxLengthA, float maxLengthV)
{
    const float desat = 0.4f;
    const float aScale = maxLengthA / maxForce ();
    const float vScale = maxLengthV / maxSpeed ();
    const OpenSteer::Vec3& p = position();
    const OpenSteer::Color aColor (desat, desat, 1); // bluish
    const OpenSteer::Color vColor (    1, desat, 1); // pinkish

//FIXME    OpenSteer::AnnotationMixin::annotationLine (p, p + (velocity ()           * vScale), vColor);
//    AnnotationMixin::annotationLine (p, p + (_smoothedAcceleration * aScale), aColor);
}


// ----------------------------------------------------------------------------
// predict position of this vehicle at some time in the future
// (assumes velocity remains constant, hence path is a straight line)
//
// XXX Want to encapsulate this since eventually I want to investigate
// XXX non-linear predictors.  Maybe predictFutureLocalSpace ?
//
// XXX move to a vehicle utility mixin?


OpenSteer::Vec3 steering::predictFuturePosition (const float predictionTime) const
{
    return (position() + (velocity() * predictionTime));
}




