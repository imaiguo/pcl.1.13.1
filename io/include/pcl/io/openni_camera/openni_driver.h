/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2011 Willow Garage, Inc.
 *
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the copyright holder(s) nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

#pragma once

#include <pcl/pcl_config.h>
#ifdef HAVE_OPENNI

#include "openni.h"
#include "openni_exception.h"
#include "openni_device.h"

#include <pcl/memory.h> // for pcl::weak_ptr
#include <pcl/pcl_macros.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace openni_wrapper
{
  //class OpenNIDevice;

  /**
   * @brief Driver class implemented as Singleton. This class contains the xn::Context object used by all devices. It \
   * provides methods for enumerating and accessing devices.
   * @author Suat Gedikli
   * @date 02.january 2011
   * @ingroup io
   */
  class PCL_EXPORTS OpenNIDriver
  {
  public:
    /**
     * @author Suat Gedikli
     * @brief virtual Destructor that never throws an exception
     */
    ~OpenNIDriver () noexcept;

    /**
     * @author Suat Gedikli
     * @brief static access method to the only instance.
     * @return the only instance of this class.
     */
    inline static OpenNIDriver& getInstance ();

    /**
     * @author Suat Gedikli
     * @brief enumerates all devices and updates the list of available devices.
     * @return the number of devices found.
     */
    unsigned updateDeviceList ();

    /**
     * @author Suat Gedikli
     * @return the number of available devices.
     */
    inline unsigned getNumberDevices () const noexcept;

    /**
     * @author Suat Gedikli
     * @brief creates a virtual device from an ONI file.
     * @param[in] path the path to the ONI file
     * @param[in] repeat whether the ONI playback should be repeated in an infinite loop or not.
     * @param[in] stream whether the device should be created as a streaming or trigger-based device.
     * @return the shared_ptr to the newly created virtual device.
     */
    OpenNIDevice::Ptr createVirtualDevice (const std::string& path, bool repeat, bool stream) const;

    /**
     * @author Suat Gedikli
     * @brief returns the device with a given index, where the index is its position in the device list.
     * @param[in] index index of the device to be retrieved.
     * @return shared_ptr to the device, null if no matching device found.
     */
    OpenNIDevice::Ptr getDeviceByIndex (unsigned index) const;

    /**
     * @author Suat Gedikli
     * @brief returns the device with the given serial number.
     * @param[in] serial_number the serial number of the device to be retrieved.
     * @return shared_ptr to the device, null if no matching device found.
     */
    OpenNIDevice::Ptr getDeviceBySerialNumber (const std::string& serial_number) const;

#ifndef _WIN32
    /**
     * @author Suat Gedikli
     * @brief returns the device that is given by the USB bus/address combination.
     * @param[in] bus the USB bus id
     * @param[in] address the USB address
     * @return shared_ptr to the device, null if no matching device found.
     */
    OpenNIDevice::Ptr getDeviceByAddress (unsigned char bus, unsigned char address) const;
#endif

    /**
     * @author Suat Gedikli
     * @brief method to retrieve the serial number of a device without creating it.
     * @param[in] index the index of the device in the device list.
     * @return the serial number of the device.
     */
    const char* getSerialNumber (unsigned index) const noexcept;

    /**
     * @author Suat Gedikli
     * @brief method to retrieve the connection string of a device without creating it.
     * @param[in] index the index of the device in the device list.
     * @return the connection string of the device.
     */
    const char* getConnectionString (unsigned index) const noexcept;

    /**
     * @author Suat Gedikli
     * @brief method to retrieve the vendor name of the USB device without creating it.
     * @param[in] index the index of the device in the device list.
     * @return the vendor name of the USB device.
     */
    const char* getVendorName (unsigned index) const noexcept;

    /**
     * @author Suat Gedikli
     * @brief method to retrieve the product name of the USB device without creating it.
     * @param[in] index the index of the device in the device list.
     * @return the product name of the USB device.
     */
    const char* getProductName (unsigned index) const noexcept;

    /**
     * @author Suat Gedikli
     * @brief method to retrieve the vendor id of the USB device without creating it.
     * @param[in] index the index of the device in the device list.
     * @return the vendor id of the USB device.
     */
    unsigned short getVendorID (unsigned index) const noexcept;

    /**
     * @author Suat Gedikli
     * @brief method to retrieve the product id of the USB device without creating it.
     * @param[in] index the index of the device in the device list.
     * @return the product id of the USB device.
     */
    unsigned short getProductID (unsigned index) const noexcept;

    /**
     * @author Suat Gedikli
     * @brief method to retrieve the bus id of the USB device without creating it.
     * @param[in] index the index of the device in the device list.
     * @return the bus id of the USB device.
     */
    unsigned char  getBus (unsigned index) const noexcept;

    /**
     * @author Suat Gedikli
     * @brief method to retrieve the vaddress of the USB device without creating it.
     * @param[in] index the index of the device in the device list.
     * @return the address of the USB device.
     */
    unsigned char  getAddress (unsigned index) const noexcept;

    /**
     * @author Suat Gedikli
     * @brief stops all streams from all devices.
     */
    void stopAll ();

    /**
     * @author Suat Gedikli
     * @brief decomposes the connection string into vendor id and product id.
     * @param[in] connection_string the string containing the connection information
     * @param[out] vendorId the vendor id
     * @param[out] productId the product id
     */
    static void
    getDeviceType (const std::string& connection_string, unsigned short& vendorId, unsigned short& productId);
  protected:

    struct PCL_EXPORTS DeviceContext
    {
      DeviceContext (const xn::NodeInfo& device_node, xn::NodeInfo* image_node, xn::NodeInfo* depth_node, xn::NodeInfo * ir_node);
      DeviceContext (const xn::NodeInfo & device_node);
      DeviceContext (const DeviceContext&);
      xn::NodeInfo device_node;
      std::shared_ptr<xn::NodeInfo> image_node;
      std::shared_ptr<xn::NodeInfo> depth_node;
      std::shared_ptr<xn::NodeInfo> ir_node;
      pcl::weak_ptr<OpenNIDevice> device;
    } ;

    OpenNIDriver ();
    OpenNIDevice::Ptr getDevice (unsigned index) const;

#ifndef _WIN32
    // workaround to get additional device nformation like serial number, vendor and product name, until Primesense fix this
    void getDeviceInfos () noexcept;
#endif

    mutable std::vector<DeviceContext> device_context_;
    mutable xn::Context context_;

    std::map< unsigned char, std::map<unsigned char, unsigned > > bus_map_;
    std::map< std::string, unsigned > serial_map_;
    std::map< std::string, unsigned > connection_string_map_;
  } ;

  OpenNIDriver&
  OpenNIDriver::getInstance ()
  {
    static OpenNIDriver driver;
    return driver;
  }

  unsigned
  OpenNIDriver::getNumberDevices () const noexcept
  {
    return static_cast<unsigned> (device_context_.size ());
  }

} // namespace openni_wrapper

#endif

