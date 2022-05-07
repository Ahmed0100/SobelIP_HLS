#include "hls_video.h"
#include <ap_fixed.h>

#define MAX_WIDTH 320
#define MAX_HEIGHT 240
typedef hls::stream<ap_axiu<32,1,1,1> > AXI_STREAM;

typedef hls::Mat<MAX_HEIGHT, MAX_WIDTH,HLS_8UC3> RGB_IMG;
typedef hls::Mat<MAX_HEIGHT,MAX_WIDTH,HLS_8UC1> GRAY_IMG;

void sobel(AXI_STREAM& inStream,AXI_STREAM& outStream);
