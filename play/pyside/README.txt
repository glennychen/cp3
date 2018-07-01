#build a python37 environemnt
virtualenv -p python37/bin/python3 pysideenv

source pysideenv/bin/activate

(pysideenv) pip install --index-url=http://download.qt.io/snapshots/ci/pyside/5.11/latest/ pyside2 --trusted-host download.qt.io
