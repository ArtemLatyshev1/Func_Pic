#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat imlocalbrighten(Mat image)
{
    try
    {
        // ������� ����� ����������� (������)
        Mat new_image1 = Mat::zeros(image.size(), image.type());
        // ��������� � ������ HSV (H - �������� ���, S - ������������, V - �������)
        cv::cvtColor(image, new_image1, COLOR_BGR2HSV_FULL);
        int i, j;
        for (i = 1; i < new_image1.rows; i++)
            for (j = 1; j < new_image1.cols; j++)
            {
                // ������ ������� ��������� ��� ���������, ������� ��������� ���������
                if (new_image1.at<Vec3b>(i, j)[2] < 20)
                {
                    continue;

                }
                else
                {
                    int value = 255 - new_image1.at<Vec3b>(i, j)[2];
                    new_image1.at<Vec3b>(i, j)[2] += value;
                }
            }
        // ��������� � ������ BGR
        cv::cvtColor(new_image1, new_image1, COLOR_HSV2BGR_FULL);
        return new_image1;
    }
    catch(Exception ex)
    {
        cout << ex.msg;
    }
}

int main(int argc, char** argv)
{
    try
    {
        // file_in, file_out - ���� � ������ ����� ��������� ����,
        // ���� ���� ��������� �������� ���� ��������������
        string file_in = "mindal4_nonbg.png";
        string file_out = "mindal4_nonbg_ac.png";

        Mat Im = imread(file_in);

        Mat Ia = imlocalbrighten(Im);
        imshow("In", Im);
        imshow("Out", Ia);
        imwrite(file_out, Ia);
        waitKey();
        return 0;
    }
    catch (Exception ex){
        cout << ex.msg;
    }
}