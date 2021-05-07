//#include "opencv.hpp"                                                                                  
//#include "imgproc.hpp"
//#include "highgui.hpp"
//#include "iostream"
//#include "core.hpp"
//
//using namespace cv;
//using namespace std;
//
//int Otsu(Mat srcimage);           //一维Otsu算法
//int main()
//{
//	Mat srcimage, grayimage, dstimage;
//	srcimage = imread("D://test//456.jpg");
//	namedWindow("原图", 0);
//	imshow("王涵情的王冰冰", srcimage);                                            //显示原图
//	cvtColor(srcimage, grayimage, COLOR_RGB2GRAY);                         //得到灰度图
//	//imshow("灰度图", grayimage);
//	double time0 = static_cast<double>(getTickCount());                    //记录程序开始时间
//	int thresholdValue = Otsu(grayimage);                                  //调用Otsu函数
//	time0 = ((double)getTickCount() - time0) / getTickFrequency();
//	cout << "算法运行时间为：" << time0 << endl;
//	cout << "Otsu阈值为：" << thresholdValue << endl;
//	threshold(grayimage, dstimage, thresholdValue, 255, THRESH_BINARY);    //将得到的阈值传入函数，得到分割效果图
//	namedWindow("Otsu算法结果", 0);
//	imshow("王涵情的王冰冰", dstimage);
//	waitKey();
//	return 0;
//}
////一维Otsu算法
//int Otsu(Mat srcimage)
//{
//	if (srcimage.channels() != 1)  //图片的通道数为1，即灰度图片
//	{
//		cout << "请输入灰度图片" << endl;
//		return 0;
//	}
//	int height = srcimage.rows;    //rows为图片的行数，相当于高度，对应.y
//	int width = srcimage.cols;     //cols为图片的列数，相当于宽度，对应.x
//	long number = height * width;    //像素总数
//	int T = 0;                     //Otsu算法阈值
//	double varValue = 0;           //类间方差中间值
//	double w1 = 0;                 //前景像素点所占比例
//	double w2 = 0;                 //背景像素点所占比例
//	double u1 = 0;                 //前景平均灰度
//	double u2 = 0;                 //背景平均灰度
//	int Histogram[256] = { 0 };    //灰度直方图，下标是灰度值，保存内容是灰度值对应的像素点总数。
//	uchar* data = srcimage.data;
//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//		{
//			Histogram[data[i * srcimage.step + j]]++;//step指向每行的字节总量，date访问每个像素的值
//		}
//	}
//	for (int i = 1; i < 255; i++)//从1开始遍历，寻找最合适的值
//	{
//		//每次遍历前需要初始化各变量
//		w1 = 0; u1 = 0; w2 = 0; u2 = 0;
//		for (int j = 0; j <= i; j++)//背景部分各值计算  
//		{
//			w1 += Histogram[j];    //背景部分像素点总数  
//			u1 += j * Histogram[j];  //背景部分像素总灰度和  
//		}
//		u1 = u1 / w1;              //背景像素平均灰度
//		w1 = w1 / number;          //背景部分像素点所占比例
//		for (int k = i + 1; k < 255; k++)
//		{
//			w2 += Histogram[k];    //前景部分像素点总数
//			u2 += k * Histogram[k];  //前景部分像素总灰度和
//		}
//		u2 = u2 / w2;              //前景像素平均灰度
//		w2 = w2 / number;          //前景部分像素所占比例
//		//类间方差计算
//		double varValueI = w1 * w2 * (u1 - u2) * (u1 - u2);
//		if (varValueI > varValue)
//		{
//			varValue = varValueI;
//			T = i;
//		}
//	}
//	cout << T << endl;
//	return T;
//}




