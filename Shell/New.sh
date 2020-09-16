#!/bin/bash
#author:ZERO-A-ONE
DISTRO=""
Version=0

Ch_System(){
    echo "---------------------------------------------------------------------------------"
    echo "Check Info System"
    echo "---------------------------------------------------------------------------------"
    Linux_True=0
    if [ "$(uname)" == "Darwin" ];then
        echo '->目前本脚本仅支持Linux'
    elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ];then  
        echo '->当前操作系统：Linux' 
        Linux_True=1
    elif ["$(expr substr $(uname -s) 1 10)" == "MINGW32_NT" ];then    
        echo '->目前本脚本仅支持Linux'
    fi
    
    if [ $Linux_True == 1 ];then
        Ch_Liunx
        if [ $DISTRO == "Ubuntu" ];then
            ch_Ubuntu
            #echo "$Version"
            Conf_Ubuntu
        elif [ $DISTRO == "Debian" ];then
            ch_Debian
            Conf_Debian
        fi
    fi   
}

Ch_Liunx(){
    echo "---------------------------------------------------------------------------------"
    echo "Check Distro Linux"
    echo "---------------------------------------------------------------------------------"
    if grep -Eqii "CentOS" /etc/issue || grep -Eq "CentOS" /etc/*-release; then
        DISTRO="CentOS"
        #PM='yum'
    elif grep -Eqi "Red Hat Enterprise Linux Server" /etc/issue || grep -Eq "Red Hat Enterprise Linux Server" /etc/*-release; then
        DISTRO="RHEL"
        #PM='yum'
    elif grep -Eqi "Aliyun" /etc/issue || grep -Eq "Aliyun" /etc/*-release; then
        DISTRO="Aliyun"
        #PM='yum'
    elif grep -Eqi "Fedora" /etc/issue || grep -Eq "Fedora" /etc/*-release; then
        DISTRO='Fedora'
        #PM='yum'
    elif grep -Eqi "Debian" /etc/issue || grep -Eq "Debian" /etc/*-release; then
        DISTRO='Debian'
        #PM='apt'
    elif grep -Eqi "Ubuntu" /etc/issue || grep -Eq "Ubuntu" /etc/*-release; then
        DISTRO='Ubuntu'
        #PM='apt'
    elif grep -Eqi "Raspbian" /etc/issue || grep -Eq "Raspbian" /etc/*-release; then
        DISTRO='Raspbian'
        #PM='apt'
    else
        DISTRO='unknow'
    fi
    echo "->当前发行版：$DISTRO"
}

ch_Ubuntu(){
    echo "---------------------------------------------------------------------------------"
    echo "Check Ubuntu Version"
    echo "---------------------------------------------------------------------------------"
    if grep "16.04" /etc/issue >nul 2>nul; then
        Version=16.04
    elif grep "18.04" /etc/issue >nul 2>nul; then
        Version=18.04
    elif grep "20.04" /etc/issue >nul 2>nul; then
        Version=20.04
    fi
    echo "->当前Ubuntu版本：$Version"
}

ch_Debian(){
    echo "---------------------------------------------------------------------------------"
    echo "Check Debian Version"
    echo "---------------------------------------------------------------------------------"
    if grep "11" /etc/issue >nul 2>nul; then
        Version=11
    elif grep "10" /etc/issue >nul 2>nul; then
        Version=10
    elif grep "9" /etc/issue >nul 2>nul; then
        Version=9
    elif grep "8" /etc/issue >nul 2>nul; then
        Version=8
    fi
    echo "->当前Debian版本：$Version"
}


Ch_Root(){
    echo "---------------------------------------------------------------------------------"
    echo "Check Root"
    echo "---------------------------------------------------------------------------------"
    if [ `whoami` != "root" ]; then
        echo "->This script must be runing as root!!!"
        exit 71
    else
        echo "->Runing as Root"
    fi
}

#配置ubuntu16.04网络源
Conf_Ubuntu16.04(){
    [ ! -f /etc/apt/sources.list.save ] &&  cp /etc/apt/sources.list{,.bak}
    tee /etc/apt/sources.list << EOF
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse 
EOF
    apt-get update
    apt-get upgrade -y
}

#配置ubuntu18.04网络源
Conf_Ubuntu18.04(){
    [ ! -f /etc/apt/sources.list.save ] &&  cp /etc/apt/sources.list{,.bak}
    tee /etc/apt/sources.list << EOF
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
EOF
    apt-get update
    apt-get upgrade -y
}

#配置ubuntu20.04网络源
Conf_Ubuntu20.04(){
    [ ! -f /etc/apt/sources.list.save ] &&  cp /etc/apt/sources.list{,.bak}
    tee /etc/apt/sources.list << EOF
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-security main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-security main restricted universe multiverse
EOF
    apt-get update
    apt-get upgrade -y
}

#配置debian Jessie网络源 debian8
Conf_DebianJessie(){
    [ ! -f /etc/apt/sources.list.save ] &&  cp /etc/apt/sources.list{,.bak}
    tee /etc/apt/sources.list << EOF
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ jessie main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ jessie main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ jessie-updates main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ jessie-updates main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ jessie-backports main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ jessie-backports main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian-security jessie/updates main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian-security jessie/updates main contrib non-free
EOF
    apt install apt-transport-https ca-certificates -y
    apt-get update
    apt-get upgrade -y
}

#配置debian Stretch网络源 debian9
Conf_DebianStretch(){
    [ ! -f /etc/apt/sources.list.save ] &&  cp /etc/apt/sources.list{,.bak}
    tee /etc/apt/sources.list << EOF
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ stretch main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ stretch main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ stretch-updates main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ stretch-updates main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ stretch-backports main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ stretch-backports main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian-security stretch/updates main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian-security stretch/updates main contrib non-free
EOF
    apt install apt-transport-https ca-certificates -y
    apt-get update
    apt-get upgrade -y
}

#配置debian Buster网络源 debian10
Conf_DebianBuster(){
    [ ! -f /etc/apt/sources.list.save ] &&  cp /etc/apt/sources.list{,.bak}
    tee /etc/apt/sources.list << EOF
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ buster main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ buster main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ buster-updates main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ buster-updates main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ buster-backports main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ buster-backports main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian-security buster/updates main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian-security buster/updates main contrib non-free
EOF
    apt install apt-transport-https ca-certificates -y
    apt-get update
    apt-get upgrade -y
}

#配置debian Bullseye网络源 debian11
Conf_DebianBullseye(){
    [ ! -f /etc/apt/sources.list.save ] &&  cp /etc/apt/sources.list{,.bak}
    tee /etc/apt/sources.list << EOF
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ bullseye main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ bullseye main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ bullseye-updates main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ bullseye-updates main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian/ bullseye-backports main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian/ bullseye-backports main contrib non-free
deb https://mirrors.tuna.tsinghua.edu.cn/debian-security bullseye-security main contrib non-free
# deb-src https://mirrors.tuna.tsinghua.edu.cn/debian-security bullseye-security main contrib non-free
EOF
    apt install apt-transport-https ca-certificates -y
    apt-get update
    apt-get upgrade -y
}


Conf_Ubuntu(){
    echo "---------------------------------------------------------------------------------"
    echo "Update Ubuntu APT Source"
    echo "---------------------------------------------------------------------------------"
    echo "THe Ubuntu Version : $Version"
    if [ $Version == 16.04 ];then
        Conf_Ubuntu16.04
    elif [ $Version == 18.04 ];then
        Conf_Ubuntu18.04
    elif [ $Version == 20.04 ];then
        Conf_Ubuntu20.04
    else
        echo "未兼容的版本"
    fi
}

Conf_Debian(){
    echo "---------------------------------------------------------------------------------"
    echo "Update Ubuntu APT Source"
    echo "---------------------------------------------------------------------------------"
    echo "THe Debian Version : $Version"
    if [ $Version == 11 ];then
        Conf_DebianBullseye
    elif [ $Version == 10 ];then
        Conf_DebianBuster
    elif [ $Version == 9 ];then
        Conf_DebianStretch
    elif [ $Version == 8 ];then
        Conf_DebianJessie
    else
        echo "未兼容的版本"
    fi
}

Up_Python(){
    echo "---------------------------------------------------------------------------------"
    echo "Install Python and Pip"
    echo "---------------------------------------------------------------------------------"
    apt install python2 python3 python-pip python3-pip -y
    echo "---------------------------------------------------------------------------------"
    echo "Update Python Source"
    echo "---------------------------------------------------------------------------------"
    pip install -i https://pypi.tuna.tsinghua.edu.cn/simple pip -U
    pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
}

In_Pwndbg(){
    echo "---------------------------------------------------------------------------------"
    echo "Install Pwndbg"
    echo "---------------------------------------------------------------------------------"
    git clone https://github.com/pwndbg/pwndbg
    cd pwndbg
    ./setup.sh
    cd ..
}

In_Pwntools(){
    echo "---------------------------------------------------------------------------------"
    echo "Install Pwntools"
    echo "---------------------------------------------------------------------------------"
    apt-get update
    apt-get install python3 python3-pip python3-dev git libssl-dev libffi-dev build-essential -y
    python3 -m pip install --upgrade pip
    python3 -m pip install --upgrade pwntools
}

main(){
    Ch_Root
    Ch_System
    Up_Python	
    In_Pwntools
    In_Pwndbg
}
main
