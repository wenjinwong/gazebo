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
#ifndef _GAZEBO_GUI_CONVERSIONS_HH_
#define _GAZEBO_GUI_CONVERSIONS_HH_

#include "gazebo/gui/qt.h"

#include "gazebo/util/system.hh"

namespace gazebo
{
  namespace common
  {
    class Color;
  }

  namespace gui
  {
    /// \addtogroup gazebo_gui
    /// \{

    /// \brief Conversions Conversions.hh gui/Conversions.hh
    /// \brief A set of utility function to convert between Gazebo and Qt
    /// data types
    class GZ_GUI_VISIBLE Conversions
    {
      /// \brief Return the equivalent qt color
      /// \param[in] _color Gazebo color to convert
      /// \return Qt color value
      public: static QColor Convert(const common::Color &_color);

      /// \brief Return the equivalent gazebo color
      /// \param[in] _color Qt color to convert
      /// \return Gazebo color value
      public: static common::Color Convert(const QColor &_color);
    };
    /// \}
  }
}
#endif