# 利用VC++2010 来编写C程序

**先写在前面，VC++2010组件对C99的支持并不完善，真正开发工程时不建议使用这个玩意，毕竟是十年前的东西了**  
**这里使用Win10进行演示，VC++2010用的是学习版，下面有激活密钥**

## 01. 下载 && 安装
使用你们的**迅雷**或者是其他的**P2P工具**下载下面的这个链接：  
`ed2k://|file|cn_visual_studio_2010_express_x86_dvd_532024.iso|1884567552|3BB6EFEECD4966BE6DFAAB5D579A80CF|/`

之后选择你下载的镜像文件进行安装  

![01.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/01.jpg)  
![02.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/02.jpg)  
![03.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/03.jpg)

**如果你的系统没有`装载`这个选项，可以使用你的压缩软件来直接解压这个镜像文件**  
**然后双击解压文件夹下的`Setup.hta`来进行上面的操作**

![06-1.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/06-1.jpg)

**进入安装界面，有一个地方要注意：**  

![04.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/04.jpg)

安装完成后，在开始菜单里面选择VC++2010打开  

![05.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/05.jpg)

然后单击`帮助 --> 注册产品`，输入下面的密钥进行注册激活  
> 6VPJ7-H3CXH-HBTPT-X4T74-3YVY7  

![06.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/06.jpg)

## 02. 使用

先选择`文件 --> 新建 --> 项目`  

![07.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/07.jpg)  

创建一个工程：

![08.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/08.jpg)  
![09.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/09.jpg)  
![10.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/10.jpg)  

再新建一个源文件  
**这里一定要注意，你保存的源代码文件后缀必须是`.c`**  
这样软件才不会调用C++的编译器来进行编译  

![011.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/011.jpg)  
![012.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/012.jpg)  

然后就可以写你的代码了：

![013.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/013.jpg)  

运行一下试试看？  
保存文件后按下键盘上的`Ctrl + F5`  

![014.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/014.jpg)  
![015.jpg](https://gitee.com/szleaves/C-Practise/raw/master/VC2010-C/pictures/015.jpg)  

> 需要注意的是：如果你的程序是单文件运行的话，那么在VC++2010中，一个新建的工程项目只能存放一份源代码  
> 需要注意的是：如果你的程序是单文件运行的话，那么在VC++2010中，一个新建的工程项目只能存放一份源代码  
> 需要注意的是：如果你的程序是单文件运行的话，那么在VC++2010中，一个新建的工程项目只能存放一份源代码  