#include "sobel.h"

void sobel(AXI_STREAM& inStream,AXI_STREAM& outStream)
{
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE axis register both port=outStream
#pragma HLS INTERFACE axis register both port=inStream
	RGB_IMG img_0(MAX_HEIGHT,MAX_WIDTH);
	GRAY_IMG img_1(MAX_HEIGHT,MAX_WIDTH);
	GRAY_IMG img_2(MAX_HEIGHT,MAX_WIDTH);
	GRAY_IMG img_2a(MAX_HEIGHT,MAX_WIDTH);
	GRAY_IMG img_2b(MAX_HEIGHT,MAX_WIDTH);
	GRAY_IMG img_3(MAX_HEIGHT,MAX_WIDTH);
	GRAY_IMG img_4(MAX_HEIGHT,MAX_WIDTH);
	GRAY_IMG img_5(MAX_HEIGHT,MAX_WIDTH);
	RGB_IMG img_6(MAX_HEIGHT,MAX_WIDTH);
#pragma HLS DATAFLOW
	hls::AXIvideo2Mat(inStream,img_0);
	hls::CvtColor<HLS_RGB2GRAY>(img_0,img_1);
	hls::GaussianBlur<3,3>(img_1,img_2);
	hls::Duplicate(img_2,img_2a,img_2b);
	hls::Sobel<1,0,3>(img_2a,img_3);
	hls::Sobel<0,1,3>(img_2b,img_4);
	hls::AddWeighted(img_4,0.5,img_3,0.5,0.0,img_5);
	hls::CvtColor<HLS_GRAY2RGB>(img_5,img_6);
	hls::Mat2AXIvideo(img_6,outStream);

}
