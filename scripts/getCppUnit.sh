echo $HOME/include/cppunit/
if [ -f  $HOME/include/cppunit/Message.h ]; then
    echo "CppUnit is already installed"
    . scripts/exports.sh
else
    echo "Install CppUnit"
    wget http://dev-www.libreoffice.org/src/cppunit-1.13.2.tar.gz
    tar -xvzf cppunit-1.13.2.tar.gz
    cd cppunit-1.13.2
    ./configure --prefix=$HOME
    make
    make install
    export CPLUS_INCLUDE_PATH=$HOME/include:$CPLUS_INCLUDE_PATH
    export LIBRARY_PATH=$HOME/lib:$LIBRARY_PATH
    export LD_LIBRARY_PATH=$HOME/lib:$LD_LIBRARY_PATH
fi
