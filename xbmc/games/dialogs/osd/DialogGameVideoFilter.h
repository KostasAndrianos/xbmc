/*
 *  Copyright (C) 2017-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "DialogGameVideoSelect.h"
#include "cores/GameSettings.h"
#include "FileItem.h"

class TiXmlNode;

namespace KODI
{
namespace GAME
{
  class CDialogGameVideoFilter : public CDialogGameVideoSelect
  {
  public:
    CDialogGameVideoFilter();
    ~CDialogGameVideoFilter() override = default;

  protected:
    // implementation of CDialogGameVideoSelect
    std::string GetHeading() override;
    void PreInit() override;
    void GetItems(CFileItemList &items) override;
    void OnItemFocus(unsigned int index) override;
    unsigned int GetFocusedItem() const override;
    void PostExit() override;

  private:
    void InitVideoFilters();

    static bool IsCompatible(const TiXmlNode* presetNode);

    static std::string GetLocalizedString(uint32_t code);
    static void GetProperties(const CFileItem &item, std::string &videoFilter, std::string &description);

    struct ShaderPresetProperties
    {
      std::string path;
      int nameIndex;
      int categoryIndex;
      int descriptionIndex;
    };

    CFileItemList m_items;

    //! \brief Set to true when a description has first been set
    bool m_bHasDescription = false;
  };
}
}
