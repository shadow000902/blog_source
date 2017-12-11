---
title: Appium命令参数说明
date: 2016-04-10 22:56:03
categories: [Appium]
tags: [appium]
---

appium命令帮助

  <!--more-->

``` bash
C:\Users\shadow>appium -h
usage: main.js [-h] [-v] [--shell] [--ipa IPA] [-a ADDRESS] [-p PORT]
               [-ca CALLBACKADDRESS] [-cp CALLBACKPORT] [-bp BOOTSTRAPPORT]
               [-r BACKENDRETRIES] [--session-override] [-l] [-g LOG]
               [--log-level {info,info:debug,info:info,info:warn,info:error,warn,warn:debug,warn:info,warn:warn,warn:error,error,error:debug,error:info,error:warn,error:error,debug,debug:debug,debug:info,debug:warn,debug:error}]
               [--log-timestamp] [--local-timezone] [--log-no-colors]
               [-G WEBHOOK] [--safari] [--default-device] [--force-iphone]
               [--force-ipad] [--tracetemplate AUTOMATIONTRACETEMPLATEPATH]
               [--instruments INSTRUMENTSPATH] [--nodeconfig NODECONFIG]
               [-ra ROBOTADDRESS] [-rp ROBOTPORT]
               [--selendroid-port SELENDROIDPORT]
               [--chromedriver-port CHROMEDRIVERPORT]
               [--chromedriver-executable CHROMEDRIVEREXECUTABLE]
               [--show-config] [--no-perms-check]
               [--command-timeout DEFAULTCOMMANDTIMEOUT] [--strict-caps]
               [--isolate-sim-device] [--tmp TMPDIR] [--trace-dir TRACEDIR]
               [--debug-log-spacing] [--suppress-adb-kill-server]
               [--async-trace]
               [--webkit-debug-proxy-port WEBKITDEBUGPROXYPORT]
               [--default-capabilities DEFAULTCAPABILITIES] [-k]
               [--platform-name PLATFORMNAME]
               [--platform-version PLATFORMVERSION]
               [--automation-name AUTOMATIONNAME] [--device-name DEVICENAME]
               [--browser-name BROWSERNAME] [--app APP] [-lt LAUNCHTIMEOUT]
               [--language LANGUAGE] [--locale LOCALE] [-U UDID]
               [--orientation ORIENTATION] [--no-reset] [--full-reset]
               [--app-pkg APPPACKAGE] [--app-activity APPACTIVITY]
               [--app-wait-package APPWAITPACKAGE]
               [--app-wait-activity APPWAITACTIVITY]
               [--device-ready-timeout DEVICEREADYTIMEOUT]
               [--android-coverage ANDROIDCOVERAGE] [--avd AVD]
               [--avd-args AVDARGS] [--use-keystore]
               [--keystore-path KEYSTOREPATH]
               [--keystore-password KEYSTOREPASSWORD] [--key-alias KEYALIAS]
               [--key-password KEYPASSWORD] [--intent-action INTENTACTION]
               [--intent-category INTENTCATEGORY] [--intent-flags INTENTFLAGS]
               [--intent-args OPTIONALINTENTARGUMENTS]
               [--dont-stop-app-on-reset] [--calendar-format CALENDARFORMAT]
               [--native-instruments-lib] [--keep-keychains]
               [--localizable-strings-dir LOCALIZABLESTRINGSDIR]
               [--show-ios-log]


A webdriver-compatible server for use with native and hybrid iOS and Android applications.

Optional arguments:
  -h, --help            Show this help message and exit.
  -v, --version         Show program's version number and exit.
  --shell               Enter REPL mode
  --ipa IPA             (IOS-only) abs path to compiled .ipa file
  -a ADDRESS, --address ADDRESS IP Address to listen on
  -p PORT, --port PORT  port to listen on
  -ca CALLBACKADDRESS, --callback-address CALLBACKADDRESS callback IP Address (default: same as --address)
  -cp CALLBACKPORT, --callback-port CALLBACKPORT callback port (default: same as port)
  -bp BOOTSTRAPPORT, --bootstrap-port BOOTSTRAPPORT
                        (Android-only) port to use on device to talk to Appium
  -r BACKENDRETRIES, --backend-retries BACKENDRETRIES
                        (iOS-only) How many times to retry launching Instruments before saying it crashed or timed out
  --session-override    Enables session override (clobbering)
  -l, --pre-launch      Pre-launch the application before allowing the first session (Requires --app and, for Android, --app-pkg and --app-activity)
  -g LOG, --log LOG     Also send log output to this file
  --log-level {info,info:debug,info:info,info:warn,info:error,warn,warn:debug,warn:info,warn:warn,warn:error,error,error:debug,error:info,error:warn,error:error,debug,debug:debug,debug:info,debug:warn,debug:error} log level; default (console[:file]): debug[:debug]
  --log-timestamp       Show timestamps in console output
  --local-timezone      Use local timezone for timestamps
  --log-no-colors       Do not use colors in console output
  -G WEBHOOK, --webhook WEBHOOK
                        Also send log output to this HTTP listener
  --safari              (IOS-Only) Use the safari app
  --default-device, -dd
                        (IOS-Simulator-only) use the default simulator that instruments launches on its own
  --force-iphone        (IOS-only) Use the iPhone Simulator no matter what the app wants
  --force-ipad          (IOS-only) Use the iPad Simulator no matter what the app wants
  --tracetemplate AUTOMATIONTRACETEMPLATEPATH
                        (IOS-only) .tracetemplate file to use with Instruments
  --instruments INSTRUMENTSPATH
                        (IOS-only) path to instruments binary
  --nodeconfig NODECONFIG
                        Configuration JSON file to register appium with selenium grid
  -ra ROBOTADDRESS, --robot-address ROBOTADDRESS
                        IP Address of robot
  -rp ROBOTPORT, --robot-port ROBOTPORT
                        port for robot
  --selendroid-port SELENDROIDPORT
                        Local port used for communication with Selendroid
  --chromedriver-port CHROMEDRIVERPORT
                        Port upon which ChromeDriver will run
  --chromedriver-executable CHROMEDRIVEREXECUTABLE
                        ChromeDriver executable full path
  --show-config         Show info about the appium server configuration and exit
  --no-perms-check      Bypass Appium's checks to ensure we can read/write necessary files
  --command-timeout DEFAULTCOMMANDTIMEOUT
                        The default command timeout for the server to use for all sessions (in seconds and should be less than 2147483). Will still be overridden by newCommandTimeout cap
  --strict-caps         Cause sessions to fail if desired caps are sent in that Appium does not recognize as valid for the selected device
  --isolate-sim-device  Xcode 6 has a bug on some platforms where a certain simulator can only be launched without error if all other simulator devices are first deleted. This option causes Appium to delete all devices other than the one being used by Appium. Note that this is a permanent deletion, and you are responsible for using simctl or xcode to manage the categories of devices used with Appium.
  --tmp TMPDIR          Absolute path to directory Appium can use to manage temporary files, like built-in iOS apps it needs to move around. On *nix/Mac defaults to /tmp, on Windows defaults to C:\Windows\Temp
  --trace-dir TRACEDIR  Absolute path to directory Appium use to save ios instruments traces, defaults to <tmp dir>/appium-instruments
  --debug-log-spacing   Add exaggerated spacing in logs to help with visual inspection
  --suppress-adb-kill-server
                        (Android-only) If set, prevents Appium from killing the adb server instance
  --async-trace         Add long stack traces to log entries. Recommended for debugging only.
  --webkit-debug-proxy-port WEBKITDEBUGPROXYPORT
                        (IOS-only) Local port used for communication with ios-webkit-debug-proxy
  --default-capabilities DEFAULTCAPABILITIES
                        Set the default desired capabilities, which will be set on each session unless overridden by received capabilities.
  -k, --keep-artifacts  [DEPRECATED] - no effect, trace is now in tmp dir by default and is cleared before each run. Please also refer to the --trace-dir flag.
  --platform-name PLATFORMNAME
                        [DEPRECATED] - Name of the mobile platform: iOS, Android, or FirefoxOS
  --platform-version PLATFORMVERSION
                        [DEPRECATED] - Version of the mobile platform
  --automation-name AUTOMATIONNAME
                        [DEPRECATED] - Name of the automation tool: Appium or Selendroid
  --device-name DEVICENAME
                        [DEPRECATED] - Name of the mobile device to use
  --browser-name BROWSERNAME
                        [DEPRECATED] - Name of the mobile browser: Safari or Chrome
  --app APP             [DEPRECATED] - IOS: abs path to simulator-compiled . app file or the bundle_id of the desired target on device; Android: abs path to .apk file
  -lt LAUNCHTIMEOUT, --launch-timeout LAUNCHTIMEOUT
                        [DEPRECATED] - (iOS-only) how long in ms to wait for Instruments to launch
  --language LANGUAGE   [DEPRECATED] - Language for the iOS simulator / Android Emulator
  --locale LOCALE       [DEPRECATED] - Locale for the iOS simulator / Android Emulator

  # 指定设备UDID运行
  -U UDID, --udid UDID  [DEPRECATED] - Unique device identifier of the connected physical device
  --orientation ORIENTATION
                        [DEPRECATED] - (IOS-only) use LANDSCAPE or PORTRAIT to initialize all requests to this orientation

  # 在appium的各个session之间不重置app
  --no-reset            [DEPRECATED] - Do not reset app state between sessions (IOS: do not delete app plist files; Android: do not uninstall app before new session)
  --full-reset          [DEPRECATED] - (iOS) Delete the entire simulator folder. (Android) Reset app state by uninstalling app instead of clearing app data. On Android, this will also remove the app after the session is complete.
  --app-pkg APPPACKAGE  [DEPRECATED] - (Android-only) Java package of the Android app you want to run (e.g., com.example. android.myApp)
  --app-activity APPACTIVITY
                        [DEPRECATED] - (Android-only) Activity name for the Android activity you want to launch from your package (e.g., MainActivity)
  --app-wait-package APPWAITPACKAGE
                        [DEPRECATED] - (Android-only) Package name for the Android activity you want to wait for (e.g., com. example.android.myApp)
  --app-wait-activity APPWAITACTIVITY
                        [DEPRECATED] - (Android-only) Activity name for the Android activity you want to wait for (e.g., SplashActivity)
  --device-ready-timeout DEVICEREADYTIMEOUT
                        [DEPRECATED] - (Android-only) Timeout in seconds while waiting for device to become ready
  --android-coverage ANDROIDCOVERAGE
                        [DEPRECATED] - (Android-only) Fully qualified instrumentation class. Passed to -w in adb shell am instrument -e coverage true -w
  --avd AVD             [DEPRECATED] - (Android-only) Name of the avd to launch
  --avd-args AVDARGS    [DEPRECATED] - (Android-only) Additional emulator arguments to launch the avd
  --use-keystore        [DEPRECATED] - (Android-only) When set the keystore will be used to sign apks.
  --keystore-path KEYSTOREPATH
                        [DEPRECATED] - (Android-only) Path to keystore
  --keystore-password KEYSTOREPASSWORD
                        [DEPRECATED] - (Android-only) Password to keystore
  --key-alias KEYALIAS  [DEPRECATED] - (Android-only) Key alias
  --key-password KEYPASSWORD
                        [DEPRECATED] - (Android-only) Key password
  --intent-action INTENTACTION
                        [DEPRECATED] - (Android-only) Intent action which will be used to start activity
  --intent-category INTENTCATEGORY
                        [DEPRECATED] - (Android-only) Intent category which will be used to start activity
  --intent-flags INTENTFLAGS
                        [DEPRECATED] - (Android-only) Flags that will be used to start activity
  --intent-args OPTIONALINTENTARGUMENTS
                        [DEPRECATED] - (Android-only) Additional intent arguments that will be used to start activity
  --dont-stop-app-on-reset
                        [DEPRECATED] - (Android-only) When included, refrains from stopping the app before restart
  --calendar-format CALENDARFORMAT
                        [DEPRECATED] - (IOS-only) calendar format for the iOS simulator
  --native-instruments-lib
                        [DEPRECATED] - (IOS-only) IOS has a weird built-in unavoidable delay. We patch this in appium. If you do not want it patched, pass in this flag.
  --keep-keychains      [DEPRECATED] - (iOS-only) Whether to keep keychains (Library/Keychains) when reset app between sessions
  --localizable-strings-dir LOCALIZABLESTRINGSDIR
                        [DEPRECATED] - (IOS-only) the relative path of the dir where Localizable.strings file resides
  --show-ios-log        [DEPRECATED] - (IOS-only) if set, the iOS system log will be written to the console
```