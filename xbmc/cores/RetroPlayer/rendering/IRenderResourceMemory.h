/*
 *      Copyright (C) 2018 Team Kodi
 *      http://kodi.tv
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
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "IRenderResource.h"

#include <stddef.h>
#include <stdint.h>

namespace KODI
{
namespace RETRO
{
  class IRenderResourceMemory : public IRenderResource
  {
  public:
    ~IRenderResourceMemory() override = default;

    virtual uint8_t *GetMemory() = 0;
    virtual size_t GetSize() const = 0;
    virtual void ReleaseMemory() = 0;
  };
}
}
