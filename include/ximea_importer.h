#ifndef XIMEA_IMPORTER_H
#define XIMEA_IMPORTER_H

#include <lms/module.h>
#ifdef WIN32
#include "xiApi.h"       // Windows
#else
#include <m3api/xiApi.h> // Linux, OSX
#endif
#include <memory.h>

/**
 * @brief LMS module ximea_importer
 **/
class XimeaImporter : public lms::Module {
public:
    bool initialize() override;
    bool deinitialize() override;
    bool cycle() override;

private:

HANDLE xiH;
XI_RETURN stat;
XI_IMG image;
};

#endif // XIMEA_IMPORTER_H
