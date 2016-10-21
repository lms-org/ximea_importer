#ifndef XIMEA_IMPORTER_H
#define XIMEA_IMPORTER_H

#include <lms/module.h>
#ifdef WIN32
#include "xiApi.h"       // Windows
#else
#include <m3api/xiApi.h> // Linux, OSX
#endif
#include <memory.h>
#include <lms/imaging/image.h>

/**
 * @brief LMS module ximea_importer
 **/
class XimeaImporter : public lms::Module {
public:
    bool initialize() override;
    bool deinitialize() override;
    bool cycle() override;
    void configsChanged() override;

private:
    lms::WriteDataChannel<lms::imaging::Image> myImage;

HANDLE xiH;
XI_RETURN stat;
XI_IMG image;
};

#endif // XIMEA_IMPORTER_H
