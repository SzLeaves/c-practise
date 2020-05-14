# Microsoft Visual Studio Code C语言开发环境配置

vscode本质上其实还是一个编辑器，要想在这建立一个C开发环境，还安装一个编译器，和对vscode进行相应的配置

下面操作中需要写很多的配置文件的部分我都在我的gitee仓库中提供了模板，只需要做细微改动即可正常使用.

本指南操作系统使用Win10进行配置，编译器使用基于MYSY2构建的GCC——MinGW-i686（针对x86架构）进行安装，在MYSY2中可以方便的对编译器进行更新.

> GCC也有x64下的编译器，不过要加上这个配置起来就比较复杂了，有兴趣的同学可以私聊我怎么操作，这里仅仅只是配置出一个能用的上的简单开发环境而已

## 01. 配置编译器

### 安装MYSY2
首先要下载并安装MYSY2，可以直接选择以下链接下载  
（由于官方的链接在国外服务器，下载速度较慢，可以自行选择国内的镜像提供的链接进行下载，这里选择清华大学的镜像站）：  
> <https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/msys2-i686-latest.exe>  

下载后进行安装，安装完成时选择打开MYSY2    

**安装时为了方便后面的操作，建议选择默认路径安装**  
**后面下载组件大约需要消耗 1-2GB 的空间**

**安装时为了方便后面的操作，建议选择默认路径安装**  
**后面下载组件大约需要消耗 1-2GB 的空间**

![00-1.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/00-1.jpg)

打开你所选择安装MYSY2的文件夹,在其安装的文件夹下会有三个启动项：  

![00.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/00.jpg)  

三种启动方式区别主要在于编译环境软件包的不同，如gcc，clang等版本不同。通用的工具如：grep,git,vim,emacs等等在三种方式内都是一样的。  
但是我们的重点需要放在这个文件夹上：mingw32  
它们就是之后我们下载编译器的存放位置

首先，我们选择启动mysy2.exe

![01.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/01.jpg)

![01-1.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/01-1.jpg)

### 配置软件源

然后我们需要更新一下软件源，选择国内的镜像站，方便之后快速的下载所需软件及依赖  
打开你所选择安装MYSY2的文件夹，找到路径：`\etc\pacman.d`

![02.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/02.jpg)

然后下载我在仓库中已经写好的配置文件：  
> https://gitee.com/szleaves/C-Practise/blob/master/VSCode-C/setting/pacman.zip

解压后将三个文件直接复制到`\etc\pacman.d`下替换原文件

替换后返回刚刚打开的终端，执行以下命令更新软件源：  
> pacman -Sy

![03.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/03.jpg)

### 更新操作环境
在终端中执行以下命令更新MYSY2中的软件：  
> pacman -Syu
 
![04.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/04.jpg)  

输入y，按回车确认更新  

由于更新过程中会重写配置文件，加上网络原因，如果更新卡在这个地方不动：  

![04-1.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/04-1.png)

**请按下键盘上的`Ctrl + C`结束当前进程，然后关掉终端（就是这个窗口）**  
**然后按上面替换配置文件的步骤重新到那个文件夹下替换一次配置文件**  
**重新打开终端，再重新执行一次`pacman -Syu`命令**
**出现以下界面， 输入y回车安装即可**  

![04-2.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/04-2.jpg)


### 安装MinGW
更新后，输入以下命令来安装x86架构的MinGW：  
> pacman -S --needed base-devel mingw-w64-i686-toolchain   

出现以下类似的内容，按回车确认即可  

![05-1.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/05-1.jpg)

![05.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/05.jpg)   

安装后，查看一下MYSY2根目录下的mingw32文件夹，是不是已经有文件内容了？  

![07.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/07.jpg)   

### 设置环境变量
将mingw32文件夹下的bin文件的目录添加到系统的环境变量中：  

![013.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/013.jpg)  
![09.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/09.jpg)  
![010.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/010.jpg)  
![011.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/011.jpg)  
![012.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/012.jpg)  
![014.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/014.jpg)  

添加完成后，按下Win+R键，输入`cmd`并回车  

![015.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/015.jpg)  
![016.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/016.jpg)  

输入以下命令回车，查看输出  
`gcc -v`

![017.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/017.jpg)

如果有类似这样的信息，说明环境变量配置成功

## 02.配置Microsoft Visual Studio Code

### 安装vscode
进入网址：  
> https://code.visualstudio.com   

选择你需要下载的vscode版本（这里肯定选windows啦  
下载后自行安装，打开即可  

![018.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/018.jpg)  
![019.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/019.jpg)

### 安装插件

* 安装中文插件   

![020.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/020.jpg)  
![021.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/021.jpg)

> 剩下的插件也是按照上面进入拓展商店的方法进行安装

* 搜索/安装插件：C/C++ （又称cpptools）  

![022.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/022.jpg)

* 搜索/安装插件：Code Runner（右键直接运行单文件，但是无法debug  

![023.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/023.jpg)

* 搜索/安装插件：Bracket Pair Colorize（彩虹花括号）  

![024.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/024.jpg)

### 编辑工作区配置文件

首先，你需要在合适的位置建立一个存放你所有运行代码的文件夹（顺便起个好记的名字），
**但是：**

**所有的文件夹路径中都不能有中文名！！**  
**所有的文件夹路径中都不能有中文名！！**  
**所有的文件夹路径中都不能有中文名！！**

~~（三回啊三回kora）~~

![025.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/025.jpg)  
![026.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/026.jpg)  

__然后，回到你创建存放代码文件夹的根目录下__  
下载我在仓库中已经写好的配置文件：  
> https://gitee.com/szleaves/C-Practise/blob/master/VSCode-C/setting/.vscode.zip

下载后解压，选择`.vscode`文件夹并复制到你自己创建的代码文件夹下  

![027.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/027.jpg)  

> .vscode里面是我已经写好的四个配置文件  
> 有兴趣的同学可以查看vscode的官方文档，看看这四个配置文件有什么作用：  
> https://code.visualstudio.com/docs/languages/cpp


### 写代码 && 尝试运行   

1. 打开你所创建存放代码的文件夹作为工作区  

![028.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/028.jpg)  
![029.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/029.jpg)  

**注意：以后你需要运行的源代码，都需要放到这个文件夹下！**  
**注意：以后你需要运行的源代码，都需要放到这个文件夹下！**  
**注意：以后你需要运行的源代码，都需要放到这个文件夹下！**

~~（梅 开 二 度）~~

2. 新建C源代码文件  

![030.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/030.jpg)  

3. 在你创建的文件中写代码  

![031.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/031.jpg)  

4. 运行代码  

    这里有两种运行方式：

    * 控制台调试运行  

    ![032.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/032.jpg)  

    * 如果代码有语法错误，则软件会弹出提示错误，请根据下面终端中显示的信息查找你的错误

    ![033.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/033.jpg)  

    * 右键直接运行单文件（需要上面安装的`Code Runner`插件）  

    ![034.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/034.jpg)  
    ![035.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/035.jpg)  


### 断点调试  

![036.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/036.jpg)    
![037.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VSCode-C/pictures/037.jpg)  

**注意：以后你需要运行的源代码，都需要放到这个文件夹下！**  
**注意：以后你需要运行的源代码，都需要放到这个文件夹下！**  
**注意：以后你需要运行的源代码，都需要放到这个文件夹下！**

~~（三 顾 茅 庐）~~

## 如果运行或配置过程中遇到问题，请邮件至steven-zh@foxmail.com 并附上问题截图说明情况
