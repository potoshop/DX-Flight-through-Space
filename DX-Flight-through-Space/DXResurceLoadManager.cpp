//
// Created by obelekhov on 1/03/2019.
//

#include "DXResurceLoadManager.h"
#include "DXResurce.h"

DXResurceLoadManager&  DXResurceLoadManager::Get() noexcept
{
    static DXResurceLoadManager Resource;
    return Resource;
}

bool DXResurceLoadManager::CheckLoadResurce (const std::string sIndex, DXResurce ** OutResurce) noexcept
{
    std::map <std::string, DXResurce*> ::iterator it;
    it = m_file_storage.find(sIndex);

    if (it != m_file_storage.end())
    {
        *OutResurce = it->second;
        return true;
    }


    return true;
}

bool DXResurceLoadManager::AddLoadResurce(const std::string ResurceName, DXResurce* dxResurce) noexcept
{
   m_file_storage.insert(std::make_pair(ResurceName, dxResurce));
   return true;
}
