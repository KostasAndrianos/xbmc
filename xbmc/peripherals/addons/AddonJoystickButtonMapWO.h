/*
 *      Copyright (C) 2014-2015 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "addons/include/kodi_peripheral_types.h"
#include "input/joysticks/JoystickDriverPrimitive.h"
#include "input/joysticks/JoystickTypes.h"
#include "peripherals/addons/PeripheralAddon.h"

#include <string>

namespace PERIPHERALS
{
  class CAddonJoystickButtonMapWO
  {
  public:
    CAddonJoystickButtonMapWO(CPeripheral* device, const PeripheralAddonPtr& addon, const std::string& strControllerId);

    virtual ~CAddonJoystickButtonMapWO(void) { }

    std::string ControllerID(void) const { return m_strControllerId; }
    bool Load(void);
    bool AddPrimitiveFeature(const JoystickFeature& feature, const CJoystickDriverPrimitive& primitive);
    bool AddAnalogStick(const JoystickFeature& feature, const CJoystickDriverPrimitive& up,
                                                        const CJoystickDriverPrimitive& down,
                                                        const CJoystickDriverPrimitive& right,
                                                        const CJoystickDriverPrimitive& left);
    bool AddAccelerometer(const JoystickFeature& feature, const CJoystickDriverPrimitive& positiveX,
                                                          const CJoystickDriverPrimitive& positiveY,
                                                          const CJoystickDriverPrimitive& positiveZ);

  private:
    // Utility functions
    static ADDON::DriverPrimitive             ToPrimitive(const CJoystickDriverPrimitive& primitive);
    static JOYSTICK_DRIVER_HAT_DIRECTION      ToHatDirection(HAT_DIRECTION dir);
    static JOYSTICK_DRIVER_SEMIAXIS_DIRECTION ToSemiAxisDirection(SEMIAXIS_DIRECTION dir);

    CPeripheral* const m_device;
    PeripheralAddonPtr m_addon;
    const std::string  m_strControllerId;
  };
}
