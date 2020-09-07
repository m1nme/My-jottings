# 警告和遵守守则

对任何原因在使用中可能对用户自己或他人造成的任何形式的损失和伤害不承担责任。一切仅用作交流和学习用途，请合理利用，请遵守您所在国家的法律法规。

# 简介

一些我个人无聊时无聊写的无聊的小程序和小工具

|        名称        |                     功能                     |     语言     | 最后更新日期 |
| :----------------: | :------------------------------------------: | :----------: | :----------: |
|     模联计时器     |       提供模联活动中的模拟时间轴的展示       |      C#      |  2016.02.29  |
|     AutoClone      |          提供Git中自动进行Clone操作          |    Python    |  2018.11.10  |
|      AutoPull      |          提供Git中自动进行Pull操作           |    Python    |  2018.11.10  |
|      cpuinfo       |                 查看CPU信息                  |    Python    |  2019.01.10  |
|  福大照片精准打击  | 精确查找某人照片（仅供技术验证请勿非法使用） |    Python    |  2019.12.31  |
|  福大照片全面打击  |   全面查找照片（仅供技术验证请勿非法使用）   |    Python    |  2019.12.31  |
|    颜值检测分类    |               自动颜值评分分类               |    Python    |  2019.10.01  |
|      BoomCode      |          自动爆破文件可能的编码形式          |    Python    |  2019.10.20  |
|     BoomCode2      |          自动爆破文件可能的编码形式          |    Python    |  2019.10.28  |
|    EMIXED_Code     |        自动混淆C++或C语言的源代码格式        |    Python    |  2019.12.01  |
|      WatchDog      |           Windows平台硬件信息监控            |      C#      |     未知     |
|       CTFNET       |          CTF线下赛网络环境配置脚本           |    Python    |  2019.12.31  |
|        IDA         |                 一些IDA脚本                  |     IDC      |  2019.12.31  |
|   I-LOVE-Yuzuru    |         为羽生结弦的2020韩国比赛查票         |    Python    |  2020.01.05  |
| I-LOVE-Yuzuru-PLUS |        改良增强版本，注意ID每天会变化        |    Python    |  2020.01.07  |
|      COMOOC20      |           到点自动上网课带系统弹窗           |    Python    |  2020.02.16  |
|      ZXYCalc       |       一个模仿win10风格的计算器基于QT        |     C++      |  2020.07.07  |
|   垃圾邮件轰炸机   |                  小学期作业                  |    Python    |  2020.07.10  |
|        New         |           用于新机器国内源加速更新           | Shell Script |  2020.09.06  |

# Shell Script使用指南

本人写的一些Bash脚本使用指南

## New

用于自动更换国内清华源更新包管理器与Pyhton源，快速配置一台可以用的PWN环境

```bash
curl https://github.com/ZERO-A-ONE/My-jottings/raw/master/Shell/New.sh 
sudo chmod +x New.sh
sudo ./New.sh
```

# 开发日志

### WatchDog

#### 2019.12.07

在控制台应用下实现了基本数据获取功能，对Intel平台支持较为友好，AMD移动端支持较为差劲

#### 2019.12.08

项目迁移到独立仓库`suyucheng-lz/WatchDog`

# 备注

- I-LOVE-Yuzuru感谢`https://github.com/sunnyMengXing/check4cc`寻找到的接口和框架