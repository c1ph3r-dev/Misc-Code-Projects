#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudafilters.hpp>
#include <opencv2/cudabgsegm.hpp>
#include <opencv2/cudacodec.hpp>
#include <opencv2/cudaobjdetect.hpp>
#include <opencv2/cudaoptflow.hpp>
#include <opencv2/cudastereo.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/cudafeatures2d.hpp>

void gpu_prog(cv::Mat& img)
{
    using namespace cv;

    cuda::GpuMat imgGpu;
    std::vector<cuda::GpuMat> gpuMats;
    cuda::GpuMat mat;

    imgGpu.upload(img);

    /// Core operations
    cuda::cvtColor(imgGpu, imgGpu, COLOR_BGR2GRAY);
    //cuda::transpose(imgGpu, imgGpu);

    //cuda::split(imgGpu, gpuMats);
	
	// Do the operations on the individual channels

    //cuda::merge(gpuMats, imgGpu);

    /// Elements wise operations
    //cuda::threshold(imgGpu, imgGpu, 100.0, 255.0, THRESH_BINARY);

	/// Matrix operations
    //cuda::normalize(imgGpu, imgGpu, 0, 1, NORM_MINMAX, CV_32F);

	/// Image filtering
    //auto gaussianFiler = cuda::createGaussianFilter(CV_8UC1, CV_8UC1, { 3,3 }, 1);
	//gaussianFiler->apply(imgGpu, imgGpu);

    //auto laplacianFilter = cuda::createLaplacianFilter(CV_8UC1, CV_8UC1, 3, 3);
    //laplacianFilter->apply(imgGpu, imgGpu);

    auto morphFilter = cuda::createMorphologyFilter(MORPH_CLOSE, CV_8UC1, 9);
    morphFilter->apply(imgGpu, imgGpu);

    imgGpu.download(img);
}

int main()
{
    cv::VideoCapture cap(0);

    // Print GPU info
    cv::cuda::printCudaDeviceInfo(0);

    while (cap.isOpened())
    {   
        cv::Mat image;
        auto isSuccess = cap.read(image);

        auto start = cv::getTickCount();
        gpu_prog(image);
        auto end = cv::getTickCount();

        auto totalTime = (end - start) / cv::getTickFrequency();
        auto fps = 1 / totalTime;
        std::cout << "FPS: " << fps << std::endl;

        cv::putText(image, "FPS: " + std::to_string(int(fps)), cv::Point(50, 50), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255, 0));
        cv::imshow("Image", image);

        if (cv::waitKey(1) == 'q')
            break;
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}

