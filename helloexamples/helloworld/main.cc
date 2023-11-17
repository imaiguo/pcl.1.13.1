#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/common/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>


using namespace std;
using namespace pcl;

void viewerOneOff(visualization::PCLVisualizer& viewer) {
	viewer.setBackgroundColor(0, 0, 0); //设置背景颜色为黑色
}

int main() {
	PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>);

	char strfilepath[256] = "milk.pcd";
	if (-1 == io::loadPCDFile(strfilepath, *cloud)) {
		cout << "error input!" << endl;
		return -1;
	}

	cout << "points.size:[" << cloud->points.size() << "]." << endl;
	visualization::CloudViewer viewer("Cloud Viewer: Rabbit");

	viewer.showCloud(cloud);
	viewer.runOnVisualizationThreadOnce(viewerOneOff);
	system("pause");
	return 0;
}
