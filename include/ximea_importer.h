#ifndef XIMEA_IMPORTER_H
#define XIMEA_IMPORTER_H

#include <lms/module.h>

/**
 * @brief LMS module ximea_importer
 **/
class XimeaImporter : public lms::Module {
public:
    bool initialize() override;
    bool deinitialize() override;
    bool cycle() override;
};

#endif // XIMEA_IMPORTER_H
