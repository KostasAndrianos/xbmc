/*
 *      Copyright (C) 2012-2016 Team Kodi
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

#include "GameTypes.h"

#include <set>
#include <string>

class CFileItem;

namespace GAME
{
  class CGameUtils
  {
  public:
    /*!
     * \brief Select a game client, possibly via prompt, for the given game
     *
     * \param file The game being played
     *
     * \return A game client ready to be initialized for playback
     */
    static GameClientPtr OpenGameClient(const CFileItem& file);

    /*!
     * \brief Check if the file extension is supported by an add-on in
     *        a local or remote repository
     *
     * \param path The path of the game file
     *
     * \return true if the path's extension is supported by a known game client
     */
    static bool HasGameExtension(const std::string& path);

    static std::set<std::string> GetGameExtensions();

  private:
    static void GetGameClients(const CFileItem& file, GameClientVector& candidates, GameClientVector& installable);
  };
} // namespace GAME
