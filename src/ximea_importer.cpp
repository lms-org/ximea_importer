#include "ximea_importer.h"


#define HandleResult(res,place) if (res!=XI_OK) {logger.error("Error after: ")<<place<<" "<<res;}

//#include <usb.h>
//#include <unistd.h>

bool is_XIMEAcam(uint16_t idVendor, uint16_t idProduct) {
    if(idVendor == 0x04B4 && (idProduct == 0x00F0 || idProduct == 0x00F1 || idProduct == 0x00F2 || idProduct == 0x00F3 || idProduct == 0x8613)
            || idVendor == 0x20F7 && (idProduct == 0x3000 || idProduct == 0x3001 || idProduct == 0xA003)
            || idVendor == 0xDEDA && idProduct == 0xA003)
        return true;
    else
        return false;
}

void try2reset() {
    /*TODO
    libusb_context *ctx;
    if(libusb_init(&ctx)) return;
    libusb_device **list;
    libusb_device_handle *handle;
    libusb_device_descriptor desc;
    ssize_t i, cnt = libusb_get_device_list(ctx, &list);
    for(i = 0; i < cnt; i++) {
        if(libusb_get_device_descriptor(list[i], &desc)) continue;
        if(!is_XIMEAcam(desc.idVendor, desc.idProduct)) continue;
        if(libusb_open(list[i], &handle)) continue;
        libusb_reset_device(handle);
        libusb_close(handle);
    }
    if(cnt >= 0)
        libusb_free_device_list(list, 1);
    libusb_exit(ctx);
    */
}
//TODO https://www.ximea.com/support/wiki/apis/XiApi_Manual
//Taken from the xiExample
bool XimeaImporter::initialize() {
    myImage = writeChannel<lms::imaging::Image>("IMAGE");
    // image buffer
    memset(&image,0,sizeof(image));
    image.size = sizeof(XI_IMG);

    //try to reset, from https://www.ximea.com/support/wiki/apis/Linux_SP_Knowledge_Base
    try2reset();
    // Sample for XIMEA API V4.05
    XI_RETURN stat = XI_OK;

    // Retrieving a handle to the camera device
    logger.debug("Opening camera");
    stat = xiOpenDevice(0, &xiH);
    HandleResult(stat,"xiOpenDevice");
    if(stat != XI_OK){
        return false;
    }
    logger.debug("Opening camera 2");

    logger.debug("Setting parameters");
    configsChanged();
    logger.debug("Starting acquisition...");
    stat = xiStartAcquisition(xiH);
    HandleResult(stat,"xiStartAcquisition");
    return stat==XI_OK;
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
        logger.error("failed to collect image")<<"trying to reconnect!";
        try2reset();
        deinitialize();
        initialize();
        return false;
    }

    myImage->resize(image.width,image.height,lms::imaging::Format::GREY);
    myImage->fill(255);
    memcpy(myImage->data(),image.bp,myImage->size());
    return true;
}
