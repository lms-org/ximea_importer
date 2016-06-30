#include "ximea_importer.h"


#define HandleResult(res,place) if (res!=XI_OK) {printf("Error after %s (%d)",place,res);}


//TODO https://www.ximea.com/support/wiki/apis/XiApi_Manual
//Taken from the xiExample
bool XimeaImporter::initialize() {
    myImage = writeChannel<lms::imaging::Image>("IMAGE");
    // image buffer
        memset(&image,0,sizeof(image));
        image.size = sizeof(XI_IMG);

        // Sample for XIMEA API V4.05
        HANDLE xiH = NULL;
        XI_RETURN stat = XI_OK;

        // Retrieving a handle to the camera device
        printf("Opening first camera...\n");
        stat = xiOpenDevice(0, &xiH);
        HandleResult(stat,"xiOpenDevice");

        // Setting "exposure" parameter (10ms=10000us)
        stat = xiSetParamInt(xiH, XI_PRM_EXPOSURE, 10000);
        HandleResult(stat,"xiSetParam (exposure set)");

        // Note:
        // The default parameters of each camera might be different in different API versions
        // In order to ensure that your application will have camera in expected state,
        // please set all parameters expected by your application to required value.

        printf("Starting acquisition...\n");
        stat = xiStartAcquisition(xiH);
        HandleResult(stat,"xiStartAcquisition");
    return true;
}

bool XimeaImporter::deinitialize() {
    printf("Stopping acquisition...\n");
    xiStopAcquisition(xiH);
    xiCloseDevice(xiH);
    return true;
}

bool XimeaImporter::cycle() {

    // getting image from camera
    stat = xiGetImage(xiH, 5000, &image);
    HandleResult(stat,"xiGetImage");
    unsigned char pixel = *(unsigned char*)image.bp;
    printf("Image %d (%dx%d) received from camera. First pixel value: %d\n", cycleCounter(), (int)image.width, (int)image.height, pixel);
    return true;
}
