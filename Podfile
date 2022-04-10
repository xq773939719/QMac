install! 'cocoapods'

workspace 'QMac'
source 'https://mirrors.tuna.tsinghua.edu.cn/git/CocoaPods/Specs.git'
# Uncomment the next line to define a global platform for your project
platform :osx, '10.10'

use_frameworks!
use_modular_headers!
inhibit_all_warnings!
set_arc_compatibility_flag!

#------ 业务组件 ------#
def BusinessModules

end


#------ 通用组件 ------#
def CommonModules

end

#------ 基础组件 ------#
def BaseModules

end

#------ 第三方库 ------#
def ThridPartyModules

  # 网络请求
  pod 'AFNetworking'
  pod 'Reachability'

  # 布局
  pod 'Masonry'

  # 响应式
  pod 'ReactiveCocoa'
  pod 'ReactiveObjC'
  pod 'RxSwift'
  pod 'RxCocoa'

  # pod 'GPUImage'
  
  # 图片
  pod 'SDWebImage'
  
  # UICollectionView
  pod 'IGListKit'
  
  # CrashReporter
  pod 'PLCrashReporter'

  # Socket 库
  pod 'CocoaAsyncSocket'
  
  # JSON Dictionary
  pod 'MJExtension'

  pod "Aspects"
  
  # 动画
  pod 'lottie-ios'

  # 数据解析
  pod 'JSONModel'

  # 数据库
  pod 'FMDB'

  # PromiseKit
  pod "PromiseKit"
  pod 'PromisesSwift'
  
  # 日志框架
  pod 'CocoaLumberjack'
  pod "NSLogger"
  
  # gRPC
  # pod 'gRPC'
  # pod 'gRPC-Core'
  # pod 'gRPC-ProtoRPC'
  
  # proto
  pod 'Protobuf'

  # 压缩解压
  pod 'SSZipArchive'

  # JS热修复 交互
  pod 'JSPatch'
  pod 'WebViewJavascriptBridge'

  # 正则表达式
  pod 'RegexKitLite-NoWarning'

  # 图像
  # pod 'GPUImage'
  
  # Crash 防护
  pod 'JJException'
  
  pod 'SocketRocket'
  
  pod 'GRDB.swift'
  
  pod 'ReachabilitySwift'
  
  pod 'SwiftDate'
  
  pod 'Alamofire'

  pod 'SwifterSwift'
  pod 'SQLite.swift'
  pod 'SwiftLint'
  
end

#------ 开发组件 ------#
# !!! 不要忘记注释相应的模块
def DevelopModule
  pod 'QTools', :path => '../Develop/QTools'
end

# Pods for QMac
target 'QMac' do
  # Comment the next line if you don't want to use dynamic frameworks
  DevelopModule()
  ThridPartyModules()
  BaseModules()
  CommonModules()
  BusinessModules()
end
