echo downloading SFML
wget https://github.com/LaurentGomila/SFML/tarball/master
tar zxf master
rm master
cd LaurentGomila-SFML-56c2eb8

echo installing dependancies
sudo apt-get install libpthread-stubs0-dev
sudo apt-get install libgl1-mesa-dev
sudo apt-get install libx11-dev
sudo apt-get install libxrandr-dev
sudo apt-get install libfreetype6-dev
sudo apt-get install libglew1.5-dev
sudo apt-get install libjpeg8-dev
sudo apt-get install libsndfile1-dev
sudo apt-get install libopenal-dev
sudo apt-get install libjpeg62
sudo apt-get install cmake
sudo apt-get install g++
sudo apt-get install clang

echo Starting SFML 2.0 install
echo building make for dynamic release
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=TRUE > install.log
echo Complete
echo making
make >> install.log
echo Complete
echo Installing
sudo make install >> install.log
echo Complete

echo building make for dynamic debug
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=TRUE >> install.log
echo Complete
echo making
make >> install.log
echo Complete
echo Installing
sudo make install >> install.log
echo Complete


echo building make for static release
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=FALSE >> install.log
echo Complete
echo making
make >> install.log
echo Complete
echo Installing
sudo make install >> install.log
echo Complete


echo building make for static debug
cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=FALSE >> install.log
echo Complete
echo making
make >> install.log
echo Complete
echo Installing
sudo make install >> install.log
echo Complete
