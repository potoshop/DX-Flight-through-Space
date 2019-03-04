//
// Created by obelekhov on 1/03/2019.
//

#include "DXResurce.h"
#include "DXResurceLoadManager.h"

DXResurce::DXResurce()
{
	m_resurce_name.clear();
}

inline std::string DXResurce::GetName() const
{
	return std::move(m_resurce_name);
}

bool DXResurce::CheckLoadResurce(std::string path, DXResurce** OutRefResurce)
{
	return DXResurceLoadManager::Get().CheckLoadResurce(path, OutRefResurce) ? true : false;
}

bool DXResurce::RegisterResurce(std::string path)
{
	if (!SetName(path))
	{
		return false;
	}

	if (!DXResurceLoadManager::Get().AddLoadResurce(std::move(m_resurce_name), this))
	{
		return false;
	}

	return true;
}

bool DXResurce::SetName(std::string sname)
{
	if (!m_resurce_name.empty() && !sname.empty())
	{
		m_resurce_name = sname;
		return true;
	}
	
	return false;
}
