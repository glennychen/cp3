https://www.python.org/downloads/

python3.4.8, 2018-02-05 (might be a newer version of 3.4.8)
https://www.python.org/downloads/release/python-348/


mkdir ~/python34
(where to install python34)


tar xvfz Python-3.4.8.tgz

cd Python-3.4.8
$ ./configure --prefix=/home/bps/python34

$ make -j8
$ make install




# Install necessary system packages
sudo apt-get install -y \
    python-pip \
    build-essential \
    git \
    python3 \
    python3-dev \
    ffmpeg \
    libsdl2-dev \
    libsdl2-image-dev \
    libsdl2-mixer-dev \
    libsdl2-ttf-dev \
    libportmidi-dev \
    libswscale-dev \
    libavformat-dev \
    libavcodec-dev \
    zlib1g-dev
    
    
# Install gstreamer for audio, video (optional)
sudo apt-get install -y \
    libgstreamer1.0 \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good

    
# Make sure Pip, Virtualenv and Setuptools are updated
sudo pip install --upgrade pip virtualenv setuptools


virtualenv --no-site-packages -p /home/bps/python34/bin/python3.4 kivyinstall


# Enter the virtualenv
. kivyinstall/bin/activate

# Use correct Cython version here
pip install Cython==0.28.3

# For the development version of Kivy, use the following command instead
# pip install git+https://github.com/kivy/kivy.git@master


# Install development version of buildozer into the virtualenv
pip install git+https://github.com/kivy/buildozer.git@master

# Install development version of plyer into the virtualenv
pip install git+https://github.com/kivy/plyer.git@master

# Install a couple of dependencies for KivyCatalog
pip install -U pygments docutils

pip install kivy-examples

(kivyinstall) bps@glenn:~$ python -c "import pkg_resources; print(pkg_resources.resource_filename('kivy', '../share/kivy-examples'))"
[WARNING] [Config      ] Older configuration version detected (0 instead of 20)
[WARNING] [Config      ] Upgrading configuration in progress.
[INFO   ] [Logger      ] Record log in /home/bps/.kivy/logs/kivy_18-07-06_0.txt
[INFO   ] [Kivy        ] v1.11.0.dev0, git-e6c4516, 20180707
[INFO   ] [Python      ] v3.4.8 (default, Jul  6 2018, 19:58:34) 
[GCC 5.5.0 20171010]
/home/bps/kivyinstall/lib/python3.4/site-packages/kivy/../share/kivy-examples
(kivyinstall) bps@glenn:~$ cd /home/bps/kivyinstall/share/kivy-examples

=======



Android:

Might need to install dependencies, (java sdk, etc...)
https://buildozer.readthedocs.io/en/latest/installation.html#targeting-android
e.g. 

Ubuntu 16.04
# sudo apt install openjdk-8-jdk 


$buildozer init

now plug in your android device
(remember to enable "USB debugging" in your phone settings)
 

$buildozer android debug deploy run

TROUBLESHOOT: raise the log level, go to the spec file, change it to "2". looks like cython has to be 0.21? pip install cython==0.21
export JAVA_HOME=/home/bps/android-studio/jre



TROUBLESHOOT: buildozer cannot push the app to the phone
https://github.com/kivy/buildozer/pull/691/files#diff-2369900362f2c0ecf8559eb6d48e6feb
https://raw.githubusercontent.com/gautam-kumar-22/buildozer/bb10d1d9a6c19852d19a4b34a1c92829b1d688a2/buildozer/targets/android.py