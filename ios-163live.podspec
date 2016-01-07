Pod::Spec.new do |s|
  s.name             = "ios-163live"
  s.version          = "0.1.0"
  s.summary          = "163live for ios development"

  s.description      = <<-DESC
                       DESC
  s.homepage         = "https://github.com/brivio/ios-163live"
  s.license          = 'MIT'
  s.author           = { "brivio" => "brivio@qq.com" }
  s.source           = { :git => "https://github.com/brivio/ios-163live.git", :tag => s.version.to_s }
  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'source/**/*.{h,m,c}'
  s.vendored_libraries  = 'source/**/*.a'
  s.vendored_frameworks  = 'source/**/*.framework'
  s.resources='source/**/*.bundle'
  s.frameworks='Foundation','OpenGLES','QuartzCore','CoreAudio','CoreGraphics','CoreMedia','AVFoundation','VideoToolBox','AudioToolBox','UIKit'
  s.libraries='z','bz2','iconv'
end
