# Maintainer: opekope2 <opekope2@gmail.com>
_gitname=bashd
pkgname=$_gitname-git
pkgver=r3.ff4da90
pkgrel=1
pkgdesc="bash'd is a simple daemon process for executing a command on a signal."
arch=('x86_64')
url="https://github.com/opekope2/$_gitname"
license=('Unlicense')
makedepends=('git' 'gcc')
source=("git+https://github.com/opekope2/$_gitname.git")
sha256sums=('SKIP')

pkgver() {
    cd "$srcdir/$_gitname"
    echo "r$(git rev-list --count HEAD).$(git rev-parse --short HEAD)"
}

build() {
    cd "$srcdir/bashd"
    gcc -o bashd bashd.c
}

package() {
    install -D -m755 "$_gitname/bashd" "$pkgdir/usr/bin/bashd"
}
