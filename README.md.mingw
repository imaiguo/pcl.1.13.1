
# PCL

## Mingw64环境编译

依赖

1. Eigen 不需要编译, 只使用头文件

在cmake参数中添加
```bash
> -DEIGEN_INCLUDE_DIR=D:/devtools/elgen.3.4.0/include/eigen3
```

2. FLANN

```bash
> set PKG_CONFIG_PATH=D:/devtools/flann.1.9.2/lib/pkgconfig;D:\devtools\lz4.1.9.4\lib\pkgconfig;%PKG_CONFIG_PATH%
```

3. boost-1_82

提示找不到boost库, 可以在cmake 后面添加-DBoost_DEBUG=ON标记 打印详细信息

```bash
> -DBOOST_ROOT=D:/devtools/boost.1.82.0
```

4. VTK

```bash
> -DVTK_DIR=D:\devtools\VTK.9.3.0\lib\cmake\vtk-9.3
```

5. Qhull

```bash
> -DQhull_DIR=D:\devtools\QHULL.8.0.2\lib\cmake\Qhull
```


6. OpenNI2

not install

编译
```bash
> mingw64qt
> mkdir build & cd build
> set PKG_CONFIG_PATH=D:/devtools/flann.1.9.2/lib/pkgconfig;D:\devtools\lz4.1.9.4\lib\pkgconfig;%PKG_CONFIG_PATH%
>
```

Release 编译
```
> cmake .. -G "MinGW Makefiles"  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=D:\devtools\pcl.1.13.1 -DEIGEN_INCLUDE_DIR=D:/devtools/eigen.3.4.0/include/eigen3 -DBOOST_ROOT=D:/devtools/boost.mingw64.1.82.0 -DVTK_DIR=D:\devtools\VTK.9.3.0\lib\cmake\vtk-9.3 -DQhull_DIR=D:\devtools\QHULL.8.0.2\lib\cmake\Qhull
>
```

Debug 编译
```bash
> cmake .. -G "MinGW Makefiles"  -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=D:\devtools\pcl.1.13.1\debug -DEIGEN_INCLUDE_DIR=D:/devtools/eigen.3.4.0/include/eigen3 -DBOOST_ROOT=D:/devtools/boost.mingw64.1.82.0 -DVTK_DIR=D:\devtools\VTK.9.3.0\lib\cmake\vtk-9.3 -DQhull_DIR=D:\devtools\QHULL.8.0.2\lib\cmake\Qhull
>
> mingw32-make.exe -j12
```


## 运行环境


Release

```bash
> set Path=D:\devtools\liblas.1.8.1;D:\devtools\pcl.1.13.1\bin;D:\devtools\PDAL.2.6.0\bin;D:\devtools\VTK.9.3.0\bin;D:\devtools\proj.9.2.1\bin;D:\devtools\TIFF.4.6.0\bin;D:\devtools\crul.mingw.8.2.1\bin;D:\devtools\lz4.1.9.4\bin;D:\devtools\GDAL.3.7.3\bin;D:\devtools\zlib.1.3\bin;%Path%
>
```


Debug

```bash
> set Path=D:\devtools\liblas.1.8.1;D:\devtools\pcl.1.13.1\debug\bin;D:\devtools\PDAL.2.6.0\bin;D:\devtools\VTK.9.3.0\bin;D:\devtools\proj.9.2.1\bin;D:\devtools\TIFF.4.6.0\bin;D:\devtools\crul.mingw.8.2.1\bin;D:\devtools\lz4.1.9.4\bin;D:\devtools\GDAL.3.7.3\bin;D:\devtools\zlib.1.3\bin;%Path%
>
```
