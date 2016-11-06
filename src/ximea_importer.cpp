#include "ximea_importer.h"


#define HandleResult(res,place) if (res!=XI_OK) {logger.error("Error after: ")<<place<<" "<<res;}


//TODO https://www.ximea.com/support/wiki/apis/XiApi_Manual
//Taken from the xiExample
bool XimeaImporter::initialize() {
    myImage = writeChannel<lms::imaging::Image>("IMAGE");
    // image buffer
    memset(&image,0,sizeof(image));
    image.size = sizeof(XI_IMG);

    // Sample for XIMEA API V4.05
    XI_RETURN stat = XI_OK;

    // Retrieving a handle to the camera device
    logger.debug("Opening camera");
    stat = xiOpenDevice(0, &xiH);
    logger.debug("Opening camera 1");
    HandleResult(stat,"xiOpenDevice");
    logger.debug("Opening camera 2");

    logger.debug("Setting parameters");
    configsChanged();
    logger.debug("Starting acquisition...");
    stat = xiStartAcquisition(xiH);
    HandleResult(stat,"xiStartAcquisition");
    return true;
}

void XimeaImporter::configsChanged(){
    // Setting "exposure" parameter (10ms=10000us)
    stat = xiSetParamInt(xiH, XI_PRM_EXPOSURE, config().get<int>("exposure",10000));
    HandleResult(stat,"xiSetParam (exposure set)");
    stat = xiSetParamInt(xiH,XI_PRM_GAIN,config().get<int>("gain",2));
    HandleResult(stat,"xiSetParam (XI_PRM_GAIN set)");
    stat = xiSetParamInt(xiH,XI_PRM_IMAGE_DATA_FORMAT,XI_MONO8);
    HandleResult(stat,"xiSetParam (XI_PRM_IMAGE_DATA_FORMAT set)");
    stat = xiSetParamInt(xiH,XI_PRM_AUTO_WB,1);
    HandleResult(stat,"xiSetParam (XI_PRM_AUTO_WB set)");
    stat = xiSetParamInt(xiH,XI_PRM_FRAMERATE,config().get<int>("fps",100));
    HandleResult(stat,"xiSetParam (XI_PRM_FRAMERATE set)");
}

bool XimeaImporter::deinitialize() {
    logger.debug("Stopping acquisition...\n");
    xiStopAcquisition(xiH);
    xiCloseDevice(xiH);
    return true;
}

bool XimeaImporter::cycle() {
    // getting image from camera
    stat = xiGetImage(xiH, 5000, &image);
    HandleResult(stat,"xiGetImage");
    if(stat!= XI_OK){
        logger.error("failed to collect image");
        return false;
    }

    myImage->resize(image.width,image.height,lms::imaging::Format::GREY);
    myImage->fill(255);
    memcpy(myImage->data(),image.bp,myImage->size());
    return true;
}
