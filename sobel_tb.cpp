#include <hls_opencv.h>
#include "sobel.h"
int main()
{
	IplImage *src;
	IplImage *dst;
	AXI_STREAM src_axi;
	AXI_STREAM dst_axi;
	src = cvLoadImage("lena.bmp");
	dst = cvCreateImage(cvGetSize(src),src->depth,src->nChannels);
	IplImage2AXIvideo(src,src_axi);
	sobel(src_axi,dst_axi);
	AXIvideo2IplImage(dst_axi,dst);
	cvSaveImage("lena_out.bmp",dst);
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	return 0;
}
