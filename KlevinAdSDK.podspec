#
# Be sure to run `pod lib lint KlevinAdSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
    s.name             = 'KlevinAdSDK'
    s.version          = '2.9.0.216'
    s.summary          = '游可赢广告SDK'
    s.description      = <<-DESC
    游可赢广告SDK，为第三方移动应用快速对接互动娱乐游戏广告服务。
                       DESC

    s.homepage         = 'https://yky.qq.com/'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'KlevinAdSDK' => '3394406214@qq.com' }

    s.ios.deployment_target = '9.0'
    s.source           = { :git => 'https://github.com/KlevinTech/KlevinAdSDK-iOS.git', :tag => s.version.to_s }

    s.vendored_frameworks = 'KlevinAdSDK.framework'

    s.weak_frameworks = 'AdSupport', 'AppTrackingTransparency', 'WebKit'
    s.frameworks = 'StoreKit', 'SystemConfiguration', 'CoreTelephony', 'AVKit', 'AVFoundation', 'CoreMedia'
    s.xcconfig = { "OTHER_LDFLAGS" => "-ObjC" }
    s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    s.pod_target_xcconfig = {
       'VALID_ARCHS' => '$(ARCHS_STANDARD_64_BIT) armv7',
       'ENABLE_BITCODE' => 'NO',
    }
end