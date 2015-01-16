class Usqlxx < Formula
  homepage "http://www.cybergarage.org/do/view/Main/SqlEngineForCC"
  url "https://github.com/cybergarage/uSQL4CC.git"
  sha1 "0bf051150500074da675cac16e8b8a66d9d3d62c"

  depends_on "readline"

  def install
    system "./configure", "--disable-debug",
                          "--disable-dependency-tracking",
                          "--disable-silent-rules",
                          "--prefix=#{prefix}",
                          "MKDIR_P='mkdir -p'"
    system "make", "install"
  end
end
