//
// Created by obelekhov on 1/03/2019.
//

#pragma once

#include <map>
#include "Headers.h"

class DXResurce;

//ResurceLoadManager контролирует
//какие ресурсы уже были загружены.
//В случаи обращения к ресурсам которые
//уже созданы, он отдает на них ссылку.
class DXResurceLoadManager
{
public:
    virtual ~DXResurceLoadManager () = default;
private:
    DXResurceLoadManager() = default;
    DXResurceLoadManager(const DXResurceLoadManager&) = delete;

public:

    inline  static DXResurceLoadManager& Get() noexcept;
    virtual bool CheckLoadResurce(const std::string, DXResurce**)noexcept;
    virtual bool AddLoadResurce(const std::string ResurceName,  DXResurce* dxResurce)noexcept;

private:

    std::map<std::string, DXResurce*> m_file_storage;


};


