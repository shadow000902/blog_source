---
title: Linux命令创建及启动Android虚拟机
date: 2016-07-14 23:56:13
categories: [Linux]
tags: [linux]
---

##### 提升Android原生模拟器速度的方法
在Android SDK Manager中勾选中Inter X86 Emulator Accelerator (HAXM installer)，然后安装它

##### 查看支持的模拟器Android版本号
```
android list
```

  <!--more-->

显示如下：
```
TaoYi-Mac:~ taoyi$ android list
Available Android targets:
----------
id: 1 or "android-23"
     Name: Android 6.0
     Type: Platform
     API level: 23
     Revision: 3
     Skins: HVGA, QVGA, WQVGA400, WQVGA432, WSVGA, WVGA800 (default), WVGA854, WXGA720, WXGA800, WXGA800-7in
 Tag/ABIs : default/armeabi-v7a, default/x86, default/x86_64, google_apis/armeabi-v7a, google_apis/x86, google_apis/x86_64
----------
id: 2 or "android-24"
     Name: Android N
     Type: Platform
     API level: 24
     Revision: 1
     Skins: HVGA, QVGA, WQVGA400, WQVGA432, WSVGA, WVGA800 (default), WVGA854, WXGA720, WXGA800, WXGA800-7in
 Tag/ABIs : no ABIs.
----------
id: 3 or "Google Inc.:Google APIs:23"
     Name: Google APIs
     Type: Add-On
     Vendor: Google Inc.
     Revision: 1
     Description: Android + Google APIs
     Based on Android 6.0 (API level 23)
     Libraries:
      * com.android.future.usb.accessory (usb.jar)
          API for USB Accessories
      * com.google.android.media.effects (effects.jar)
          Collection of video effects
      * com.google.android.maps (maps.jar)
          API for Google Maps
     Skins: HVGA, QVGA, WQVGA400, WQVGA432, WSVGA, WVGA800 (default), WVGA854, WXGA720, WXGA800, WXGA800-7in
 Tag/ABIs : no ABIs.
Available Android Virtual Devices:
Available devices definitions:
id: 0 or "tv_1080p"
    Name: Android TV (1080p)
    OEM : Google
    Tag : android-tv
---------
id: 1 or "tv_720p"
    Name: Android TV (720p)
    OEM : Google
    Tag : android-tv
---------
id: 2 or "wear_round"
    Name: Android Wear Round
    OEM : Google
    Tag : android-wear
---------
id: 3 or "wear_round_chin_320_290"
    Name: Android Wear Round Chin
    OEM : Google
    Tag : android-wear
---------
id: 4 or "wear_square"
    Name: Android Wear Square
    OEM : Google
    Tag : android-wear
---------
id: 5 or "Device001"
    Name: Device001
    OEM : User
---------
id: 6 or "Galaxy Nexus"
    Name: Galaxy Nexus
    OEM : Google
---------
id: 7 or "Nexus 10"
    Name: Nexus 10
    OEM : Google
---------
id: 8 or "Nexus 4"
    Name: Nexus 4
    OEM : Google
---------
id: 9 or "Nexus 5"
    Name: Nexus 5
    OEM : Google
---------
id: 10 or "Nexus 6"
    Name: Nexus 6
    OEM : Google
---------
id: 11 or "Nexus 7 2013"
    Name: Nexus 7
    OEM : Google
---------
id: 12 or "Nexus 7"
    Name: Nexus 7 (2012)
    OEM : Google
---------
id: 13 or "Nexus 9"
    Name: Nexus 9
    OEM : Google
---------
id: 14 or "Nexus One"
    Name: Nexus One
    OEM : Google
---------
id: 15 or "Nexus S"
    Name: Nexus S
    OEM : Google
---------
id: 16 or "2.7in QVGA"
    Name: 2.7" QVGA
    OEM : Generic
---------
id: 17 or "2.7in QVGA slider"
    Name: 2.7" QVGA slider
    OEM : Generic
---------
id: 18 or "3.2in HVGA slider (ADP1)"
    Name: 3.2" HVGA slider (ADP1)
    OEM : Generic
---------
id: 19 or "3.2in QVGA (ADP2)"
    Name: 3.2" QVGA (ADP2)
    OEM : Generic
---------
id: 20 or "3.3in WQVGA"
    Name: 3.3" WQVGA
    OEM : Generic
---------
id: 21 or "3.4in WQVGA"
    Name: 3.4" WQVGA
    OEM : Generic
---------
id: 22 or "3.7 FWVGA slider"
    Name: 3.7" FWVGA slider
    OEM : Generic
---------
id: 23 or "3.7in WVGA (Nexus One)"
    Name: 3.7" WVGA (Nexus One)
    OEM : Generic
---------
id: 24 or "4in WVGA (Nexus S)"
    Name: 4" WVGA (Nexus S)
    OEM : Generic
---------
id: 25 or "4.65in 720p (Galaxy Nexus)"
    Name: 4.65" 720p (Galaxy Nexus)
    OEM : Generic
---------
id: 26 or "4.7in WXGA"
    Name: 4.7" WXGA
    OEM : Generic
---------
id: 27 or "5.1in WVGA"
    Name: 5.1" WVGA
    OEM : Generic
---------
id: 28 or "5.4in FWVGA"
    Name: 5.4" FWVGA
    OEM : Generic
---------
id: 29 or "7in WSVGA (Tablet)"
    Name: 7" WSVGA (Tablet)
    OEM : Generic
---------
id: 30 or "10.1in WXGA (Tablet)"
    Name: 10.1" WXGA (Tablet)
    OEM : Generic
```

##### 创建AVD模拟器
```
android create avd -n TestDevices001 -t 1 -b armeabi-v7a
```

```
-t --target         # 新的AVD的Target ID（必须）
-c --sdcard         # 指定一个共享的SD存储卡的路径或者是为新的AVD定制的新的SD存储卡的容量大小，如：-t 512M。（“M”必须大写）
-p --path           # 新的AVD将被创建的位置路径
-n --Name           # 新的AVD的名字（必须）
-f --force          # 强制创建（覆盖已存在的AVD）
-s --skin           # 新的AVD的皮肤
-b --abi            # 例如android-24里面的abi有armeabi-v7a/x86/x86_64，此时就需要指定，如果只有一个abi，则不需要指定
```

##### 查看AVD是否创建成功
```
android list avd
```
结果如下，就说明创建成功了
```
TaoYi-Mac:~ taoyi$ android list avd
Available Android Virtual Devices:
    Name: TestDevices001
    Path: /Users/taoyi/.android/avd/TestDevices001.avd
  Target: Android 6.0 (API level 23)
 Tag/ABI: default/armeabi-v7a
    Skin: WVGA800
```

##### 启动AVD
```
TaoYi-Mac:~ taoyi$ emulator -avd TestDevices001
emulator: WARNING: Increasing RAM size to 1024MB
emulator: WARNING: Classic qemu does not support SMP. The hw.cpu.ncore option from your config file is ignored.
Creating filesystem with parameters:
    Size: 69206016
    Block size: 4096
    Blocks per group: 32768
    Inodes per group: 4224
    Inode size: 256
    Journal blocks: 1024
    Label:
    Blocks: 16896
    Block groups: 1
    Reserved block group size: 7
Created filesystem with 11/4224 inodes and 1302/16896 blocks
```

```
TaoYi-Mac:~ taoyi$ emulator  -port 5676  -avd TestDevices001  -no-window -no-skin -no-audio -no-boot-anim &
sh: 1: glxinfo: not found
emulator: WARNING: Increasing RAM size to 1024MB
sh: 1: glxinfo: not found
emulator: WARNING: Classic qemu does not support SMP. The hw.cpu.ncore option from your config file is ignored.

Your emulator is out of date, please update by launching Android Studio:
 - Start Android Studio
 - Select menu "Tools > Android > SDK Manager"
 - Click "SDK Tools" tab
 - Check "Android SDK Tools" checkbox
 - Click "OK"
```


##### 删除AVD
```
android delete avd -n TestDevices001
```
