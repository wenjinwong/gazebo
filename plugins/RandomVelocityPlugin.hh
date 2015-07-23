/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef _GAZEBO_RANDOMVELOCITY_PLUGIN_HH_
#define _GAZEBO_RANDOMVELOCITY_PLUGIN_HH_

#include <sdf/sdf.hh>
#include <gazebo/common/UpdateInfo.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/util/system.hh>

namespace gazebo
{
  // Forward declare private data class.
  class RandomVelocityPrivate;

  /// \brief Plugin that applies a random velocity to a linke periodically.
  ///
  /// \verbatim
  ///    <!-- Apply a random velocity to the specified link-->
  ///    <!-- In this example, we move a box around. A key property of the link
  ///         is the frictionless surface -->
  ///    <plugin name="random" filename="libRandomVelocityPlugin.so">
  ///
  ///      <!-- Name of the link in this model that receives the velocity -->
  ///      <link>link</link>
  ///
  ///      <!-- Initial velocity that is applied to the link -->
  ///      <initial_velocity>0 0.5 0</initial_velocity>
  ///
  ///      <!-- Scaling factor that is used to compute a new velocity -->
  ///      <velocity_factor>0.5</velocity_factor>
  ///
  ///      <!-- Time, in seconds, between new velocities -->
  ///      <update_period>5</update_period>
  ///
  ///      <!-- Clamp the Z velocity value to zero. You can also clamp x and
  ///           y values. Clamping is performed before application of
  ///           velocity_factor-->
  ///      <min_z>0</min_z>
  ///      <max_z>0</max_z>
  ///    </plugin>
  /// \endverbatim
  ///
  /// See worlds/random_velocity.world for a complete example.
  class GAZEBO_VISIBLE RandomVelocityPlugin : public ModelPlugin
  {
    /// \brief Constructor.
    public: RandomVelocityPlugin();

    /// \brief Destructor.
    public: ~RandomVelocityPlugin();

    // Documentation inherited
    public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);

    /// \brief Update the plugin once every iteration of simulation.
    /// \param[in] _info World update information.
    private: void Update(const common::UpdateInfo &_info);

    /// \internal
    /// \brief Private data pointer
    private: RandomVelocityPluginPrivate *dataPtr;
  };
}
#endif
