//
// Created by obelekhov on 1/03/2019.
//

#pragma once

#include "Headers.h"


//базовый класс для всех ресурсов в движке
//его переопределяют как шейдеры, текстуры,  и мэш
//класс взаимодействует с DXResurceLoadManager
//в котором проверяет, была ли загрузка по указанному пути
//произведена ранее
class DXResurce
{
public:

	DXResurce();
	virtual ~DXResurce() = default;

	inline std::string GetName() const;
	bool CheckLoadResurce(std::string path,  DXResurce** OutRefResurce);
	bool RegisterResurce(std::string path);

private:

	bool SetName(std::string sname);
	std::string m_resurce_name;
};


