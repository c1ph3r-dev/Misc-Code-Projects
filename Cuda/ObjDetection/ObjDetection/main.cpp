#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>

using namespace cv;
using namespace dnn;

int main(int argc, char** argv)
{
	using namespace std;

	string file_path = "G:/Dev/Cuda/ObjDetection/data";
	vector<string> class_names;
	ifstream ifs(string(file_path + "object_detection_classes_coco.txt").c_str());
	string line;

	// Load in all the classes from the file
	while (getline(ifs, line))
	{
		cout << line << endl;
		class_names.push_back(line);
	}

	// Read in the neural network from the files
	auto net = readNet(file_path + "frozen_inference_graph.pb", file_path + "ssd_mobilenet_v2_coco_2018_03_29.pbtxt.txt", "TensorFlow");
}
