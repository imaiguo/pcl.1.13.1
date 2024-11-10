
# PCL

## 依赖项

1. Eigen
2. FLANN
3. boost-1_82
4. VTK
5. Qhull
6. lz4
7. Qt

8. OpenNI2
    PDAL
    proj
    zlib
    curl
    TIFF


## Build with MSVC

### Release 编译
```bash
> git checkout msvc
> cmd
> "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
> set LIB=D:\devtools\Qt\qteverywhere.5.15.2\bin;D:\devtools\openssl.3.0.8\bin;%LIB%
> set PATH=%Path%;D:\devtools\Qt\qteverywhere.5.15.2\bin;
> cmake -B build -G Ninja  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=D:\devtools\pcl.1.13.1 -DEIGEN_INCLUDE_DIR=D:\devtools\eigen.3.4.0\include\eigen3 -DBOOST_ROOT=D:\devtools\boost.1.82.0 -DVTK_DIR=D:\devtools\VTK.9.3.0\lib\cmake\vtk-9.3 -DQhull_DIR=D:\devtools\QHULL.8.0.2\lib\cmake\Qhull -Dflann_DIR=D:\devtools\flann.1.9.2\lib\cmake\flann -DLZ4_INCLUDE_DIRS=D:\devtools\lz4.1.9.4\include
```

### Debug 编译
```bash
> cmake .. -G "MinGW Makefiles"  -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=D:\devtools\pcl.1.13.1\debug -DEIGEN_INCLUDE_DIR=D:/devtools/eigen.3.4.0/include/eigen3 -DBOOST_ROOT=D:/devtools/boost.mingw64.1.82.0 -DVTK_DIR=D:\devtools\VTK.9.3.0\lib\cmake\vtk-9.3 -DQhull_DIR=D:\devtools\QHULL.8.0.2\lib\cmake\Qhull
>
```

## Build with MingW

### 编译Release
```bash
> cmd
> mkdir build & cd build
> "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
> qtenv
> set PKG_CONFIG_PATH=D:/devtools/flann.1.9.2/lib/pkgconfig;D:\devtools\lz4.1.9.4\lib\pkgconfig;%PKG_CONFIG_PATH%
> cmake .. -G "MinGW Makefiles"  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=D:\devtools\pcl.1.13.1 -DEIGEN_INCLUDE_DIR=D:/devtools/eigen.3.4.0/include/eigen3 -DBOOST_ROOT=D:/devtools/boost.mingw64.1.82.0 -DVTK_DIR=D:\devtools\VTK.9.3.0\lib\cmake\vtk-9.3 -DQhull_DIR=D:\devtools\QHULL.8.0.2\lib\cmake\Qhull
>
```

### Debug 编译
```bash
> cmake .. -G "MinGW Makefiles"  -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=D:\devtools\pcl.1.13.1\debug -DEIGEN_INCLUDE_DIR=D:/devtools/eigen.3.4.0/include/eigen3 -DBOOST_ROOT=D:/devtools/boost.mingw64.1.82.0 -DVTK_DIR=D:\devtools\VTK.9.3.0\lib\cmake\vtk-9.3 -DQhull_DIR=D:\devtools\QHULL.8.0.2\lib\cmake\Qhull
>
```

## 运行环境

### Release

```bash
> set Path=D:\devtools\liblas.1.8.1;D:\devtools\pcl.1.13.1\bin;D:\devtools\PDAL.2.6.0\bin;D:\devtools\VTK.9.3.0\bin;D:\devtools\proj.9.2.1\bin;D:\devtools\TIFF.4.6.0\bin;D:\devtools\crul.mingw.8.2.1\bin;D:\devtools\lz4.1.9.4\bin;D:\devtools\GDAL.3.7.3\bin;D:\devtools\zlib.1.3\bin;%Path%
>
```

### Debug

```bash
> set Path=D:\devtools\liblas.1.8.1;D:\devtools\pcl.1.13.1\debug\bin;D:\devtools\PDAL.2.6.0\bin;D:\devtools\VTK.9.3.0\bin;D:\devtools\proj.9.2.1\bin;D:\devtools\TIFF.4.6.0\bin;D:\devtools\crul.mingw.8.2.1\bin;D:\devtools\lz4.1.9.4\bin;D:\devtools\GDAL.3.7.3\bin;D:\devtools\zlib.1.3\bin;%Path%
>
```
